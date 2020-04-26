#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
using namespace std;

int main() {

    cv::Mat dst, cdst, cdstp;

    cv::Mat src = cv::imread("./images/sudoku.png", cv::IMREAD_COLOR);
    if (src.empty()) {
        return -1;
    }

    // edge detection
    cv::Canny(src, dst, 50, 200, 3);

    // copy edges to the images that will display the results in BGR
    cv::cvtColor(dst, cdst, cv::COLOR_GRAY2BGR);
    cdstp = cdst.clone();

    // standard hough line transform
    vector<Vec2f> lines;
    cv::HoughLines(dst, lines, 1, CV_PI / 180, 150, 0, 0);

    for (auto &i : lines) {
        float rho = i[0], theta = i[1];
        cv::Point pt1, pt2;
        double a = std::cos(theta), b = std::sin(theta);
        double x0 = a * rho, y0 = b * rho;
        pt1.x = cvRound(x0 + 1000 * (-b));
        pt1.y = cvRound(y0 + 1000 * (a));
        pt2.x = cvRound(x0 - 1000 * (-b));
        pt2.y = cvRound(y0 - 1000 * (a));

        cv::line(cdst, pt1, pt2, cv::Scalar(0, 255), 3, LINE_AA);
    }

    vector<Vec4i> linep;
    cv::HoughLinesP(dst, linep, 1, CV_PI / 180, 50, 50, 10);

    // draw lines
    for (auto l : linep) {
        cv::line(cdstp, cv::Point(l[0], l[1]), cv::Point(l[2], l[3]), cv::Scalar(0, 0, 255), 3, LINE_AA);
    }

    // show results
    cv::imshow("Source", src);
    cv::imshow("Detected lines - Standard Hough Line Transform", cdst);
    cv::imshow("Detected lines - Probabilistic Line Transform", cdstp);

    cv::waitKey(0);
    return 0;
}
