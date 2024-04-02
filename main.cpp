#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <filesystem>
#include <iostream>

int main() {

    //creating output directory
    std::string outputFolder = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/resizedLeftImg8bit_trainvaltest/train/aachen"; 
    if(!std::__fs::filesystem::exists(outputFolder))
    {
        if(!std::__fs::filesystem::create_directories(outputFolder))
        {
            std::cout << "Error creating directory" << "\n";
            return 1;
        }
        else
        {
            std::cout << "Successfully created folder: " << outputFolder << "\n";
        }
    }

    //load the training data
    std::string left_training_image_aachen = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_trainvaltest/leftImg8bit/train/aachen";

    for (const auto& entry : std::__fs::filesystem::directory_iterator(left_training_image_aachen))
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
            std::string outputPath = outputFolder + "/" + entry.path().filename().string();
            cv::imwrite(outputPath, croppedImage);
            std::cout << "Resized image saved to: " << outputPath << std::endl;
            std::cout << "width: " << image.cols << "height: " << image.rows << "\n";
        }

    }
    return 0;
}
