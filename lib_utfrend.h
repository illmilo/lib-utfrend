#include <iostream>
#include <opencv2/opencv.hpp>

#ifdef LIB_UTFREND_IMAGE_H

std::string getANSIColor(int r, int g, int b) {
    return "\033[38;2;" + std::to_string(r) + ";" + std::to_string(g) + ";" + std::to_string(b) + "m";
}

void renderImageToTerminal(const cv::Mat& frame) {
    for (int y = 0; y < frame.rows; y += 2) { // 2 vertical pixels at a time
        for (int x = 0; x < frame.cols; ++x) {
            const cv::Vec3b& topPixel = frame.at<cv::Vec3b>(y, x),
                bottomPixel = (y + 1 < frame.rows) ? frame.at<cv::Vec3b>(y + 1, x) :
                                           cv::Vec3b(0, 0, 0);

            std::cout << getANSIColor(topPixel[2], topPixel[1], topPixel[0]) // Top pixel color
                      << getANSIColor(bottomPixel[2], bottomPixel[1], bottomPixel[0]) // Bottom pixel color
                      << "▄"; // Unicode block character
        }
        std::cout << "\033[0m\n"; // Reset color and newline
    }
}

#endif //LIB_UTFREND_IMAGE_H

#ifdef LIB_UTFREND_VIDEO_H

#endif //LIB_UTFREND_VIDEO_H
