#include <opencv2/opencv.hpp>
#include <filesystem>
#include <iostream>
#include <utility>

class Normalize
{
    public:
        //Normalize(std::string inputData, std::string outputData);
        Normalize();
        bool createOutputDirectory(std::string outputData);
        void Normalization(std::string inputData, std::string outputData);
        void displayNormPixelValues(cv::Mat normalizedImage);

    private:
        cv::Mat image, normalizedImage;





};