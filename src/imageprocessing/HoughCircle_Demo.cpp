#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;

int main() {

    cv::Mat src = cv::imread("./images/smarties.png", cv::IMREAD_COLOR);

    if (src.empty()) return -1;

    cv::Mat gray;
    cv::cvtColor(src, gray, cv::COLOR_BGR2GRAY);

    cv::medianBlur(gray, gray, 5);

    vector<Vec3f> circles;
    cv::HoughCircles(gray, circles, HOUGH_GRADIENT, 1, gray.rows / 16, 100, 30, 1, 30);

    for (auto &circle : circles) {
        Vec3i c = circle;
        cv::Point center = cv::Point(c[0], c[1]);

        // circle center
        cv::circle(src, center, 1, cv::Scalar(0, 100, 100), 3, LINE_AA);

        // circle outline
        int radius = c[2];
        cv::circle(src, center, radius, cv::Scalar(255, 0, 255), 3, LINE_AA);
    }

    cv::imshow("Detected circles", src);
    cv::waitKey(0);
    return 0;
}