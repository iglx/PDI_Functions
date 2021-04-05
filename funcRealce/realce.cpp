#include "realce.h"
using namespace std;


//função de truncamento
int trunca(float v){

    int valor = 0;
    valor = (int)v;

    if(v>255)
    {
        valor=255;
    }if(v<0)
    {
        valor=0;
    }

    return valor;
}

//função reta simples
Mat retaSimples(Mat img, int a, int b){
    Mat img2;
    img2 = img.clone();
    float valor;
    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){
            valor = a*img.at<uchar>(i,j)+b;
            img2.at<uchar>(i,j) = trunca(valor);
        }
    }

    return img2;
}

//funão logaritima
Mat funcLog(Mat img, float c){
    Mat img2;
    img2 = img.clone();
    float valor;

    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){

            valor = img.at<uchar>(i,j)*log(c+1);
            img2.at<uchar>(i,j) = trunca(valor);

        }
    }

    return img2;
}

//função exponencial
Mat exponencial(Mat img, int c, float gamma){
    Mat img2;
    img2 = img.clone();
    float valor;

    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){

            valor = c*pow(img.at<uchar>(i,j),gamma);
            img2.at<uchar>(i,j) = trunca(valor);

        }
    }

    return img2;
}




//função negativo
Mat negativoImg(Mat img){
    Mat img2;
    img2 = img.clone();
    float valor;

    for(int i=0; i<img.rows; i++){
        for(int j=0; j<img.cols; j++){

            valor = img.at<uchar>(i,j);
            valor = 255 - valor;
            img2.at<uchar>(i,j) = trunca(valor);

        }
    }

    return img2;
}
