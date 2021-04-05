#include <iostream>
#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat img, img2;
    img = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\orcaRoberts==---pççç0ioooooooooooooooookki9kiki9ki99999999999999111111111.png",0);
    img2 = img.clone();
    //int otsu;


    //threshold(img, img2, 0, 255, THRESH_OTSU);

    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){
            if(img.at<uchar>(i,j)>128){
                img2.at<uchar>(i,j)=255;
            }else{
                img2.at<uchar>(i,j)=0;
            }
        }
    }

    namedWindow("original");
    namedWindow("processada");
    imshow("original",img);
    imshow("processada",img2);

    waitKey(0);
    destroyAllWindows();
    return 0;
}
