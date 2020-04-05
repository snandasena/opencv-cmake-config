#include<opencv2/core.hpp>
#include<opencv2/imgproc.hpp>
#include<opencv2/highgui.hpp>

#define w 400

using namespace cv;

void MyEllipse(Mat img, double angle);

void MyFilledCircle(Mat img, Point center);

int main() {
    char atom_window[] = "Drawing 1: Atom";

    Mat atom_image = Mat::zeros(w, w, CV_8UC3);


    MyEllipse(atom_image, 90.0);
    MyEllipse(atom_image, 0);
    MyEllipse(atom_image, 45);
    MyEllipse(atom_image, -45);

    MyFilledCircle(atom_image, Point(w / 2, w / 2));

    cv::imshow(atom_window, atom_image);
    cv::moveWindow(atom_window, 0, 200);
    waitKey(0);

    return 0;

}

void MyEllipse(Mat img, double angle) {
    int thickness = 2;
    int lineType = 8;

    cv::ellipse(img,
                cv::Point(w / 2, w / 2),
                cv::Size(w / 4, w / 4),
                angle,
                0,
                360,
                cv::Scalar(255, 0, 0),
                thickness,
                lineType);
}


void MyFilledCircle(Mat img, Point center) {
    cv::circle(img,
               center,
               w / 32,
               Scalar(0, 0, 255),
               FILLED,
               LINE_8);

}