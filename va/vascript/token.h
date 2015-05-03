#ifndef __LEX__HEADER__
#define __LEX__HEADER__
#include "vasparser.h"
#include "token.def"
#if 1
//! used for debugging
enum {
    DEFINE_KEYWD(DEFINE_KEYENUM)
};

static char* keywd_name[]={
    DEFINE_KEYWD(DEFINE_KEYNAME)
};

inline char const* get_key_name(int key)
{
    return keywd_name[key - tok(TK_IDENTIFIER)];
}
#endif
#endif
