#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>
#include <math.h>
#include "limiarizacao.h"

using namespace std;
using namespace cv;



//LIMIAR
Mat limiar(Mat img, int T){
    int pixel;
    Mat img2 = img.clone();

    for(int i=0;i<img.rows; i++){
        for(int j=0;j<img.cols; j++){
            pixel = img.at<uchar>(i,j);
            if(pixel<=T){
                pixel=0;
            }else{
                pixel=255;
            }
            img2.at<uchar>(i,j)=pixel;
        }
    }

    return img2;

}


//CONTADOR DE PIXELS PRETOS
int contPreto(Mat img){
    int pixel=0, cont=0;
    for(int i=0;i<img.rows; i++){
        for(int j=0;j<img.cols; j++){
            pixel=img.at<uchar>(i,j);
            if(pixel==0){
                cont++;
            }
        }
    }

    return cont;
}


//Função 10%
int dezPorcento(Mat img){
    Mat aux;
    int tp=0, t=0;
    float pcp=0;

    for(int L=0; L<255; L++){
        aux=limiar(img,L);
        tp=contPreto(aux);
        pcp=(tp/(float)(img.rows*img.cols));

        if(pcp>0.09 && pcp<0.11){
            t=L;
        }

    }

    return t;
}


//Função histograma
uchar *histograma(Mat img){
    uchar hist[256];

    for(int i=0; i<256; i++){
        hist[i]=0;
    }
    for(int i=0;i<img.rows; i++){
        for(int j=0;j<img.cols; j++){
            hist[img.at<uchar>(i,j)++];
        }
    }

    return hist;
}


//Função maior cor
int maiorCor(Mat img){
    int maior=0, aux=99999;
    uchar *hist;

    hist=histograma(img);

    for(int i=0; i<256; i++){
        if(hist[i]>aux){
            maior=hist[i];
        }
    }

    return maior;
}


//LIMIAR POR DOIS PICOS
int doisPicos(Mat img){
    int pico1=0, pico2=0, aux=-1, media=0;
    uchar *hist;

    hist = histograma(img);

    for(int i=0; i<256; i++){
        if(hist[i]>aux){
            aux=hist[i];
            pico1=i;
        }
    }

    for(int k=0; k<256; k++){
        if((pow(k-(pico1),2)*hist[k])>aux){
            aux=pow((k-pico1),2)*hist[k];
            pico2=k;
        }
    }

    media = abs((pico1+pico2)/2);

    return media;

}

//MEDIA
int media(int cor1, int cor2){
    int med=0;

    med=(cor1+cor2)/2;

    return med;
}

//FUNÇÃO MENOR COR
int menorCor(Mat img){
    int menor=0, aux=-99999;
    uchar *hist;

    hist=histograma(img);
    for(int i=0; i<256; i++){
        if(hist[i]<aux){
            menor=hist[i];
        }
    }

    return menor;
}
