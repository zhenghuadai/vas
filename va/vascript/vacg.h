#ifndef __VACG_HEADER__
#define __VACG_HEADER__
#include "cv.h"
#include "cvKernel.h"
#include "debprintf.h"
#include "ccg.h"
#if defined(__GNUC__)
#include <sys/mman.h>
#endif
typedef int i32;
typedef long long i64;
//typedef size_t i32;
typedef unsigned char u8;
typedef unsigned int u32;
typedef void* pvoid;
typedef void (*pfunc)();
//!global variables
const int nFrame_in_pool =16;
const int POOLSIZE =  8;
extern IplImage* pImagePool[POOLSIZE] ;    
extern IplImage* pFrames[nFrame_in_pool];
extern int Prv, Cur, Nxt;
extern IplImage* oFrame ;
extern int numAstNode;
extern char* gVideoIn ;
extern char* gVideoOut ;
extern int gArgc;
extern char** gArgv;
using namespace CCG;
enum{
	ZERO=0, PRV_FRAME= -1, CUR_FRAME = 0, NXT_FRAME=1
};

typedef enum{
	atFUNC=0, atIMM=0, atREF=1, atDIR=2, atFRAME=3,atFILTER=0, atVarFRAME=4, atTmpFRAME=5
}argtype_t;
enum{FILTER_SOBEL=0, FILTER_ROBERT=1};
class argSig{
};

#ifdef __GNUC__
#define WRITE_1CHAR(f,a0) {*f++=a0;}
#define WRITE_2CHAR(f,a0, a1) {*f++=a0; *f++=a1;}
#define WRITE_3CHAR(f,a0, ...) {*f++=a0; WRITE_2CHAR(f,__VA_ARGS__)}
#define WRITE_4CHAR(f,a0, ...) {*f++=a0; WRITE_3CHAR(f,__VA_ARGS__)}
#define WRITE_5CHAR(f,a0, ...) {*f++=a0; WRITE_4CHAR(f,__VA_ARGS__)}
#define WRITE_6CHAR(f,a0, ...) {*f++=a0; WRITE_5CHAR(f,__VA_ARGS__)}
#define WRITE_7CHAR(f,a0, ...) {*f++=a0; WRITE_6CHAR(f,__VA_ARGS__)}
typedef void* PVOID;
#else
#define WRITE_1CHAR(f,a0) {*f++=a0;}
#define WRITE_2CHAR(f,a0,a1)                 {*f++=a0; *f++=a1;}
#define WRITE_3CHAR(f,a0,a1,a2)              {*f++=a0; WRITE_2CHAR(f,a1,a2            )}
#define WRITE_4CHAR(f,a0,a1,a2,a3)           {*f++=a0; WRITE_3CHAR(f,a1,a2,a3         )}
#define WRITE_5CHAR(f,a0,a1,a2,a3,a4)        {*f++=a0; WRITE_4CHAR(f,a1,a2,a3,a4      )}
#define WRITE_6CHAR(f,a0,a1,a2,a3,a4,a5)     {*f++=a0; WRITE_5CHAR(f,a1,a2,a3,a4,a5   )}
#define WRITE_7CHAR(f,a0,a1,a2,a3,a4,a5,a6)  {*f++=a0; WRITE_6CHAR(f,a1,a2,a3,a4,a5,a6)}
#endif
#if __WORDSIZE == 32
#define WRITE_1INT(f, a0) { *((unsigned int*)(f)) = (unsigned int)a0; f+=4;}
#else
#define WRITE_1INT(f, a0) { *((unsigned int*)(f)) = (unsigned int)a0; f+=4;}
#endif

