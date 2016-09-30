#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include <vector>
#include <unistd.h>

using namespace std;
using namespace cv;

int main() {
    cout << "Hello, World!" << endl;

    string window_name = "camera";
    VideoCapture camera = VideoCapture(0);
    Mat src;

    namedWindow(window_name, CV_WINDOW_KEEPRATIO);
    for (int i = 0; i < 100; ++i) {
        camera >> src;
        if (!src.empty())
            imshow(window_name, src);
        waitKey(10);
    }
    destroyAllWindows();
    cout << "test1" << endl;

    namedWindow(window_name, CV_WINDOW_FULLSCREEN);
    for (int i = 0; i < 100; ++i) {
        camera >> src;
        if (!src.empty())
            imshow(window_name, src);
        waitKey(10);
    }
    destroyAllWindows();
    cout << "test2" << endl;

    return 0;
}