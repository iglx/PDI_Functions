#include <iostream>
#include "opencv/cv.hpp"
#include "opencv/highgui.h"

using namespace cv;
int main()
{

    //cria o objeto que quarda a imagem
    Mat obj, R, G, B;
    //ler a imagem
    obj = imread("C:\\Users\\igorl\\OneDrive\\Imagens\\Tucano.jpg",1);
    //clonar a imagem
    R = obj.clone();
    G = obj.clone();
    B = obj.clone();


    for(int i=0; i<obj.rows; i++){
        for(int j=0; j<obj.cols; j++){
            //separando a imagem em 3 canais
                //Vermelho
                R.at<Vec3b>(i,j)[2] = obj.at<Vec3b>(i,j)[2];
                R.at<Vec3b>(i,j)[1] = 0;
                R.at<Vec3b>(i,j)[0] = 0;
                //Verde
                G.at<Vec3b>(i,j)[1] = obj.at<Vec3b>(i,j)[1];
                G.at<Vec3b>(i,j)[2] = 0;
                G.at<Vec3b>(i,j)[0] = 0;
                //Azul
                B.at<Vec3b>(i,j)[0] = obj.at<Vec3b>(i,j)[0];
                B.at<Vec3b>(i,j)[2] = 0;
                B.at<Vec3b>(i,j)[1] = 0;

        }
    }

    //Cria a janela e mostra a imagem
    namedWindow("tela1");
    imshow("tela1",obj);

    namedWindow("tela2");
    imshow("tela2",R);

    namedWindow("tela3");
    imshow("tela3",G);

    namedWindow("tela4");
    imshow("tela4",B);



    //Espera uma tecla para fechar a janela
    waitKey(0);

    //Destroi a janela
    destroyWindow("tela1");

    return 0;
}
