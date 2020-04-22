#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main() {

    cv::Mat src, dst, kernel;
    cv::Point anchor;
    double delta;
    int depth, kernel_size;

    const char *window_name = "Filter 2D Demo";

    src = cv::imread("./images/cute-dog.jpg", cv::IMREAD_COLOR);

    if (src.empty()) {
        return -1;
    }

    anchor = Point(-1, -1);
    delta = 0;
    depth = -1;

    int ind = 0;
    while (true) {

        // update kernel size for a normalized box filter
        kernel_size = 3 + 2 * (ind % 5);

        kernel = cv::Mat::ones(kernel_size, kernel_size, CV_32F) / (float) (kernel_size * kernel_size);

        // apply filter
        cv::filter2D(src, dst, depth, kernel, anchor, delta, BORDER_DEFAULT);
        cv::imshow(window_name, dst);

        auto c = (char) cv::waitKey(500);
        if (c == 27) {
            break;
        }
        ind++;
    }

    return 0;
}