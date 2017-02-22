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
   
   
    Mat image, dst; // get a new frame from camera
	Mat new_image = Mat::zeros( image.size(), image.type() );

	cap >> image;

	/// Initialize values
	// cout<<" Mejora de contraste "<<endl;
	// cout<<"-------------------------"<<endl;

	// cout<<"* Introduzca valor de alfa [1.0 - 3.0]: ";
	// cin>>alpha;

	// cout<<"* Introduzca valor de beta: "; 
	// cin>>beta;


	// image.convertTo(new_image, -1, alpha, beta);

	// /// Do the operation new_image(i,j) = alpha*image(i,j) + beta
	// // for( int y = 0; y < image.rows; y++ ){ 
	// //    	for( int x = 0; x < image.cols; x++ ){ 
	// //         	for( int c = 0; c < 3; c++ ){
	// //      new_image.at<Vec3b>(y,x)[c] =
	// //         saturate_cast<uchar>( alpha*( image.at<Vec3b>(y,x)[c] ) + beta ); // sature cast es por que hay valores que se pasan
	// //             }
	// //     }
	// // }

	// /// Create Windows
	// namedWindow("Original Image", 1);
	// namedWindow("New Image", 1);
	

	// /// Show stuff
	// imshow("Original Image", image);
	// imshow("New Image", new_image);

	// /// Separate the image in 3 places ( B, G and R )
 //  	vector<Mat> bgr_planes;
 //  	split( image, bgr_planes );

	// /// Establish the number of bins
	// int histSize = 256;

	// /// Set the ranges ( for B,G,R) )
	// float range[] = { 0, 256 } ;
	// const float* histRange = { range };

	// bool uniform = true; bool accumulate = false;

	// Mat b_hist, g_hist, r_hist;

	// /// Compute the histograms:
	// calcHist( &bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
	// calcHist( &bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
	// calcHist( &bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

	// // Draw the histograms for B, G and R
	// int hist_w = 512; int hist_h = 400;
	// int bin_w = cvRound( (double) hist_w/histSize );

	// Mat histImage( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

	// /// Normalize the result to [ 0, histImage.rows ]
	// normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	// normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );
	// normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat() );

	// /// Draw for each channel
	// for( int i = 1; i < histSize; i++ )
	// {
	//     line( histImage, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
	//                      Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
	//                      Scalar( 255, 0, 0), 2, 8, 0  );
	//     line( histImage, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
	//                      Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
	//                      Scalar( 0, 255, 0), 2, 8, 0  );
	//     line( histImage, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
	//                      Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
	//                      Scalar( 0, 0, 255), 2, 8, 0  );
	// }

	// /// Display
	// namedWindow("Histograma", CV_WINDOW_AUTOSIZE );
	// imshow("Histograma", histImage );

	// // ECUALIZACION DE IMAGEN
	// Mat equalized_b, equalized_g, equalized_r;

	// // ECUALIZAMOS POR COLORES
	// equalizeHist( bgr_planes[0], equalized_b );
	// equalizeHist( bgr_planes[1], equalized_g );
	// equalizeHist( bgr_planes[2], equalized_r );

	// vector<Mat> rgb;
	// Mat equalized;

	// rgb.push_back(equalized_b);
	// rgb.push_back(equalized_g);
	// rgb.push_back(equalized_r);

	// merge(rgb, equalized);

	// /// Compute the histograms:
	// calcHist( &equalized_b, 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );
	// calcHist( &equalized_g, 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
	// calcHist( &equalized_r, 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );

	// Mat histImageEcualizada( hist_h, hist_w, CV_8UC3, Scalar( 0,0,0) );

	// normalize(b_hist, b_hist, 0, histImageEcualizada.rows, NORM_MINMAX, -1, Mat() );
	// normalize(g_hist, g_hist, 0, histImageEcualizada.rows, NORM_MINMAX, -1, Mat() );
	// normalize(r_hist, r_hist, 0, histImageEcualizada.rows, NORM_MINMAX, -1, Mat() );

	// /// Draw for each channel
	// for( int i = 1; i < histSize; i++ )
	// {
	//     line( histImageEcualizada, Point( bin_w*(i-1), hist_h - cvRound(b_hist.at<float>(i-1)) ) ,
	//                      Point( bin_w*(i), hist_h - cvRound(b_hist.at<float>(i)) ),
	//                      Scalar( 255, 0, 0), 2, 8, 0  );
	//     line( histImageEcualizada, Point( bin_w*(i-1), hist_h - cvRound(g_hist.at<float>(i-1)) ) ,
	//                      Point( bin_w*(i), hist_h - cvRound(g_hist.at<float>(i)) ),
	//                      Scalar( 0, 255, 0), 2, 8, 0  );
	//     line( histImageEcualizada, Point( bin_w*(i-1), hist_h - cvRound(r_hist.at<float>(i-1)) ) ,
	//                      Point( bin_w*(i), hist_h - cvRound(r_hist.at<float>(i)) ),
	//                      Scalar( 0, 0, 255), 2, 8, 0  );
	// }

	// namedWindow("Imagen ecualizada", 1);
	// imshow("Imagen ecualizada", equalized);

	// /// Display
	// namedWindow("Histograma ecualizado", CV_WINDOW_AUTOSIZE );
	// imshow("Histograma ecualizado", histImageEcualizada );


	// EMBORRONAR
	//Mat image_blur;
	//blur(image, image_blur, Size(9,9));

	// char c;
	// int rojo = 0;
	// int azul = 0;
	// int verde = 0;
	// cout << "Qué color de piel desea (R = rojo, G = verde, B = azul)" << endl;
	// cin >> c;

	// Mat hsv;
	// dst = image.clone();

	// Vec3b color;

	// image.convertTo(hsv, CV_32FC3);
 //    cvtColor(hsv, hsv, CV_BGR2HSV);

 //    for(int i = 0; i < image.rows; i++) {
 //        for(int j = 0; j < image.cols; j++) {

 //            // Vec3b pix_bgr = image.ptr<Vec3b>(i)[j];
 //            Vec3f pix_hsv = hsv.ptr<Vec3f>(i)[j];
 //            Vec3b cambio = dst.ptr<Vec3b>(i)[j];

 //            float H = pix_hsv.val[0];
 //            float S = pix_hsv.val[1];
 //            float V = pix_hsv.val[2];

 //            if ((H < 25) || (H > 230)){
 //            	if (c == 'R'){
	// 				cambio[0] = 0;
	// 				cambio[1] = 0;
	// 			}else if(c == 'G'){
	// 				cambio[0] = 0;
	// 				cambio[2] = 0;
	// 			}else{
	// 				cambio[1] = 0;
	// 				cambio[2] = 0;
	// 			}
 //            }
 //        }
 //    }

  

	// for( int i = 0; i < image.rows; i++ ){ 
	//   	for( int j = 0; j < image.cols; j++ ){ 
	//   		rojo = image.at<cv::Vec3b>(i,j)[2];
	//   		azul = image.at<cv::Vec3b>(i,j)[0];
	//   		verde = image.at<cv::Vec3b>(i,j)[1]; 
	//   		if (azul >= 0 && azul <= 20 
	//   			&& verde >= 10 && verde <= 150
	//   			&& rojo >= 60 && rojo <= 255)
	// 		{
	// 			if (color == 'R'){
	// 				image.at<cv::Vec3b>(i,j) = { 0, 0, rojo};
	// 			}else if(color == 'G'){
	// 				image.at<cv::Vec3b>(i,j) = { 0, verde, 0};
	// 			}else if(color == 'B'){
	// 				image.at<cv::Vec3b>(i,j) = { azul, 0, 0};
	// 			}
	//   		}
	//   	}
	  
	// }

	// comprobaciones....

	namedWindow("Original", 1);
	imshow("Original", image );

	//namedWindow("Blur", 1);
	//imshow("Blur", image_blur );

	int colores;
	cout << "Número de colores de la imagen: " << endl;
	cin >> colores;

	Mat c_reduce = image.clone();

	colorReduce(c_reduce, colores);

	namedWindow("Reducida", 1);
	imshow("Reducida", c_reduce );


 	/// Wait until user press some key
	waitKey(0);

	cout << "Terminado..." << endl;

	return 0;
}

