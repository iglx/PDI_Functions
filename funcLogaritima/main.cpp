#include <iostream>
#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>
#include <math.h>

using namespace std;
using namespace cv;

int main()
{

    Mat img, img2;
    float valor, c=1, r=0;
    int valor2;
    img = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\lena.bmp",0);
    img2 = img.clone();

    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.rows; j++){

            valor=c*log(1+r)+0.1;
            valor2 = (int)valor;

            if(valor2>255)
            {
                valor2=255;
            }
            if(valor2<0)
            {
                valor2=0;
            }


            //Truncada
            img2.at<uchar>(i,j)= valor2;


        }
    }


    namedWindow("imagem original");
    imshow("imagem original", img);

    namedWindow("imagem trabalhada");
    imshow("imagem trabalhada", img2);
    waitKey();

    return 0;
}
