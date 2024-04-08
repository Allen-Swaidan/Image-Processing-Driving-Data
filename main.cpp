#include "cropImage.h"
#include "normalize.h"
#include "grayScale.h"
#include "histEqualization.h"
#include "medianBlur.h"

int main() {

    //training data path
    std::string stuttgart00Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_00";
    std::string stuttgart01Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_01";
    std::string stuttgart02Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/leftImg8bit_demoVideo/leftImg8bit/demoVideo/stuttgart_02";

    //creating output directory path
    std::string croppedStuttgart00Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/CroppedImages/stuttgart_00"; 
    std::string croppedStuttgart01Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/CroppedImages/stuttgart_01"; 
    std::string croppedStuttgart02Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/CroppedImages/stuttgart_02"; 
    std::string normCroppedStutt00Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/NormalizedCroppedImages/stuttgart_00";
    std::string normCroppedStutt01Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/NormalizedCroppedImages/stuttgart_01";
    std::string normCroppedStutt02Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/NormalizedCroppedImages/stuttgart_02";
    std::string grayScaledCroppedStuttgart00Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/grayScaledImages/stuttgart_00";
    std::string grayScaledCroppedStuttgart01Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/grayScaledImages/stuttgart_01";
    std::string grayScaledCroppedStuttgart02Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/grayScaledImages/stuttgart_02";
    std::string equalizedCroppedStuttgart00Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/equalizedImages/stuttgart_00";
    std::string equalizedCroppedStuttgart01Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/equalizedImages/stuttgart_01";
    std::string equalizedCroppedStuttgart02Data = "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/equalizedImages/stuttgart_02";
    
    /*
    //cropping the images to keep only the bottom half
    Crop crop1(stuttgart00Data, croppedStuttgart00Data, "bottomHalf");
    Crop crop2(stuttgart01Data, croppedStuttgart01Data, "bottomHalf");
    Crop crop3(stuttgart02Data, croppedStuttgart02Data, "bottomHalf");

    //normalizing the cropped images to pixel values between 0 and 255
    Normalize norm1, norm2, norm3;
    norm1.Normalization(croppedStuttgart00Data, normCroppedStutt00Data);
    norm2.Normalization(croppedStuttgart01Data, normCroppedStutt01Data);
    norm3.Normalization(croppedStuttgart02Data, normCroppedStutt02Data);

    //gray scaling the cropped images
    grayScale grayScale1(normCroppedStutt00Data, grayScaledCroppedStuttgart00Data);
    grayScale grayScale2(normCroppedStutt01Data, grayScaledCroppedStuttgart01Data);
    grayScale grayScale3(normCroppedStutt02Data, grayScaledCroppedStuttgart02Data);

    //applying histogram equalization to the cropped images
    histEqual applyEqualization1(grayScaledCroppedStuttgart00Data, equalizedCroppedStuttgart00Data);
    histEqual applyEqualization2(grayScaledCroppedStuttgart01Data, equalizedCroppedStuttgart01Data);
    histEqual applyEqualization3(grayScaledCroppedStuttgart02Data, equalizedCroppedStuttgart02Data);
    */

    //applying median filtering
    medianBlur filter1(equalizedCroppedStuttgart00Data, "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/medianFilteredImg/stuttgart_00", 21);
    medianBlur filter2(equalizedCroppedStuttgart01Data, "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/medianFilteredImg/stuttgart_01", 21);
    medianBlur filter3(equalizedCroppedStuttgart02Data, "/Users/allen/Downloads/Code/Image-Processing-Driving-Data/medianFilteredImg/stuttgart_02", 21);

    return 0;

}
