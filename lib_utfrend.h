#include <opencv2/opencv.hpp>

std::string getANSIColor(int r, int g, int b) {
    return "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
}

// settings for the function
// frame : cv::Mat& of the image file
// k : amount of vertical pixels read at the time
// width & height : sizes of the output image
std::string renderImage(cv::Mat& frame, int k = 2, int width = 40, int height = 40) {
    cv::resize(frame, frame, cv::Size(width, height));
    std::string result;
    for (int y = 0; y < frame.rows; y += k) {               // k vertical pixels at a time
        for (int x = 0; x < frame.cols; ++x) {
            const cv::Vec3b& topPixel = frame.at<cv::Vec3b>(y, x),
                bottomPixel = (y + 1 < frame.rows) ?
                        frame.at<cv::Vec3b>(y + 1, x) :
                                cv::Vec3b(0, 0, 0);

            result += getANSIColor(topPixel[2], topPixel[1], topPixel[0])               // top pixel
                      + getANSIColor(bottomPixel[2], bottomPixel[1], bottomPixel[0])    // bottom pixel
                      + "▄"; // Unicode block character
        }
        result += "\033[0m\n"; // reset color
    }
    return result;
}