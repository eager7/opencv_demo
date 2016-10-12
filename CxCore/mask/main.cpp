#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<iostream>
   
using namespace cv; 
using namespace std;

void Sharpen(const Mat& myImage, Mat &Result)
{

}

int main()
{
	Mat Src;
	Src = imread("../test.jpg");
	namedWindow("test");
	imshow("test", Src);
	waitKey();


	return 0;
}
