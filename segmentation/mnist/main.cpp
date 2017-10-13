#include "mnist.h"

#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/imgcodecs.hpp"
#include <opencv2/highgui.hpp>
#include <opencv2/ml.hpp>

#include <string>
#include <iostream>

using namespace std;
using namespace cv;
using namespace cv::ml;

string trainImage = "train-labels.idx1-ubyte";
string trainLabel = "train-labels.idx1-ubyte";
string testImage = "mnist_dataset/t10k-images.idx3-ubyte";
string testLabel = "mnist_dataset/t10k-labels.idx1-ubyte";
int main()
{
	Mat trainData;
	Mat labels;
	trainData = read_mnist_image(trainImage);
	labels = read_mnist_label(trainLabel);

	cout << trainData.rows << " " << trainData.cols << endl;
	cout << labels.rows << " " << labels.cols << endl;
	system("pause");
	return 0;
}