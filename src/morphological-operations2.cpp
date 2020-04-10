#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

cv::Mat src, dst;
int morph_elem = 0;
int morph_size = 0;
int morph_operator = 0;
int const max_operator = 4;
int const max_elem = 2;
int const max_kernel_size = 21;
const char *window_name = "Morphology Transformations Demo";

void Morphology_Operations(int, void *);

int main(int argc, char **argv) {

    const char *filename = argc >= 2 ? argv[1] : "./images/cute-dog.jpg";
    src = cv::imread(filename, cv::IMREAD_COLOR);

    if (src.empty()) {
        std::cout << "Could not open or find the image!\n" << std::endl;
        std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
        return -1;
    }

    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);

    cv::createTrackbar("Operator:\n 0: Opening - 1: Closing  \n 2: Gradient - 3: Top Hat \n 4: Black Hat",
                       window_name,
                       &morph_operator,
                       max_operator,
                       Morphology_Operations);

    cv::createTrackbar("Element:\n 0: Rect - 1: Cross - 2: Ellipse", window_name,
                       &morph_elem, max_elem,
                       Morphology_Operations);

    cv::createTrackbar("Kernel size:\n 2n +1", window_name,
                       &morph_size, max_kernel_size,
                       Morphology_Operations);


    Morphology_Operations(0, 0);

    cv::waitKey(0);

    return 0;
}


void Morphology_Operations(int, void *) {

    int operation = morph_operator + 2;
    cv::Mat element = cv::getStructuringElement(morph_elem,
                                                cv::Size(2 * morph_size + 1, 2 * morph_size + 1),
                                                cv::Point(morph_size, morph_size));

    cv::morphologyEx(src, dst, operation, element);
    cv::imshow(window_name, dst);
}