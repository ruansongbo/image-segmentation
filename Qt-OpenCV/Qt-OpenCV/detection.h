#ifndef DETECTION_H
#define DETECTION_H

#include <QtWidgets/QMainWindow>
#include "ui_detection.h"
#include <qtimer.h>
#include <qstring.h>

#include<opencv2/opencv.hpp>  
#include "opencv2/features2d/features2d.hpp"  
#include "opencv2/core/core.hpp"      
#include "opencv2/highgui/highgui.hpp"   
#include<opencv2/legacy/legacy.hpp>  

#include <iostream>    
#include <vector>    
#include<windows.h> 

using namespace cv;


class detection : public QMainWindow
{
	Q_OBJECT

public:
	detection(QWidget *parent = 0);
	~detection();

private:
	Ui::detectionClass ui;
	QTimer       *timer;
	VideoCapture *capture;// 视频获取结构， 用来作为视频获取函数的一个参数
	QButtonGroup *typeGroup;
	int checkedID;

private slots:
	void openCamera();      // 打开摄像头  
	void readFrame();       // 读取当前帧信息  
	void closeCamera();     // 关闭摄像头。  
	void takingPictures();  // 拍照 
	QImage Mat2QImage(cv::Mat cvImg);
};

#endif // DETECTION_H
