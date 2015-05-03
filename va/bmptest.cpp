#include "bmp.h"
#include <stdlib.h>

#include "Kernel.h"
#include "Kernel.hxx"
#define pix(row, col) ((row)* w + col)
using namespace dmFrameSimple;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#define MEDIA_T u16
void diff(rgb_t* in1, rgb_t* in2, rgb_t* out, int w, int h){
	for(int i=1;i<h-1;i++){
		for(int j=1;j<w-1;j++){
			out[pix(i,j)].B = abs((short)in1[pix(i,j)].B- (short)in2[pix(i,j)].B);
			out[pix(i,j)].G = abs((short)in1[pix(i,j)].G- (short)in2[pix(i,j)].G);
			out[pix(i,j)].R = abs((short)in1[pix(i,j)].R- (short)in2[pix(i,j)].R);
		}
	}
}
 
int main(int argc, char** argv)
{
	char* inf =(char*)"test.bmp";
	char* outf=(char*)"test2.bmp";

	if(argc==2){
		inf=argv[1];
	}else	if(argc ==3) {
		inf = argv[1];
		outf=argv[2];
	}

	bitmapFileHeader_t  file_header;
	bitmapInfoHeader_t  info_header;
	bmp_t bmp;

	rgb_t* data;
	rgb_t* data0;
	rgb_t* dataOut;
 	data = (rgb_t*)read_bmp(inf, &bmp );
	 
	data0= (rgb_t*)read_bmp(outf, &bmp);
	dataOut= (rgb_t*)malloc(bmp.sizeimage );
	 
	DoPixels<LapLas>((char*)dataOut, (char*)data,bmp.width, bmp.height,realWidth(bmp.width)*3,0);
	write_bmp((char*)"testout.bmp", &bmp, dataOut);
    DoAlpha<diffKernel>( (char*)dataOut,(char*)data, (char*)data0,bmp.width,bmp.height, realWidth(bmp.width)*3,0);
    write_bmp((char*)"testdiff.bmp", &bmp, dataOut);
    //int width ,height;
    //width = bmp.info_header.width;
    //height=bmp.info_header.height;
    //
    //diff(data0,data, data, width, height);
    //write_bmp("diff.bmp", &bmp, data);

}
