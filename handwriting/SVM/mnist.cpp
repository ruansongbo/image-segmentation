 #include "mnist.h"
 
 //��ʱ��
 double cost_time;
 clock_t start_time;
 clock_t end_time;
 
 //����item����
 int training_testing_Num = 1000;
 
 int reverseInt(int i) 
 {
     unsigned char c1, c2, c3, c4;
 
     c1 = i & 255;
     c2 = (i >> 8) & 255;
     c3 = (i >> 16) & 255;
     c4 = (i >> 24) & 255;
 
     return ((int)c1 << 24) + ((int)c2 << 16) + ((int)c3 << 8) + c4;
 }
 
 Mat read_mnist_image(const string fileName) {
     int magic_number = 0;
     int number_of_images = 0;
     int n_rows = 0;
     int n_cols = 0;
 
     Mat DataMat;
 
     ifstream file(fileName, ios::binary);
     if (file.is_open())
     {
         cout << "�ɹ���ͼ�� ... \n";
 
         file.read((char*)&magic_number, sizeof(magic_number));
         file.read((char*)&number_of_images, sizeof(number_of_images));
         file.read((char*)&n_rows, sizeof(n_rows));
         file.read((char*)&n_cols, sizeof(n_cols));
         //cout << magic_number << " " << number_of_images << " " << n_rows << " " << n_cols << endl;
 
         magic_number = reverseInt(magic_number);
         number_of_images = reverseInt(number_of_images);
         number_of_images = training_testing_Num;
         n_rows = reverseInt(n_rows);
         n_cols = reverseInt(n_cols);
         cout << "MAGIC NUMBER = " << magic_number
             << " ;NUMBER OF IMAGES = " << number_of_images
             << " ; NUMBER OF ROWS = " << n_rows
             << " ; NUMBER OF COLS = " << n_cols << endl;
 
         //-test-
         //number_of_images = testNum;
         //�����һ�ź����һ��ͼ������ȡ��������
         Mat s = Mat::zeros(n_rows, n_cols, CV_32FC1);
         Mat e = Mat::zeros(n_rows, n_cols, CV_32FC1);
 
         cout << "��ʼ��ȡImage����......\n";
         start_time = clock();
         DataMat = Mat::zeros(number_of_images, n_rows * n_cols, CV_32FC1);
         for (int i = 0; i < number_of_images; i++) 
         {
             for (int j = 0; j < n_rows * n_cols; j++) 
             {
                 unsigned char temp = 0;
                 file.read((char*)&temp, sizeof(temp));
                 //printf("temp:%d\r\n", temp);
                 float pixel_value = float((temp + 0.0) / 255.0);
                 if (pixel_value != 0)
                 {
                     pixel_value = 1.0;
                 }
                 //cout << "pixel_value:" << pixel_value << endl;
                 DataMat.at<float>(i, j) = pixel_value;

                 //ת������Ϊ28*28ͼ��
                 s.at<float>(j / n_cols, j % n_cols) = pixel_value;
                 
                 //cout << "pixel_value:" << pixel_value << endl;

                 //ת���һ��ͼ��Ϊ28*28
                 if (i == number_of_images - 1) 
                 {
                     e.at<float>(j / n_cols, j % n_cols) = pixel_value;
                 }
             }
             //cout << "s:" << endl << s << endl;
             char label[30];
             sprintf_s(label,"label:%d", i);
             //imshow(label, s);
         }
         end_time = clock();
         cost_time = (end_time - start_time) / CLOCKS_PER_SEC;
         cout << "��ȡImage�������......" << cost_time << "s\n";
 
         //imshow("first image", s);
         //imshow("last image", e);
         //waitKey(0);
     }
     file.close();
     return DataMat;
 }
 
 Mat read_mnist_label(const string fileName) {
     int magic_number;
     int number_of_items;
 
     Mat LabelMat;
 
     ifstream file(fileName, ios::binary);
     if (file.is_open())
     {
         cout << "�ɹ���Label�� ... \n";
 
         file.read((char*)&magic_number, sizeof(magic_number));
         file.read((char*)&number_of_items, sizeof(number_of_items));
         magic_number = reverseInt(magic_number);
         number_of_items = reverseInt(number_of_items);
         number_of_items = training_testing_Num;
         cout << "MAGIC NUMBER = " << magic_number << "  ; NUMBER OF ITEMS = " << number_of_items << endl;
 
         //-test-
         //number_of_items = testNum;
         //��¼��һ��label�����һ��label
         unsigned int s = 0, e = 0;
 
         cout << "��ʼ��ȡLabel����......\n";
         start_time = clock();


         LabelMat = Mat::zeros(number_of_items, 1, CV_32SC1);
         for (int i = 0; i < number_of_items; i++) 
         {
             unsigned char temp = 0;
             file.read((char*)&temp, sizeof(temp));
			 //cout << int(temp);

             LabelMat.at<int>(i, 0) = (int)temp;
 
             //��ӡ��һ�������һ��label
             if (i == 0) s = (int)temp;
             else if (i == number_of_items - 1) e = (int)temp;
         }

		 ////����ȡ��ǩ  
		 //int maigcNum = 0;//��ȡħ��  
		 //readLabel.read((char*)&maigcNum, sizeof(maigcNum));
		 //int labelNum;//��ȡ��ǩ����  
		 //readLabel.read((char*)&labelNum, sizeof(labelNum));
		 //labelNum = ReverseInt(labelNum);
		 //int count1 = 0;//����ѭ��  
		 //unsigned char labelTemp;
		 //while (count1<labelNum)
		 //{
			// readLabel.read((char*)&labelTemp, sizeof(labelTemp));
			// Label.push_back(int(labelTemp));//��Ҫǿ��ת��������  
			// //cout << int(labelTemp);  
			// count1++;
		 //}


         end_time = clock();
         cost_time = (end_time - start_time) / CLOCKS_PER_SEC;
         cout << "��ȡLabel�������......" << cost_time << "s\n";
 
         cout << "first label = " << s << endl;
         cout << "last label = " << e << endl;
     }
     file.close();
     return LabelMat;
 }