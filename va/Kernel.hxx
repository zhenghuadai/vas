#ifndef __TRANSFORM_KERNEL_TEMPLATE_HEADER__ 
#define __TRANSFORM_KERNEL_TEMPLATE_HEADER__

#include "Kernel.h"
namespace dmFrameSimple{

extern size_t gHeight;
extern size_t gWidth;
extern size_t gBytesinLine;

/**
 * @brief 
 *
 * @param width
 * @param height
 * @param step
 */
inline void setDefaultSize(int width, int height, int step)
{
    gHeight=height;
    gWidth=width;
    gBytesinLine=step;
}

/**
 * @brief Do predefined filter 
 *
 * @param dataOut
 * @param dataIn
 * @param width
 * @param height
 * @param step
 * @param sLimit
 */
    template<mKernel func/*= dxyOne*/>
void DoPixels(char *dataOut, char *dataIn,int width=gWidth,int height=gHeight,int step= gBytesinLine,int sLimit=0)
{
    int i,j; 
    for(i = 1;i< height -1 ;i++){
        for(j =1; j< width-1 ;j++){
            func (dataOut,dataIn,i,j,step,0);           
        } 
    }

}

static int globalFK[9] = {
    1,1,1,
    1,1,1,
    1,1,1};

/**
 * @brief Do filter 
 *
 * @param dataOut
 * @param dataIn
 * @param width
 * @param height
 * @param step
 * @param KernelArray
 * @param mrows
 * @param ncols
 */
    template<fKernel func /*= fandFilter*/>
void DoFilter(char *dataOut, char *dataIn, int width=gWidth,int height=gHeight,int step= gBytesinLine,int* KernelArray=globalFK,int mrows=3,int ncols=3 )
{
    int i,j;

    for(i = 1;i< height -1 ;i++){
        for(j =1; j< width-1 ;j++){
            func (dataOut,dataIn,i,j,step,KernelArray,3,3);           
        }
    }

}



inline void diffKernel(char* dataout, char* dataIn1, char* dataIn2)
{
    dataout[0] = dataIn1[0] - dataIn2[0];
    dataout[1] = dataIn1[1] - dataIn2[1];
    dataout[2] = dataIn1[2] - dataIn2[2];
}

    template<alphaKernel func/*= diffKernel*/>
void DoAlpha( char *dataOut, char *dataIn1, char* dataIn2,int width=gWidth, int height=gHeight,int step= gBytesinLine,int sLimit=0)
{
    int i,j; 
    for(i = 1;i< height -1 ;i++){
        for(j =1; j< width-1 ;j++){
            func (& dataOut P(i,j,step,0), & dataIn1 P(i,j,step,0), & dataIn2 P(i,j,step,0)) ;           
        } 
    }

}


}
#endif 
