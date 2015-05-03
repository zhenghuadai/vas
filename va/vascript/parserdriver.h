#ifndef  PARSER_INC
#define  PARSER_INC
#include "vasparser.h"
#include "vasFlexLexer.h"
#include "yy.lex.parser.h"

extern vasFlexLexer* gvaslexer;
class vasParserDriver
#  ifdef YY_USE_CLASS
:public vasParser
#endif
{
    public:
        vasParserDriver(){ 
#  ifdef YY_USE_CLASS
            setPointer((YYSTYPE*)&yylval, (YYLTYPE*)&yylloc);
#else
        gvaslexer = &vaslexer;
#endif
        void initParser();
        initParser();
        };
    public:
        void parse(char* str);
        void parsefile(char* fn);
        virtual void yyerror(char * msg);
        virtual int yylex();
    private:
        void parse();
#  ifdef YY_USE_CLASS
        void setPointer(YYSTYPE* s, YYLTYPE* l){ ::yylval = s; ::yylloc = l;}
#endif
    private:
        vasFlexLexer vaslexer;

};

//extern vasParserDriver gparser;
#endif   /* ----- #ifndef PARSER_INC  ----- */
