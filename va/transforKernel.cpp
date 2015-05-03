
#include "Kernel.h"

namespace dmFrameSimple{
/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param w
 * @param h
 * @param bytesinLine
 */
void histogramNormalize( char* dataOut, char* dataIn, int w, int h, int bytesinLine)//(IplImage *out, IplImage *in,mKernel func )
{
    int i,j;
    int step;
    //unsigned char *dataIn,*dataOut;
    int h_r[256],h_g[256],h_b[256];
    for(i =0;i< 256; i++){
        h_r[i] = 0;
        h_g[i] = 0;
        h_b[i] = 0;
    }
    step = bytesinLine;  
    for(i = 0;i< h  ;i++){
        for(j =0; j< w ;j++){
            h_r[dataIn P(i,j,step,0)] ++;
            h_g[dataIn P(i,j,step,1)] ++;
            h_b[dataIn P(i,j,step,2)] ++;
        }
    }
    
    for(i =1;i< 256; i++){
        h_r[i] = h_r[i] + h_r[i-1];    
        h_g[i] = h_g[i] + h_g[i-1];
        h_b[i] = h_b[i] + h_b[i-1];
    }

    for(i =1;i< 256; i++){
        h_r[i] = int( float(255 * h_r[i]) /float(h*w) +0.5 );
        h_g[i] = int( float(255 * h_g[i]) /float(h*w) +0.5 );
        h_b[i] = int( float(255 * h_b[i]) /float(h*w) +0.5 );
    }
    
    for(i = 0;i< h  ;i++){
        for(j =0; j< w ;j++){
           dataOut P(i,j,step,0) =  h_r[dataIn P(i,j,step,0)] ;
           dataOut P(i,j,step,1) =   h_g[dataIn P(i,j,step,1)];
           dataOut P(i,j,step,2) =  h_b[dataIn P(i,j,step,2)];
        }
    }
}



/**
 * @brief 
 *            0  0      ;     -1 0
 *       Gx=  -1 1 *A      Gy= 1 0 * A
 *            0  0             0 0
 * @param dataOut
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param sLimit
 */
void dxyOne(char* dataOut, char* dataIn,int row,int col,int step,int sLimit)
{
    float dx = (float)dataInP(row,col+1,step,0) - dataInP(row,col,step,0);
    float dy = (float)dataInP(row,col,step,0)   - dataInP(row-1,col,step,0);
    float dxy = sqrt(dx *dx + dy *dy);
    dataOutP(row,col,step,0) = (int) dxy;

    dx = (float)dataInP(row,col+1,step,1) - dataInP(row,col,step,1);
    dy = (float)dataInP(row,col,step,1)   - dataInP(row-1,col,step,1);
    dxy = sqrt(dx *dx + dy *dy);
    dataOutP(row,col,step,1) = (int) dxy;

    dx = (float)dataInP(row,col+1,step,2) - dataInP(row,col,step,2);
    dy = (float)dataInP(row,col,step,2)   - dataInP(row-1,col,step,2);
    dxy = sqrt(dx *dx + dy *dy);
    dataOutP(row,col,step,2) = (int) dxy;

}

/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param sLimit
 */
void Sobel(char* dataOut, char* dataIn,int row,int col,int step,int sLimit)
{
    float dx, dy, dxy;
    dx =    ((float)dataInP(row-1,col+1,step,0) +2*(float)dataInP(row,col+1,step,0)+ (float)dataInP(row+1,col+1,step,0))
          - ((float)dataInP(row-1,col-1,step,0) +2*(float)dataInP(row,col-1,step,0)+ (float)dataInP(row+1,col-1,step,0));
    dy =    ((float)dataInP(row-1,col-1,step,0) +2*(float)dataInP(row-1,col,step,0)+ (float)dataInP(row-1,col+1,step,0))
          - ((float)dataInP(row+1,col-1,step,0) +2*(float)dataInP(row+1,col,step,0)+ (float)dataInP(row+1,col+1,step,0));
    dxy = sqrt(dx *dx/16+ dy *dy/16);
    dataOutP(row,col,step,0) = (int) dxy;

    dx =    ((float)dataInP(row-1,col+1,step,1) +2*(float)dataInP(row,col+1,step,1)+ (float)dataInP(row+1,col+1,step,1))
          - ((float)dataInP(row-1,col-1,step,1) +2*(float)dataInP(row,col-1,step,1)+ (float)dataInP(row+1,col-1,step,1));
    dy =    ((float)dataInP(row-1,col-1,step,1) +2*(float)dataInP(row-1,col,step,1)+ (float)dataInP(row-1,col+1,step,1))
          - ((float)dataInP(row+1,col-1,step,1) +2*(float)dataInP(row+1,col,step,1)+ (float)dataInP(row+1,col+1,step,1));
    dxy = sqrt(dx *dx/16+ dy *dy/16);
    dataOutP(row,col,step,1) = (int) dxy;

    dx =    ((float)dataInP(row-1,col+1,step,2) +2*(float)dataInP(row,col+1,step,2)+ (float)dataInP(row+1,col+1,step,2))
          - ((float)dataInP(row-1,col-1,step,2) +2*(float)dataInP(row,col-1,step,2)+ (float)dataInP(row+1,col-1,step,2));
    dy =    ((float)dataInP(row-1,col-1,step,2) +2*(float)dataInP(row-1,col,step,2)+ (float)dataInP(row-1,col+1,step,2))
          - ((float)dataInP(row+1,col-1,step,2) +2*(float)dataInP(row+1,col,step,2)+ (float)dataInP(row+1,col+1,step,2));
    dxy = sqrt(dx *dx/16+ dy *dy/16);
    dataOutP(row,col,step,2) = (int) dxy;

}


/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param sLimit
 */
void Robert(char* dataOut, char* dataIn,int row,int col,int step,int sLimit)
{
    float dx = (float)dataInP(row,col,step,0) - dataInP(row+1,col+1,step,0);
    float dy = (float)dataInP(row,col+1,step,0)   - dataInP(row+1,col,step,0);
    float dxy = sqrt(dx *dx + dy *dy);
    dataOutP(row,col,step,0) = (int) dxy;

    dx = (float)dataInP(row,col,step,1) - dataInP(row+1,col+1,step,1);
    dy = (float)dataInP(row,col+1,step,1)   - dataInP(row+1,col,step,1);
    dxy = sqrt(dx *dx + dy *dy);
    dataOutP(row,col,step,1) = (int) dxy;

    dx = (float)dataInP(row,col,step,2) - dataInP(row+1,col+1,step,2);
    dy = (float)dataInP(row,col+1,step,2)   - dataInP(row+1,col,step,2);
    dxy = sqrt(dx *dx + dy *dy);
    dataOutP(row,col,step,2) = (int) dxy;

}

/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param sLimit
 */
void Prewitt(char* dataOut, char* dataIn,int row,int col,int step,int sLimit)
{
    float dx,dy,dxy;
    dx =    ((float)dataInP(row-1,col+1,step,0) + (float)dataInP(row,col+1,step,0) + (float)dataInP(row+1,col+1,step,0))
          - ((float)dataInP(row-1,col-1,step,0) + (float)dataInP(row,col-1,step,0) + (float)dataInP(row+1,col-1,step,0));
    dy =    ((float)dataInP(row-1,col-1,step,0) + (float)dataInP(row-1,col,step,0) + (float)dataInP(row-1,col+1,step,0))
          - ((float)dataInP(row+1,col-1,step,0) + (float)dataInP(row+1,col,step,0) + (float)dataInP(row+1,col+1,step,0));
    dxy = sqrt(dx *dx/9 + dy *dy/9);
    dataOutP(row,col,step,0) = (int) dxy;

    dx =    ((float)dataInP(row-1,col+1,step,1) + (float)dataInP(row,col+1,step,1) + (float)dataInP(row+1,col+1,step,1))
          - ((float)dataInP(row-1,col-1,step,1) + (float)dataInP(row,col-1,step,1) + (float)dataInP(row+1,col-1,step,1));
    dy =    ((float)dataInP(row-1,col-1,step,1) + (float)dataInP(row-1,col,step,1) + (float)dataInP(row-1,col+1,step,1))
          - ((float)dataInP(row+1,col-1,step,1) + (float)dataInP(row+1,col,step,1) + (float)dataInP(row+1,col+1,step,1));
    dxy = sqrt(dx *dx/9 + dy *dy/9);
    dataOutP(row,col,step,1) = (int) dxy;

    dx =    ((float)dataInP(row-1,col+1,step,2) + (float)dataInP(row,col+1,step,2) + (float)dataInP(row+1,col+1,step,2))
          - ((float)dataInP(row-1,col-1,step,2) + (float)dataInP(row,col-1,step,2) + (float)dataInP(row+1,col-1,step,2));
    dy =    ((float)dataInP(row-1,col-1,step,2) + (float)dataInP(row-1,col,step,2) + (float)dataInP(row-1,col+1,step,2))
          - ((float)dataInP(row+1,col-1,step,2) + (float)dataInP(row+1,col,step,2) + (float)dataInP(row+1,col+1,step,2));
    dxy = sqrt(dx *dx/9 + dy *dy/9);
    dxy  = dxy<20.0?0:dxy;
    dataOutP(row,col,step,2) = (int) dxy;

}

/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param sLimit
 */
void LapLas(char* dataOut, char* dataIn,int row,int col,int step,int sLimit)
{
    float dxy = (4 *  (float)dataInP(row,col,step,0)  
                -    (float)dataInP(row-1,col,step,0)
                -    (float)dataInP(row,col-1,step,0)
                -    (float)dataInP(row,col+1,step,0)
                -    (float)dataInP(row+1,col,step,0));
    dxy = dxy /4;
    dataOutP(row,col,step,0) = (int) dxy;

    dxy = 4 *  (float)dataInP(row,col,step,1)  
                -    (float)dataInP(row-1,col,step,1)
                -    (float)dataInP(row,col-1,step,1)
                -    (float)dataInP(row,col+1,step,1)
                -    (float)dataInP(row+1,col,step,1);
    dxy = dxy /4;
    dataOutP(row,col,step,1) = (int) dxy;

    dxy = 4 *  (float)dataInP(row,col,step,2)  
                -    (float)dataInP(row-1,col,step,2)
                -    (float)dataInP(row,col-1,step,2)
                -    (float)dataInP(row,col+1,step,2)
                -    (float)dataInP(row+1,col,step,2);
    dxy = dxy /4;
    dataOutP(row,col,step,2) = (int) dxy;

}

/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param sLimit
 */
void FreiChen(char* dataOut, char* dataIn,int row,int col,int step,int sLimit)
{
    float dx,dy,dxy;
    for(int rgb = 0;rgb < 3;rgb++){
        dx = ((float)dataInP(row-1,col-1,step,rgb) + SQRTTWO*(float)dataInP(row,col-1,step,rgb) + (float)dataInP(row+1,col-1,step,rgb) -
            ((float)dataInP(row-1,col+1,step,rgb) + SQRTTWO*(float)dataInP(row,col+1,step,rgb) + (float)dataInP(row+1,col+1,step,rgb))) / (2 + SQRTTWO);
        dy = ( (float)dataInP(row+1,col-1,step,rgb) + SQRTTWO*(float)dataInP(row+1,col,step,rgb) + (float)dataInP(row+1,col+1,step,rgb) -
             ( (float)dataInP(row-1,col-1,step,rgb) + SQRTTWO*(float)dataInP(row-1,col,step,rgb) + (float)dataInP(row-1,col+1,step,rgb))) / (2 + SQRTTWO);
        dxy = sqrt(dx * dx + dy * dy);
        dataOutP(row,col,step,rgb) = (int) dxy;
    } 
}

/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param sLimit
 */
void CopyFrame(char* dataOut, char* dataIn,int row,int col,int step,int sLimit)
{
    float dx,dy,dxy;
    for(int rgb = 0;rgb < 3;rgb++){
        dataOutP(row,col,step,rgb) =dataInP(row,col,step,rgb);
    } 
}

 
} 
