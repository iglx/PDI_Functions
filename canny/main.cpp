#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;
using namespace cv;

//Mat detectaCanny(Mat img){
//    Mat img2 = img.clone();
//    blur(img, img2, Size(3,3));
//    Mat img3 = img2.clone();
//    Canny(img2, img3, 90, 128, 3x3);

//    return img3;
//}

int main()
{

    Mat img, img2;
    img = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\anime.png",0);
    img2 = img.clone();

    Canny(img, img2, 10, 35, 3);

    namedWindow("imgOriginal");
    namedWindow("imgProcessada");
    imshow("imgOriginal",img);
    imshow("imgProcessada",img2);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
