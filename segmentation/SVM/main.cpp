/*
 svm_type �C
 ָ��SVM�����ͣ������ǿ��ܵ�ȡֵ��
 CvSVM::C_SVC C��֧������������� n�����  (n \geq 2)���������쳣ֵ�ͷ�����C���в���ȫ���ࡣ
 CvSVM::NU_SVC \nu��֧�������������n����Ȼ����ȫ����ķ�����������Ϊ \nu ȡ��C����ֵ�����䡾0��1���У�nuԽ�󣬾��߽߱�Խƽ������
 CvSVM::ONE_CLASS �������������е�ѵ��������ȡ��ͬһ�����Ȼ��SVM������һ���ֽ����Էָ�����������ռ�����ռ������������������ռ�����ռ����
 CvSVM::EPS_SVR \epsilon��֧�������ع����ѵ�����е�������������ϳ����ĳ�ƽ��ľ�����ҪС��p���쳣ֵ�ͷ�����C�����á�
 CvSVM::NU_SVR \nu��֧�������ع���� \nu ������ p��
 
 �ɴ� [LibSVM] ��ȡ����ϸ�ڡ�
 
 kernel_type �C
 SVM���ں����ͣ������ǿ��ܵ�ȡֵ��
 CvSVM::LINEAR �����ںˡ�û���κ���ӳ������ά�ռ䣬�������֣���ع飩��ԭʼ�����ռ��б���ɣ���������ѡ��K(x_i, x_j) = x_i^T x_j.
 CvSVM::POLY ����ʽ�ںˣ� K(x_i, x_j) = (\gamma x_i^T x_j + coef0)^{degree}, \gamma > 0.
 CvSVM::RBF ���ھ���ĺ��������ڴ�����������һ���Ϻõ�ѡ�� K(x_i, x_j) = e^{-\gamma ||x_i - x_j||^2}, \gamma > 0.
 CvSVM::SIGMOID Sigmoid�����ںˣ�K(x_i, x_j) = \tanh(\gamma x_i^T x_j + coef0).
 
 degree �C �ں˺�����POLY���Ĳ���degree��
 
 gamma �C �ں˺�����POLY/ RBF/ SIGMOID���Ĳ���\gamma��
 
 coef0 �C �ں˺�����POLY/ SIGMOID���Ĳ���coef0��
 
 Cvalue �C SVM���ͣ�C_SVC/ EPS_SVR/ NU_SVR���Ĳ���C��
 
 nu �C SVM���ͣ�NU_SVC/ ONE_CLASS/ NU_SVR���Ĳ��� \nu��
 
 p �C SVM���ͣ�EPS_SVR���Ĳ��� \epsilon��
 
 class_weights �C C_SVC�еĿ�ѡȨ�أ�����ָ�����࣬����C�Ժ��� class\_weights_i * C��������ЩȨ��Ӱ�첻ͬ���Ĵ������ͷ��Ȩ��Խ��ĳһ������������ݵĳͷ����Խ��
 
 term_crit �C SVM�ĵ���ѵ�����̵���ֹ���������������Լ�������������⡣������ָ���Ĺ����/��������������
 
 */
 
 
 #include "mnist.h"
 
 #include <opencv2/core.hpp>
 #include <opencv2/imgproc.hpp>
 #include "opencv2/imgcodecs.hpp"
 #include <opencv2/highgui.hpp>
 #include <opencv2/ml.hpp>
 
 #include <string>
 #include <iostream>
