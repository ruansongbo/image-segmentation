
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

	namedWindow("Ô­Í¼Ïñ", 1);
	imshow("Ô­Í¼Ïñ", m_SrcImg);

	Mat m_ResImg;

	//Canny±ßÔµ¼ì²â
	Canny(m_SrcImg, m_ResImg, 120, 240,3);

	namedWindow("Canny±ßÔµ¼ì²â", 1);
	imshow("Canny±ßÔµ¼ì²â", m_ResImg);

	imwrite("res.jpg", m_ResImg);
	waitKey(0);
	return 0;
}