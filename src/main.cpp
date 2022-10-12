#include <opencv2/opencv.hpp>
#include <iostream>

#include "output.h"
#include "input.h"

using namespace cv;
using namespace std;

int main(){

	output(input());
  
	const std::string gst_pipline_3 = "appsrc ! videoconvert! videoscale ! video/x-raw, width=1280, height=800, framerate=30/1 ! fbdevsink";
    int capture_width = 1280;
    int capture_height = 800;
    int framerate = 30;
	
	cv::VideoWriter video_write3(gst_pipline_3, NULL , framerate, cv::Size(capture_width,capture_height), true);
    if (!video_write3.isOpened()) {
      std::cout<<"Failed to open VideoWrite";
      return -1;
    }
	
	Mat frame;     
    VideoCapture cap;
    cap.open(0, cv::CAP_V4L2);
    cap.set(cv::CAP_PROP_FPS, 30);
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 800);
	
	while(true){
		cap.read(frame);  
        //imshow("Live", frame);
        video_write3.write(frame);
        if (waitKey(5) >= 0)
            break;
    }        
	
	return 0;
}
