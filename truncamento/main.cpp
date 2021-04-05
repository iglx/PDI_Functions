#include <iostream>
#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>

using namespace std;
using namespace cv;

int main()
{

    Mat img, img2, img3;
    int a=2, b=0, valor;
    img = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\lena.bmp",0);
    img2 = img.clone();
    img3 = img.clone();

    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.rows; j++){

            img2.at<uchar>(i,j)=a*img.at<uchar>(i,j)+b;
            valor=a*img.at<uchar>(i,j)+b;
            //Não truncada
            img2.at<uchar>(i,j)= valor;

            //Truncando a imagem
            if(valor>255)
            {
                valor=255;
            }
            if(valor<0)
            {
                valor=0;
            }

            //Truncada
            img3.at<uchar>(i,j)= valor;

        }
    }

    valor = a*img3.at<uchar>(22,22)+b;
    printf("%d\n",valor);

    namedWindow("imagem original");
    imshow("imagem original", img);

    namedWindow("imagem trabalhada");
    imshow("imagem trabalhada", img2);

    namedWindow("imagem trabalhado com truncamento");
    imshow("imagem trabalhado com truncamento", img3);

    waitKey();

    return 0;
}
//FORMA ERRADA
//            //truncamento
//            if(img2.at<uchar>(i,j)>255){
//                img3.at<uchar>(i,j)=255;
//            }else if(img2.at<uchar>(i,j)<0){
//                img3.at<uchar>(i,j)=0;
//            }else{
//                img3.at<uchar>(i,j)=img2.at<uchar>(i,j);
//            }
