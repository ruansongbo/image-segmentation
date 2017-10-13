#include <iostream>    
#include "opencv2/core/core.hpp"    
#include "opencv2/features2d/features2d.hpp"    
#include "opencv2/highgui/highgui.hpp"   
#include<opencv2/legacy/legacy.hpp>  
#include <iostream>    
#include <vector>    
#include<windows.h> 
#pragma warning(disable:4996)
using namespace cv;
using namespace std;
int main()
{
	CvFont font;
	cvInitFont(&font, CV_FONT_HERSHEY_SCRIPT_SIMPLEX, 0.5, 1.0, 0);
	for (int i = 9; i < 11; i++)
	{
		char readbuffer[50];
		sprintf(readbuffer, "../t_%d.jpg", i);
		String readfile(readbuffer);
		Mat img2_rgb = imread(readfile);

		Mat img1_rgb = imread("../template.jpg");

		Mat img_1, img_2;
		cvtColor(img1_rgb, img_1, CV_BGR2GRAY);
		cvtColor(img2_rgb, img_2, CV_BGR2GRAY);
		if (!img_1.data || !img_2.data)
		{
			cout << "error reading images " << endl;
			return -1;
		}
		
		Mat img_tran,img_result;
		absdiff(img_1, img_2, img_tran);
		imshow("ss", img_tran);
		threshold(img_tran, img_result, 100, 255, 0);
		imshow("rr", img_result);
		Mat ROI = imread("../ROI.jpg");
		Mat ddd;
		cvtColor(ROI, ddd, CV_BGR2GRAY);
		//imwrite("../ROI.jpg", ddd);
		Mat fin;
		bitwise_and(ddd, img_result, fin);
		imshow("fin", fin);	
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
				char textbuffer[50];
				sprintf(textbuffer, "%d:Pits", i);
				String text(textbuffer);
				putText(img1_rgb, text, cvPoint(centroid.x+10, centroid.y), CV_FONT_HERSHEY_COMPLEX, 0.6, Scalar(255, 0, 0));
				drawContours(img1_rgb, contours, i, cv::Scalar(0, 0, 255), -1);
			}
			else
			{
				char textbuffer[50];
				sprintf(textbuffer, "%d:Scratches", i);
				String text(textbuffer);
				putText(img1_rgb, text, cvPoint(centroid.x+10, centroid.y), CV_FONT_HERSHEY_COMPLEX, 0.6, Scalar(255, 0, 0));
				drawContours(img1_rgb, contours, i, cv::Scalar(0, 0, 255), -1);
			}
		}
		imshow("rgb", img1_rgb);
		char writebuffer[50];
		sprintf(writebuffer, "../z_%d.jpg", i);
		String writefile(writebuffer);
		imwrite(writefile, img1_rgb);
		cvWaitKey();
	}
	cvWaitKey();
	return 0;
}