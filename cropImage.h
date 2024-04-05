#include <opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>
#include <utility>

class Crop
{
    public:
        Crop(std::string inputData, std::string outputData, std::string croppingStrategy);
        bool createOutputDirectory(std::string outputData);
        void defineROI(int &imageWidth, int &imageHeight);
        void bottomHalf(std::string inputData, std::string outputData);
        
    private:
        cv::Mat image;
        int x, y, imageWidth, imageHeight, ROIheight;

};