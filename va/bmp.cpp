#include "bmp.h"
#include <stdlib.h>    
#ifndef __inline__
#define __inline__  
#endif

__inline__ unsigned char* read_bmp(char * filename, bmp_t* bmp )
{
    int lwidth;  
    int n = 0;
    FILE * file = fopen(filename, "rb");
    if (!file) {
        printf("File open error: %s\n", filename);
        return NULL;
    }
    for(int i=0;i<sizeof(bmp_t); i++){ ((u8*)bmp)[i] = 0;}

    n = fread((void *)&(bmp->file_header), sizeof(bitmapFileHeader_t), 1, file);
    if (bmp->file_header.type != 0x4d42) {
        printf("Not a bmp file\n");
        fclose(file);
        return NULL;
    }

    n = fread((void *)&(bmp->info_header), sizeof(bitmapInfoHeader_t), 1, file);
    if(bmp->offsetbytes != 54)
        fseek(file, bmp->file_header.offsetbytes, SEEK_SET);
    //lwidth = ((bmp->info_header.width %4)?((bmp->info_header.width+4) &(~3)) :bmp->info_header.width);
    // Do we need this?
    bmp->info_header.sizeimage = lineBytes(bmp->info_header.width) * bmp->info_header.height ;
    rgb_t * p = (rgb_t*)malloc(bmp->info_header.sizeimage);
    if (!p) {
        printf("Memory allocation error.\n");
        return NULL;
    }
    n = fread((void *)p, bmp->info_header.sizeimage, 1, file);
    bmp->data =(unsigned char*) p;

    fclose(file);
    return (unsigned char*) p;
}

__inline__ int write_bmp(char * filename, bmp_t* bmp,
        rgb_t * pixel)
{
    if(!pixel) 
        pixel = (rgb_t*) bmp->data;
    if(bmp->bitcount == 8 && bmp->color_table == NULL){
        return write_gray256(filename, (u8*)pixel, bmp->width, bmp->height);
    }
    FILE * file = fopen(filename, "wb");
    if (!file) {
        printf("File open error: %s\n", filename);
        return -1;
    }
    if(!pixel)
        return -1;
    fwrite((void *)&(bmp->file_header), sizeof(bitmapFileHeader_t), 1, file);
    fwrite((void *)&(bmp->info_header), sizeof(bitmapInfoHeader_t), 1, file);
    if(bmp->color_table !=NULL)
        fwrite((void *)bmp->color_table, sizeof(RGBQUAD)*256, 1, file);
    fwrite((void *)pixel, bmp->info_header.sizeimage, 1, file);
    fclose(file);
    return 0;
}

__inline__ bmp_t* create_bmp(
        int  width,
        int  height,
        rgb_t * pixel)
{
    bmp_t* bmp = (bmp_t*) malloc(sizeof(bmp_t));
    int lwidth = realWidth(width);
    int sizeImage = lineBytes(width)* height ;

    //int sizeImage = lwidth * height * (int)sizeof(rgb_t);

    bmp->file_header.type = 19778;  
    bmp->file_header.reserved1 = bmp->file_header.reserved2 = 0;
    bmp->file_header.offsetbytes = 54;  
    bmp->file_header.fsize = 54 + sizeImage;

    bmp->info_header.hsize = sizeof(bitmapInfoHeader_t);
    bmp->info_header.width = width;
    bmp->info_header.height = height;
    bmp->info_header.planes = 1;
    bmp->info_header.bitcount = 8 * sizeof(rgb_t);
    bmp->info_header.compression = 0;
    bmp->info_header.sizeimage = sizeImage;
    bmp->info_header.xpelspermeter = 0;
    bmp->info_header.ypelspermeter = 0;
    bmp->info_header.colorsused = 0;
    bmp->info_header.colorsimportant = 0;
    if(pixel != NULL)
        bmp->data= (u8*)pixel;
    else
        bmp->data = (u8*)malloc(sizeImage); 

    return bmp;
}


__inline__ int write_bmp(char * filename,
        rgb_t * pixel,
        int  width,
        int  height)
{
    bmp_t bmp;
    int lwidth = realWidth(width);

    //int sizeImage = lwidth * height * (int)sizeof(rgb_t);
    int sizeImage = lineBytes(width)* height ;

    bmp.file_header.type = 19778;  
    bmp.file_header.reserved1 = bmp.file_header.reserved2 = 0;
    bmp.file_header.offsetbytes = 54;  
    bmp.file_header.fsize = 54 + sizeImage;

    bmp.info_header.hsize = sizeof(bitmapInfoHeader_t);
    bmp.info_header.width = width;
    bmp.info_header.height = height;
    bmp.info_header.planes = 1;
    bmp.info_header.bitcount = 8 * sizeof(rgb_t);
    bmp.info_header.compression = 0;
    bmp.info_header.sizeimage = sizeImage;
    bmp.info_header.xpelspermeter = 0;
    bmp.info_header.ypelspermeter = 0;
    bmp.info_header.colorsused = 0;
    bmp.info_header.colorsimportant = 0;

    return write_bmp(filename, &bmp, pixel);
}

