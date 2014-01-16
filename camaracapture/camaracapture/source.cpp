#include"opencv2/highgui/highgui.hpp"
#include<iostream>

using namespace std;
using namespace cv;


void cameraView(){
		CvCapture* capture;	
		capture = cvCaptureFromCAM(0);
		if (!capture)
		{		
			cout << "Camera couldn't be opened.";
			int c = cvWaitKey(5000);	
			return;
		}

		cvNamedWindow("Camera", CV_WINDOW_AUTOSIZE);
		IplImage* frame;
		while (true)
		{
			//Read the video stream		
			frame = cvQueryFrame( capture );		

			// display frame
			cvShowImage("Camera", frame);

			int c = cvWaitKey(5);
			if( (char)c == 27 ) { 
				// release resource
				cvReleaseImage(&frame);	
				exit(0); 
			}
		}
	}
int main()
{
	cameraView();


}