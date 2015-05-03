/**
 * =====================================================================================
 *       @file    global.cpp
 *
 *       @brief   '
 *
 *       @author  DAI ZHENGHUA (), djx.zhenghua@gmail.com
 *       @version 1.0
 *       @date    01/24/2011 11:00:50 PM
 *
 *       Revision none
 *       Compiler gcc
 *       Company  
 * =====================================================================================
 */
#include "cvKernel.h"
#include "vacg.h"
IplImage* pImagePool[POOLSIZE] ;    

IplImage* pFrames[nFrame_in_pool];
int Prv = 0, Cur = 1, Nxt =2;
IplImage* oFrame ;
//VASDEBUG(int numAstNode=0);
int numAstNode=0;
