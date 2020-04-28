#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


using namespace std;
using namespace cv;


int threshold_value = 0;
int threshold_type = 3;
int const max_value = 255;
int const max_type = 4;
int const max_binary_value = 255;
cv::Mat src, src_gray, dst;
const char *window_name = "Threshold Demo";
const char *trackbar_type = "Type: \n 0: Binary \n 1: Binary Inverted \n 2: Truncate \n 3: To Zero \n 4: To Zero Inverted";
const char *trackbar_value = "Value";

static void Threshold_Demo(int, void *) {
    cv::threshold(src_gray, dst, threshold_value, max_binary_value, threshold_type);
    cv::imshow(window_name, dst);
}

int main(int argc, char *argv) {

    src = cv::imread("./images/cute-dog.jpg", cv::IMREAD_COLOR);

    if (src.empty()) {
        return -1;
    }

    // convert the image to gray
    cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);

    // create a window to display results
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    // create a trackerbar to choose type of the Threshold
    cv::createTrackbar(trackbar_type,
                       window_name,
                       &threshold_type,
                       max_type, Threshold_Demo);


    // create a trackerbar to choose Threshold value
    cv::createTrackbar(trackbar_value,
                       window_name,
                       &threshold_value,
                       max_value,
                       Threshold_Demo);

    Threshold_Demo(0, 0);
    cv::waitKey(0);
    return 0;
}