#include "Kernel.h"
namespace dmFrameSimple{

/*
[Y] [0.299   0.587   0.114]  [R]
[I]=[0.596  -0.274  -0.322] *[G] 
[Q] [0.212  -0.523   0.311]  [B] 
*/

/**
  From RGB to YUV
  Y = 0.299R + 0.587G + 0.114B
  U = 0.492 (B-Y)
  V = 0.877 (R-Y)
  It can also be represented as:
  Y =  0.299R + 0.587G + 0.114B
  U = -0.147R - 0.289G + 0.436B
  V =  0.615R - 0.515G - 0.100B
  From YUV to RGB
  R = Y + 1.140V
  G = Y - 0.395U - 0.581V
  B = Y + 2.032U
  */
typedef struct _gray2rgb_t
{    
    RGB24_t rgb;
    int counts;
    _gray2rgb_t(){rgb.R =0;rgb.G = 0; rgb.B = 0; counts = 0;};
}gray2rgb_t;

static RGB24_t gray2rgbTable[256];
static gray2rgb_t gray2rgbTableTmp[256][256];

/**
 * @brief 
 *
 * @param dataIn
 * @param w
 * @param h
 * @param bytesinLine
 */
void studyFromRGBimg( char* dataIn, int w, int h, int bytesinLine)
{
    int i,j;
    //int w;
    //int h;
    int step;
    //char *dataIn ;
    unsigned char  r;
    unsigned char  g;
    unsigned char  b;
    unsigned char  y;
    //w = in ->width;
    //h = in ->height;
    //dataIn = in->imageData;

    step = bytesinLine/*in ->widthStep*/;
    for(i = 1;i< h -1 ;i++){
        for(j =1; j< w-1 ;j++){
            r = dataIn P(i,j,step,0);           
            g = dataIn P(i,j,step,1);
            b = dataIn P(i,j,step,2);
            y = (unsigned char)(0.299 * (double)r + 0.587 *(double)g + 0.114 * (double)b);
            if(y> 255) y =255;
            gray2rgbTableTmp[y][r].counts ++;
            gray2rgbTableTmp[y][r].rgb.R =( r );
            gray2rgbTableTmp[y][r].rgb.G = (g );
            gray2rgbTableTmp[y][r].rgb.B = (b );
        }
    }

    for(i=0;i<255;i++){
        int theBiggest = 0;
        int theBiggestI = 0;
        for(j =0;j<255;j++){
            if(gray2rgbTableTmp[i][j].counts > theBiggest){
                theBiggest = gray2rgbTableTmp[i][j].counts;
                theBiggestI = j;
            }
        }
        gray2rgbTable[i] =  gray2rgbTableTmp[i][theBiggestI].rgb;
    }
}

/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param w
 * @param h
 * @param bytesinLine
 */
void transGray2RGB(char* dataOut, char* dataIn, int w, int h, int bytesinLine)
{
    int i,j;
    //int w;
    //int h;
    int step;
    //char *dataIn, *dataOut;
    unsigned char  r;
    unsigned char  g;
    unsigned char  b;
    unsigned char  y;
    //w = in ->width;
    //h = in ->height;
    //dataIn = in->imageData;
    //dataOut = out->imageData;
    step =bytesinLine /*in ->widthStep*/;
    for(i = 1;i< h -1 ;i++){
        for(j =1; j< w-1 ;j++){
            r = dataIn P(i,j,step,0);           
            g = dataIn P(i,j,step,1);
            b = dataIn P(i,j,step,2);   
            y = (unsigned char)(0.299 * (double)r + 0.587 *(double)g + 0.114 * (double)b);

            dataOut P(i,j,step,0) = gray2rgbTable[r].R;
            dataOut P(i,j,step,1) = gray2rgbTable[r].G;
            dataOut P(i,j,step,2) = gray2rgbTable[r].B;
        }
    }

}

/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param w
 * @param h
 * @param bytesinLine
 */
void transGray2RGB_2(char* dataOut, char* dataIn, int w, int h, int bytesinLine)
{
    int i,j;
    //int w;
    //int h;
    int step;
    //char *dataIn, *dataOut;
    unsigned char  r;
    unsigned char  g;
    unsigned char  b;
    unsigned char  y;
    double Ic,Hc,Sc;
    double rd,gd,bd;
    //w = in ->width;
    //h = in ->height;
    //dataIn = in->imageData;
    //dataOut = out->imageData;
    step =bytesinLine/* in ->widthStep*/;
    for(i = 1;i< h -1 ;i++){
        for(j =1; j< w-1 ;j++){
            r = dataIn P(i,j,step,0);           
            g = dataIn P(i,j,step,1);
            b = dataIn P(i,j,step,2);   
            //y = (unsigned char)(0.299 * (double)r + 0.587 *(double)g + 0.114 * (double)b);
            Ic = (double) r;
            Hc = 2* M_PI * r / 256.0;
            if(r<127) 
                Sc = 1.5 * (double)r;
            else
                Sc = 1.5 * (double)(255 -r);
            rd= (Ic - 0.204124 * Sc * cos(Hc) + 0.612372 * Sc * sin(Hc));
            gd= (Ic - 0.204124 * Sc * cos(Hc) - 0.612372 * Sc * sin(Hc));
            bd= (Ic + 0.408248 * Sc * cos(Hc));

            dataOut P(i,j,step,0) = rd;
            dataOut P(i,j,step,1) = gd;
            dataOut P(i,j,step,2) = bd;
        }
    }

}

/**
 * @brief 
 *
 * @param dataOut
 * @param dataIn
 * @param w
 * @param h
 * @param bytesinLine
 */
void transRGB2Gray(char* dataOut, char* dataIn, int w, int h, int bytesinLine)
{
    int i,j;
    int step;
    unsigned char  r;
    unsigned char  g;
    unsigned char  b;
    unsigned char  y;
    for(i = 1;i< h -1 ;i++){
        for(j =1; j< w-1 ;j++){
            r = dataIn P(i,j,step,0);           
            g = dataIn P(i,j,step,1);
            b = dataIn P(i,j,step,2);   
            y = (unsigned char)(0.299 * (double)r + 0.587 *(double)g + 0.114 * (double)b);
            //printf("%d\n",y);
            dataOut P(i,j,step,0) = y;
            dataOut P(i,j,step,1) = y;
            dataOut P(i,j,step,2) = y;
        }
    }

}
}
