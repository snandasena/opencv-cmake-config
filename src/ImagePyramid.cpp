#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;
const char *window_name = "Pyramids Demo";

int main() {

    cv::Mat src = cv::imread("/home/sajith/github/opencv-cmake-config/images/cute-dog.jpg");

    if (src.empty()) {
        return -1;
    }

    while (true) {
        cv::imshow(window_name, src);
        auto c = (char) cv::waitKey(0);

        if (c == 27) {
            break;
        } else if (c == 'i') {
            cv::pyrUp(src, src, cv::Size(src.cols * 2, src.rows * 2));
        } else if (c == 'o') {
            cv::pyrDown(src, src, cv::Size(src.cols / 2, src.rows / 2));
        }
    }

    return 0;
}