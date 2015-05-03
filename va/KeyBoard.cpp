
#include "cvKernel.h"
#define MAX_FNAME_LEN       255
int VIEDOW =  720;
int VIEDOH = 480;

#define SAFE_RELEASE(pImage) if(pImage !=0) { cvReleaseImage(&pImage); }



const int POOLSIZE =  8;
const int nFrame_in_pool=3;

IplImage* pImagePool[POOLSIZE] ;    

IplImage* pFrames[nFrame_in_pool];

int whichKernel = 7;


void Detect(IplImage *out,IplImage *in,mKernel func = dxyOne)
{
	int i,j;
	int w;
	int h;
	int step;
	char *dataIn,*dataOut;
	w = in ->width;
	h = in ->height;
	dataIn = in->imageData;
	dataOut = out->imageData;
	step = in ->widthStep;
	for(i = 1;i< h -1 ;i++){
		for(j =1; j< w-1 ;j++){
			func (dataOut,dataIn,i,j,step,0);           
		}
	}

}

int tmpFK[9] = {1,1,1,
1,1,1,
1,1,1};
void Filter(IplImage *out,IplImage *in,fKernel func = fandFilter)
{
	int i,j;
	int w;
	int h;
	int step;
	char *dataIn,*dataOut;
	w = in ->width;
	h = in ->height;
	dataIn = in->imageData;
	dataOut = out->imageData;
	step = in ->widthStep;
	for(i = 1;i< h -1 ;i++){
		for(j =1; j< w-1 ;j++){
			func (dataOut,dataIn,i,j,step,tmpFK,3,3);           
		}
	}

}

void preProcess(IplImage *prv,IplImage *cur,IplImage *nxt,IplImage *wrt)
{    

	// 
	//cvSub(cur,prv,pImagePool[0]);
	//Detect(pImagePool[0],wrt,Robert);
	switch ( whichKernel)
	{
	case 0:
		// diff two img
		cvSub(cur,prv,wrt);
		break;
	case 1:
		Detect(wrt, cur,Robert);
		break;
	case 2:
		Detect(wrt, cur,Prewitt);
		break;
	case 3:
		Detect(wrt, cur,LapLas);
		break;
	case 4:
		histogramNormalize(wrt, cur);
		break;
	case 5:
		histogramNormalize(pImagePool[0], cur);
		Detect(wrt,pImagePool[0],Prewitt);
		break;
	case 6:
		{
			imgDFT(wrt, cur);
		}
		break;
	case 7:
		{
			Detect(wrt, cur,FreiChen);
			break;
		}
	case 8:
		{
			Filter(wrt, cur);
			break;
		}
	case 9:
		{

			transRGB2Gray( pImagePool[0], cur);
			Filter(wrt, pImagePool[0],averageFilter);

		}
	default:
		break;
	}

}

int ProcessVideo(int argc,char** argv) {

	char fn_in[MAX_FNAME_LEN] = {0};
	char fn_tmp[MAX_FNAME_LEN] = {0};
	int i = 0;
	if(argc ==3){
		strcpy(fn_in,argv[1]);
		strcpy(fn_tmp,argv[2]);
		//whichKernel = 7;
	}else if(argc ==4){
		strcpy(fn_in,argv[1]);
		strcpy(fn_tmp,argv[2]);
		whichKernel = atoi(argv[3]);
	}else{
		strcpy(fn_in,"test.avi");
		strcpy(fn_tmp,"out.avi");
		/*	exit(0);*/
	}

	CvCapture* pCapture01 = cvCreateFileCapture/*cvCaptureFromFile*/( fn_in );


	if ( 0 == ( pCapture01  ) ) {
		//printf("%s %s %s",argv[0],argv[1],argv[2]);
		printf("can't create the CvCapture object.pls check the input fname or the codec\n");
		return -1;
	}

	IplImage* pImageTmp = 0;    
	pImageTmp = cvQueryFrame( pCapture01 );
	VIEDOW = pImageTmp ->width;
	VIEDOH = pImageTmp ->height;
	/*
	CV_FOURCC('P','I','M','1') = MPEG-1 codec
	CV_FOURCC('M','J','P','G') = motion-jpeg codec
	CV_FOURCC('M', 'P', '4', '2') = MPEG-4.2 codec
	CV_FOURCC('D', 'I', 'V', '3') = MPEG-4.3 codec
	CV_FOURCC('D', 'I', 'V', 'X') = MPEG-4 codec
	CV_FOURCC('U', '2', '6', '3') = H263 codec
	CV_FOURCC('I', '2', '6', '3') = H263I codec
	CV_FOURCC('F', 'L', 'V', '1') = FLV1 codec
	*/
	CvSize ImageSize = cvSize(VIEDOW,VIEDOH);
	CvVideoWriter* videoWt = cvCreateVideoWriter(  fn_tmp,CV_FOURCC('D', 'I', 'V', 'X') /*-1*/, 30, ImageSize ); //raise a dialog to choose the codec
	if(videoWt == 0) {
		printf("error create video writer\n");
		return 0;
	}

	IplImage* pImageTransform =  cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 ); 
	for(int i=0;i<POOLSIZE;i++){
		pImagePool[i] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 ); 
	}
	pImageTransform->origin = 1;  //when reading from video, windows bmp coordinate. 0,0 is the bottom, left.
	//pImageTransform->origin = 0;  //when reading from image, windows bmp coordinate. 0,0 is the bottom, left.
	IplImage* pImage[3];
	int Prv = 0, Cur = 1, Nxt =2;
	pImage[Prv] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 );
	pImage[Cur] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 );
	pImage[Nxt] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 );

	cvCopy(pImageTmp,pImage[Prv]);
	pImageTmp = cvQueryFrame( pCapture01 );  
	cvCopy(pImageTmp,pImage[Cur]);
	pImageTmp = cvQueryFrame( pCapture01 );  
	cvCopy(pImageTmp,pImage[Nxt]);

	long fno = 0;
	while(1)
	{
		pImageTmp = cvQueryFrame( pCapture01 ); 
		//printf("channel:%d ; depth:%d\n",pImageTmp->nChannels,pImageTmp->depth);
		//continue;
		Prv = (Prv + 1) % 3;
		Cur = (Cur + 1) % 3;
		Nxt = (Nxt + 1) % 3;


		if( pImageTmp != 0/*(0 != pImage[Prv]) && (0 != pImage[Cur]) && (0 != pImage[Nxt])*/ ){
			cvCopy(pImageTmp,pImage[Nxt]);
			preProcess(pImage[Prv],pImage[Cur],pImage[Nxt],pImageTransform);
			int wr_recd = cvWriteFrame( videoWt, pImageTransform);  
			fno++;
			printf(".");
		}
		else
		{
			break;
		}
		//SAFE_RELEASE(pImageTmp);
	}


	printf("\ntotoal process %d frames\n", fno);
	cvReleaseVideoWriter(&videoWt);
	cvReleaseCapture(&pCapture01);
	SAFE_RELEASE(pImage[Prv]);
	SAFE_RELEASE(pImage[Cur]);
	SAFE_RELEASE(pImage[Nxt]);
	SAFE_RELEASE(pImageTransform);
	return 0;
}


