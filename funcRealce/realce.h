#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <math.h>

using namespace std;
using namespace cv;

#ifndef REALCE
#define REALCE

//prototipo truncamento
int trunca(float v);


//prototipos funções de realce
Mat retaSimples(Mat img, int a, int b);
Mat funcLog(Mat img, float c);
Mat negativoImg(Mat img);
Mat exponencial(Mat img, int c, float gamma);

#endif // REALCE