#include <fstream>
 
 using namespace std;
 using namespace cv;
 using namespace cv::ml;
 
 string trainImage = "D:/mnist_dataset/train-images.idx3-ubytee";
 string trainLabel = "D:/mnist_dataset/train-labels.idx1-ubyte";
 string testImage = "D:/mnist_dataset/t10k-images.idx3-ubyte";
 string testLabel = "D:/mnist_dataset/t10k-labels.idx1-ubyte";
 //string testImage = "mnist_dataset/train-images.idx3-ubyte";
 //string testLabel = "mnist_dataset/train-labels.idx1-ubyte";
 
 //��ʱ��
 double cost_time_;
 clock_t start_time_;
 clock_t end_time_;

 extern int training_testing_Num;
 int main()
 {
     system("color 5F");
#define TRAINING
#ifdef TRAINING


     
     //--------------------- 1. Set up training data ---------------------------------------
     Mat trainData;
     Mat labels;

	 int magic_number = 0;
	 int number_of_images = 0;
	 int n_rows = 0;
	 int n_cols = 0;

	 Mat DataMat;

	 ifstream file("train-images.idx3-ubyte", ios::binary);

	cout << "�ɹ���ͼ�� ... \n";

	file.read((char*)&magic_number, sizeof(magic_number));
	file.read((char*)&number_of_images, sizeof(number_of_images));
	file.read((char*)&n_rows, sizeof(n_rows));
	file.read((char*)&n_cols, sizeof(n_cols));

     trainData = read_mnist_image("train-images.idx3-ubyte");
	 labels = read_mnist_label("train-labels.idx1-ubyte");
 
     std::cout << trainData.rows << " " << trainData.cols << endl;
     std::cout << labels.rows << " " << labels.cols << endl;
 
     //------------------------ 2. Set up the support vector machines parameters --------------------
     Ptr<SVM> svm = SVM::create();
     svm->setType(SVM::C_SVC);
     svm->setKernel(SVM::RBF);
     svm->setDegree(10.0);
     svm->setGamma(0.01);
     svm->setCoef0(1.0);
     svm->setC(10.0);
     svm->setNu(0.5);
     svm->setP(0.1);
     svm->setTermCriteria(TermCriteria(CV_TERMCRIT_EPS, 1000, FLT_EPSILON));
 
     //------------------------ 3. Train the svm ----------------------------------------------------
     cout << "Starting training process" << endl;
     start_time_ = clock();
     svm->train(trainData, ROW_SAMPLE, labels);
     end_time_ = clock();
     cost_time_ = (end_time_ - start_time_) / CLOCKS_PER_SEC;
     cout << "Finished training process...cost " << cost_time_ << " seconds..." << endl;
     
     //------------------------ 4. save the svm ----------------------------------------------------
     svm->save("mnist_dataset/mnist_svm.xml");
     cout << "save as /mnist_dataset/mnist_svm.xml" << endl;
#endif 
     
     //------------------------ 5. load the svm ----------------------------------------------------
     cout << "��ʼ����SVM�ļ�...\n";
     Ptr<SVM> svm1 = StatModel::load<SVM>("mnist_dataset/mnist_svm.xml");
     cout << "�ɹ�����SVM�ļ�...\n";
 
 
     //------------------------ 6. read the test dataset -------------------------------------------
#define TESTING
#ifdef TESTING
     cout << "��ʼ�����������...\n";
     Mat testData;
     Mat tLabel;
     testData = read_mnist_image(testImage);
     tLabel = read_mnist_label(testLabel);
     cout << "�ɹ�����������ݣ�����\n";
 
     
     float count = 0;
     int error_count = 0;
     for (int i = 0; i < testData.rows; i++) 
     {
         Mat sample = testData.row(i);
         //cout << "sizeof(sample):" << sizeof(sample) << endl;
         //cout << "testData.row:" << testData.row(i) << endl;
         //imshow("sample", sample);
         float res = svm1->predict(sample);
         //cout << "res:" << res << endl;
         float test_result = std::abs(res - tLabel.at<unsigned int>(i, 0)) <= FLT_EPSILON ? 1.f : 0.f;
         if (test_result == 0)
         {
             error_count++;
             //cout << "ʶ������������:" << res << endl;
             
//#define USE_ERROR_IMAGE_SHOW        
#ifdef USE_ERROR_IMAGE_SHOW
             Mat error_image = Mat::zeros(28, 28 * 15, CV_32FC1);
             for (int row = 0; row < 28; row++)
             {
                 for (int col = 0; col < 28; col++)
                 {
                     error_image.at<float>(row, col) = sample.at<float>(0, row * 28 + col);
                 }
             }
             char error_image_label[30];
             sprintf_s(error_image_label,"%d,error_value:%d", error_count,(int)res);
             imshow(error_image_label, error_image);
#endif

         }
         count += test_result;
     }
     cout << "���Լ�����ȷ��ʶ������ָ��� count = " << count << endl;
     cout << "���Լ�ʶ�����ȷ��Ϊ..." << (count + 0.0) / training_testing_Num * 100.0 << "%....\n";
     //cout << "������Ϊ..." << (training_testing_Num - count + 0.0) / training_testing_Num * 100.0 << "%....\n";
#endif   
     //system("pause");
     
     cout << endl;
     char filename[30];
     for (int i = 0; i < 10; i++)
     {
         sprintf_s(filename, "%d.png", i);
         Mat gray_origin_image;
         gray_origin_image = imread(filename, 0);

         Mat resize_image;
         resize(gray_origin_image, resize_image, Size(28, 28));
         //imshow("resize_image", resize_image);

         Mat SVM_format_image = Mat::zeros(1, 28 * 28, CV_32FC1);
         Mat view_svm_format = Mat::zeros(28, 28, CV_32FC1);
         for (int i = 0; i < 28; i++)
         {
             //uchar* data = gray_origin_image.ptr<uchar>(i);
             for (int j = 0; j < 28; j++)
             {
                 uchar data = resize_image.at<uchar>(i, j);
                 //printf("data:%d\r\n", data);
                 float pixel_value = (float)data / 255.0;
                 if (pixel_value != 0)
                 {
                     pixel_value = 1.0;
                 }
                 SVM_format_image.at<float>(0, i * 28 + j) = pixel_value;
                 view_svm_format.at<float>(i, j) = pixel_value;
             }
         }
         float result = svm1->predict(SVM_format_image);
         //cout << "sizeof(SVM_format_image):" << sizeof(SVM_format_image) << endl;
         //imshow("view_svm_format", view_svm_format);
         //cout << "view_svm_format:" << endl << view_svm_format << endl;
         
         if (i == (int)result)
         {
             printf("��д����%d�ķ�������%.0f,������ȷ\r\n", i, result);
         }
         else
         {
             printf("��д����%d�ķ�������%.0f,�������\r\n", i, result);
         } 
     }
     system("pause");
     return 0;
 }