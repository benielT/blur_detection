
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/imgproc/types_c.h"
#include "opencv2/highgui/highgui_c.h"
#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "blur_det.hpp"

using namespace std;
using namespace cv;

void printText(Mat src, string text){
	int fontFace = FONT_HERSHEY_PLAIN;
	putText(src,text,Point(src.cols/2, src.rows/10),fontFace, 1.2f,Scalar(200,0,0),2);
}

int main(){
	Mat image=imread("image/sharp2.png");

	double sharpness = blur_dectect(image);
	cvNamedWindow("result",CV_WINDOW_AUTOSIZE);
	string text;
	stringstream ss;
	ss<<"image is ";
	if(sharpness > 850)
		ss<<"blury. ";
	else
		ss<<"not_blury. ";

	ss<<"val "<<sharpness<<endl;
	//ss.ignore();
	getline(ss, text);
	printText(image,text);

	imshow("result",image);
	waitKey(0);

	destroyAllWindows();
	return 0;
}
