#include "normalize.h"

Normalize::Normalize()
{}

//creates an output folder for the edited images to be written to
bool Normalize::createOutputDirectory(std::string outputData)
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

//normalizing the input image
void Normalize::Normalization(std::string inputData, std::string outputData)
{
    createOutputDirectory(outputData);
    for (const auto& entry : std::__fs::filesystem::directory_iterator(inputData))
        {
            if (std::__fs::filesystem::is_regular_file(entry.path())) 
            {
                image = cv::imread(entry.path().string());
    
                if (image.empty()) 
                {
                    std::cerr << "Error loading image." << std::endl;
                    continue;
                }
    
                image.convertTo(image, CV_32F);
                cv::normalize(image, normalizedImage, 0.0, 255.0, cv::NORM_MINMAX);
                std::string outputPath = outputData + "/" + entry.path().filename().string();
                cv::imwrite(outputPath, normalizedImage);

                std::cout << "Normalized image saved to: " << outputPath << "\n";
            }    
        }
}

//displayes the values of each pixel in the normalized image
void Normalize::displayNormPixelValues(cv::Mat normalizedImage)
{
    for (int y = 0; y < normalizedImage.rows; ++y) 
    {
        for (int x = 0; x < normalizedImage.cols; ++x) 
        {
            cv::Vec3f pixel = normalizedImage.at<cv::Vec3f>(y, x);
            float channel1 = pixel[0]; // Value of the first channel
            float channel2 = pixel[1]; // Value of the second channel
            float channel3 = pixel[2]; // Value of the third channel

            // Print or process pixel values as needed
            std::cout << "Pixel at (" << x << ", " << y << "): ";
            std::cout << "Channel 1: " << channel1 << ", " << "Channel 2: " << channel2 << ", " << "Channel 3: " << channel3 << "\n";
        }
    }

}
