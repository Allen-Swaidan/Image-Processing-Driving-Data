#include "grayScale.h"

grayScale::grayScale(std::string inputData, std::string outputData)
{
    createOutputDirectory(outputData);
    applyGrayScale(inputData, outputData);
    
}

bool grayScale::createOutputDirectory(std::string outputData)
{
    if(!std::__fs::filesystem::exists(outputData))
    {
        if(!std::__fs::filesystem::create_directories(outputData))
        {
            std::cout << "Error creating directory" << "\n";
            return false;
        }
        else
        {
            std::cout << "Successfully created folder: " << outputData << "\n";
            return true;
        }
    }
}

void grayScale::applyGrayScale(std::string inputData, std::string outputData)
{
    for (const auto& entry : std::__fs::filesystem::directory_iterator(inputData))
    {
        if (std::__fs::filesystem::is_regular_file(entry.path())) 
        {

            image = cv::imread(entry.path().string());
    
            // Check if the image is loaded successfully
            if (image.empty()) 
            {
                std::cerr << "Error: Could not read the image." << std::endl;
                continue;
            }
    
            // Convert the image to grayscale
            cv::Mat grayscaleImage;
            cv::cvtColor(image, grayscaleImage, cv::COLOR_BGR2GRAY);
    
            std::string outputPath = outputData + "/" + entry.path().filename().string();
            cv::imwrite(outputPath, grayscaleImage);
            std::cout << "Gray scaled image saved to: " << outputPath << "\n";
        }
    }
}   