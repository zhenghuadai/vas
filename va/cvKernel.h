#ifndef __TRANSFORM_CVKERNEL__HEADER__
#define __TRANSFORM_CVKERNEL__HEADER__
#include "Kernel.h"
#include "cv.h"
#include "highgui.h"
#include "Kernel.hxx"
namespace dmFrameSimple{
#if defined(__GNUC__)
# define DEFAULT_ARG(x) 
#elif defined(_MSC_VER)
# define DEFAULT_ARG(x) 
#endif
void cvSubWrapper(const IplImage * src1, const IplImage * src2, IplImage * dst, IplImage * mask);
void Detect(IplImage *out,IplImage *in,mKernel func = dxyOne);
void Filter(IplImage *out,IplImage *in,fKernel func = fandFilter);
inline void histogramNormalize(IplImage *out, IplImage *in,mKernel func = 0);
void imgDFT(IplImage *out, IplImage *in,mKernel func = 0);


inline void studyFromRGBimg( IplImage *in){
	studyFromRGBimg(in->imageData, in->width, in->height, in->widthStep);
}

inline void transGray2RGB( IplImage *out, IplImage *in){
	transGray2RGB(out->imageData, in->imageData, in->width, in->height, in->widthStep);
}

inline void transGray2RGB_2( IplImage *out, IplImage *in){
	transGray2RGB_2(out->imageData, in->imageData, in->width, in->height, in->widthStep);
}

inline void transRGB2Gray( IplImage *out, IplImage *in){
	transRGB2Gray(out->imageData, in->imageData, in->width, in->height, in->widthStep);
}


inline void histogramNormalize(IplImage *out, IplImage *in,mKernel func )
{
	histogramNormalize(out->imageData, in->imageData, in->width, in->height, in->widthStep);
}

template<alphaKernel func>
void DoAlpha(IplImage *image1, IplImage* image2, IplImage *imageOut)
{
 
	DoAlpha<func>( image1->imageData, image2->imageData, imageOut->imageData,
		image1->width, image1->height, image1->widthStep,0);

}

template<mKernel func/*= dxyOne*/>
void DoPixels(IplImage *image1, IplImage* image2,int sLimit=0)
{
    int i,j;      
	DoPixels<func>(image1->imageData, image2->imageData, image1->width, image1->height, image1->widthStep, sLimit);           
  

}

template<fKernel func /*= fandFilter*/>
void DoFilter(IplImage *image1, IplImage* image2,int* KernelArray=globalFK,int mrows=3,int ncols=3 )
{
	DoFilter<func>(image1->imageData, image2->imageData,image1->width, image1->height, image1->widthStep,KernelArray,mrows,ncols);
}

#define CUTSIZE 300
inline void imgDFTChannel(CvMat *s, CvMat *d,float *sdata,float *ddata,char *dataIn,char * dataOut,int w,int h,int step,int rgb)
{
    int i,j;
    for(i = 0;i< h  ;i++){
        for(j =0; j< w ;j++){
            sdata S(i,j,w,0) = float ( dataIn P(i,j,step,rgb));
        }
    }
    cvDFT(s,d,CV_DXT_FORWARD);
    for(i =0;i<CUTSIZE;i++)
        for(j = CUTSIZE ;j<w;j++)
            ddata S(i,j,w,0) = 0.0;

    for(i = CUTSIZE; i<h ; i++){
        for(j =0;j<w;j++){
            ddata S(i,j,w,0) = 0.0;
        }
    }

    cvDFT(d,s,CV_DXT_INVERSE);

    for(i = 0;i< h  ;i++){
        for(j =0; j< w ;j++){
            float t = (sdata S(i,j,w,0) +1.0) / (w *h) ;
            dataOut P(i,j,step,rgb) = (int) t;            
        }
    }
}
inline void imgDFT(IplImage *out, IplImage *in,mKernel func )
{
    int w;
    int h;
    int step;
    char *dataIn,*dataOut;
    CvMat *s,*d;
    w = in ->width;
    h = in ->height;
    dataIn = in->imageData;
    dataOut = out->imageData;
    step = in ->widthStep;
    s = cvCreateMat(h,w,CV_32FC1);
    d = cvCreateMat(h,w,CV_32FC1);
    float *sdata,*ddata;
    sdata = s->data.fl;
    ddata = d->data.fl;
    int rgb = 0;
    imgDFTChannel(s,d,sdata,ddata,dataIn,dataOut,w,h,step,0);
    imgDFTChannel(s,d,sdata,ddata,dataIn,dataOut,w,h,step,1);
    imgDFTChannel(s,d,sdata,ddata,dataIn,dataOut,w,h,step,2);
 
}

}//end namespace dmFrameSimple
#endif
