#include "lib_utfrend.h"

int main(int argc, char* argv[]) {
    // find file path
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <path>\n";
        return 1;
    }

    // read image
    cv::Mat image = cv::imread(argv[1]);

    // check image
    if (image.empty()) {
        std::cerr << "Failed to load file.\n";
        return 1;
    }
    std::cout << renderImage(image, 2, 40, 40);
    return 0;
}