#if 0
//! push the arg pFrames[*idx] onto the stack 
inline void code_pushFrame(u8*& f, int* idx)
{
    u8* f0 = f;
	WRITE_2CHAR(f,	 0x8B, 0x0D) WRITE_1INT(f, idx);//00181C35 8B 0D 20 E5 20 00   mov         ecx,dword ptr [Prv (20E520h)] 
	WRITE_3CHAR(f,	 0x8B, 0x14, 0x8D) WRITE_1INT(f, &pFrames);//00181C3B 8B 14 8D F0 E4 20 00mov         edx,dword ptr pFrames (20E4F0h)[ecx*4] 
	WRITE_1CHAR(f,	 0x52                        );//00181C42 52                  push        edx  
    printf("pushFrame "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}

//! push the arg pFrames[Prv] onto the stack 
inline void code_pushPrvFrame(u8*& f)
{
    u8* f0 = f;
	WRITE_2CHAR(f,	 0x8B, 0x0D) WRITE_1INT(f, &Prv);//00181C35 8B 0D 20 E5 20 00   mov         ecx,dword ptr [Prv (20E520h)] 
	WRITE_3CHAR(f,	 0x8B, 0x14, 0x8D) WRITE_1INT(f, &pFrames);//00181C3B 8B 14 8D F0 E4 20 00mov         edx,dword ptr pFrames (20E4F0h)[ecx*4] 
	WRITE_1CHAR(f,	 0x52                        );//00181C42 52                  push        edx  
    printf("pushPrvFrame "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}
//! push the arg pFrames[Cur] onto the stack 
inline void code_pushCurFrame(u8*& f)
{
    u8* f0 = f;
	WRITE_1CHAR(f,	 0xA1) WRITE_1INT(f, &Cur);//00181C43 A1 30 E0 18 00      mov         eax,dword ptr [Cur (18E030h)] 
	WRITE_3CHAR(f,	 0x8B, 0x0C, 0x85) WRITE_1INT(f, &pFrames);//00181C48 8B 0C 85 F0 E4 20 00mov         ecx,dword ptr pFrames (20E4F0h)[eax*4] 
	WRITE_1CHAR(f,	 0x51                        );//00181C4F 51                  push        ecx  
    printf("pushCurFrame "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}
//! push the arg pFrames[Nxt] onto the stack 
inline void code_pushNxtFrame(u8*& f)
{
    u8* f0 = f;
	WRITE_1CHAR(f,	 0xA1) WRITE_1INT(f, &Nxt);//00181C43 A1 30 E0 18 00      mov         eax,dword ptr [Cur (18E030h)] 
	WRITE_3CHAR(f,	 0x8B, 0x0C, 0x85) WRITE_1INT(f, &pFrames);//00181C48 8B 0C 85 F0 E4 20 00mov         ecx,dword ptr pFrames (20E4F0h)[eax*4] 
	WRITE_1CHAR(f,	 0x51                        );//00181C4F 51                  push        ecx  
    printf("pushNxtFrame "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}


//! push the arg [v] onto the stack; v is the address of variable 
inline void code_pushVarible(u8*&f, void* v){
    u8* f0 = f;
	WRITE_1CHAR(f,	 0xA1) WRITE_1INT(f, v);//00181C2F A1 1C E5 20 00      mov         eax,dword ptr [oFrame (20E51Ch)] 
	WRITE_1CHAR(f,	 0x50                        );//00181C34 50                  push        eax  
    printf("pushVar "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}
inline void code_pushimm8(u8*& f, u8 imm){WRITE_2CHAR(f, 0x6A,imm);}
inline void code_pushimm32(u8*& f, i32 imm){WRITE_1CHAR(f, 0x68);WRITE_1INT(f,imm);}
inline void code_pushimm64(u8*& f, i64 imm){WRITE_1CHAR(f, 0x68);WRITE_1INT(f,imm);}
inline void code_call(u8*& f, void* func){	
	WRITE_1CHAR(f,	 0xB8) WRITE_1INT(f, func);//mov eax, cvSubWrapper
	WRITE_2CHAR(f,   0xFF, 0xD0); // call eax;
}

#else
#define GET_ONE_INSTR() len = pasm->copyto(f); f += len;
//! push the arg pFrames[*idx] onto the stack 
inline void code_pushFrame(u8*& f, int* idx)
{
    u8* f0 = f;
    int len;  
    pasm->trans(MN_MOV, (GPR)GPR_ECX, MemMod((int)(long long)idx));
    GET_ONE_INSTR();
    pasm->trans(MN_MOV, (GPR)GPR_EDX, MemMod((int)(long long)&pFrames, GPR_ECX, 4));
    GET_ONE_INSTR();
    pasm->trans(MN_PUSH, (GPR)GPR_EDX);
    GET_ONE_INSTR();
    printf("pushFrame "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}

//! push the arg pFrames[Prv] onto the stack 
inline void code_pushPrvFrame(u8*& f)
{
    u8* f0 = f;
    int len;  
    pasm->trans(MN_MOV, (GPR)GPR_ECX, MemMod((int)(long long)&Prv));
    GET_ONE_INSTR();
    pasm->trans(MN_MOV, (GPR)GPR_EDX, MemMod((int)(long long)&pFrames, GPR_ECX, 4));
    GET_ONE_INSTR();
    pasm->trans(MN_PUSH, (GPR)GPR_EDX);
    GET_ONE_INSTR();
    printf("pushPrvFrame "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}
//! push the arg pFrames[Cur] onto the stack 
inline void code_pushCurFrame(u8*& f)
{
    u8* f0 = f;
    int len;  
    pasm->trans(MN_MOV, (GPR)GPR_EAX, MemMod((int)(long long)&Cur));
    GET_ONE_INSTR();
    pasm->trans(MN_MOV, (GPR)GPR_ECX, MemMod((int)(long long)&pFrames, GPR_EAX, 4));
    GET_ONE_INSTR();
    pasm->trans(MN_PUSH, (GPR)GPR_ECX);
    GET_ONE_INSTR();
    printf("pushCurFrame "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}
//! push the arg pFrames[Nxt] onto the stack 
inline void code_pushNxtFrame(u8*& f)
{
    u8* f0 = f;
    int len;  
    pasm->trans(MN_MOV, (GPR)GPR_EAX, MemMod((int)(long long)&Nxt));
    GET_ONE_INSTR();
    pasm->trans(MN_MOV, (GPR)GPR_ECX, MemMod((int)(long long)&pFrames, GPR_EAX, 4));
    GET_ONE_INSTR();
    pasm->trans(MN_PUSH, (GPR)GPR_ECX);
    GET_ONE_INSTR();
    printf("pushNxtFrame "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}


//! push the arg [v] onto the stack; v is the address of variable 
inline void code_pushVarible(u8*&f, void* v){
    u8* f0 = f;
    int len;  
    pasm->trans(MN_MOV, (GPR)GPR_EAX, MemMod((int)(long long)v));
    GET_ONE_INSTR();
    pasm->trans(MN_PUSH, (GPR)GPR_EAX);
    GET_ONE_INSTR();
    printf("pushVar "); for(u8* p = f0; p <f; p++) printf("%0x ", *p); printf("\n");
}
inline void code_pushimm8(u8*& f, u8 imm){
    u8* f0 = f;
    int len;  
    pasm->trans(MN_PUSH, (I64)imm);
    GET_ONE_INSTR();
    //WRITE_2CHAR(f, 0x6A,imm);
}
inline void code_pushimm32(u8*& f, i32 imm){
	int len;  
    pasm->trans(MN_PUSH, (I64)imm);
    GET_ONE_INSTR(); 
}
inline void code_pushimm64(u8*& f, i64 imm){
	int len;  
    pasm->trans(MN_PUSH, (I64)imm);
    GET_ONE_INSTR();
}
inline void code_call(u8*& f, void* func){
	int len;
	pasm->trans(MN_MOV, (GPR)GPR_EAX, (I64) func);
	GET_ONE_INSTR();
	pasm->trans(MN_CALL, (GPR)GPR_EAX);
	GET_ONE_INSTR();
}


#endif
void* compile_str(char* dmvscript=NULL);
void* compile_file(char* dmvscript);
inline void release_function(void*& f, size_t size = 1024){
#if defined(_MSC_VER)
    ::VirtualFree(f, 0, MEM_RELEASE);
#elif defined(__GNUC__)
    munmap(f, size);
#endif
    f = 0;
}

/**
 * @brief 
 */
class VaVar{
private:
public:
    typedef void*& value_type;
public:
	argtype_t var_type;
    union{
        void* var;
        int ivar;
    };
public:

    template<typename T>
        VaVar(argtype_t t, T*& v){
            var_type = t;
            if(t == atREF)
                var = &v;
            else
                var = (void*)v;
        }

    template<typename T>
        VaVar(argtype_t t, T** v){
            var_type =t ;
            var = (void*)v;
        }

    VaVar(argtype_t t, size_t v){
        var_type =t ;
        var = (void*)v;
    }

    VaVar(argtype_t t, pfunc v){
        var_type =t ;
        var = (void*)v;
    }
    /**/
    template<typename T>
        VaVar(argtype_t t, T v){
            var_type =t ;
            var = (void*)v;
        }

    //! ref type var
    template<typename T>
        VaVar(T& v){
            var_type =atREF ;
            var = (void*)&v;
        }

    VaVar(){}
public:
    /**
     * @brief The var is an argument of a function call. push_arg does push this arg onto the stack.
     *
     * @param f
     */
    void push_arg(u8*& f){
        switch(var_type){
            case atIMM: code_pushimm32(f, (i32)(unsigned long)var);break;
            case atREF:push_ref(f);break;
            case atDIR:break;
            case atFRAME:push_frame(f);break;
            case atVarFRAME:push_frame(f);break;
            case atTmpFRAME:push_frame(f);break;
        }
    }
    void call(u8*& f){code_call(f, var);}
    void dump(FILE* fp){fprintf(fp, "<Type:%3d,Addr:%p>",var_type,var);}
    void setValue(void* v){var = v;}
    void setType(argtype_t t){var_type =t ;}

private:
    void push_ref(u8*& f){code_pushVarible(f, (void*)var);}
    void push_imm(u8*& f){}
    void push_frame(u8*& f){
        if( ( ((long)(var)) < 16) &&(((long)var)>-16)){// predefined frame
        }
        switch ((long)var)
        {
            case PRV_FRAME: code_pushPrvFrame(f); break;
            case CUR_FRAME: code_pushCurFrame(f);break;
            case NXT_FRAME: 
                            //code_pushNxtFrame(f);
                            printf("Nxt: %p\n", pFrames[Nxt]);
                            code_pushFrame(f, &Nxt);
                            break;
            default:
                            code_pushVarible(f, (void*)var);
                            break;
        }
    }


};
/*  
    template<argtype_t T>
    class VaVar:public VaVar
    {
    };

    template<>
    class VaVar<atREF>:public VaVar
    {
    public:
    template<typename varT>
    VaVar(varT*& ref){var_type=atREF; var=&ref;}
    };
    */
#if defined(_MSC_VER)
typedef VaVar& VaVarRef;
#elif defined(__GNUC__)
typedef VaVar VaVarRef;
#endif

/**
 * @brief 
 */
class vaCG
{
    public:
        vaCG():f(NULL), f0(NULL){}
        void init(int size=1024){ if(f0)release_function((void*&)f0, this->size); setf(vacgmalloc(size)); this->size= size;}
        //void init(){ init(1024);}
        void reset(){}
    public:
        //!accessor
        u8*& getf(){return f;}
        u8* getf0(){return f0;}
    public:

        //!static
        static inline void code_addespimm(u8*& f, int imm){WRITE_3CHAR(f, 0x83,0xC4,imm)}
        static inline void code_ret(u8*& f){ *f++ = 0xc3;}
        static void call_general(u8*& f, VaVarRef, VaVarRef, VaVarRef,VaVarRef,VaVarRef);
        static void call_Detect(u8*& f, VaVarRef, VaVarRef, VaVarRef);
        static void copy_frame(u8*& f, VaVarRef dst, VaVarRef src1);
        static void sub_frame(u8*& f, VaVarRef dst, VaVarRef src1, VaVarRef src2);

        static inline u8* vacgmalloc(int size){
#if defined(_MSC_VER)
            return (u8*)::VirtualAlloc(NULL, size,MEM_RESERVE|MEM_COMMIT ,PAGE_EXECUTE_READWRITE); 
#elif defined(__GNUC__)
            return (u8*) mmap(
                    NULL,
                    size,
                    PROT_READ | PROT_WRITE | PROT_EXEC,
                    MAP_ANONYMOUS | MAP_PRIVATE,
                    0,
                    0);
            //return (u8*) malloc(size);
#endif
        }
    public:
        inline void code_adjustesp(u8*& f){}
        inline void code_addespimm(int imm){ return code_addespimm(f, imm);}
        inline void code_ret(){ return code_ret(f);}
        void setf(u8* _f){f0=f=_f;}
        void call_general(VaVarRef func, VaVarRef src2, VaVarRef src3,VaVarRef src4,VaVarRef src5){call_general(f, func, src2, src3, src4, src5);}
        void call_Detect(VaVarRef dst, VaVarRef src1, VaVarRef oper){call_Detect(f, dst, src1, oper);};
        void copy_frame(VaVarRef dst, VaVarRef src1){copy_frame(f, dst, src1);};
        void sub_frame(VaVarRef dst, VaVarRef src1, VaVarRef src2){sub_frame(f, dst, src1,src2);};
    public:
    private:
        void start_pusharg(){};
        void end_pusharg(){}
    public:
        void* test_ccg();
        void* test_ccg2();
        void dumpCode(){ for(u8* p = f0; p<f; p++) printf("%0x ", *p);}
    private:
        u8* f;//! From f, the code will be written in.
        u8* f0;//! From f, the code will be written in.
        size_t size;
};


extern vaCG gvacg;
using namespace dmFrameSimple;
#endif
