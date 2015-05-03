
#include "cvKernel.h"
#include "vacg.h"
#include "parserdriver.h"
#define MAX_FNAME_LEN       255
int VIEDOW =  720;
int VIEDOH = 480;

#define SAFE_RELEASE(pImage) if(pImage !=0) { cvReleaseImage(&pImage); }

typedef void (*frameKernel_t)();
static int whichKernel = 0;
frameKernel_t f ;


//void Detect(IplImage *out,IplImage *in,mKernel func = dxyOne);
//void Filter(IplImage *out,IplImage *in,fKernel func = fandFilter);

void processFrame()
{	
	f();
}

void preProcess(IplImage *prv,IplImage *cur,IplImage *nxt,IplImage *wrt)
{    

	switch ( whichKernel)
	{
	case 0:{
		// diff two img
		//eabcdm();
		//f();
		cvSub(cur,prv,wrt);
		//_asm{
		//	push 0;
		//	mov eax, wrt;
		//	push eax;
		//	mov eax, prv;
		//	push eax;
		//	mov eax,cur;
		//	push eax;
		//	call cvSub;
		//	add  esp,10h
		//}
		break;
		   }
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


int ProcessVideo() {

	int i = 0;
	int c;
    CvCapture* pCapture01 = NULL;
    CvVideoWriter* videoWt = NULL; 

    if(gVideoIn == NULL) gVideoIn = strdup("in.avi");

    if( strcmp(gVideoIn, "cam")){
        //CvCapture* pCapture01 =  cvCaptureFromFile( fn_in );
        pCapture01 = cvCreateFileCapture/*cvCaptureFromFile*//*cvCaptureFromAVI*/( gVideoIn);
        //CvCapture* pCapture01 = cvCreateFileCapture/*cvCaptureFromFile*//*cvCaptureFromAVI*/( fn_in );
    }else{
        pCapture01 =  cvCaptureFromCAM( 0);
    }


	if ( 0 == ( pCapture01  ) ) {
		//printf("%s %s %s",argv[0],argv[1],argv[2]);
		printf("can't create the CvCapture object.pls check the input fname(%s) or the codec\n", gVideoIn);
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
    if((gVideoOut !=NULL) && ( strcmp(gVideoOut, "stdout"))){
        videoWt = cvCreateVideoWriter(  gVideoOut, CV_FOURCC('D', 'I', 'V', 'X') /*-1*/, 30, ImageSize ); //raise a dialog to choose the codec
        if(videoWt == 0) {
            printf("error create video writer\n");
            return 0;
        }
    }

	oFrame =  cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 ); 
	for(int i=0;i<POOLSIZE;i++){
		pImagePool[i] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 ); 
	}
	//oFrame->origin = 1;  //when reading from video, windows bmp coordinate. 0,0 is the bottom, left.
	oFrame->origin = 0;  //when reading from image, windows bmp coordinate. 0,0 is the bottom, left.

    for(int i=0;i<nFrame_in_pool; i++){
        pFrames[i] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 );
    }
//	pFrames[Prv] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 );
//	pFrames[Cur] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 );
//	pFrames[Nxt] = cvCreateImage( ImageSize , IPL_DEPTH_8U, 3 );

	cvCopy(pImageTmp,pFrames[0]);
    for(i = 1; i<nFrame_in_pool/ 2; i++){
        pImageTmp = cvQueryFrame( pCapture01 );  
        cvCopy(pImageTmp,pFrames[i]);
    }
//	pImageTmp = cvQueryFrame( pCapture01 );  
//	cvCopy(pImageTmp,pFrames[Cur]);
//	pImageTmp = cvQueryFrame( pCapture01 );  
//	cvCopy(pImageTmp,pFrames[Nxt]);
    if(!videoWt)
        cvNamedWindow("Object", 1);
	long fno = 0;
#define INDEX_IN_FRAMEPOOL(idx) ((idx) &(nFrame_in_pool -1))
    Prv = nFrame_in_pool -1;
    Cur = 0;
    Nxt = 1;
	while(1)
	{
		pImageTmp = cvQueryFrame( pCapture01 ); 


		if( pImageTmp != 0/*(0 != pFrames[Prv]) && (0 != pFrames[Cur]) && (0 != pFrames[Nxt])*/ ){
			cvCopy(pImageTmp,pFrames[INDEX_IN_FRAMEPOOL(Cur+nFrame_in_pool/2)]);
			//preProcess(pFrames[Prv],pFrames[Cur],pFrames[Nxt],oFrame);
			processFrame();
            if(videoWt){
                int wr_recd = cvWriteFrame( videoWt, oFrame);  
                fprintf(stdout, ".");
                fflush(stdout);
            }else{
                cvShowImage( "Object", oFrame  );
                fprintf(stdout, ".");
                fflush(stdout);
                c = cvWaitKey(10);
            }
			fno++;
		}
		else
		{
			break;
		}
 		Prv = (Prv + 1) & (nFrame_in_pool -1);
		Cur = (Cur + 1) & (nFrame_in_pool -1);
		Nxt = (Nxt + 1) & (nFrame_in_pool -1);
		/*if(fno>30) break;*/
		//SAFE_RELEASE(pImageTmp);
	}

	//cvWaitKey(0);
	printf("\ntotoal process %d frames\n", fno);
    if(videoWt)
        cvReleaseVideoWriter(&videoWt);
	cvReleaseCapture(&pCapture01);
    for(int i=0;i<nFrame_in_pool; i++){
        SAFE_RELEASE(pFrames[i]);
    }
//	SAFE_RELEASE(pFrames[Prv]);
//	SAFE_RELEASE(pFrames[Cur]);
//	SAFE_RELEASE(pFrames[Nxt]);
	SAFE_RELEASE(oFrame);
	return 0;
}



void testvas()
{
	char* str1= "oframe = 2; oframe=frame*sobel;oframe=frame; oframe = frame - frame[-1];";
	char* str2= "oframe=frame*sobel;";
	char* fn="main.cpp";
	vasParserDriver myparser;
	gvacg.init();
	myparser.parse(str2);

	printf("number of AstNodes:%d\n", numAstNode);
	programGraph->dumpAst(stdout);
	printf("dump end.\n");
	gvacg.init();
	printf("Generate code ...\n");
	programGraph->codeGen();

	f=(frameKernel_t) (gvacg.getf0());
	printf("Generate code End.\n");
}

int main(int argc,char** argv) {
	//testvas();
    gArgc = argc;
    gArgv = argv;
    if(argc > 1)
        f = (frameKernel_t)compile_file(argv[1]);
    else
        f = (frameKernel_t)compile_str();
	ProcessVideo();
	release_function((void*&)f);
    if(gVideoIn) free(gVideoIn); 
    if(gVideoOut) free(gVideoOut); 
}
