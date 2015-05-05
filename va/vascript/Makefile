ext_inc=../opencv/include ../ ./ ccg/ 
arch=$(shell uname -m)
ifeq "$(arch)" "x86_64"
ext_libpath=../opencv/libx64
ext_lib=opencv_core opencv_highgui 
else 
ext_libpath=../opencv/lib
ext_lib=cxcore highgui 
endif
#ext_flags= -m32
TARGET= testvas.exe
vacgSRC= OBJ_DIR/vasparser.cpp OBJ_DIR/vaslexer.cpp  parserdriver.cpp testvas.cpp vacg.cpp node.cpp symbol.cpp graph.cpp ../global.cpp ../detect.cpp ../filterKernel.cpp ../transforKernel.cpp ccg/ccg.cpp
clean_obj=vaslexer.cpp vasparser.cpp vasparser.h
-include ../makefile.inc
vacgOBJ=$(call getobjs, $(vacgSRC))
abc:
	echo ${vacgOBJ}
%.cv.avi:%.avi
	mencoder $<  -ovc raw -vf format=i420 -o $@ 
testvas.exe:${vacgOBJ}
	${LINK++}
${OBJ_DIR}vaslexer.cpp:vascript.l	
	flex++ -o$@ $^
${OBJ_DIR}vasparser.cpp:vascript.y	
	bison -d  -o $@ $<

#tok=$(shell gcc -E token.ly.h | tail -n 1);
vascript.y:token.def
	cp vascript.y vascript.cppld
	sed -e "s/^%token.*$$/$(shell gcc -E token.ly.h | tail -n 1)/"  vascript.cppld > vascript.y

