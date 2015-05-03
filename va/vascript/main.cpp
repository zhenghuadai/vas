/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/07/2009 10:38:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghua Dai (Zhenghua Dai), djx.zhenghua@gamil.com
 *        Company:  dzh
 *
 * =====================================================================================
 */
//!require "vaslexer.cpp vasparser.cpp parserdriver.cpp  vacg.cpp ../global.cpp ../detect.cpp ../filterKernel.cpp ../transforKernel.cpp"
//!require "../opencv/include/ ../ ../opencv/lib/"
//!require "cxcore highgui" 
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <strstream>
#include "parserdriver.h"
#include "vacg.h"
using namespace std;

int main(int argc, char** argv)
{
    char* str= "pong pong pong pong ";
    char* str2= "oframe = 2; oframe=frame*sobel;oframe=frame; oframe = frame - frame[-1];";
    char* fn="main.cpp";
    vasParserDriver myparser;
    gvacg.init();
    if(argc==2){
        fn = argv[1];
        printf("parse file\n");
        myparser.parsefile(fn);
    }else{
        myparser.parse(str2);
    }
    printf("number of AstNodes:%d\n", numAstNode); 
    programGraph->dumpAst(stdout);
    printf("dump end.\n");
    gvacg.init();
    printf("Generate code ...\n");
    programGraph->codeGen();
    printf("Generate code End.\n");
}
