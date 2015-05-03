#ifdef _CH_
#pragma package <opencv>
#endif

#define CV_NO_BACKWARD_COMPATIBILITY

#ifndef _EiC
#include "cv.h"
#include "highgui.h"
#include <stdio.h>
#include <ctype.h>
#include "cvKernel.h"
#endif

IplImage *preImage = 0, *curImage=0;
IplImage *preImageRaw = 0, *curImageRaw=0;





int show_hist = 1;

CvPoint curPoint, prePoint;


int main( int argc, char** argv )
{
	CvCapture* capture = 0;
	CvScalar frameColor;
	if( argc == 1 || (argc == 2 && strlen(argv[1]) == 1 && isdigit(argv[1][0])))
		capture = cvCaptureFromCAM( argc == 2 ? argv[1][0] - '0' : 0 );
	else if( argc == 2 )
		capture = cvCaptureFromAVI( argv[1] );

	if( !capture )
	{
		fprintf(stderr,"Could not initialize capturing...\n");
		return -1;
	}

	printf( "Hot keys: \n"
		"\tESC - quit the program\n"
		"\th - show/hide object histogram\n"
		"To initialize tracking, select the object with mouse\n" );

	cvNamedWindow( "preImg", 1 );
	cvNamedWindow( "Camera", 1 );
	//cvSetMouseCallback( "Camera", on_mouse, 0 );
	frameColor = cvScalar(0,0,255,0);
	curPoint = cvPoint(0,0);
	for(;;)
	{
		IplImage* frame = 0;
		int i, bin_w, c;

		frame = cvQueryFrame( capture );
		if( !frame )
			break;

		if( !preImage )
		{
			/* allocate all the buffers */
			preImage = cvCreateImage( cvGetSize(frame), 8, 3 );
			preImage->origin = frame->origin;
			curImage = cvCreateImage( cvGetSize(frame), 8, 3 );
			curImage->origin = frame->origin;
			preImageRaw = cvCreateImage( cvGetSize(frame), 8, 3 );
			preImageRaw->origin = frame->origin;
			curImageRaw = cvCreateImage( cvGetSize(frame), 8, 3 );
			curImageRaw->origin = frame->origin;

		}

		cvCopy( frame, curImageRaw, 0 );
		//DoAlpha<diffKernel>(preImageRaw, curImageRaw, curImage);
		//DoFilter<averageFilter>(curImageRaw,curImage);
		DoPixels<Robert>(curImage,curImageRaw);
		//cvCvtColor( frame, curImage, CV_BGR2HSV );


		cvRectangle(frame, cvPoint(curPoint.x -10,curPoint.y-10), cvPoint(curPoint.x+10,curPoint.y+10), frameColor,1,8,0);
		cvShowImage( "Camera", frame );

		cvShowImage( "preImg", curImage );

		c = cvWaitKey(10);
		if( (char) c == 27 )
			break;
		switch( (char) c )
		{
		case 'h':
			show_hist ^= 1;
			if( !show_hist )
				cvDestroyWindow( "preImg" );
			else
				cvNamedWindow( "preImg", 1 );
			break;
		default:
			;
		}
		cvCopy(curImageRaw, preImageRaw, 0);
	}

	cvReleaseCapture( &capture );
	cvDestroyWindow("Camera");

	return 0;
}

#ifdef _EiC
main(1,"camshiftdemo.c");
#endif