__inline__ int write_gray256(char* filename, bmp_t* bmp, u8* pixel)
{
    FILE * file;
    if(bmp->bitcount != 8)
        return -1;
    file= fopen(filename, "wb");
    if (!file) {
        printf("File open error: %s\n", filename);
        return -1;
    }
    if(!pixel) 
        pixel = (u8*) bmp->data;
    if(!pixel)
        return -1;
    fwrite((void *)&(bmp->file_header), sizeof(bitmapFileHeader_t), 1, file);
    fwrite((void *)&(bmp->info_header), sizeof(bitmapInfoHeader_t), 1, file);
    if(bmp->color_table !=NULL)
        fwrite((void *)bmp->color_table, sizeof(RGBQUAD)*256, 1, file);
    fwrite((void *)pixel, bmp->info_header.sizeimage, 1, file);
    fclose(file);
    return 0;
}

__inline__ bmp_t* create_gray256(
        int  width,
        int  height,
        u8* pixel)
{
    int i;
    bmp_t* bmp = (bmp_t*) malloc(sizeof(bmp_t));
    int lwidth = realWidth(width);

    int sizeImage = lwidth * height * (int)sizeof(u8);

    bmp->file_header.type = 19778;  
    bmp->file_header.reserved1 = bmp->file_header.reserved2 = 0;
    bmp->file_header.offsetbytes = 54 + 1024;  
    bmp->file_header.fsize = 54 + 1024 + sizeImage;

    bmp->info_header.hsize = sizeof(bitmapInfoHeader_t);
    bmp->info_header.width = width;
    bmp->info_header.height = height;
    bmp->info_header.planes = 1;
    bmp->info_header.bitcount = 8;
    bmp->info_header.compression = 0;
    bmp->info_header.sizeimage = sizeImage;
    bmp->info_header.xpelspermeter = 0;
    bmp->info_header.ypelspermeter = 0;
    bmp->info_header.colorsused = 0;
    bmp->info_header.colorsimportant = 0;
    if(pixel != NULL)
        bmp->data= pixel;
    else
        bmp->data = (u8*)malloc(sizeImage); 
    bmp->color_table= (RGBQUAD*)malloc((1<< bmp->info_header.bitcount)*sizeof(RGBQUAD));
    for(i=0;i<(1<< bmp->info_header.bitcount);i++){
        bmp->color_table[i].B= i;
        bmp->color_table[i].G= i;
        bmp->color_table[i].R= i;
        bmp->color_table[i].Reserved=i;
    }

    return bmp;
}


__inline__ int write_gray256(char * filename,
        u8* pixel,
        int  width,
        int  height)
{
    int i;
    bmp_t bmp;
    int lwidth = realWidth(width);

    int sizeImage = lwidth * height * (int)sizeof(u8);

    bmp.file_header.type = 19778;  
    bmp.file_header.reserved1 = bmp.file_header.reserved2 = 0;
    bmp.file_header.offsetbytes = 54 + 1024;  
    bmp.file_header.fsize = 54 + 1024 + sizeImage;

    bmp.info_header.hsize = sizeof(bitmapInfoHeader_t);
    bmp.info_header.width = width;
    bmp.info_header.height = height;
    bmp.info_header.planes = 1;
    bmp.info_header.bitcount = 8;
    bmp.info_header.compression = 0;
    bmp.info_header.sizeimage = sizeImage;
    bmp.info_header.xpelspermeter = 0;
    bmp.info_header.ypelspermeter = 0;
    bmp.info_header.colorsused = 0;
    bmp.info_header.colorsimportant = 0;
    bmp.data= pixel;
    bmp.color_table= (RGBQUAD*)malloc((1<< bmp.info_header.bitcount)*sizeof(RGBQUAD));
    for(i=0;i<(1<< bmp.info_header.bitcount);i++){
        bmp.color_table[i].B= i;
        bmp.color_table[i].G= i;
        bmp.color_table[i].R= i;
        bmp.color_table[i].Reserved=i;
    }

    return write_gray256(filename, &bmp, pixel);
}

void printbmp(bmp_t * bmp)
{
    printf("	    unsigned short type:           ", bmp-> type);          
	printf("		unsigned int fsize:            ", bmp-> fsize); 
	printf("		unsigned short reserved1:      ", bmp-> reserved1); 
	printf("		unsigned short reserved2:      ", bmp-> reserved2); 
	printf("		unsigned int offsetbytes:      ", bmp-> offsetbytes); 
	printf("		unsigned int hSize:            ", bmp-> hSize); 
	printf("		unsigned int width:            ", bmp-> width); 
	printf("		unsigned int height:           ", bmp-> height); 
	printf("		unsigned short planes:         ", bmp-> planes); 
	printf("		unsigned short bitcount:       ", bmp-> bitcount); 
	printf("		unsigned int compression:      ", bmp-> compression); 
	printf("		unsigned int sizeimage:        ", bmp-> sizeimage); 
	printf("		int xpelspermeter:             ", bmp-> xpelspermeter); 
	printf("		int ypelspermeter:             ", bmp-> ypelspermeter); 
	printf("		unsigned int colorsused:       ", bmp-> colorsused); 
	printf("		unsigned int colorsimportant:  ", bmp-> colorsimportant);
}


size_t gHeight;
size_t gWidth;
size_t gBytesinLine;
