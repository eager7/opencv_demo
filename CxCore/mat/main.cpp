#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<iostream>
   
using namespace cv; 
using namespace std; 

int main()
{
	Mat M(2, 2, CV_8UC3, Scalar(0,0,255));

	cout << M << endl;
	cout << "--------------------------" << endl;

	int sz[3] = {2,2,2};
	Mat L(3, sz, CV_8UC3, Scalar::all(0));

//	cout << L << endl;
//	cout << "--------------------------" << endl;

	return 0;

}
