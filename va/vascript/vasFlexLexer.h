/*
 * =====================================================================================
 *
 *       Filename:  dmFlexLexer.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/04/2010 03:50:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghua Dai , djx.zhenghua@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef  DMFLEXLEXER_INC
#define  DMFLEXLEXER_INC
#undef yyFlexLexer
#define yyFlexLexer yyFlexLexer
#include "FlexLexer.h"
#undef yyFlexLexer

class vasFlexLexer :public yyFlexLexer{
    public:
        vasFlexLexer( std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0 ):yyFlexLexer(arg_yyin, arg_yyout){};

};
#endif   /* ----- #ifndef DMFLEXLEXER_INC  ----- */
