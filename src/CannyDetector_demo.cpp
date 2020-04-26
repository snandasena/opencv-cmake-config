#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

cv::Mat src, src_gray;
cv::Mat dst, detected_edges;
int lowThreshold = 0;
const int max_lowThreshold = 100;
const int ratio = 3;
const int kernal_size = 3;
const char *window_name = "Edge Map";

static void CannyThreshold(int, void *) {
    cv::blur(src_gray, detected_edges, cv::Size(3, 3));

    cv::Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratio, kernal_size);

    dst = cv::Scalar::all(0);

    src.copyTo(dst, detected_edges);

    cv::imshow(window_name, dst);
}

int main() {

    src = cv::imread("./images/cute-dog.jpg", cv::IMREAD_COLOR);

    if (src.empty()) {
        return -1;
    }

    dst.create(src.size(), src.type());

    cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    cv::createTrackbar("Min Threshold", window_name, &lowThreshold, max_lowThreshold, CannyThreshold);

    CannyThreshold(0, 0);
    cv::waitKey(0);

    return 0;

}