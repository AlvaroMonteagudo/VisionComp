#include <cv.h>
#include <highgui.h>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
//#include "opencv2/imageproc/imageproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

double alpha; /**< Simple contrast control */
int beta;  /**< Simple brightness control */

void colorReduce(Mat& image, int div)
{    
    int nl = image.rows;                    // number of lines
    int nc = image.cols * image.channels(); // number of elements per line

    for (int j = 0; j < nl; j++)
    {
        // get the address of row j
        uchar* data = image.ptr<uchar>(j);

        for (int i = 0; i < nc; i++)
        {
            // process each pixel
            data[i] = data[i] / div * div + div;
        }
    }
}

int main( int argc, char** argv )
{
	VideoCapture cap(0); // open the default camera

    if(!cap.isOpened()){
    	// check if we succeeded
        return -1;
    }  
   
   	Mat image;
   	cap >> image;

	int colores;
	cout << "Número de colores de la imagen: " << endl;
	cin >> colores;

	Mat c_reduce = image.clone();

	colorReduce(c_reduce, colores);

	namedWindow("Original", 1);
	imshow("Original", image );

	namedWindow("Reducida", 1);
	imshow("Reducida", c_reduce );


 	/// Wait until user press some key
	waitKey(0);

	cout << "Terminado..." << endl;

	return 0;
}

