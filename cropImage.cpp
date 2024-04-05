#include "cropImage.h"

Crop::Crop(std::string inputData, std::string outputData, std::string croppingStrategy)
{
    createOutputDirectory(outputData);

    if(croppingStrategy == "bottomHalf")
    {
        bottomHalf(inputData, outputData);
    }
    else
    {
        std::cout << "Error: Cropping function does not exist" << "\n";
    }
}

bool Crop::createOutputDirectory(std::string outputData)
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

void Crop::defineROI(int &imageWidth, int &imageHeight)
{
    imageWidth = image.cols;
    imageHeight = image.rows;

    //Define the region of interest (ROI) for cropping
    x = 0;                            //x-coordinate of the top-left corner of the ROI
    y = imageHeight / 2;              //y-coordinate of the top-left corner of the ROI
    ROIheight = imageHeight / 2 ;     //height of the ROI
}

void Crop::bottomHalf(std::string inputData, std::string outputData)
{
    for (const auto& entry : std::__fs::filesystem::directory_iterator(inputData))
    {
        if (std::__fs::filesystem::is_regular_file(entry.path())) 
        {
            // Load the image from file
            image = cv::imread(entry.path().string());
            if (image.empty()) 
            {
                std::cerr << "Error loading image: " << entry.path() << std::endl;
                continue; // Skip to the next file
            }

            defineROI(imageWidth, imageHeight);

            cv::Rect bottomHalfRect(x, y, imageWidth, ROIheight);
            cv::Mat croppedImage = image(bottomHalfRect);

            // Save the resized image
            std::string outputPath = outputData + "/" + entry.path().filename().string();

            cv::imwrite(outputPath, croppedImage);
            std::cout << "Resized image saved to: " << outputPath << std::endl;
            std::cout << "width: " << image.cols << "height: " << image.rows << "\n";

        }
    }
}

