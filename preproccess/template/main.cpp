#include <iostream>    
#include "opencv2/core/core.hpp"    
#include "opencv2/features2d/features2d.hpp"    
#include "opencv2/highgui/highgui.hpp"   
#include<opencv2/legacy/legacy.hpp>  
#include <iostream>    
#include <vector>    
#include<windows.h>  
using namespace cv;
using namespace std;
int main()
{
	Mat image = imread("../1.jpg");
	/*Mat img;
	cvtColor(img, img, CV_BGR2GRAY);*/
	if (!image.data)
	{
		cout << "error reading images " << endl;
		return -1;
	}
	//std::vector<cv::Point> points;
	//points.push_back(cv::Point(66, 46));
	//points.push_back(cv::Point(55, 397));
	//points.push_back(cv::Point(598, 382));
	//points.push_back(cv::Point(587, 67));
	//std::vector<cv::Point>::const_iterator it = points.begin();
	//while (it != points.end()) {
	//	 ½Çµã´¦»­È¦  
	//	cv::circle(image, *it, 3, cv::Scalar(0, 0, 255),2);
	//	++it;
	//}
	//imshow("result", image);


	Point2f srcTriangle[4];
	Point2f dstTriangle[4];
	srcTriangle[0] = cv::Point(66, 46);
	srcTriangle[1] = cv::Point(587, 67);
	srcTriangle[2] = cv::Point(598, 382);
	srcTriangle[3] = cv::Point(55, 397);
	dstTriangle[0] = cv::Point(55, 46);
	dstTriangle[1] = cv::Point(598, 46);
	dstTriangle[2] = cv::Point(598, 397);
	dstTriangle[3] = cv::Point(55, 397);
	Mat transform = getPerspectiveTransform(srcTriangle, dstTriangle);
	Mat img_tran;
	img_tran = Mat::zeros(image.rows, image.cols, image.type());
	warpPerspective(image, img_tran, transform, img_tran.size());
	imshow("img_tran", img_tran);
	imwrite("img.jpg", img_tran);
	cvWaitKey();
	return 0;

}