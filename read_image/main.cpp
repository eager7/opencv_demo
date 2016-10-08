#include <opencv2/core/core.hpp>  
#include<opencv2/highgui/highgui.hpp>  
   
using namespace cv; 
using namespace std; 

int main()
{
	Mat image = imread("../test.jpg");
	namedWindow("image");
	imshow("image", image);

	waitKey();
	destroyAllWindows();
	return 0;
}
