#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include<opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

int main() {
    cout << "Hello, World!" << endl;
    VideoCapture cap;
    string video_path ;
    cout << "please input path of video" << endl;
    cin >> video_path;

    if(video_path == "video0"){
        cap = VideoCapture(0);//camera
    } else{
        cap = VideoCapture(video_path);
    }

    if(!cap.isOpened()){
        cout << "can't open video" << endl;
        exit(1);
    }

    Mat video_mat;
    string window_name = "camera";
    namedWindow(window_name, CV_WINDOW_KEEPRATIO);

    while (1){
        cap >> video_mat;
        if (!video_mat.empty())
            imshow(window_name, video_mat);
        if(waitKey(5) == 'q') break;
    }
    destroyAllWindows();

    return 0;
}