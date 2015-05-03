#ifndef __OPCODE_DES_HEADER__
#define __OPCODE_DES_HEADER__
#pragma once
#include "op_x86_32.h"
#include "op_x86_64.h"
#include "opname_x86.h"
#ifdef _WINDEF_
#undef IN
#undef OUT
#endif

namespace CCG{
typedef float F32;
typedef double F64;
typedef unsigned long long U64;
typedef unsigned int  U32;
typedef unsigned short U16;
typedef unsigned char U8;
typedef unsigned char Uchar;
typedef long long I64;
typedef int I32;
typedef short I16;
typedef char I8;

#define NULLOPC2 0xCC
#define declareDefaultValue(v) \
    template< unsigned int N=0x##v>\
class default##v{\
    public:\
           enum {\
               value = N\
           };\
};

declareDefaultValue(0);
declareDefaultValue(CC);
declareDefaultValue(FF);

#define opName( n) MN_##n  
#define declareOpName(n) opName(n) ,
typedef enum{
    opNameList(declareOpName)
        instructionNum
}MN;

template<MN mn>
class MNname{};

#define defineMN2str(n) \
template<>class MNname< opName(n)>{public: static const char* name(){return #n;};};
#define declareMNname(n) #n,  
opNameList(defineMN2str);
static const char* MNnames[]={
opNameList(declareMNname)
};

#define opc1_R2RM 1
#define opc1_RM2R 0
class OPC1
{
    public:
        union {
            Uchar c;
            struct{
                unsigned int w:1;
                unsigned int d:1;
                unsigned int o:6;
            };
            struct{
                unsigned int reg:3;
                unsigned int code:5;
            };
        };
    public:
        OPC1(Uchar _c){c = _c;}
        OPC1(){c =0;}
        void setW(){w = 1;}
        void setW(Uchar _w){w = _w;}
        void clearW(){w=0;}
        void setRM2R(){w=0;}
        void setR2RM(){w=1;}

        void setD(){d=1;}
        void setD(Uchar _d){d=_d;}
        void clearD(){d=0;}

        void setReg(Uchar r){reg = r;}
};

typedef enum {
CodeOrdinary=0,
CodeOneByte=0xFD,
} CodeType;

#define regop_r 0xFE
#define regop_s 0xFD
#define regop_0 0x00
#define regop_1 0x01
#define regop_2 0x02
#define regop_3 0x03
#define regop_4 0x04
#define regop_5 0x05
#define regop_6 0x06
#define regop_7 0x07
#define regop_  0xFF
#define oper_   0xFF
#define oper_Empty  oper_ 


class OpInfo
{
    public:
        MN    mn;
        Uchar oper1; 	//OPerKind
        Uchar oper2; 	//OPerKind
        Uchar oper3; 	//OPerKind
        Uchar oper4; 	//OPerKind
        Uchar iext;   	// instruction extention
        Uchar prefix;
        Uchar prefix0F;
        OPC1 opc1; 	// first OPCODE
        Uchar opc2; 	// second OPCODE
        Uchar opreg; 	// third 3-bit OPCODE or register
        Uchar proc; 	// introduce with processor
        Uchar st;   	// status of document
        Uchar mode ; 	// mode of operation
        Uchar ringLevel;
        Uchar prefixLock;
        unsigned int testedFlag;
        unsigned int modifFlag;
        unsigned int defFlag;
        unsigned int undefFlag;
        unsigned int FlagValues;
        char* description;
        CodeType codeType;
    public:
        OpInfo(
                MN _mnemonic,Uchar _oper1, 	Uchar _oper2, 	Uchar _oper3, 	Uchar _oper4, 	Uchar _iext,   	Uchar _prefix,Uchar _prefix0F,Uchar _opc1, 	Uchar _opc2, 	Uchar _opreg, 	Uchar _proc, 	Uchar _st,   	Uchar _mode , 	Uchar _ringLevel,Uchar _prefixLock,unsigned int _testedFlag,unsigned int _modifFlag,unsigned int _defFlag,unsigned int _undefFlag,unsigned int _FlagValues,char* _description, CodeType ct = CodeOrdinary)
            :mn(_mnemonic),
            oper1(_oper1),
            oper2(_oper2),
            oper3(_oper3),
            oper4(_oper4),
            iext(_iext),
            prefix(_prefix),
            prefix0F(_prefix0F),
            opc1(_opc1),
            opc2(_opc2),
            opreg(_opreg),
            proc(_proc),
            st(_st),
            mode(_mode),
            ringLevel(_ringLevel),
            prefixLock(_prefixLock),
            testedFlag(_testedFlag),
            modifFlag(_modifFlag),
            defFlag(_defFlag),
            undefFlag(_undefFlag),
            FlagValues(_FlagValues),
            description(_description),
            codeType(ct)
    {};
        int isMnEmpty()   const{}
        int isOper1Empty()const{} 	//OPerKind
        int isOper2Empty()const{return (oper2 == oper_Empty); } 	//OPerKind
        int isOper3Empty()const{} 	//OPerKind
        int isOper4Empty()const{} 	//OPerKind
        int isIextEmpty()const{}   	// instruction extention
        int isPrefixEmpty()  const{ return (prefix==0xFF);}
        int isPrefix2Empty()const{return (prefix0F == 0xFF);}
        int isOpc1Empty() const{} 	// first OPCODE
        int isOpc2Empty() const{} 	// second OPCODE
        int isOpregEmpty()const{ return (opreg == regop_ );} 	// third 3-bit OPCODE or register
        int isProcEmpty() const{} 	// introduce with processor
        int isStEmpty()   const{}   	// status of document
        int isModeEmpty() const{} 	// mode of operation
        int isRingLevelEmpty() const{}
        int isPrefixLockEmpty()const{}
        int isTestedFlagEmpty()const{}
        int isModifFlagEmpty() const{}
        int isDefFlagEmpty()   const{}
        int isUndefFlagEmpty() const{}
        int isFlagValuesEmpty()const{}
        int isDescriptionEmpty()const{}
		int isOper1RM()const{ return (oper1 >= 224);}
		int isOper2RM()const{ return (oper2 >= 224);}
        //CodeType getCodeType()const{return CodeType;}
        int isCodeOneByte()const{ return opreg == regop_s;}
        int isOpregReg()const{ return (opreg == regop_r );} 	// third 3-bit OPCODE or register


};
#define OpInfoArgList(mnemonic, oper1, oper2, oper3, oper4, iext, prefix1,  prefix0F,  opc1,  opc2,  regop,   proc,    st,  m ,  ringL,  x,   testedFlag,    modifFlag, defFlag,   undefFlag, FlagValues,    description) \
    MN_##mnemonic,(Uchar) oper_##oper1,(Uchar)  oper_##oper2,(Uchar)  oper_##oper3,(Uchar)  oper_##oper4,(Uchar)  0, \
(Uchar) defaultFF<prefix1>::value, (Uchar) defaultFF<prefix0F>::value, (Uchar) default0<opc1>::value, (Uchar) defaultCC<opc2>::value, (Uchar) regop_##regop, \
(Uchar) 0xff, (Uchar) 0xff, (Uchar) 0xff, (Uchar) 0xff, (Uchar)0xff, (unsigned int) 0x00,\
(unsigned int) 0x00,(unsigned int) 0x00,(unsigned int) 0x00, (unsigned int) 0x00, (char*) #description

//#define decOP(...) OpInfo( OpInfoArgList(__VA_ARGS__) ),
//! winodws macro is different with linux
#define decOP(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21) OpInfo( OpInfoArgList(a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16,a17,a18,a19,a20,a21) ),

}// namespace CCG

#ifdef _WINDEF_

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#endif

#endif

