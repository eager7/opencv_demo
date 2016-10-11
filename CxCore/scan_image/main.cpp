#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
#include<iostream>
   
using namespace cv; 
using namespace std;

uchar table[256];
void make_table(int iDevide)
{
	for (int i = 0; i < 256; ++i) {
		table[i] = (uchar)(iDevide * (i / iDevide));
	}
}

double t;
void time_start()
{
	t = (double)getTickCount();
	//cout << "start:" << t << endl;
}

void time_done()
{
	t = ((double)getTickCount() - t) / getTickFrequency();
	cout << "time count:" << t << endl;
}

Mat& ReduceImage(Mat &I, const uchar *const table)
{
	CV_Assert(I.depth() != sizeof(uchar));
	int nRows = I.rows * I.channels();
	int nCols = I.cols;

	if (I.isContinuous()){	//判断图片是否连续存放，如果是连续存放则可以把所有的像素连接起来，形成一个长行
		nCols *= nRows;
		nRows = 1;
	}

	uchar *p;
	for (int i = 0; i < nRows; ++i) {
		p = I.ptr<uchar>(i);
		for (int j = 0; j < nCols; ++j) {
			p[j] = table[p[j]];
		}
	}
	return I;
}

int main()
{
	Mat Src;
	Src = imread("../test.jpg");
	namedWindow("test");
	imshow("test", Src);
	waitKey();

	make_table(50);
	time_start();
	Mat &R = ReduceImage(Src, table);
	time_done();
	imshow("test", R);
	waitKey();

	return 0;

}
