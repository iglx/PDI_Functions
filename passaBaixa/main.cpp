#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>


using namespace std;
using namespace cv;

int bubbleSort(int vet[]){
    int aux;
    for(int i=0;i<9;i++){
        for(int j=0;j<8;j++){
            if(vet[j]>vet[j+1]){
                aux=vet[j];
                vet[j]=vet[j+1];
                vet[j+1]=aux;
            }
        }
    }

    return vet[4];
}

int main(){

    int vet[9];
    Mat img, img2;
    img = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\luizgay.jpg",0);
    img2 = img.clone();

    for(int i=1; i<img.rows-1; i++){
        for(int j=1; j<img.rows-1; j++){
            vet[0] = img.at<uchar>(i,j);
            vet[1] = img.at<uchar>(i-1,j);
            vet[2] = img.at<uchar>(i+1,j);
            vet[3] = img.at<uchar>(i,j+1);
            vet[4] = img.at<uchar>(i,j-1);
            vet[5] = img.at<uchar>(i-1,j+1);
            vet[6] = img.at<uchar>(i-1,j-1);
            vet[7] = img.at<uchar>(i+1,j+1);
            vet[8] = img.at<uchar>(i+1,j-1);




            img2.at<uchar>(i,j) = bubbleSort(vet);


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
