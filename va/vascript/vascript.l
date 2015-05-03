%{
#include <stdio.h>
//#include "flexLexer.h"
//#define LEX_PARAM YYSTYPE *val, YYLTYPE *loc

#ifndef YY_SKIP_YYWRAP
#ifdef __cplusplus
extern "C" int yywrap (void );
#else
extern int yywrap (void );
#endif
#endif
#include "yy.lex.parser.h"
#include "vasparser.h"
#ifdef YY_USE_CLASS
YYSTYPE *yylval;
YYLTYPE *yylloc;
#endif

#include "token.h"
int check_type();
%}
D [0-9]
L [a-zA-Z_]
LHEADER [a-zA-Z_]
H [a-fA-F0-9]
E [Ee][+-]?{D}+
FS (f|F|l|L)
IS (u|U|l|L)*
%s comment
%%
\/\/.*$  {}
\/\*  { BEGIN(comment) ; }
<comment>\*\/ { BEGIN(INITIAL); }
<comment>\n { }
<comment>. { }
^\#\![^\n]*\n {}
"auto"			{  return(tok(TK_AUTO)); }
"break"			{  return(tok(TK_BREAK)); }
"case"			{  return(tok(TK_CASE)); }
"char"			{  return(tok(TK_CHAR)); }
"const"			{  return(tok(TK_CONST)); }
"continue"		{  return(tok(TK_CONTINUE)); }
"default"		{  return(tok(TK_DEFAULT)); }
"do"			{  return(tok(TK_DO)); }
"double"		{  return(tok(TK_DOUBLE)); }
"else"			{  return(tok(TK_ELSE)); }
"enum"			{  return(tok(TK_ENUM)); }
"extern"		{  return(tok(TK_EXTERN)); }
"float"			{  return(tok(TK_FLOAT)); }
"for"			{  return(tok(TK_FOR)); }
"goto"			{  return(tok(TK_GOTO)); }
"if"			{  return(tok(TK_IF)); }
"int"			{  printf("THis is int%d:\n", tok(TK_INT)); return(tok(TK_INT)); }
"long"			{  return(tok(TK_LONG)); }
"register"		{  return(tok(TK_REGISTER)); }
"return"		{  return(tok(TK_RETURN)); }
"short"			{  return(tok(TK_SHORT)); }
"signed"		{  return(tok(TK_SIGNED)); }
"sizeof"		{  return(tok(TK_SIZEOF)); }
"static"		{  return(tok(TK_STATIC)); }
"struct"		{  return(tok(TK_STRUCT)); }
"switch"		{  return(tok(TK_SWITCH)); }
"typedef"		{  return(tok(TK_TYPEDEF)); }
"union"			{  return(tok(TK_UNION)); }
"unsigned"		{  return(tok(TK_UNSIGNED)); }
"void"			{  return(tok(TK_VOID)); }
"volatile"		{  return(tok(TK_VOLATILE)); }
"while"			{  return(tok(TK_WHILE)); }
"frame"			{  return(tok(TK_FRAME)); }
"oframe"		{  return(tok(TK_OFRAME)); }
"sobel"		    {  return(tok(TK_SOBEL)); }
"robert"		    {  return(tok(TK_ROBERT  )); }
"prewitt"		    {  return(tok(TK_PREWITT )); }
"lapLas"		    {  return(tok(TK_LAPlAS  )); }
"freichen"		    {  return(tok(TK_FREICHEN)); }
"invideo"		    {  return(tok(TK_INFILE)); }
"outvideo"		    {  return(tok(TK_OUTFILE)); }
"stdout"	{  return(tok(TK_STDOUT)); }
\$		            {  return(tok(TK_DOLLAR)); }
[a-zA-Z_][0-9a-zA-Z_]* { yylvalfd(name)= strdup((char*)YYText()); return(check_type()); }
0[xX][a-fA-F0-9]+(u|U|l|L)?		{  return(tok(TK_CONSTANT)); }
0{D}+{IS}?		        {  return(tok(TK_CONSTANT)); }
{D}+{IS}?		        {  yylvalfd(ival) = atoi(YYText()); return(tok(TK_CONSTANT)); }
L?'(\\.|[^\\'])+'	    {  return(tok(TK_CONSTANT)); }

{D}+{E}{FS}?		    {  return(tok(TK_CONSTANT)); }
{D}*"."{D}+({E})?{FS}?	{  return(tok(TK_CONSTANT)); }
{D}+"."{D}*({E})?{FS}?	{  return(tok(TK_CONSTANT)); }

L?\"(\\.|[^\\"])*\"	{ char* tmpstr = strdup(((char*)YYText())+1); tmpstr[strlen(tmpstr)-1] = 0; yylvalfd(name)=tmpstr; return(tok(TK_STRING_LITERAL)); }

"..."			{  return(tok(TK_ELLIPSIS)); }
">>="			{  return(tok(TK_RIGHT_ASSIGN)); }
"<<="			{  return(tok(TK_LEFT_ASSIGN)); }
"+="			{  return(tok(TK_ADD_ASSIGN)); }
"-="			{  return(tok(TK_SUB_ASSIGN)); }
"*="			{  return(tok(TK_MUL_ASSIGN)); }
"/="			{  return(tok(TK_DIV_ASSIGN)); }
"%="			{  return(tok(TK_MOD_ASSIGN)); }
"&="			{  return(tok(TK_AND_ASSIGN)); }
"^="			{  return(tok(TK_XOR_ASSIGN)); }
"|="			{  return(tok(TK_OR_ASSIGN)); }
">>"			{  return(tok(TK_RIGHT_OP)); }
"<<"			{  return(tok(TK_LEFT_OP)); }
"++"			{  return(tok(TK_INC_OP)); }
"--"			{  return(tok(TK_DEC_OP)); }
"->"			{  return(tok(TK_PTR_OP)); }
"&&"			{  return(tok(TK_AND_OP)); }
"||"			{  return(tok(TK_OR_OP)); }
"<="			{  return(tok(TK_LE_OP)); }
">="			{  return(tok(TK_GE_OP)); }
"=="			{  return(tok(TK_EQ_OP)); }
"!="			{  return(tok(TK_NE_OP)); }
";"			{  return(';'); }
"{"			{  return('{'); }
"}"			{  return('}'); }
","			{  return(','); }
":"			{  return(':'); }
"="			{  return('='); }
"("			{  return('('); }
")"			{  return(')'); }
"["			{  return('['); }
"]"			{  return(']'); }
"."			{  return('.'); }
"&"			{  return('&'); }
"!"			{  return('!'); }
"~"			{  return('~'); }
"-"			{  return('-'); }
"+"			{  return('+'); }
"*"			{  return('*'); }
"/"			{  return('/'); }
"%"			{  return('%'); }
"<"			{  return('<'); }
">"			{  return('>'); }
"^"			{  return('^'); }
"|"			{  return('|'); }
"?"			{  return('?'); }

[ \t\v\n\f]		{  }

%%

//
//void yyFlexLexer::comment()
//{
//	char c, c1;
//
//loop:
//	while ((c = yyinput()) != '*' && c != 0);
//
//	if ((c1 = yyinput()) != '/' && c != 0)
//	{
//		yyunput(c1,yytext);
//		goto loop;
//	}
//}

#if defined(_MSC_VER)
int /*yyFlexLexer::*/yywrap()
#else
int yyFlexLexer::yywrap()
#endif
{
    return -1;
}


int check_type()
{
	return(tok(TK_IDENTIFIER));
}

//int main(int argc,char** argv)
//{
//	while( (c=	yylex()) != EOF); 
//	{
//	}
//}