int TransVideo(int argc,char** argv) {


	char fn_in[MAX_FNAME_LEN] = {0};
	char fn_tmp[MAX_FNAME_LEN] = {0};
	int i = 0;




	if(argc ==3){
		strcpy(fn_in,argv[1]);
		strcpy(fn_tmp,argv[2]);
		//whichKernel = 7;
	}else if(argc ==4){
		strcpy(fn_in,argv[1]);
		strcpy(fn_tmp,argv[2]);
		whichKernel = atoi(argv[3]);
	}else{
		exit(0);
	}

	IplImage * pImgIn;
	pImgIn = cvLoadImage( "pattern.BMP",-1);
	studyFromRGBimg( pImgIn);

	CvCapture* pCapture01 = cvCreateFileCapture /*cvCaptureFromFile*/( fn_in );


	if ( 0 == ( pCapture01  ) ) {
		printf("%s %s %s",argv[0],argv[1],argv[2]);
		printf("can't create the CvCapture object.pls check the input fname or the codec\n");
		return -1;
	}

	IplImage* pImageTmp = 0;    
	pImageTmp = cvQueryFrame( pCapture01 );
	VIEDOW = pImageTmp ->width;
	VIEDOH = pImageTmp ->height;

	CvSize ImageSize = cvSize(VIEDOW,VIEDOH);
	CvVideoWriter* videoWt = cvCreateVideoWriter(  fn_tmp, -1, 30, ImageSize ); //raise a dialog to choose the codec
	if(videoWt == 0) {
		printf("error create video writer\n");
		return 0;
	}

	IplImage* pImageTransform =  cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 ); 
	for(int i=0;i<POOLSIZE;i++){
		pImagePool[i] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 ); 
	}
	pImageTransform->origin = 1;  //when reading from video, windows bmp coordinate. 0,0 is the bottom, left.
	//pImageTransform->origin = 0;  //when reading from image, windows bmp coordinate. 0,0 is the bottom, left.


	long fno = 0;
	while(1)
	{
		pImageTmp = cvQueryFrame( pCapture01 ); 
		//printf("channel:%d ; depth:%d\n",pImageTmp->nChannels,pImageTmp->depth);
		if( pImageTmp != 0/*(0 != pImage[Prv]) && (0 != pImage[Cur]) && (0 != pImage[Nxt])*/ ){
			transGray2RGB(pImageTransform, pImageTmp);           
			int wr_recd = cvWriteFrame( videoWt, pImageTransform);  
			fno++;
			printf(".");
		}
		else
		{
			break;
		}
	}

	cvReleaseVideoWriter(&videoWt);
	printf("\ntotoal process %d frames\n", fno);
	//
	cvReleaseCapture(&pCapture01);

	SAFE_RELEASE(pImageTransform);
	//SAFE_RELEASE(pImageTmp);

	return 0;
}

int ProcessImg(int argc,char** argv) {


	char fn_in[MAX_FNAME_LEN] = {0};
	char fn_out[MAX_FNAME_LEN] = {0};
	int i = 0;
	IplImage * pImgIn, *pImgOut;
	if(argc ==3){
		strcpy(fn_in,argv[1]);
		strcpy(fn_out,argv[2]);
		//whichKernel = 7;
	}else if(argc ==4){
		strcpy(fn_in,argv[1]);
		strcpy(fn_out,argv[2]);
		whichKernel = atoi(argv[3]);
	}else{
		exit(0);
	}

	pImgIn = cvLoadImage( fn_in,-1);

	VIEDOW = pImgIn ->width;
	VIEDOH = pImgIn ->height;

	CvSize ImageSize = cvSize(VIEDOW,VIEDOH);
	pImgOut = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 ); 
	pImagePool[0] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 ); 
	preProcess(0,pImgIn,0,pImgOut);

	cvSaveImage(fn_out,pImgOut);
	return 0;
}


int main(int argc,char** argv) {
	ProcessVideo(argc,argv);
	//TransVideo (argc,argv);
	//ProcessImg(argc,argv);
}
