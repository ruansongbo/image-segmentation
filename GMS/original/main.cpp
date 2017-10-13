#include <opencv2/opencv.hpp>  
#include "opencv2/features2d/features2d.hpp"  
#include "opencv2/core/core.hpp"      
#include "opencv2/highgui/highgui.hpp"   
#include <opencv2/legacy/legacy.hpp>  
#include <time.h> 

using namespace cv;

int main()
{
	Mat img1_rgb = imread("../data/7.BMP");
	Mat img2_rgb = imread("../data/8.BMP");
	resize(img1_rgb, img1_rgb, Size(640, 480));
	resize(img2_rgb, img2_rgb, Size(640, 480));
	Mat img_1, img_2;
	cvtColor(img1_rgb, img_1, CV_BGR2GRAY);
	cvtColor(img2_rgb, img_2, CV_BGR2GRAY);
	ORB orb(100);// , 1.05f, 4, 32, 0, 2, ORB::FAST_SCORE, 80);//初始化ORB
	vector<KeyPoint> keyPoints_1, keyPoints_2;
	Mat descriptors_1, descriptors_2;
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
		if (matches[i].distance < 1*max_dist)					//选定匹配点
		{
			good_matches.push_back(matches[i]);
		}
	}
	Mat img_matches;
	drawMatches(img_1, keyPoints_1, img_2, keyPoints_2,
		good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
		vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("Match", img_matches);							//显示匹配图
	imwrite("Match.jpg", img_matches);
	std::vector<Point2f> obj;
	std::vector<Point2f> scene;
	for (size_t i = 0; i < good_matches.size(); i++)
	{
		obj.push_back(keyPoints_1[good_matches[i].queryIdx].pt);
		scene.push_back(keyPoints_2[good_matches[i].trainIdx].pt);
	}
	//用clock()来计时  毫秒    
	clock_t  clockBegin, clockEnd;
	clockBegin = clock();
	Mat H = findHomography(scene, obj, RANSAC);				//影射矩阵
	clockEnd = clock();
	printf("%d\n", clockEnd - clockBegin);
	Mat img_tran;
	img_tran = Mat::zeros(img2_rgb.rows, img2_rgb.cols, img2_rgb.type());
	warpPerspective(img2_rgb, img_tran, H, img_tran.size());
	imshow("img_tran", img_tran);							//显示转换后图像
	imwrite("img_tran.jpg", img_tran);
	Mat Template_rgb = imread("../data/7.BMP");
	resize(Template_rgb, Template_rgb, Size(640, 480));
	Mat Template, img_tran_gray;
	cvtColor(Template_rgb, Template, CV_BGR2GRAY);
	cvtColor(img_tran, img_tran_gray, CV_BGR2GRAY);
	Mat diff, BW_image;

	//absdiff(Template, img_tran_gray, diff);
	//imshow("ss", diff);
	//imwrite("original.jpg", diff);
	//float sum=0.;
	//uchar max=0, min=0;
	//for (int i = 0; i < diff.rows; i++)
	//{
	//	for (int j = 0; j < diff.cols; j++)
	//	{
	//		sum += diff.at<uchar>(i, j);
	//		if (diff.at<uchar>(i, j)>max)
	//			max = diff.at<uchar>(i, j);
	//		if (diff.at<uchar>(i, j) < min)
	//			min = diff.at<uchar>(i, j);
	//	}
	//}
	printf("pixel:%f", mean);
	//printf("max:%d", max);
	//printf("min:%d", min);
	waitKey(0);
	return 0;
}