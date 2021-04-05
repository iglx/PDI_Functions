#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;
using namespace cv;


int main(){

    int conv;
    Mat img, img2;
    float mascara[3][3]={1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0, 1/9.0};
    img = imread("C:\\Users\\igorl\\OneDrive\\Documentos\\P.D.I\\banco\\ruido\\mona_lisa.pgm",0);
    img2 = img.clone();

    for(int i=1; i<img.rows-1; i++){
        for(int j=1; j<img.rows-1; j++){
            conv=0;
            for(int x=-1;x<=1;x++){
                for(int y=-1;y<=1;y++){
                    conv = conv + mascara[y+1][x+1]*img.at<uchar>(i-y,j-x);
                }
            }
            img2.at<uchar>(i,j)=conv;

        }
    }

    namedWindow("Original");
    namedWindow("Processada");
    imshow("Original",img);
    imshow("Processada",img2);


    waitKey(0);

    destroyWindow("Original");
    destroyWindow("Processada");



    return 0;
}
