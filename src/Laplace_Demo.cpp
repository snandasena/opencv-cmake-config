#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

int main() {

    cv::Mat src, src_gray, dst;

    int kernel_size = 3;
    int scale = 3;
    int delta = 3;
    int ddepth = CV_16S;

    const char *window_name = "Laplace Demo";
    src = cv::imread("./images/cute-dog.jpg", cv::IMREAD_COLOR);
    if (src.empty()) {
        return -1;
    }

    // reduce noise by blurring with a Gaussian filter ( kernel size = 3)
    cv::GaussianBlur(src, src, cv::Size(3, 3), 0, 0, cv::BORDER_DEFAULT);

    // convert the image to grayscale
    cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);

    cv::Mat abs_dst;
    cv::Laplacian(src_gray, dst, ddepth, kernel_size, scale, delta, cv::BORDER_DEFAULT);

    // converting back to CV_8U
    cv::convertScaleAbs(dst, abs_dst);

    cv::imshow(window_name, abs_dst);
    cv::waitKey(0);

    return 0;
}