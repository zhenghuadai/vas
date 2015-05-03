ext_inc= vascript vascript/ccg vascript/OBJ_DIR /usr/include/opencv/ #opencv/include 
ext_lib=cxcore highgui 
#ext_libpath=opencv/lib
#TARGET=vacg.exe2
#vacgSRC=dmvideo.cpp filterKernel.cpp transColor.cpp transforKernel.cpp vascript/vacg.cpp detect.cpp global.cpp vascript/vaslexer.cpp vascript/vasparser.cpp vascript/parserdriver.cpp 
EXECUTABLE= vacg.default.exe
SOURCEFILE=dmvideo.cpp filterKernel.cpp transColor.cpp transforKernel.cpp vascript/vacg.cpp detect.cpp global.cpp vascript/OBJ_DIR/vaslexer.cpp vascript/OBJ_DIR/vasparser.cpp vascript/parserdriver.cpp vascript/symbol.cpp vascript/node.cpp vascript/graph.cpp vascript/ccg/ccg.cpp 
clean_obj=vaslexer.cpp vasparser.cpp vasparser.h
all: lib vacg.default.exe

-include makefile.inc
lib:
	make -C vascript
bmptest.exe:bmptest.cpp	 bmp.cpp transforKernel.cpp ../speach/wav.cpp
	${LINK++}
%.cv.avi:%.avi
	mencoder $<  -ovc raw -vf format=i420 -o $@ 
