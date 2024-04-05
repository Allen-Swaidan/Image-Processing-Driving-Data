#include "cropImage.h"

int main() {

   //load the training data
    std::string stuttgart00Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_00";
    std::string stuttgart01Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_01";
    std::string stuttgart02Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_02";

   //creating output directory
    std::string outputFolder1 = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/BottomHalfImg8bitVideo/stuttgart_00"; 
    std::string outputFolder2 = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/BottomHalfImg8bitVideo/stuttgart_01"; 
    std::string outputFolder3 = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/BottomHalfImg8bitVideo/stuttgart_02"; 

    //cropping the images to keep only the bottom half
    Crop crop1(stuttgart00Data, outputFolder1, "bottomHalf");
    Crop crop2(stuttgart01Data, outputFolder2, "bottomHalf");
    Crop crop3(stuttgart02Data, outputFolder3, "bottomHalf");

    return 0;
}