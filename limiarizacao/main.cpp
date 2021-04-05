#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "limiarizacao.h"

using namespace std;
using namespace cv;


int main(){

    Mat img, img2;
    img = imread("C:\\Users\\igorl\\Music\\texto.jpg",0);
    img2 = img.clone();
    int valor=0, cor1, cor2;

    //10%
    //valor=dezPorcento(img);

    //dois picos
    //valor=doisPicos(img);

    //maior cor
    cor1=maiorCor(img);

    //menor cor
    cor2=menorCor(img);

    //media
    //valor=media(cor1,cor2);


    namedWindow("Original");
    imshow("Original",img);

    namedWindow("Processada");
    imshow("Processada",limiar(img2,valor));

    waitKey(0);


    return 0;
}
