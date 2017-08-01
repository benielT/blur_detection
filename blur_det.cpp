#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

double blur_dectect(Mat img){
	Mat gray, dst, abs_dst;
	Scalar mean,stddev;
	GaussianBlur( img,img, Size(3,3), 0, 0, BORDER_DEFAULT );

	cvtColor( img, gray, CV_BGR2GRAY );

	Laplacian(gray,dst,CV_16S,3,1,0,BORDER_DEFAULT);

	convertScaleAbs(dst,abs_dst);

	meanStdDev(abs_dst, mean, stddev, Mat());
	double variance = stddev.val[0] * stddev.val[0];

	return variance;
}
