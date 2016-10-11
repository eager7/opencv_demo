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

Mat& ReduceImageIterator(Mat &I, const uchar *const table)
{
	CV_Assert(I.depth() != sizeof(uchar));

	switch (I.channels()){
		case 1:{
			MatIterator_<uchar> it, end;
			for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end ; ++it) {
				*it = table[*it];
			}
		}
			break;
		case 3:{
			MatIterator_<Vec3b> it, end;
			for (it = I.begin<Vec3b>(), end = I.end<Vec3b>(); it != end ; ++it) {
				(*it)[0] = table[(*it)[0]];
				(*it)[1] = table[(*it)[1]];
				(*it)[2] = table[(*it)[2]];
			}
		}
			break;
		default:
			break;
	}
	return I;
}

Mat& ReduceImageCore(Mat &I, const uchar *const table)
{
	Mat &J = I;
	Mat lookUpTable(1, 256, CV_8U);
	uchar *p = lookUpTable.data;
	for (int i = 0; i < 256; ++i) {
		p[i] = table[i];
	}

	LUT(I, lookUpTable, J);
	return J;
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

	time_start();
	Mat &RI = ReduceImageIterator(Src, table);
	time_done();
	imshow("test", RI);
	waitKey();

	time_start();
	Mat &RC = ReduceImageCore(Src, table);
	time_done();
	imshow("test", RC);
	waitKey();

	return 0;
}
