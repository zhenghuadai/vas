#include "token.h"
#include "parserdriver.h"
#include <iostream>
#include <fstream>
#include <strstream>
using namespace std;
//vasParserDriver gparser;
#  ifndef YY_USE_CLASS
vasFlexLexer* gvaslexer;
int yyparse();
int yylex()
{
    return gvaslexer->yylex();
}
#endif

#if defined(_MSC_VER)
YYLTYPE yylloc;
#endif

void vasParserDriver::parse()
{
    int tokType;
    while ((tokType = vaslexer.yylex()) != 0){
        if(tokType <256)
            printf("type(%3d)%10c:%s\n", tokType, tokType ,vaslexer.YYText());
        else
            printf("type(%3d)%10s:%s\n", tokType, get_key_name(tokType) ,vaslexer.YYText());
    };
}

void vasParserDriver::parse(char* str)
{
    istrstream is(str, 0);	
    struct yy_buffer_state* buf = vaslexer.yy_create_buffer(&is,1);
    vaslexer.yy_switch_to_buffer(buf);
    //    bufferState[bufferPointer++] = buf1;
//    parse();
    yyparse();
    vaslexer.yy_delete_buffer(buf);
}

void vasParserDriver::parsefile(char* fn)
{
    ifstream fi(fn, ios::in);
    struct yy_buffer_state* buf = vaslexer.yy_create_buffer(&fi,1);
    //    bufferState[bufferPointer++] = buf;
    vaslexer.yy_switch_to_buffer(buf);
//    parse();
    yyparse();
    vaslexer.yy_delete_buffer(buf);
}

void vasParserDriver::yyerror(char * msg)
{
	cerr << yylloc.first_line << ":" << yylloc.first_column <<  ": "
		<< msg << " : <" << yylloc.text << ">" <<  endl;
}

int vasParserDriver::yylex()
{
    //yylloc.first_line = scanner.line;
	//yylloc.first_column = scanner.column;
	//int token = scanner.yylex(&yylval, &yylloc);
	//yylloc.last_line = scanner.line;
	//yylloc.last_column = scanner.column;
	//yylloc.text = (char *)scanner.yytext;
    int token = vaslexer.yylex();
//    yylloc.text = (char*)vaslexer.YYText();
	return token;
}

