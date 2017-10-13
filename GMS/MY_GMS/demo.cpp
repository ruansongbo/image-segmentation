// GridMatch.cpp : Defines the entry point for the console application.

//#define USE_GPU 

#include "Header.h"
#include "gms_matcher.h"
#include <time.h> 
void GmsMatch(Mat &img1, Mat &img2);

void runImagePair(){
	Mat img1 = imread("../data/5.jpg");
	Mat img2 = imread("../data/6.jpg");

	imresize(img1, 480);
	imresize(img2, 480);

	GmsMatch(img1, img2);
}


int main()
{
#ifdef USE_GPU
	int flag = cuda::getCudaEnabledDeviceCount();
	if (flag != 0){ cuda::setDevice(0); }
#endif // USE_GPU

	runImagePair();

	return 0;
}


void GmsMatch(Mat &img1, Mat &img2){
	vector<KeyPoint> kp1, kp2;
	Mat d1, d2;
	vector<DMatch> matches_all, matches_gms;

	Ptr<ORB> orb = ORB::create(100000);
	orb->setFastThreshold(0);
	orb->detectAndCompute(img1, Mat(), kp1, d1);
	orb->detectAndCompute(img2, Mat(), kp2, d2);

#ifdef USE_GPU
	GpuMat gd1(d1), gd2(d2);
	Ptr<cuda::DescriptorMatcher> matcher = cv::cuda::DescriptorMatcher::createBFMatcher(NORM_HAMMING);
	matcher->match(gd1, gd2, matches_all);
#else
	BFMatcher matcher(NORM_HAMMING);
	//用clock()来计时  毫秒    
	clock_t  clockBegin, clockEnd;
	clockBegin = clock();
	matcher.match(d1, d2, matches_all);
	clockEnd = clock();
	printf("%d\n", clockEnd - clockBegin);
#endif

	// GMS filter
	int num_inliers = 0;
	std::vector<bool> vbInliers;
	gms_matcher gms(kp1,img1.size(), kp2,img2.size(), matches_all);
	num_inliers = gms.GetInlierMask(vbInliers, false, false);

	cout << "Get total " << num_inliers << " matches." << endl;

	// draw matches
	for (size_t i = 0; i < vbInliers.size(); ++i)
	{
		if (vbInliers[i] == true)
		{
			matches_gms.push_back(matches_all[i]);
		}
	}

	Mat show = DrawInlier(img1, img2, kp1, kp2, matches_gms, 1);
	imshow("show", show);
	imwrite("show.jpg", show);
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;
	for (size_t i = 0; i < num_inliers; i++)
	{
		obj.push_back(kp1[matches_gms[i].queryIdx].pt);
		scene.push_back(kp2[matches_gms[i].trainIdx].pt);
	}
	Mat H = findHomography(scene, obj, RANSAC);				//影射矩阵
	Mat img_tran;
	img_tran = Mat::zeros(img2.rows, img2.cols, img2.type());
	warpPerspective(img2, img_tran, H, img_tran.size());
	imshow("img_tran", img_tran);							//显示转换后图像
	imwrite("img_tran.jpg", img_tran);
	Mat Template_rgb = imread("../data/5.jpg");
	imresize(Template_rgb, 480);
	Mat Template, img_tran_gray;
	cvtColor(Template_rgb, Template, CV_BGR2GRAY);
	cvtColor(img_tran, img_tran_gray, CV_BGR2GRAY);
	Mat diff, BW_image;
	absdiff(Template, img_tran_gray, diff);
	imshow("ss", diff); 
	imwrite("GMS.jpg", diff);
	float sum = 0.;
	for (int i = 0; i < diff.rows; i++)
	{
		for (int j = 0; j < diff.cols; j++)
		{
			sum += diff.at<uchar>(i, j);
		}
	}
	printf("pixel:%f", sum / (diff.rows*diff.cols));
	waitKey(0);
}


