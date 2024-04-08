#include "histEqualization.h"

histEqual::histEqual(std::string inputData, std::string outputData)
{
    createOutputDirectory(outputData);
    applyhist(inputData, outputData);
}

bool histEqual::createOutputDirectory(std::string outputData)
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

void histEqual::applyhist(std::string inputData, std::string outputData)
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

            // Convert the image to grayscale if it's not already in grayscale            
            if (image.channels() > 1) 
            {
                cv::cvtColor(image, grayScaleImage, cv::COLOR_BGR2GRAY);
            } 
            else 
            {
                grayScaleImage = image.clone(); // If already grayscale, create a copy
            }

            // Apply histogram equalization
            cv::equalizeHist(grayScaleImage, equalizedImage);
            std::string outputPath = outputData + "/" + entry.path().filename().string();

            // Save the equalized image
            cv::imwrite(outputPath, equalizedImage);
            std::cout << "Histogram Equalized image saved to: " << outputPath << "\n";
        }
    }
}