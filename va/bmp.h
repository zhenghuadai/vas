#ifndef _BITMAP_HEADNER__
#define _BITMAP_HEADNER__

#include <stdio.h>
typedef unsigned char u8;
#define bitmapHeaderSize (54) // (sizeof(bitmapFileHeader_t) + sizeof(bitmapInfoHeader_t))

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack (2)
typedef struct { 
	unsigned short type;      /*Specifies the file type. It must be set to the signature word BM (0x4D42) to indicate bitmap. */
	unsigned int fsize;       /*Specifies the size, in u8s, of the bitmap file.*/
	unsigned short reserved1; /**/
	unsigned short reserved2; /**/
	unsigned int offsetbytes;  /*Specifies the offset, in u8s, from the bitmapFileHeader_t structure to the bitmap bits*/
} bitmapFileHeader_t; 

typedef struct { 
	unsigned int hsize;       /*sizeof(bitmapInfoHeader_t), 40.*/
	unsigned int width;      /**/
	unsigned int height;     /**/
	unsigned short planes;   /*Specifies the number of planes for the target device. This value must be set to 1*/
	unsigned short bitcount; /*1;4;8;24*/
	unsigned int compression;/**/ 
	unsigned int sizeimage;  /**/
	int xpelspermeter;       /**/
	int ypelspermeter;       /**/
	unsigned int colorsused; /**/
	unsigned int colorsimportant;/**/ 
} bitmapInfoHeader_t; 

typedef struct tagRGBQUAD {
    u8 B;//
    u8 G;//
    u8 R; //
    u8 Reserved;//
} RGBQUAD;

typedef struct { 
	unsigned char B; 
	unsigned char G; 
	unsigned char R; 
} rgb_t;

inline size_t realWidth(size_t w){
	//return ((w %4)?((w+4) &(~3)) :w);
	return ( w + 3) & (~3);
}

inline int lineBytes(int width){ return (realWidth(width* sizeof(rgb_t)));}

typedef struct {
	union{
		struct{
			bitmapFileHeader_t file_header; 
			bitmapInfoHeader_t info_header;
		};
		struct{
			unsigned short type; 
			unsigned int fsize; 
			unsigned short reserved1; 
			unsigned short reserved2; 
			unsigned int offsetbytes; 
			/**/
			unsigned int hSize; 
			unsigned int width; 
			unsigned int height; 
			unsigned short planes; 
			unsigned short bitcount; 
			unsigned int compression; 
			unsigned int sizeimage; 
			int xpelspermeter; 
			int ypelspermeter; 
			unsigned int colorsused; 
			unsigned int colorsimportant; 

		};
	};
	unsigned char* data;
    RGBQUAD* color_table;
}bmp_t;
#pragma pack ()
 
#ifdef __cplusplus
} // END  extern "C" {
#endif

unsigned char* read_bmp(char * filename,	bmp_t* bmp);

int write_bmp(char * filename, bmp_t* bmp, rgb_t * pixel=0);

int write_bmp(char * filename, rgb_t * pixel, int  width, int  height);

int write_gray256(char* filename, bmp_t* bmp, u8* pixel=NULL);
int write_gray256(char * filename, u8* pixel, int  width, int  height);

void printbmp(bmp_t * bmp);

bmp_t* create_bmp(int width, int height, rgb_t* pixel=0);
bmp_t* create_gray256(int width, int height, u8* pixel=0);

/**
 * @name foreach macro 
 * @code  foreachpix(my_bmp, ({int a, b; a = my_bmp->width;}))
 * @code 
 *   foreachpix(mybmp, ({
 *               mybmp->data[pixi] = ((unsigned short*)(wavHeader->wavData))[pixi];
 *               }));
 * @code
 *   foreach_rgb(a in mybmp, ({
 *               a = (wavHeader->wavData)[pixi];
 *               })
 *           );
 * @code
 *   foreach_rgb(a in mybmp, ({eachrgb(b in bmp2);eachrgb(c in bmp3)
 *               a = b;
 *               })
 *           );
 * @code
 *   foreach_gray(a in mybmp, ({
 *               a = ((unsigned short*)(wavHeader->wavData))[pixi];
 *               })
 *           );
 * @{ */
#define _eachrgb(a, bmp) rgb_t& a = ((rgb_t*)(bmp->data))[pixi];
#define eachrgb(a) _eachrgb(a) 
#define _eachgray(a, bmp) u8& a = ((u8*)(bmp->data))[pixi];
#define eachgray(a) _eachgray(a) 

#define foreachpix(bmp, x) { int rowi, colj,pixi=0; for(rowi = 0; rowi < bmp->height; rowi++){\
    rgb_t* rowdata = (rgb_t*) ((bmp->data) + rowi * lineBytes(width));\
    for(colj=0; colj<bmp->width; colj++){ \
        rgb_t& pixel = ((rgb_t*)(rowdata))[colj]; \
        x;\
        pixi++;\
    }\
}\
}

#define in ,
#define _foreach_rgb(a, bmp , x){ int rowi, colj,pixi=0;  for(rowi = 0; rowi < bmp->height; rowi++){\
    rgb_t* rowdata = (rgb_t*) ((bmp->data) + rowi * lineBytes(width));\
    for(colj=0; colj<bmp->width; colj++){ \
        rgb_t& a = ((rgb_t*)(rowdata))[colj]; \
        x;\
        pixi++;\
    }\
}\
}

#define foreach_rgb(a , x) _foreach_rgb(a ,x)

#define _foreach_gray(a, bmp , x){ int rowi, colj,pixi=0;  \
  for(rowi = 0; rowi < bmp->height; rowi++){\
    u8* rowdata = bmp->data + rowi * realWidth(bmp->width);\
    for(colj=0; colj<bmp->width; colj++){ \
        u8& a = ((u8*)(rowdata))[colj]; \
        x;\
        pixi++;\
    }\
}\
}

#define foreach_gray(a , x) _foreach_gray(a ,x)


/**  @} */
#endif	//_BITMAP_HEADNER__
