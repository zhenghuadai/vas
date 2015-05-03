
#include "cvKernel.h"
#include "vacg.h"
#define MAX_FNAME_LEN       255

#define SAFE_RELEASE(pImage) if(pImage !=0) { cvReleaseImage(&pImage); }
namespace dmFrameSimple{

typedef void (*frameKernel_t)();
static int whichKernel = 0;

void cvSubWrapper(const IplImage * src1, const IplImage * src2, IplImage * dst , IplImage * mask)
{
	cvSub(src1, src2, dst );
}

IplImage* getFrame(int nid)
{
	int i = (nid + Cur) % nFrame_in_pool;
	if( i <0 ) i += nFrame_in_pool;
	return (pFrames[i]);
}




void Detect(IplImage *out,IplImage *in,mKernel func  DEFAULT_ARG(dxyOne))
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
void Filter(IplImage *out,IplImage *in,fKernel func DEFAULT_ARG(fandFilter))
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
}
