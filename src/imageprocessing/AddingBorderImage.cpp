#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

cv::Mat src, dst;
int top, bottom, left, right;
int borderType = cv::BORDER_CONSTANT;
const char *window_name = "Copy border demo";
cv::RNG rng(12345);

int main() {

    src = cv::imread("./images/cute-dog.jpg", cv::IMREAD_COLOR);

    if (src.empty()) {
        return -1;
    }

    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    // initialize args for the filter
    top = (int) (0.05 * src.rows);
    bottom = top;
    left = (int) (0.05 * src.cols);
    right = left;

    while (true) {

        cv::Scalar value(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));

        cv::copyMakeBorder(src, dst, top, bottom, left, right, borderType, value);

        cv::imshow(window_name, dst);

        auto c = (char) cv::waitKey(500);

        if (c == 27) {
            break;
        } else if (c == 'c') {
            borderType = cv::BORDER_CONSTANT;
        } else if (c == 'r') {
            borderType = cv::BORDER_REPLICATE;
        }

    }

    return 0;
}