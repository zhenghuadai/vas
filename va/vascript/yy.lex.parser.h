/*
 * =====================================================================================
 *
 *       Filename:  yylexparser.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/2010 02:35:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef  yylexparser_INC
#define  yylexparser_INC
#include <iostream>
using namespace std;
#include "vasparser.h"
#include "debprintf.h"
//#ifndef YYSTYPE
//#define YYSTYPE YY_vasParser_STYPE
//#endif
#if ((!defined YYLTYPE) &&(!defined YY_vasParser_LTYPE))



typedef
  struct YYLTYPE
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  YYLTYPE;

#define YYLTYPE YYLTYPE

#endif


//#define YY_DECL int yyFlexLexer::yylex(YYSTPE *yylval, YYLTYPE *yylloc)

#  ifndef YY_USE_CLASS
extern YYSTYPE yylval;
extern YYLTYPE yylloc;
#define yylvalfd(x) yylval.x
#  else
extern YYSTYPE* yylval;
extern YYLTYPE* yylloc;
#define yylvalfd(x) yylval->x
#  endif

extern FlowGraph* programGraph;
#endif   /* ----- #ifndef yylexparser_INC  ----- */
