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
    char* str2= "oframe=(frame+frame[-1])*sobel; oframe=frame*sobel;oframe=frame; tframe = frame - frame[-1]; oframe=tframe; \
    {oframe=(frame+frame[-1])*sobel; oframe=frame*sobel;oframe=frame; tframe = frame - frame[-1]; oframe=tframe; oframe=frame*sobel;}";
    char* fn="main.cpp";
    {
        for(int i=0;i<argc;i++){
            printf(" arg %d: %s\n", i, argv[i]);
        }
    }
    vasParserDriver myparser;
    gvacg.init();
    if(argc==2){
        fn = argv[1];
        printf("parse file\n");
        myparser.parsefile(fn);
    }else{
        printf("\nparsing ...\n"); 
        myparser.parse(str2);
    }
    //programGraph->gimplify(NULL);

    printf("number of AstNodes:%d\n\n", numAstNode); 
    programGraph->dumpAst(stdout);
    printf("dump end.\n");

    printf("\nDump Gimple\n"); 
    programGraph->dumpGimple(stdout);
    printf("Dump Gimple end.\n");

    printf("Optimize start.\n");
    programGraph->optimize();
    printf("Optimize end.\n");

    printf("\nDump Gimple\n"); 
    programGraph->dumpGimple(stdout);
    printf("Dump Gimple end.\n");

    printf("Generate code ...\n\n");
    programGraph->codeGen();
    printf("Generate code End.\n");

    gvacg.dumpCode();
}
