#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

#include <iostream>

using namespace std;
using namespace cv;

void show_wait_destroy(const char *winname, const cv::Mat &img);

int main() {
    Mat src = cv::imread("./images/src.png", cv::IMREAD_COLOR);

//    show source image
//    cv::imshow("src", src);

    std::cout << src.size << std::endl;

    cv::Mat gray;

    if (src.channels() == 3) {
        cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);
    } else {
        gray = src;
    }

//    Show gray image
//    show_wait_destroy("gray", gray);

    cv::Mat bw;

//    Apply adaptive threshold at the biwise_not of gray. notice the ~ symbol
    cv::adaptiveThreshold(~gray, bw, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 15, -2);

//    show binary image
//    show_wait_destroy("binary", bw);

//    create  the image that will use to extract the horizontal and vertical lines
    cv::Mat horizontal = bw.clone();
    cv::Mat vertical = bw.clone();

//    Specify size on horizontal axis
    int horizontal_size = horizontal.cols / 30;

//    Create structure element for extracting horizontal lines though morphology operations
    cv::Mat horizontalStructure = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(horizontal_size, 1));


//    Apply morphology operations
    cv::erode(horizontal, horizontal, horizontalStructure, cv::Point(-1, -1));
    cv::dilate(horizontal, horizontal, horizontalStructure, cv::Point(-1, -1));


//    Show extracted horizontal lines
//    show_wait_destroy("horizontal", horizontal);

//    Specify size on vertical axis

    int vertical_size = vertical.rows / 30;

//    Create structure element for extracting vertical lines through morphology operations
    cv::Mat verticalStructure = cv::getStructuringElement(MORPH_RECT, cv::Size(1, vertical_size));

//    Apply morphology operations
    cv::erode(vertical, vertical, verticalStructure, cv::Point(-1, -1));
    cv::dilate(vertical, vertical, verticalStructure, cv::Point(-1, -1));

//    show extracted vertical lines
//    show_wait_destroy("vertical", vertical);

//    inverse vertical image
    cv::bitwise_not(vertical, vertical);
//    show_wait_destroy("vertical_bit", vertical);

//    Extract edges and smooth image
//    Step 01: extract edges
    cv::Mat edges;
    cv::adaptiveThreshold(vertical, edges, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 3, -2);
//    show_wait_destroy("edges", edges);

//    Step 02: dilate edges
    cv::Mat kernel = Mat::ones(2, 2, CV_8UC1);
    cv::dilate(edges, edges, kernel);
//    show_wait_destroy("dilate", edges);

//    Step 03: Copy  src to smooth
    cv::Mat smooth;
    vertical.copyTo(smooth);

//    Step 04: blur smooth image
    cv::blur(smooth, smooth, cv::Point(2, 2));

//    Step 05: Copy smooth to edges
    smooth.copyTo(vertical, edges);

//    show final results
    show_wait_destroy("smooth final", vertical);

    return 0;

}


void show_wait_destroy(const char *winname, const cv::Mat &img) {
    cv::imshow(winname, img);
    cv::moveWindow(winname, 100, 0);
    cv::waitKey(0);
}