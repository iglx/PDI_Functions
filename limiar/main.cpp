#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;
using namespace cv;

int miaMid(int valorMenor, int valorMaior){

    int limiar;

    return limiar;
}



int main(){

    Mat img,img2;
    img = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\luizgay.jpg",0);
    img2 = img.clone();

    printf("Luiz eh Gay\n");

    //Binarizando
    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){
            if(img.at<uchar>(i,j)>128)
            {
                img2.at<uchar>(i,j)=255;
            }else
            {
                img2.at<uchar>(i,j)=0;
            }
        }
    }

    namedWindow("Original");
    namedWindow("Processada");
    imshow("Original",img);
    imshow("Processada",img2);

    waitKey(0);

    destroyAllWindows();

    return 0;
}
