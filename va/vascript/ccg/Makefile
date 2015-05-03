dmcompiler:main.cpp dmlexer.cpp parserdriver.cpp dmccparser.cpp 
	g++ -o $@ $^  -ll
dmlexer.cpp: lexer.l
	flex++ -o $@ $^ 
	#sed "s/<FlexLexer.h>/\"flexLexer.h\"/" $@ > tmp1.cpp; mv tmp1.cpp $@
dmccparser.cpp:dmccparser.y	
	bison++ -d -hdmccparser.h -o $@ $<
lexerC: main.c lexer.c 
	g++ -o $@ $^  -ll
lexer.c: lexer.l
	flex -o$@ $^ 
testopcode:testopcode.cpp	
	g++ -m64 -o $@.64 -g $<
#	g++ -m32 -o $@.32 -g $<
testccg:testccg.cpp ccg.cpp 
	g++ -g -o $@ $^
parseCoderHtml:	parseCoderHtml.cpp
	g++ -o parseCoderHtml -O0 parseCoderHtml.cpp -g
clean:
	rm -f *.o testccg lexer.c lexer lexer.cpp dmcompiler dmccparser.h dmccparser.cpp dmlexer.cpp

main.cpp:lex.h
	@touch  $@
ccg.cpp:ccg.h
	@touch  $@
ccg.cpp:ccg.h opcodeDes.h
