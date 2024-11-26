#define LIB_UTFREND_IMAGE_H
#include "lib_utfrend.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <image file>\n";
        return 1;
    }

    cv::Mat image = cv::imread(argv[1]);
    if (image.empty()) {
        std::cerr << "Failed to load image.\n";
        return 1;
    }

    // resize into terminal dimensions
    int terminalWidth = 40;
    int terminalHeight = 40;
    cv::resize(image, image, cv::Size(terminalWidth, terminalHeight));

    // Convert image to RGB format
//    cv::cvtColor(image, image, cv::COLOR_BGR2RGB);

    // Render the image
    std::cout << "\033[2J\033[H"; // Clear screen and reset cursor
    renderImageToTerminal(image);

    return 0;
}