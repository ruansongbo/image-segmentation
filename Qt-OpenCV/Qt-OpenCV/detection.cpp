#include "detection.h"



detection::detection(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	typeGroup = new QButtonGroup(this);
	typeGroup->addButton(ui.radioButton, 0);
	typeGroup->addButton(ui.radioButton_2, 1);
	ui.radioButton->setChecked(true);
	ui.textEdit->setFontWeight(1);
	ui.textEdit->setFontPointSize(12);
	ui.textEdit->setAlignment(Qt::AlignLeft | Qt::AlignTop);
}

detection::~detection()
{

}
void detection::openCamera()
{
	bool stop = false;
	capture = new VideoCapture(0);
	capture->set(CV_CAP_PROP_FRAME_WIDTH, 2048);
	capture->set(CV_CAP_PROP_FRAME_HEIGHT, 1536);
	if (capture->isOpened())
	{
		connect(timer, SIGNAL(timeout()), this, SLOT(readFrame()));
		timer->start(250);
	}
}
void detection::takingPictures()
{
	Mat frame,origin_frame;
	QImage image;
	capture->operator >>(origin_frame);// 从摄像头中抓取并返回每一帧 
	cv::resize(origin_frame, frame, Size(600, 452));
	if (typeGroup->checkedId())
	{
		ui.textEdit->insertPlainText("B-");
	}
	else
	{
		ui.textEdit->insertPlainText("A-");
	}
	ui.textEdit->insertPlainText(ui.lineEdit->text()+":\n");
	if (!frame.empty())
	{
		timer->stop();			// 停止读取数据。  
		capture->release();		//释放内存；  
		Mat img1_rgb = imread("../template.jpg");
		Mat img_1, img_2;
		cvtColor(img1_rgb, img_1, CV_BGR2GRAY);
		cvtColor(frame, img_2, CV_BGR2GRAY);
		ORB orb(100, 1.05f, 4, 32, 0, 2, ORB::FAST_SCORE, 80);//初始化ORB
		vector<KeyPoint> keyPoints_1, keyPoints_2;
		Mat descriptors_1, descriptors_2;
		double start = GetTickCount();							//开始计时
		orb(img_1, Mat(), keyPoints_1, descriptors_1);
		orb(img_2, Mat(), keyPoints_2, descriptors_2);
		BruteForceMatcher<HammingLUT> matcher;
		vector<DMatch> matches;
		matcher.match(descriptors_1, descriptors_2, matches);
		double max_dist = 0; double min_dist = 100;
		for (int i = 0; i < descriptors_1.rows; i++)
		{
			double dist = matches[i].distance;
			if (dist < min_dist) min_dist = dist;
			if (dist > max_dist) max_dist = dist;
		}   
		std::vector< DMatch > good_matches;
		for (int i = 0; i < descriptors_1.rows; i++)
		{
			if (matches[i].distance < 0.5*max_dist)					//选定匹配点
			{
				good_matches.push_back(matches[i]);		
			}
		}
		double end = GetTickCount();							//计时结束
		Mat img_matches;
		drawMatches(img_1, keyPoints_1, img_2, keyPoints_2,
			good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
			vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		imshow("Match", img_matches);							//显示匹配图
		std::vector<Point2f> obj;
		std::vector<Point2f> scene;
		for (size_t i = 0; i < good_matches.size(); i++)
		{
			obj.push_back(keyPoints_1[good_matches[i].queryIdx].pt);
			scene.push_back(keyPoints_2[good_matches[i].trainIdx].pt);
		}
		Mat H = findHomography(scene, obj, RANSAC);				//影射矩阵
		Mat img_tran;
		img_tran = Mat::zeros(frame.rows, frame.cols, frame.type());
		warpPerspective(frame, img_tran, H, img_tran.size());
		//imshow("img_tran", img_tran);							//显示转换后图像


		Mat Template_rgb = imread("../template.jpg");
		Mat Template,img_tran_gray;
		cvtColor(Template_rgb, Template, CV_BGR2GRAY);
		cvtColor(img_tran, img_tran_gray, CV_BGR2GRAY);
		Mat diff,BW_image;
		absdiff(Template, img_tran_gray, diff);
		//imshow("ss", diff);
		threshold(diff, BW_image, 100, 255, 0);
		//imshow("rr", BW_image);
		Mat ROI = imread("../ROI.jpg");
		Mat ddd;
		cvtColor(ROI, ddd, CV_BGR2GRAY);
		Mat fin;
		bitwise_and(ddd, BW_image, fin);
		imshow("Defect", fin);
		vector<vector<Point> > contours;
		vector<Vec4i> hierarchy;
		findContours(fin, contours, hierarchy, CV_RETR_CCOMP, CV_CHAIN_APPROX_NONE);
		double m00, m10, m01;
		CvMoments mu;
		for (int i = 0; i<contours.size(); i++)
		{
			double dArea = contourArea(contours[i]);
			//Mat contoursImage(fin.rows, fin.cols, CV_8U, Scalar(255));
			//drawContours(contoursImage, contours, i, Scalar(0), -1);
			mu = moments(contours[i], false);
			Point centroid = cv::Point(mu.m10 / mu.m00, mu.m01 / mu.m00);
			CvBox2D box = minAreaRect(contours[i]);
			if (box.size.height / box.size.width<2 && box.size.height / box.size.width>0.5)
			{
				ui.textEdit->insertPlainText("Defect");
				ui.textEdit->insertPlainText(QString::number(i)+":\t");
				ui.textEdit->insertPlainText("Pits\t");
				ui.textEdit->insertPlainText("[" + QString::number(centroid.x) + "," + QString::number(centroid.y) + "]\n");
				char textbuffer[50];
				sprintf(textbuffer, "%d:Pits", i);
				String text(textbuffer);
				putText(img_tran, text, cvPoint(centroid.x + 10, centroid.y), CV_FONT_HERSHEY_COMPLEX, 0.6, Scalar(255, 0, 0));
				drawContours(img_tran, contours, i, cv::Scalar(0, 0, 255), -1);
			}
			else
			{
				ui.textEdit->insertPlainText("Defect");
				ui.textEdit->insertPlainText(QString::number(i) + ":\t");
				ui.textEdit->insertPlainText("Scratches\t");
				ui.textEdit->insertPlainText("[" + QString::number(centroid.x) + "," + QString::number(centroid.y) + "]\n");
				char textbuffer[50];
				sprintf(textbuffer, "%d:Scratches", i);
				String text(textbuffer);
				putText(img_tran, text, cvPoint(centroid.x + 10, centroid.y), CV_FONT_HERSHEY_COMPLEX, 0.6, Scalar(255, 0, 0));
				drawContours(img_tran, contours, i, cv::Scalar(0, 0, 255), -1);
			}
		}
		//imshow("rgb", img_tran);
		image = Mat2QImage(img_tran);
		ui.label->setPixmap(QPixmap::fromImage(image));
		image.save("save.jpg");	
	}
}
void detection::closeCamera()
{
	timer->stop();			// 停止读取数据。  
	capture->release();		//释放内存；  
}
QImage  detection::Mat2QImage(cv::Mat cvImg)
{
	QImage qImg;
	if (cvImg.channels() == 3)                             //3 channels color image
	{

		cv::cvtColor(cvImg, cvImg, CV_BGR2RGB);
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}
	else if (cvImg.channels() == 1)                    //grayscale image
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_Indexed8);
	}
	else
	{
		qImg = QImage((const unsigned char*)(cvImg.data),
			cvImg.cols, cvImg.rows,
			cvImg.cols*cvImg.channels(),
			QImage::Format_RGB888);
	}

	return qImg;

}

void detection::readFrame()
{
	Mat frame, origin_frame;
	QImage image;
	capture->operator >>(origin_frame);// 从摄像头中抓取并返回每一帧 
	cv::resize(origin_frame, frame, Size(600, 452));
	if (!frame.empty())
	{
		image = Mat2QImage(frame);
		ui.label->setPixmap(QPixmap::fromImage(image));
	}
}

