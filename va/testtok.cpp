/*
 * =====================================================================================
 *
 *       Filename:  testtok.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/16/2011 06:22:25 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  DAI ZHENGHUA (), djx.zhenghua@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include "token.h"
#define _STR(x) #x
#define STR(x) _STR(x)

int main()
{
    printf("%s\n", STR(DEFINE_KEYWD(DEFINE_TOKEN)));
}
