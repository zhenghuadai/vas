#ifndef __TRANSFORM_KERNEL__HEADER__
#define __TRANSFORM_KERNEL__HEADER__
#include "stdio.h"
#include "string.h"

#include "math.h"
#define SQRTTWO 1.14
#define M_PI       3.14159265358979323846
namespace dmFrameSimple{
typedef struct {
    unsigned char R;
    unsigned char G;
    unsigned char B;
}RGB24_t;

typedef struct{
	int width;
	int height;
}cvSize_t;

/**
 * @brief predefined filter kernel 
 *
 * @param dataOut 
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param sLimit
 *
 * @return 
 */
#define mKernelArg      (char* dataOut, char* dataIn,int row,int col,int step,int sLimit=0)
typedef void (* mKernel)(char* dataOut, char* dataIn,int row,int col,int step,int sLimit);

/**
 * @brief filter kernel 
 *
 * @param dataOut 
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param KernelArray
 * @param mrows
 * @param ncols
 *
 * @return 
 */
#define fKernelArg      (char* dataOut, char* dataIn,int row,int col,int step,int* KernelArray,int mrows,int ncols )
typedef void (* fKernel)(char* dataOut, char* dataIn,int row,int col,int step,int* KernelArray,int mrows,int ncols );

/**
 * @brief alpha mixture 
 *
 * @param out 
 * @param in1
 * @param int2
 *
 * @return 
 */
typedef  void (* alphaKernel)(char* out, char* in1, char* in2);

#define P(row,col,stepPerLine,rgb) [(row)*(stepPerLine) + (3*col) + (rgb)]
#define S(row,col,stepPerLine,rgb) [(row)*(stepPerLine) + (col)]

#define dataOutP(row,col,step,rgb) dataOut[(row)*(step) + (3*col) + (rgb)]
#define dataInP(row,col,step,rgb) dataIn P(row,col,step,rgb)
inline int flatidx( int row, int col, int step, int rgb)  {return((row)*(step) + (3*col) + (rgb));}
inline int flatpixel( int row, int col, int step, int rgb){return((row)*(step) + (col) );}
// edge detecting 
void dxyOne   mKernelArg;
void Sobel    mKernelArg;
void Robert   mKernelArg;
void Prewitt  mKernelArg;
void LapLas   mKernelArg;
void FreiChen mKernelArg;
void CopyFrame mKernelArg;

// wave filtering
void fandFilter fKernelArg;
void averageFilter (char *dataIn,char *dataOut,int row,int col,int step,int* KernelArray,int m,int n );

void studyFromRGBimg( char* dataIn, int w, int h, int bytesinLine);
void transGray2RGB(char* dataOut, char* dataIn, int w, int h, int bytesinLine);
void transGray2RGB_2(char* dataOut, char* dataIn, int w, int h, int bytesinLine);
void transRGB2Gray(char* dataOut, char* dataIn, int w, int h, int bytesinLine);
void histogramNormalize(char* dataOut, char* dataIn, int w, int h, int bytesinLine);
void setDefaultSize(int width, int col, int step);

}
#endif
