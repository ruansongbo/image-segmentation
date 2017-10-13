/*#include <iostream>    
#include "opencv2/core/core.hpp"    
#include "opencv2/features2d/features2d.hpp"    
#include "opencv2/highgui/highgui.hpp"   
#include<opencv2/legacy/legacy.hpp>  
#include <vector>    
#include<windows.h>  
using namespace cv;
using namespace std;
int main()
{
	Mat img = imread("../ex.PNG");
	ORB orb(2100, 1.9f, 8, 128, 0, 2, ORB::FAST_SCORE, 31);
	vector<KeyPoint> keyPoints;
	Mat descriptors;
	double start = GetTickCount();
	orb(img, Mat(), keyPoints, descriptors);
	double end = GetTickCount();
	cout << end - start << endl;
	Mat output_img;			//输出图像矩阵
	drawKeypoints(img,		//输入图像
		keyPoints,			//特征点矢量
		output_img,			//输出图像
		Scalar::all(-1),	//绘制特征点的颜色，为随机
		//以特征点为中心画圆，圆的半径表示特征点的大小，直线表示特征点的方向
		DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	namedWindow("ORB");
	imshow("ORB", output_img);
	cout << descriptors.rows << endl;
	imwrite("ex_orb.PNG", output_img);
	waitKey(0);
	return 0;
}*/

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
#define Auto
#ifdef Auto
	for (int i = 1; i < 11; i++)
	{
		char readbuffer[50];
		sprintf(readbuffer, "../%d.jpg", i);
		String readfile(readbuffer);
		Mat img2_rgb = imread(readfile);
#else
		Mat img2_rgb = imread("../a.jpg");
#endif
		Mat img1_rgb = imread("../template.jpg");
		
		Mat img_1, img_2;
		cvtColor(img1_rgb, img_1, CV_BGR2GRAY);
		cvtColor(img2_rgb, img_2, CV_BGR2GRAY);
		if (!img_1.data || !img_2.data)
		{
			cout << "error reading images " << endl;
			return -1;
		}

		ORB orb(100, 1.05f, 4, 32, 0, 2, ORB::FAST_SCORE, 80);
		vector<KeyPoint> keyPoints_1, keyPoints_2;
		Mat descriptors_1, descriptors_2;
		double start = GetTickCount();
		orb(img_1, Mat(), keyPoints_1, descriptors_1);
		orb(img_2, Mat(), keyPoints_2, descriptors_2);

		BruteForceMatcher<HammingLUT> matcher;
		vector<DMatch> matches;
		matcher.match(descriptors_1, descriptors_2, matches);

		double max_dist = 0; double min_dist = 100;
		//-- Quick calculation of max and min distances between keypoints    
		for (int i = 0; i < descriptors_1.rows; i++)
		{
			double dist = matches[i].distance;
			if (dist < min_dist) min_dist = dist;
			if (dist > max_dist) max_dist = dist;
		}
		cout << i << ": " << endl;
		printf("-- Max dist : %f \n", max_dist);
		printf("-- Min dist : %f \n", min_dist);
		//-- Draw only "good" matches (i.e. whose distance is less than 0.6*max_dist )    
		//-- PS.- radiusMatch can also be used here.    
		std::vector< DMatch > good_matches;
		for (int i = 0; i < descriptors_1.rows; i++)
		{
			if (matches[i].distance < max_dist)
			{
				good_matches.push_back(matches[i]);
			}
		}
		double end = GetTickCount();
		cout << end - start << endl;
		cout << good_matches.size() << endl;
		Mat img_matches;
		drawMatches(img_1, keyPoints_1, img_2, keyPoints_2,
			good_matches, img_matches, Scalar::all(-1), Scalar::all(-1),
			vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
		imshow("Match", img_matches);

		/*Point2f srcTriangle[3];
		Point2f dstTriangle[3];
		srcTriangle[0] = keyPoints_2[good_matches[0].trainIdx].pt;
		srcTriangle[1] = keyPoints_2[good_matches[1].trainIdx].pt;
		srcTriangle[2] = keyPoints_2[good_matches[2].trainIdx].pt;
		dstTriangle[0] = keyPoints_1[good_matches[0].queryIdx].pt;
		dstTriangle[1] = keyPoints_1[good_matches[1].queryIdx].pt;
		dstTriangle[2] = keyPoints_1[good_matches[2].queryIdx].pt;
		Mat img_tran;
		img_tran = Mat::zeros(img_2.rows, img_2.cols, img_2.type());
		Mat warpMat(2, 3, CV_32FC1);
		warpMat = getAffineTransform(srcTriangle, dstTriangle);
		uchar val = warpMat.data[0];
		cout << val << endl;
		warpAffine(img_2, img_tran, warpMat, img_tran.size());
		imshow("img_tran", img_tran);*/
		//-- Localize the object from img_1 in img_2  
		std::vector<Point2f> obj;
		std::vector<Point2f> scene;

		for (size_t i = 0; i < good_matches.size(); i++)
		{
			//-- Get the keypoints from the good matches  
			obj.push_back(keyPoints_1[good_matches[i].queryIdx].pt);
			scene.push_back(keyPoints_2[good_matches[i].trainIdx].pt);
		}
		Mat H = findHomography(scene, obj, RANSAC);
		Mat img_tran;
		img_tran = Mat::zeros(img_1.rows, img_1.cols, img_1.type());
		warpPerspective(img_2, img_tran, H, img_tran.size());
		imshow("img_tran", img_tran);
		//-- Get the corners from the image_1 ( the object to be "detected" )  
		//std::vector<Point2f> obj_corners(4);
		//obj_corners[0] = Point(0, 0); obj_corners[1] = Point(img_1.cols, 0);
		//obj_corners[2] = Point(img_1.cols, img_1.rows); obj_corners[3] = Point(0, img_1.rows);
		//std::vector<Point2f> scene_corners(4);
		//perspectiveTransform(obj_corners, scene_corners, H);
		////-- Draw lines between the corners (the mapped object in the scene - image_2 )  
		//Point2f offset((float)img_1.cols, 0);
		//line(img_matches, scene_corners[0] + offset, scene_corners[1] + offset, Scalar(0, 255, 0), 4);
		//line(img_matches, scene_corners[1] + offset, scene_corners[2] + offset, Scalar(0, 255, 0), 4);
		//line(img_matches, scene_corners[2] + offset, scene_corners[3] + offset, Scalar(0, 255, 0), 4);
		//line(img_matches, scene_corners[3] + offset, scene_corners[0] + offset, Scalar(0, 255, 0), 4);

		////-- Show detected matches  
		//imshow("Good Matches & Object detection", img_matches);
#ifdef Auto
		char writebuffer[50];
		sprintf(writebuffer, "../t_%d.jpg", i);
		String writefile(writebuffer);
		imwrite(writefile, img_tran);
		cvWaitKey();
	}
#else
		imwrite("../save.jpg", img_tran);
#endif
	cvWaitKey();
	return 0;
}