
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"        
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <string>

using namespace cv;

int main(int argc, char *argv[])
{
	Mat m_SrcImg;

	m_SrcImg = imread("../out.jpg", -1);

	namedWindow("ԭͼ��", 1);
	imshow("ԭͼ��", m_SrcImg);

	Mat m_ResImg;

	//Canny��Ե���
	Canny(m_SrcImg, m_ResImg, 120, 240,3);

	namedWindow("Canny��Ե���", 1);
	imshow("Canny��Ե���", m_ResImg);

	imwrite("res.jpg", m_ResImg);
	waitKey(0);
	return 0;
}