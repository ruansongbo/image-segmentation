#include <fstream>  
#include "opencv2/opencv.hpp"  
#include <vector>  

using namespace std;
using namespace cv;
using namespace cv::ml;

#define SHOW_PROCESS 0  
#define ON_STUDY 1  

class NumTrainData
{
public:
	NumTrainData()
	{
		memset(data, 0, sizeof(data));
		result = -1;
	}
public:
	float data[64];
	int result;
};

vector<NumTrainData> buffer;
int featureLen = 64;

void swapBuffer(char* buf)
{
	char temp;
	temp = *(buf);
	*buf = *(buf + 3);
	*(buf + 3) = temp;

	temp = *(buf + 1);
	*(buf + 1) = *(buf + 2);
	*(buf + 2) = temp;
}

void GetROI(Mat& src, Mat& dst)
{
	int left, right, top, bottom;
	left = src.cols;
	right = 0;
	top = src.rows;
	bottom = 0;

	//Get valid area  
	for (int i = 0; i<src.rows; i++)
	{
		for (int j = 0; j<src.cols; j++)
		{
			if (src.at<uchar>(i, j) > 0)
			{
				if (j<left) left = j;
				if (j>right) right = j;
				if (i<top) top = i;
				if (i>bottom) bottom = i;
			}
		}
	}

	//Point center;  
	//center.x = (left + right) / 2;  
	//center.y = (top + bottom) / 2;  

	int width = right - left;
	int height = bottom - top;
	int len = (width < height) ? height : width;

	//Create a squre  
	dst = Mat::zeros(len, len, CV_8UC1);

	//Copy valid data to squre center  
	Rect dstRect((len - width) / 2, (len - height) / 2, width, height);
	Rect srcRect(left, top, width, height);
	Mat dstROI = dst(dstRect);
	Mat srcROI = src(srcRect);
	srcROI.copyTo(dstROI);
}

int ReadTrainData(int maxCount)
{
	//Open image and label file  
	const char fileName[] = "mnist_dataset/train-images.idx3-ubytee";
	const char labelFileName[] = "mnist_dataset/train-labels.idx1-ubyte";

	ifstream lab_ifs(labelFileName, ios_base::binary);
	ifstream ifs(fileName, ios_base::binary);

	if (ifs.fail() == true)
		return -1;

	if (lab_ifs.fail() == true)
		return -1;

	//Read train data number and image rows / cols  
	char magicNum[4], ccount[4], crows[4], ccols[4];
	ifs.read(magicNum, sizeof(magicNum));
	ifs.read(ccount, sizeof(ccount));
	ifs.read(crows, sizeof(crows));
	ifs.read(ccols, sizeof(ccols));

	int count, rows, cols;
	swapBuffer(ccount);
	swapBuffer(crows);
	swapBuffer(ccols);

	memcpy(&count, ccount, sizeof(count));
	memcpy(&rows, crows, sizeof(rows));
	memcpy(&cols, ccols, sizeof(cols));

	//Just skip label header  
	lab_ifs.read(magicNum, sizeof(magicNum));
	lab_ifs.read(ccount, sizeof(ccount));

	//Create source and show image matrix  
	Mat src = Mat::zeros(rows, cols, CV_8UC1);
	Mat temp = Mat::zeros(8, 8, CV_8UC1);
	Mat img, dst;

	char label = 0;
	Scalar templateColor(255, 0, 255);

	NumTrainData rtd;

	//int loop = 1000;  
	int total = 0;

	while (!ifs.eof())
	{
		if (total >= count)
			break;

		total++;
		cout << total << endl;

		//Read label  
		lab_ifs.read(&label, 1);
		label = label + '0';

		//Read source data  
		ifs.read((char*)src.data, rows * cols);
		GetROI(src, dst);

#if(SHOW_PROCESS)  
		//Too small to watch  
		img = Mat::zeros(dst.rows * 10, dst.cols * 10, CV_8UC1);
		resize(dst, img, img.size());

		stringstream ss;
		ss << "Number " << label;
		string text = ss.str();
		putText(img, text, Point(10, 50), FONT_HERSHEY_SIMPLEX, 1.0, templateColor);

		//imshow("img", img);  
#endif  

		rtd.result = label;
		resize(dst, temp, temp.size());
		//threshold(temp, temp, 10, 1, CV_THRESH_BINARY);  

		for (int i = 0; i<8; i++)
		{
			for (int j = 0; j<8; j++)
			{
				rtd.data[i * 8 + j] = temp.at<uchar>(i, j);
			}
		}

		buffer.push_back(rtd);

		//if(waitKey(0)==27) //ESC to quit  
		//  break;  

		maxCount--;

		if (maxCount == 0)
			break;
	}

	ifs.close();
	lab_ifs.close();

	return 0;
}


void newSvmStudy(vector<NumTrainData>& trainData)
{
	int testCount = trainData.size();

	Mat m = Mat::zeros(1, featureLen, CV_32FC1);
	Mat data = Mat::zeros(testCount, featureLen, CV_32FC1);
	Mat res = Mat::zeros(testCount, 1, CV_32SC1);

	for (int i = 0; i< testCount; i++)
	{

		NumTrainData td = trainData.at(i);
		memcpy(m.data, td.data, featureLen*sizeof(float));
		normalize(m, m);
		memcpy(data.data + i*featureLen*sizeof(float), m.data, featureLen*sizeof(float));

		res.at<unsigned int>(i, 0) = td.result;
	}

	/////////////START SVM TRAINNING//////////////////  
	/*CvSVM svm = CvSVM();
	CvSVMParams param;
	CvTermCriteria criteria;

	criteria = cvTermCriteria(CV_TERMCRIT_EPS, 1000, FLT_EPSILON);
	param = SVMParams(CvSVM::C_SVC, CvSVM::RBF, 10.0, 8.0, 1.0, 10.0, 0.5, 0.1, NULL, criteria);
	svm.train(data, res, Mat(), Mat(), param);
	svm.save("SVM_DATA.xml");*/
	Ptr<SVM> svm = SVM::create();
	svm->setType(SVM::C_SVC);
	svm->setKernel(SVM::RBF);
	svm->setDegree(10.0);
	svm->setGamma(0.01);
	svm->setCoef0(1.0);
	svm->setC(10.0);
	svm->setNu(0.5);
	svm->setP(0.1);
	svm->train(data, ROW_SAMPLE, res);
	svm->save("SVM_DATA.xml");
}


int main(int argc, char *argv[])
{
#if(ON_STUDY)  
	int maxCount = 60000;
	ReadTrainData(maxCount);

	//newRtStudy(buffer);  
	newSvmStudy(buffer);
#else  
	//newRtPredict();  
	newSvmPredict();
#endif  
	return 0;
}