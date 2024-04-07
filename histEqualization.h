#include <opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>
#include <utility>

class histEqual
{
    public:
        histEqual(std::string inputData, std::string outputData);
        bool createOutputDirectory(std::string outputData);
        void applyhist(std::string inputData, std::string outputData);

    private:
        cv::Mat image, equalizedImage, grayScaleImage;
};