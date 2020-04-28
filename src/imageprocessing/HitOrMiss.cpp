#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {
    cv::Mat input_image = cv::Mat_<uchar>(8, 8) << (
                    0, 0, 0, 0, 0, 0, 0, 0,
                    0, 255, 255, 255, 0, 0, 0, 255,
                    0, 255, 255, 255, 0, 0, 0, 0,
                    0, 255, 255, 255, 0, 255, 0, 0,
                    0, 0, 255, 0, 0, 0, 0, 0,
                    0, 0, 255, 0, 0, 255, 255, 0,
                    0, 255, 0, 255, 0, 0, 255, 0,
                    0, 255, 255, 255, 0, 0, 0, 0);

    cv::Mat kernel = cv::Mat_<int>(3, 3) << (
                    0, 1, 0,
                    1, -1, 1,
                    0, 1, 0);

    cv::Mat output_image;
    cv::morphologyEx(input_image, output_image, MORPH_HITMISS, kernel);

    const int rate = 50;
    kernel = (kernel + 1) * 127;
    kernel.convertTo(kernel, CV_8U);

    cv::resize(kernel, kernel, Size(), rate, rate, INTER_NEAREST);
    cv::imshow("kernel", kernel);
    cv::moveWindow("kernel", 0, 0);

    cv::resize(input_image, input_image, Size(), rate, rate, INTER_NEAREST);
    cv::imshow("Original", input_image);
    cv::moveWindow("Original", 0, 200);

    cv::resize(output_image, output_image, Size(), rate, rate, INTER_NEAREST);
    cv::imshow("Hit or Miss", output_image);
    cv::moveWindow("Hit or Miss", 500, 200);

    cv::waitKey(0);
    return 0;
}