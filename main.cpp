//#include <opencv2/opencv.hpp>
//#include <opencv2/imgproc.hpp>
//#include <filesystem>
//#include <iostream>
#include "cropImage.h"

int main() {
/*
    //creating output directory
    std::string outputFolder1 = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/BottomHalfImg8bitVideo/stuttgart_00"; 
    std::string outputFolder2 = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/BottomHalfImg8bitVideo/stuttgart_01"; 
    std::string outputFolder3 = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/BottomHalfImg8bitVideo/stuttgart_02"; 
    if(!std::__fs::filesystem::exists(outputFolder1))
    {
        if(!std::__fs::filesystem::create_directories(outputFolder1))
        {
            std::cout << "Error creating directory" << "\n";
            return 1;
        }
        else
        {
            std::cout << "Successfully created folder: " << outputFolder1 << "\n";
        }
    }

    //load the training data
    std::string stuttgart00Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_00";
    std::string stuttgart01Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_01";
    std::string stuttgart02Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_02";

    for (const auto& entry : std::__fs::filesystem::directory_iterator(stuttgart00Data))
    {
        // Check if the current entry is a file
        if (std::__fs::filesystem::is_regular_file(entry.path())) 
        {
            // Load the image from file
            cv::Mat image = cv::imread(entry.path().string());
            if (image.empty()) 
            {
                std::cerr << "Error loading image: " << entry.path() << std::endl;
                continue; // Skip to the next file
            }

            //getting image size
            int imageWidth = image.cols;
            int imageHeight = image.rows;

            // Define the region of interest (ROI) for cropping
            int x = 0;                        // x-coordinate of the top-left corner of the ROI
            int y = imageHeight / 2;          // y-coordinate of the top-left corner of the ROI
            int ROIheight = imageHeight / 2 ; // height of the ROI

            // Crop the image using the defined ROI
            //cv::Mat croppedImage = image(cv::Rect(x, y, imageWidth, ROIheight));
            cv::Rect bottomHalfRect(x, y, imageWidth, ROIheight);
            cv::Mat croppedImage = image(bottomHalfRect);

            // Save the resized image
            std::string outputPath = outputFolder1 + "/" + entry.path().filename().string();
            cv::imwrite(outputPath, croppedImage);
            std::cout << "Resized image saved to: " << outputPath << std::endl;
            std::cout << "width: " << image.cols << "height: " << image.rows << "\n";
            
        }

    }
    */

   //load the training data
    std::string stuttgart00Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_00";
    std::string stuttgart01Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_01";
    std::string stuttgart02Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_02";

   //creating output directory
    std::string outputFolder1 = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/BottomHalfImg8bitVideo/stuttgart_00"; 
    std::string outputFolder2 = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/BottomHalfImg8bitVideo/stuttgart_01"; 
    std::string outputFolder3 = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/BottomHalfImg8bitVideo/stuttgart_02"; 

    Crop crop1(stuttgart00Data, outputFolder1, "bottomHalf");
    Crop crop2(stuttgart01Data, outputFolder2, "bottomHalf");
    Crop crop3(stuttgart02Data, outputFolder2, "bottomHalf");

    return 0;
}
