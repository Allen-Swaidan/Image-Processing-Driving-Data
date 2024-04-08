#include <opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>
#include <utility>

class medianBlur
{
    public:
        medianBlur(std::string inputData, std::string outputData, int kernelSize);
        bool createOutputDirectory(std::string outputData);
        void applyBlur(std::string inputData, std::string outputData, int KernelSize); 

    private:
        cv::Mat image, filteredImage;
        int KernelSize;


};