/*
 * =====================================================================================
 *
 *       Filename:  parseCoderHtml.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2009 07:06:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghua Dai (Zhenghua Dai), djx.zhenghua@gamil.com
 *        Company:  dzh
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceStr(char* psrc, char* s, char* replaceto)
{
	char* p = psrc;
	while(( p = strstr(p, s)) !=NULL){
		char *d = replaceto;
		while(*d){
			*p = *d;
			p++; d++;
		}
	}
}

void removeSpace(char* psrc, char* pdst)
{
	int i =0;
	char* d = pdst;
	char* p = psrc;
	while((*p)&&(*p ==' ')) p++;
	while(*p){
		if(*p == ' '){
			p +=1;
		} else{
			*d = *p;
			d++;
			p++;
		}
	}
	*d = 0;
}


void removeDS(char* psrc, char* pdst)
{
	int i =0;
	char* d = pdst;
	char* p = psrc;
	while((*p)&&(*p ==' ')) p++;
	while(*p){
		if((*p == ' ')&&( *(p+1) == ' ')){
			p +=2;
		} else{
			*d = *p;
			d++;
			p++;
		}
	}
	*d = 0;
}

void removeTag(char* p)
{
	char* s = p;
	while(*s){
		while((*s)&&(*s!='<')) s++;
		if(*s ==NULL) return ;
		while((*s)&&(*s!='>')){ 
			*s=' '; s++;
		}
		if(*s=='>') {
			*s=' '; s++;
		}
	}
}

int getEle(char*& p, char* dst)
{
	char* startp;
	char* endp;
	endp = strstr(p, "</td>");
	startp= strstr(p, "<td");
	if(endp ==NULL) {
		dst[0] =0;
		return -1;
	}
	if(startp - endp < 0){
		while((*startp )  && (*startp !='>')) 
			startp ++;
		startp ++;
	} else{ 
		startp = p;
		while((*startp )  && (*startp !='>')) 
			startp ++;
		startp ++;
		if(startp >endp) startp = p;	
	}
	int len = endp - startp ;
	if(len>=0){
		memcpy(dst, startp, len);
		dst[len]=0;
	}
	p = endp+5;
	return len;
}

int getLine(char*& p, char* dst)
{
	char* endp = strstr(p, "</tr>");
	char* pstart = p;
	if(endp ==NULL) {
		dst[0] =0;
		return -1;
	}
	int len = endp - p;
	memcpy(dst, p, len);
	dst[len]=0;
	p = endp+5;
	return len;
}

char Line[1024*4];
char ele[1024];
char ele2[1024];
char eles[32][128];
char elesLast[32][128];
#define AN 22
int main(int argc, char** argv)
{
	char* html ;
	html = (char*)malloc( 1024 *1024*2);
	char* infn = argv[1];
	char* outfn;
	FILE* fp = fopen(infn, "r");
	unsigned long long  i=0;
	char c;
	FILE* fpout;
	if(argc ==3) 
	outfn = argv[2];
	else 
	outfn= "tmpcode.h";
	fpout= fopen(outfn, "w");
	if(fp == NULL) return 1;

	while( (c = fgetc(fp)) !=EOF){
		if(c == '\n') c = ' ';
		html[i++] = c;
	}
	html[i] = 0;

	char* p;

	p = strstr(html, "<table");

	int LineLen;
	p = strstr(p, "<tr>") + 4;
//	fprintf(fpout, "#define decOPinfoList \\\n" );
	while( (LineLen = getLine(p, Line)) != -1){
		int eleLen ;
		char* pLine = strstr(Line, "<td") ;
		int recordNum = 0;
		if(pLine==NULL) continue;
		pLine += 4;

		while( (eleLen = getEle(pLine, ele)) >=0){
			if(eleLen =0) {
				ele[0] = ' ';
				ele[1] = 0;
				eleLen = 1;
			}
			removeTag(ele);
			replaceStr(ele, "r/m16/32/64","rmWDQ      ");
			replaceStr(ele, "r/m/64/16","rmWQ     ");
			replaceStr(ele, "r64/16","rWQ   ");
			replaceStr(ele, "r/m16/32", "rmWD    ");
			replaceStr(ele, "16/32/64", "WDQ     ");
			replaceStr(ele, "32/64", "DQ   ");
			replaceStr(ele, "16/32", "WD   ");
			replaceStr(ele, "r/m", " rm");
			replaceStr(ele, "xmm/m", "   Xm");
			replaceStr(ele, "mm/m", "  Mm");
			replaceStr(ele, "imm16/32", "     iWD");
			replaceStr(ele, "imm16", "  i16");
			replaceStr(ele, "m32real", "m32f   ");
			replaceStr(ele, "m64real", "m64f   ");
			replaceStr(ele, "/", "o");
			replaceStr(ele, ".", "o");
			replaceStr(ele, ":", "O");
			removeDS(ele,ele2);
			if(recordNum == 12){
			removeSpace(ele2, ele);
			strcpy(ele2, ele);
			}
			strcpy(eles[recordNum++],ele2);
        }
        if(recordNum == AN-1){
            for( i=recordNum; i>10; i--){
                strcpy(eles[i], eles[i-1]);
            }
            strcpy(eles[i], " ");
            eles[8][2]=0; //! remove +r
            strcpy(eles[10], "s");
            recordNum ++;

        }

		if(recordNum < AN) {
			for(; recordNum < AN;recordNum ++ )
				strcpy(eles[recordNum ], elesLast[recordNum ]);
		}

		fprintf(fpout, "decOP( " );
		for(int j =0; j< recordNum ; j++){
			if( j  ){
				fprintf(fpout,", ");
			} 

			strcpy(ele2, eles[j]);
			if(j  ==0) 
				fprintf(fpout, "%-10s", ele2);
			else if(j  ==1) 
				fprintf(fpout, "%-12s", ele2);
			else if(j  ==2) 
				fprintf(fpout, "%-12s", ele2);
			else if(j  ==3) 
				fprintf(fpout, "%-7s", ele2);
			else if(j  ==5) 
				fprintf(fpout, "%-5s", ele2);
			else if((j  >=6) && (j  <= 9)){
                i=0;
                while(ele2[i] !=0){
                    if(ele2[i] !=' ') break;
                    i++;
                }
                if(ele2[i]==0) 
                    fprintf(fpout, "%-4s", ele2);
                else
                    fprintf(fpout, "0x%-2s", ele2);
            }
			else if(j  ==AN-1) 
                fprintf(fpout, "\"%s\"", ele2);
            else 
                fprintf(fpout, "%s", ele2);
		}
        fprintf(fpout, ") \\\n" );

		for( int i=0;i<AN ;i++){
			strcpy(elesLast[i] , eles[i]);
		}
    }
        fprintf(fpout, "\n" );
}
