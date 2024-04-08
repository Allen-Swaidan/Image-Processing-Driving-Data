#include "medianBlur.h"

medianBlur::medianBlur(std::string inputData, std::string outputData, int kernelSize)
{
    createOutputDirectory(outputData);
    applyBlur(inputData, outputData, kernelSize);
}

bool medianBlur::createOutputDirectory(std::string outputData)
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

void medianBlur::applyBlur(std::string inputData, std::string outputData, int kernelSize)
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

                cv::medianBlur(image, filteredImage, kernelSize);
                std::string outputPath = outputData + "/" + entry.path().filename().string();

                // Save the equalized image
                cv::imwrite(outputPath, filteredImage);
                std::cout << "Median filtered image saved to: " << outputPath << "\n";
            }
        }
}
