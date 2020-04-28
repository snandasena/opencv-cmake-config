#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;

void update_map(int &ind, cv::Mat &map_x, cv::Mat &map_y);

int main() {

    cv::Mat src = cv::imread("./images/cute-dog.jpg", cv::IMREAD_COLOR);

    if (src.empty()) {
        return -1;
    }

    cv::Mat dst(src.size(), src.type());
    cv::Mat map_x(src.size(), CV_32FC1);
    cv::Mat map_y(src.size(), CV_32FC1);

    const char *window_name = "Remap Demo";
    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    int ind = 0;
    while (true) {
        update_map(ind, map_x, map_y);
        cv::remap(src, dst, map_x, map_y, INTER_LINEAR, BORDER_CONSTANT, cv::Scalar(0, 0, 0));
        cv::imshow(window_name, dst);

        auto c = (char) cv::waitKey(1000);
        if (c == 27) {
            break;
        }
    }
    return 0;
}


void update_map(int &ind, cv::Mat &map_x, cv::Mat &map_y) {
    for (int i = 0; i < map_x.rows; i++) {
        for (int j = 0; j < map_x.cols; j++) {
            switch (ind) {
                case 0:
                    if (j > map_x.cols * 0.25 && j < map_x.cols * 0.75 && i > map_x.rows * 0.25 &&
                        i < map_x.rows * 0.75) {
                        map_x.at<float>(i, j) = 2 * (j - map_x.cols * 0.25f) + 0.5f;
                        map_y.at<float>(i, j) = 2 * (j - map_x.cols * 0.25f) + 0.5f;
                    } else {
                        map_x.at<float>(i, j) = 0;
                        map_y.at<float>(i, j) = 0;
                    }
                    break;
                case 1:
                    map_x.at<float>(i, j) = (float) j;
                    map_y.at<float>(i, j) = 0;
                    break;

                case 2:
                    map_x.at<float>(i, j) = (float) (map_x.cols - j);
                    map_y.at<float>(i, j) = (float) i;
                    break;

                case 3:
                    map_x.at<float>(i, j) = (float) (map_x.cols - j);
                    map_y.at<float>(i, j) = (float) (map_x.rows - i);
                    break;

                default:
                    break;
            }
        }
    }
    ind = (ind + 1) % 4;
}