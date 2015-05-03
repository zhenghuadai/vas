@echo off

perl compileflexbison.pl
goto exit0;



@set gnuDir=E:\daizh\GnuWin32\bin\
%gnuDir%\bison -d -ovasparser.cpp vascript.y
%gnuDir%\flex++ -+ -ovaslexer.cpp vascript.l

@echo #ifndef __VAS_PARSER_HEADER__ > vasparser.h
@echo #define __VAS_PARSER_HEADER__ >> vasparser.h
@echo #include "node.hxx"           >> vasparser.h
@echo #include "vasparser.hpp"      >> vasparser.h
@echo #endif                        >> vasparser.h



set dstf=vaslexer.cpp
set tmpfile=%temp%\vaslexer.cpp
@copy vaslexer.cpp %tmpfile%
@rem @echo #include   ^<iostream^> >%dstf%
@rem @echo using namespace std; >>%dstf%

set tmpfs=tmpfs.txt
echo >  %tmpfs%
rem for /f "delims="  %%i in (%tmpfile%) do (
set mystr=%%i
set mystr=%mystr:class istream;=;%
echo %mystr% >> %tmpfs%
)

:exit0