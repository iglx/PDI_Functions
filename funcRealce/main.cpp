#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <iostream>
#include <string.h>
#include "realce.h"


using namespace std;
using namespace cv;

int main(){

    Mat img, img2; //imgMostra;
    img = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\profile.jpg",0);
    //imgMostra = imread("C:\\Users\\igorl\\OneDrive\\Documentos\\P.D.I\\Trabalho1\\img\\ok.jpg",1);
    img2 = img.clone();
    //float contraste[6]={1,2,3,4,5,6};

   // for(int i=0; i<6; i++){
        img2 = negativoImg(img);
       //convertendo int para string
        //stringstream ss;
        //ss<<contraste[i];
        //string str = ss.str();
        //salvando a imagem
        //imwrite("C:\\Users\\igorl\\OneDrive\\Documentos\\P.D.I\\Trabalho1\\resultados\\e1-"+str+".jpg",img2);
    //}




    namedWindow("resultado");
    imshow("resultado",img2);

    waitKey(0);
   // destroyWindow("resultado");

    return 0;
}
