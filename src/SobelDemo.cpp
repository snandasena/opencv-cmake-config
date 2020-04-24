#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;

const char *window_name = "Sobel Demo";

int main() {

    cv::Mat image, src, src_gray, grad;

    int ksize = 1;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    image = cv::imread("./images/cute-dog.jpg", IMREAD_COLOR);
    if (image.empty()) {
        return -1;
    }

    while (true) {

        // remove noise by blurring with a Gaussian filter ( kernel size = 3)
        cv::GaussianBlur(image, src, cv::Size(3, 3), 0, 0, BORDER_DEFAULT);

        // convert the image to grayscale
        cv::cvtColor(src, src_gray, cv::COLOR_BGR2GRAY);

        cv::Mat grad_x, grad_y;
        cv::Mat abs_grad_x, abs_grad_y;

        cv::Sobel(src_gray, grad_x, ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);
        cv::Sobel(src_gray, grad_y, ddepth, 1, 0, ksize, scale, delta, BORDER_DEFAULT);


        // convert back to CV_8U
        cv::convertScaleAbs(grad_x, abs_grad_x);
        cv::convertScaleAbs(grad_y, abs_grad_y);

        cv::addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

        cv::imshow(window_name, grad);
        auto key = (char) waitKey(0);

        if (key == 27) {
            return EXIT_SUCCESS;
        }
        if (key == 'k' || key == 'K') {
            ksize = ksize < 30 ? ksize + 2 : -1;
        }

        if (key == 's' || key == 'S') {
            scale++;
        }

        if (key == 'd' || key == 'D') {
            delta++;
        }

        if (key == 'r' || key == 'R') {
            scale = 1;
            ksize = -1;
            delta = 0;
        }
    }

    return 0;
}