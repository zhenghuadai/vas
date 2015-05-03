#include "Kernel.h"
#define KA KernelArray
#define LIMIT(a) (a)<20?0:(1)
namespace dmFrameSimple{
/**
 * @brief AND each 
 *
 * @param dataOut
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param KernelArray
 * @param m
 * @param n
 */
void fandFilter (char *dataOut, char *dataIn, int row,int col,int step,int* KernelArray,int m,int n )
{
    unsigned char bits[9] ;
    int flag[3];
    if(KernelArray == 0) return ;
    for(int rgb =0;rgb < 3;rgb++){
    bits[0] = LIMIT(dataIn P(row-1,col-1,step,rgb));
    bits[1] = LIMIT(dataIn P(row-1,col,  step,rgb));
    bits[2] = LIMIT(dataIn P(row-1,col+1,step,rgb));
    bits[3] = LIMIT(dataIn P(row  ,col-1,step,rgb));
    bits[4] = LIMIT(dataIn P(row  ,col  ,step,rgb));
    bits[5] = LIMIT(dataIn P(row  ,col+1,step,rgb));
    bits[6] = LIMIT(dataIn P(row+1,col-1,step,rgb));
    bits[7] = LIMIT(dataIn P(row+1,col  ,step,rgb));
    bits[8] = LIMIT(dataIn P(row+1,col+1,step,rgb));
    
    flag[rgb] = (bits[4] * KA[4] ) ^ ( ( bits[1] * KA[1] ) |
                                  ( bits[3] * KA[3] ) |
                                  ( bits[5] * KA[5] ) |
                                  ( bits[7] * KA[7] ) );
    //if(flag) 
    //    dataOutP(row,col,step,rgb) = 255;
    //else
    //    dataOutP(row,col,step,rgb) = 0;
    }
    if(flag[0] | flag[1] | flag[2]){
            dataOutP(row,col,step,0) = 0;
            dataOutP(row,col,step,1) = 0;
            dataOutP(row,col,step,2) = 0;
    }else{
            dataOutP(row,col,step,0) =  dataInP(row,col,step,0);
            dataOutP(row,col,step,1) =dataInP(row,col,step,1);
            dataOutP(row,col,step,2) =dataInP(row,col,step,2);
    }
}

/**
 * @brief average filter  
 *
 * @param dataOut
 * @param dataIn
 * @param row
 * @param col
 * @param step
 * @param KernelArray
 * @param m
 * @param n
 */
void averageFilter (char *dataOut, char *dataIn, int row,int col,int step,int* KernelArray,int m,int n )
{
    unsigned char bits[9] ;
    int flag[3];
    if(KernelArray == 0) return ;
    for(int rgb =0;rgb < 3;rgb++){
        bits[0] = (dataIn P(row-1,col-1,step,rgb));
        bits[1] = (dataIn P(row-1,col,  step,rgb));
        bits[2] = (dataIn P(row-1,col+1,step,rgb));
        bits[3] = (dataIn P(row  ,col-1,step,rgb));
        bits[4] = (dataIn P(row  ,col  ,step,rgb));
        bits[5] = (dataIn P(row  ,col+1,step,rgb));
        bits[6] = (dataIn P(row+1,col-1,step,rgb));
        bits[7] = (dataIn P(row+1,col  ,step,rgb));
        bits[8] = (dataIn P(row+1,col+1,step,rgb));
        
        flag[rgb] = 0;
        int counts = 0;
        for(int k =0;k< m*n;k++){
            flag[rgb] += bits[k] *KA[k];
            counts += KA[k];
        }
        flag[rgb] /= counts;
        dataOut P(row,col,step,rgb) =  (char )flag[rgb];
        //if(flag) 
        //    dataOutP(row,col,step,rgb) = 255;
        //else
        //    dataOutP(row,col,step,rgb) = 0;
    }
 
}
}//!end namespace
