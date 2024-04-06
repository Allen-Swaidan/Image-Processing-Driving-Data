#include <opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>
#include <utility>

class grayScale
{
    public:
        grayScale(std::string inputData, std::string outputData);
        bool createOutputDirectory(std::string outputData);
        void applyGrayScale(std::string inputData, std::string outputData);

    private:
        cv::Mat image, grayScaledImage;
};