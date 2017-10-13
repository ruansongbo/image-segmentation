#include <iostream>  
#include <stack>  
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"        
#include "opencv2/highgui/highgui.hpp"  
#include <vector> 

using namespace std;
using namespace cv;

// 8 ����  
static Point connects[8] = { Point(-1, -1), Point(0, -1), Point(1, -1), Point(1, 0), Point(1, 1), Point(0, 1), Point(-1, 1), Point(-1, 0) };

int main()
{
	// ԭͼ  
	Mat src = imread("../vga.jpg", 0);
	// ���ͼ  
	Mat res = Mat::zeros(src.rows, src.cols, CV_8U);
	// ���ڱ���Ƿ������ĳ��  
	Mat flagMat;
	res.copyTo(flagMat);
	// ��ֵͼ��  
	Mat bin;
	threshold(src, bin, 80, 255, CV_THRESH_BINARY);

	// ��ʼ3�����ӵ�  
	stack<Point> seeds;
	seeds.push(Point(824, 122));
	seeds.push(Point(837, 522));
	seeds.push(Point(191, 124));
	res.at<uchar>(122, 824) = 255;
	res.at<uchar>(522, 837) = 255;
	res.at<uchar>(124, 191) = 255;

	while (!seeds.empty())
	{
		Point seed = seeds.top();
		seeds.pop();

		// ���Ϊ�ѱ������ĵ�  
		flagMat.at<uchar>(seed.y, seed.x) = 1;

		// ����8����  
		for (size_t i = 0; i < 8; i++)
		{
			int tmpx = seed.x + connects[i].x;
			int tmpy = seed.y + connects[i].y;

			if (tmpx < 0 || tmpy < 0 || tmpx >= src.cols || tmpy >= src.rows)
				continue;
			// ǰ������û�б���ǹ��ĵ�  
			if (bin.at<uchar>(tmpy, tmpx) != 0 && flagMat.at<uchar>(tmpy, tmpx) == 0)
			{
				res.at<uchar>(tmpy, tmpx) = 255; // ����  
				flagMat.at<uchar>(tmpy, tmpx) = 1; // ���  
				seeds.push(Point(tmpx, tmpy)); // ����ѹջ  
			}
		}
	}

	imshow("RES", res);
	imwrite("res.jpg", res);
	waitKey(0);
	return 1;
}