#ifndef MATRIXDEB      
#define MATRIXDEB
#define DZHDEB

#ifdef DZHDEB
#   define debprintf(format,...) { \
    fprintf(stdout,format,##__VA_ARGS__);\
}
#   define VASDEBUG(n,...) __VA_ARGS__
#   define VASMSG(n, ...) {if(n) {printf("%s", __VA_ARGS__) ;}}
#else
#   define debprintf(format,...) 
#   define VASDEBUG(...) 
#   define VASMSG(...) 
#endif

#define DEBprintf debprintf
#endif             
