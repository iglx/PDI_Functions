#ifndef LIMIARIZACAO
#define LIMIARIZACAO
#include "opencv/cv.hpp"
#include "opencv/highgui.h"

using namespace std;
using namespace cv;

//LIMIAR EMPIRICO
Mat limiar(Mat img, int T);

//CONTADOR DE PIXELS PRETOS
int contPreto(Mat img);

//Função 10%
int dezPorcento(Mat img);

//Função histograma
uchar *histograma(Mat img);

//Função maior cor
int maiorCor(Mat img);

//LIMIAR POR DOIS PICOS
int doisPicos(Mat img);
//MEDIA
int media(int cor1, int cor2);

//FUNÇÃO MENOR COR
int menorCor(Mat img);


#endif // LIMIARIZACAO

