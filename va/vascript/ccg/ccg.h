/*
 * =====================================================================================
 *
 *       Filename:  ccg.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghua Dai (Zhenghua Dai), djx.zhenghua@gamil.com
 *        Company:  dzh
 *
 * =====================================================================================
 */
#ifndef __CCG_HEADER__
#define __CCG_HEADER__
#include <stdio.h>
#include <stdlib.h>
#include "opcodeDes.h"
namespace CCG{

	
enum{DM_SUCCESS = 0};
typedef    enum{SYS_32 = 0, SYS_64} ArchType;
extern bool System64Bits;    
inline bool Is64System(){ return  System64Bits;}    
inline bool Is32System(){ return  !System64Bits;}    
inline void Set64System(){ System64Bits = true;}    
inline void Set32System(){ System64Bits = false;}    

#define defineRegB( Op) \
Op(AL, 0) \
Op(CL, 1) \
Op(DL, 2) \
Op(BL, 3) \
Op(AH, 4) \
Op(CH, 5) \
Op(DH, 6) \
Op(BH, 7) 

#define defineRegW( Op) \
Op(AX, 8) \
Op(CX, 9) \
Op(DX, 10) \
Op(BX, 11) \
Op(SP, 12) \
Op(BP, 13) \
Op(SI, 14) \
Op(DI, 15) \
              
#define defineRegE( Op) \
Op(EAX, 16) \
Op(ECX, 17) \
Op(EDX, 18) \
Op(EBX, 19) \
Op(ESP, 20) \
Op(EBP, 21) \
Op(ESI, 22) \
Op(EDI, 23) \

#define defineRegQ( Op) \
Op(RAX, 24) \
Op(RCX, 25) \
Op(RDX, 26) \
Op(RBX, 27) \
Op(RSP, 28) \
Op(RBP, 29) \
Op(RSI, 30) \
Op(RDI, 31) \

#define defineRegQe( Op) \
Op(R8 , 32) \
Op(R9 , 33) \
Op(R10, 34) \
Op(R11, 35) \
Op(R12, 36) \
Op(R13, 37) \
Op(R14, 38) \
Op(R15, 39) \

#define defineRegX( Op) \
Op(xmm0 , 40) \
Op(xmm1 , 41) \
Op(xmm2 , 42) \
Op(xmm3 , 43) \
Op(xmm4 , 44) \
Op(xmm5 , 45) \
Op(xmm6 , 46) \
Op(xmm7 , 47) \

#define defineRegXe( Op) \
Op(xmm8 , 48) \
Op(xmm9 , 49) \
Op(xmm10, 50) \
Op(xmm11, 51) \
Op(xmm12, 52) \
Op(xmm13, 53) \
Op(xmm14, 54) \
Op(xmm15, 55) \

#define defineRegSt( Op) \
/*Op(st,  56)*/ \
Op(st0,  56) \
Op(st1, 57) \
Op(st2, 58) \
Op(st3, 59) \
Op(st4, 60) \
Op(st5, 61) \
Op(st6, 62) \
Op(st7, 63) \

#define defineRegSpecial( Op) \
Op(GS,      64) \
Op(CR0,     66) \
Op(GDTR,    67) \
Op(LDTR,    68) \
Op(CRn,     76) \
Op(DRn,     77) \
Op(IDTR,    79) \
Op(MSW,     80) \
Op(FLAGS,   81) \
Op(EFLAGS,  82) \
Op(RFLAGS,  83) \
Op(FS,      85) \
Op(MSR,     86) \
Op(PMC,     87) \
Op(SS,      88) \
Op(TR,      89) \
Op(CS,      90) \
Op(DS,      91) \
Op(ES,      92) \

#define defineAllReg(Op) \
defineRegB(Op) \
defineRegW(Op) \
defineRegE(Op) \
defineRegQ(Op) \
defineRegQe(Op) \
defineRegX(Op) \
defineRegXe(Op) \
defineRegSt(Op) \
defineRegSpecial(Op) 

//! 8 16 32 64 
#define operkind(t) oper_##t 
#define defineOperKind(t, v) operkind(t) = v
#define defineOperKind2(t, v, s1, s2) operkind(t) = v
#define defineOperKind3(t, v, s1, s2, s3) operkind(t) = v


#define oper_imm8 oper_i8
#define oper_xmm oper_X 
#define oper_eAX oper_EAX
#define oper_eCX oper_ECX
#define oper_eDX oper_EDX
#define oper_mm oper_M 
#define oper_ST oper_st
#define oper_STi oper_sti
#define oper_ST1 oper_st1
#define oper_ST2 oper_st2
#define oper_immWD oper_iWD
#define oper_immWDQ oper_iWDQ
#define oper_m32f oper_m32 
#define oper_m32int oper_m32 
#define oper_m64f oper_m64 
#define oper_m64int oper_m64 
#define oper_m16int oper_m16 
#define oper_m80real oper_m80 
#define oper_Flags oper_FLAGS 
#define oper_EFlags oper_EFLAGS 
#define oper_eFlags oper_EFLAGS 
#define oper_RFlags oper_RFLAGS 
#define oper_m14o28B  oper_m14o28
#define oper_m94o108B oper_m94o108 
#define oper_m64o16 oper_mWQ 
#define oper_rm64o16 oper_rmWQ 
#define oper_r64o16 oper_rWQ 
#define oper_mDQ oper_mWDQ 
#define oper_ooo 0xFE
#define oper_relWD oper_iWD
#define oper_eBP oper_rBP


typedef enum {
//defineRegB(defineOperKind ),
defineOperKind(AL, 0),
defineOperKind(CL, 1),
defineOperKind(DL, 2),
defineOperKind(BL, 3),
defineOperKind(AH, 4),
defineOperKind(CH, 5),
defineOperKind(DH, 6),
defineOperKind(BH, 7),

defineOperKind(AX, 8),
defineOperKind(CX, 9),
defineOperKind(DX, 10),
defineOperKind(BX, 11),
defineOperKind(SP, 12),
defineOperKind(BP, 13),
defineOperKind(SI, 14),
defineOperKind(DI, 15),
                          
defineOperKind(EAX, 16),
defineOperKind(ECX, 17),
defineOperKind(EDX, 18),
defineOperKind(EBX, 19),
defineOperKind(ESP, 20),
defineOperKind(EBP, 21),
defineOperKind(ESI, 22),
defineOperKind(EDI, 23),

defineOperKind(RAX, 24),
defineOperKind(RCX, 25),
defineOperKind(RDX, 26),
defineOperKind(RBX, 27),
defineOperKind(RSP, 28),
defineOperKind(RBP, 29),
defineOperKind(RSI, 30),
defineOperKind(RDI, 31),

defineOperKind(R8 , 32),
defineOperKind(R9 , 33),
defineOperKind(R10, 34),
defineOperKind(R11, 35),
defineOperKind(R12, 36),
defineOperKind(R13, 37),
defineOperKind(R14, 38),
defineOperKind(R15, 39),

defineOperKind(xmm0 , 40),
defineOperKind(xmm1 , 41),
defineOperKind(xmm2 , 42),
defineOperKind(xmm3 , 43),
defineOperKind(xmm4 , 44),
defineOperKind(xmm5 , 45),
defineOperKind(xmm6 , 46),
defineOperKind(xmm7 , 47),
defineOperKind(xmm8 , 48),
defineOperKind(xmm9 , 49),
defineOperKind(xmm10, 50),
defineOperKind(xmm11, 51),
defineOperKind(xmm12, 52),
defineOperKind(xmm13, 53),
defineOperKind(xmm14, 54),
defineOperKind(xmm15, 55),

defineOperKind(st,  56),
defineOperKind(st1, 57),
defineOperKind(st2, 58),

#define defineOperKindComma(x, y) defineOperKind(x,y),
defineRegSpecial( defineOperKindComma)
/*  
defineOperKind(GS,      64),
defineOperKind(CR0,     66),
defineOperKind(GDTR,    67),
defineOperKind(LDTR,    68),
defineOperKind(CRn,     76),
defineOperKind(DRn,     77),
defineOperKind(IDTR,    79),
defineOperKind(MSW,     80),
defineOperKind(FLAGS,   81),
defineOperKind(EFLAGS,  82),
defineOperKind(RFLAGS,  83),
defineOperKind(FS,      85),
defineOperKind(MSR,     86),
defineOperKind(PMC,     87),
defineOperKind(SS,      88),
defineOperKind(CS,      89),
defineOperKind(DS,      90),
defineOperKind(ES,      91),
defineOperKind(TR,      92),
*/

defineOperKind(rel8,    69),
defineOperKind(rel32,   70),

defineOperKind(STiom32f, 100),
defineOperKind(1,       84),
defineOperKind(IA32_BIOS_Sooo, 101),
defineOperKind(IA32_SYSENooo, 102), 
defineOperKind(IA32_SYSEooo, 103), 
defineOperKind(IA32_SYSENTooo, 104), 
defineOperKind(IA32_KERNEooo, 105), 
defineOperKind(Sreg, 106), 
defineOperKind(IA32_TIMEooo, 107), 
defineOperKind(3, 108),
defineOperKind(ptr16OWD, 109), 
defineOperKind(m16OWD, 110), 
defineOperKind(IA32_BIOooo, 111), 
defineOperKind(IA32_Tooo, 112), 
defineOperKind(IA32_SYSooo, 113), 
defineOperKind(IA32_Sooo, 114), 

#define defineOperKindContainer(op) \
/*!100* *****/\
/*!128 ~ 159 32*/\
\
op(i8,  128+0),\
op(i16, 128+1),\
op(i32, 128+2),\
op(i64, 128+3),\
op(i128,128+4),\
op(iWD, 128+5),\
op(iWDQ,128+6),\
\
\
\
\
\
\
/*!101* **** m*/\
/*!160 ~191   32*/\
op(m8,  160+ 0),\
op(m16, 160+ 1),\
op(m32, 160+ 2),\
op(m64, 160+ 3),\
op(m128,160+ 4),\
op(m512,160+ 5),\
op##3(mWDQ,160+ 6, m16, m32, m64),\
op##2(mWD, 160+ 7, m16, m32),\
op(m16OWDQ, 160+ 8),\
op(m80,     160+ 9),\
op(m80dec,  160+ 10),\
op(m14o28B, 160+ 11),\
op(m94o108B, 160+ 12),\
op(m,   191),\
op(moffs8, 160+13),\
op(moffsWD, 160+14),\
op(moffsWDQ, 160+15),\
\
\
/*!110* **** r*/\
/*!192 ~ 223 32*/\
op(r8,  192+ 0),\
op(r16, 192+ 1),\
op(r32, 192+ 2),\
op(r64, 192+ 3),\
op(M,   192+ 4),\
op(X,   192+ 5),\
op##2(rDQ, 192+ 6 , r32, r64),\
op##3(rWDQ,192+ 7  , r16, r32, r64),\
op##2(rWQ, 192+ 8  , r16, r64),\
op##2(rWD, 192+ 9  , r16, r32),\
op##3(rAX, 192+ 11 , ax, eax, rax),\
op##3(rCX, 192+ 12 , cx, ecx, rcx),\
op##3(rDX, 192+ 13 , dx, edx, rdx),\
op##2(rBP, 192+ 14 , ebp, rbp),\
op(sti, 192+ 15),\
op(r,   223),\
                    \
/*!111* **** rm */\
/*!224 ~ 255 32*/\
op##2(rm8, 224+0, r8, m8),\
op(rm16,225),\
op(rm32,226),\
op(rm64,227),\
op(Mm64,228),\
op(Xm128,229),\
op(rmWDQ,230),\
op(Xm32 ,231),\
op(Xm64 ,232),\
op(rmDQ, 233),\
op(rmWD, 234),\
op(rmWQ, 235),\
op(rm,   255),


defineOperKindContainer(defineOperKind)  
defineOperKind(NULL, 0xff)
}OPerKind;




typedef unsigned char Uchar;
#define PREFIX(x) pre_##x
#define decPREFIX( group, y, z)  PREFIX(y)= 0x ## z,
typedef enum {
decPREFIX(GPRLOCK,LOCK, 	F0)
decPREFIX(GPRREP, REPNZ, 	F2)
decPREFIX(GPRREP, REP, 		F3)
}PREFIX1;

typedef enum {
decPREFIX(GPRSEG, CS, 		2E)
decPREFIX(GPRSEG, SS, 		36)
decPREFIX(GPRSEG, DS, 		3E)
decPREFIX(GPRSEG, ES, 		26)
decPREFIX(GPRSEG, FS, 		64)
decPREFIX(GPRSEG, GS, 		65)
}PREFIX2;


typedef enum {
decPREFIX(GPROPS, bits16In32, 	66)
decPREFIX(GPROPS, bits64, 	48)
}PREFIX3;

typedef enum {
decPREFIX(GPRADDr,addr16In32, 	67)
decPREFIX(GPRADDr,addr32In64, 	67)
}PREFIX4;

#define GPR(x) GPR_##x
#define DEF_REG(x, y) GPR(x)=y,

typedef enum{ 
DEF_REG(AL, 0)
DEF_REG(CL, 1)
DEF_REG(DL, 2)
DEF_REG(BL, 3)
DEF_REG(AH, 4)
DEF_REG(CH, 5)
DEF_REG(DH, 6)
DEF_REG(BH, 7)
//defineRegB(DEF_REG)
} GPRB;

typedef enum{
DEF_REG(AX, 8)
DEF_REG(CX, 9)
DEF_REG(DX, 10)
DEF_REG(BX, 11)
DEF_REG(SP, 12)
DEF_REG(BP, 13)
DEF_REG(SI, 14)
DEF_REG(DI, 15)
} GPRW;


typedef enum{
DEF_REG(EAX, 16)
DEF_REG(ECX, 17)
DEF_REG(EDX, 18)
DEF_REG(EBX, 19)
DEF_REG(ESP, 20)
DEF_REG(EBP, 21)
DEF_REG(ESI, 22)
DEF_REG(EDI, 23)
} GPRE;

typedef enum{
DEF_REG(RAX, 24)
DEF_REG(RCX, 25)
DEF_REG(RDX, 26)
DEF_REG(RBX, 27)
DEF_REG(RSP, 28)
DEF_REG(RBP, 29)
DEF_REG(RSI, 30)
DEF_REG(RDI, 31)
//} GPRR;


//typedef enum{
DEF_REG(R8 , 32)
DEF_REG(R9 , 33)
DEF_REG(R10, 34)
DEF_REG(R11, 35)
DEF_REG(R12, 36)
DEF_REG(R13, 37)
DEF_REG(R14, 38)
DEF_REG(R15, 39)
//} GPRext;
} GPRR;

//typedef unsigned int GPR;
#define declareAllReg(r, n) R_##r=n,
typedef enum {
defineAllReg( declareAllReg)
}GPR;
static const char* GPR_r_name[16]={"rax", "rcx","rdx","rbx","rsp","rbp","rsi","rdi","r8", "r9", "r10", "r11","r12", "r13","r14", "r15" };
static const char* GPR_e_name[8]={"eax", "ecx","edx","ebx","esp","ebp","esi","edi"};
static const char* GPR_w_name[8]={ "ax", "cx", "dx", "bx", "sp", "bp", "si", "di" };
static const char* GPR_c_name[8]={ "al", "cl", "dl", "bl", "ah", "ch", "dh", "bh" };

template<Uchar r>
class RegName{};

#define defineReg2str(n,num) \
template<>class RegName< GPR(n)>{public: static const char* name(){return #n;};};
defineRegB(defineReg2str);
defineRegW(defineReg2str);
defineRegE(defineReg2str);
defineRegQ(defineReg2str);
defineRegQe(defineReg2str);


typedef enum{
xmm0 = 40,
xmm1 = 41,
xmm2 = 42,
xmm3 = 43,
xmm4 = 44,
xmm5 = 45,
xmm6 = 46,
xmm7 = 47,
//} XMMS;
//
//
//typedef enum{
xmm8 = 48,
xmm9 = 49,
xmm10= 50,
xmm11= 51,
xmm12= 52,
xmm13= 53,
xmm14= 54,
xmm15= 55,
} XMMS;

typedef enum{
st0 = 56,
st1 = 57,
st2 = 58,
st3 = 59,
st4 = 60,
st5 = 61,
st6 = 62,
st7 = 63,
} STS;

#define defineReg2str2(n,num) \
template<>class RegName< n>{public: static const char* name(){return #n;};};
defineRegX (defineReg2str2);
defineRegXe(defineReg2str2);
defineRegSt(defineReg2str2);

#define declareReg2str(n,num) #n,  
static const char* regNames[]={
defineRegB(declareReg2str)
defineRegW(declareReg2str)
defineRegE(declareReg2str)
defineRegQ(declareReg2str)
defineRegQe(declareReg2str)
defineRegX (declareReg2str)
defineRegXe(declareReg2str)
defineRegSt(declareReg2str)
};

typedef enum{
	regL = 0,    	reg8 = 0, 
	regW = 1,    	reg16 = 1,
	regE = 2,
	regR = 3,
	regRext=4,
	regX = 5,
	regXext=6,
	regSt=7
}rGroup;
#define RGROUPMASK (7<<3)
inline rGroup getRegGroup(GPR r){    return (rGroup) ((r & RGROUPMASK) >> 3);}

inline unsigned int opcode(MN x)
{
	return 0;
}


inline int isExt(GPR reg){
	return ( (( reg >=(GPR) GPR(R8)) && (reg <=(GPR)GPR(R15) )) ||(( reg >=(GPR)xmm8) && (reg <=(GPR)xmm15 )) );
}

inline int isRegL(GPR reg) { return  ( reg & RGROUPMASK) == (regL << 3);}
inline int isRegW(GPR reg) { return  ( reg & RGROUPMASK) == (regW << 3);}
inline int isRegE(GPR reg) { return  ( reg & RGROUPMASK) == (regE << 3);}
inline int isRegR(GPR reg) { return  ( reg & RGROUPMASK) == (regR << 3);}
inline int isRegRext(GPR reg) { return  ( reg & RGROUPMASK) == (regRext << 3);}
inline int isRegX(GPR reg) { return  ( reg & RGROUPMASK) == (regX << 3);}
inline int isRegXext(GPR reg){  return ( reg & RGROUPMASK) == (regXext << 3);}
typedef enum{
	op_x = 0,
	op_r2r,
	op_e2e,
	op_X2X,
}opPattern;

/******************************************************************
 *! I1. 
 *! 1-byte opcode
 *! opcode:5bit  REG:3bit
 *! +-----------+--------+
 *! ;  OPCODE   ;REGISTER;
 *! +-----------+--------+
 *! ; 0 1 0 1 0 ; 0 0 0  ;
 *! +-----------+--------+
 *! inc reg, dec reg, push reg, pop reg, xchg eax,reg, mov reg,imm32
 *! for example:  PUSH REG <------> 01010reg
 *! PUSH EAX  --->  50h       --->  01010 000
 *! 01000reg : INC  REG       
 *! 01001reg : DEC  REG       
 *! 01010reg : PUSH REG       
 *! 01011reg : POP  REG       
 *! 10010reg : XCHG EAX,REG   
 *! 10111reg : MOV  REG,IMM32 
 ******************************************************************/
/******************************************************************
 *! I2. 
 *! 2-byte opcode
 *! opcode:8bit 			ModRM:8bit 
 *! +----------------+   +------------------+
 *! ; instr  ; d ; w ;   ; Mod; REG1 ; RM2 ;
 *! +--------+---+---;   +----+------+------+
 *! ; 100010 ; 0 ; 1 ;   ; 11 ; 000  ; 001  ;
 *! +--------+---+---+   +----+------+------+
 *! d: 0  RM2-REG1 
 *!    1  REG1-RM2
 *! w: 0  8bits  mode in 32-bit/16-bit system
 *!    1  32bits  mode in 32-bit system, 16bits mode in 16-bit system
 *!
 *! [CODE]             [ModR/M]            [CODE]             [ModR/M]
 *! +----------------;;------------------+  +----------------;;------------------+
 *! ; instr  ; d ; w ;; Mod; REG1 ; REG2 ;  ; instr  ; d ; w ;; Mod; REG1 ; REG2 ;
 *! +--------+---+---;;----+------+------+  +--------+---+---;;----+------+------+
 *! ; 100010 ; 0 ; 1 ;; 11 ; 000  ; 001  ;  ; 100010 ; 1 ; 1 ;; 11 ; 000  ; 001  ;
 *! +--------+---+---;;----+------+------+  +--------+---+---;;----+------+------+
 *!  MOV      !  32b          EAX    ECX       MOV       32b   \      EAX    ECX
 *!        					or AX  or CX       					    or AX  or CX
 *!      					or AL  or CL             				or AL  or CL
 *! the order REG2(RM)-REG1                         the orderis REG1-REG2(RM)
 *! \_______________  _________________/      \_______________  _________________/
 *! 				\/                                        \/
 *! 			MOV ECX,EAX                           	MOV EAX,ECX
 *!
 *! BINARY       OPCODE
 *! -----------------------
 *! 000010dw    OR  REG,REG
 *! 001000dw    AND REG,REG
 *! 001010dw    SUB REG,REG
 *! 001100dw    XOR REG,REG
 *! 001110dw    CMP REG,REG
 *! 100000dw    ADD REG,REG
 *! 100010dw    MOV REG,REG
 *******************************************************************/
enum{

};

/*****************************************************************
 * 1. REX PREFIX  [opcode    REG]
 *    0100W00B               xxx
 *                          Bxxx
 * 2. REX PREFIX  [opcode ] [Mod    REG    R/M]                        
 *    0100WR0B               !=11   rrr    bbb
 *                                 Rrrr   Bbbb 
 * 3. REX PREFIX  [opcode ] [Mod    REG    R/M]                        
 *    0100WR0B               11     rrr    bbb
 *                                 Rrrr   Bbbb 
 * 4. REX PREFIX  [opcode ] [Mod    REG    R/M] [scale index base]
 *    0100WRXB               !=11   rrr    100    ss    xxx   bbb 
 *                                 Rrrr                Xxxx  Bbbb 
 *
 * **************************************************************/
class REX{
	public:
		union {
			struct{
				unsigned int B:1; //Extension of the ModR/M r/m field, SIB base field, or Opcode reg field
				unsigned int X:1; //Extension of the SIB index field 
				unsigned int R:1; //Extension of the ModR/M reg field
				unsigned int W:1; //0 = Operand size determined by CS.D ; 1 = 64 Bit Operand Size
				unsigned int reserve:4;
			};
			char c;
		};
	public:
		void init(){c = 0; reserve = 4;}
		void setB(){this->B = 1;}
		void setX(){this->X = 1;}
		void setR(){this->R = 1;}
		void setW(){this->W = 1;}
		void setB(unsigned char b){this->B = b;}
		void setX(unsigned char b){this->X = b;}
		void setR(unsigned char b){this->R = b;}
		void setW(unsigned char b){this->W = b;}
		void clean(){c=0;reserve =4;}

		REX(){init();}
};

class ModRM
{
	public:
		union{
			struct{
				unsigned int RM:3;
				unsigned int Reg:3;
				unsigned int Mod:2;
			};
			struct{
				unsigned int RM2:3;
				unsigned int Opcode:3;
				unsigned int Mod2:2;
			};
			unsigned char c;
		};
	public:
		ModRM():c(0){}
		ModRM(const ModRM& o){ this->c = o.c;}
		ModRM(int mod, int reg, int rm):Mod(mod),Reg(reg),RM(rm){};
		void setRRm(Uchar dst, Uchar src){ Mod = 3; Reg=dst; RM=src;}
		void setRmR(Uchar dst, Uchar src){ Mod = 3; Reg=src; RM=dst;}
		void setMod(Uchar m){Mod =m;}
		void setRm(Uchar rm){RM =rm;}
		void setR(Uchar r){Reg = r;}
		void setOpcode(Uchar op){Opcode =op;}
		void clean(){c=0;}
#define MOD_MASK (3<<6)
#define RM_MASK (7)
#define REG_MASK (7<<3)
		//void setMod(Uchar m){c &= ~MOD_MASK; c |= ((m& 3)<<6);}
		//void setRm(Uchar rm){c &= ~RM_MASK;  c |= ((rm&7)   );}
		//void setR(Uchar r)  {c &= ~REG_MASK; c |= ((r&7) <<3);}
};

class SIB
{
	public:
		union{
			struct{
				unsigned int Base:3;
				unsigned int Index:3;
				unsigned int SS:2;
			};
			unsigned char c;
		};
	public:
		SIB():c(0){}
		SIB(const SIB& o){c= o.c;}
		SIB(int b, int i, int s):Base(b), Index(i), SS(s){}
		void clean(){c=0;}
};

typedef enum{
	scale0= 0,
	scale2= 2,
	scale4= 4,
	scale8= 8
}SIBScale;
//#define scale(n) scale##n


/************************************************
 *                               8              0       8               0
 *                               mod(2) reg(3) rm(3)    SS(2) index(3) base(3)  Disp
 *(r)                            00      x     r         -        -     -        x
 *(base + disp)                  01/10   x     r         -        -     -        x  
 *(base + index + disp)          01/10   x     100       0        x     x        x
 *(base + index )                00      x     100       0        x     x        -
 *(base + index*scale + disp)    01/10   x     100       x        x     x        - 
 * *********************************************/
class MemMod
{
	private:
		REX rex;
		ModRM modrm;
		SIB sib;
		union{
			char off8;
			int  off32;
			I64 off64;
		};
        //! store the type (R E ... and so on);
        ModRM regType;
	private:
		int checkScale(int scale){
			return sscode(scale);
		}
	public:
		int haveDisp()const {
            if(modrm.Mod == 1) 
                // m8
                return modrm.Mod ;
            else if (modrm.Mod == 2)
                // m32
                return 3;
            else if((modrm.Mod ==0 && modrm.RM==5) || (modrm.Mod == 0 && modrm.RM == 4 && sib.Base == 5))
                // m32
                return 3;
            else
                return 0;
        }
		int haveSib() const { return ((modrm.RM == 4)&&(modrm.Mod != 3));}
		int sscode(int scale){
			switch(scale){
				case 0: return 0; break; 
				case 2: return 1; break;
				case 4: return 2; break;
				case 8: return 3; break;
				default: 
						printf(" scale must be 0, 2, 4, 8\n");
						return -1;
			}
		}
		unsigned char scale(int s)const {
			switch(s){
				case 0: return 0; break; 
				case 1: return 2; break;
				case 2: return 4; break;
				case 3: return 8; break;
				default: return 0xff;
			}
		}
		void clean(){rex.clean();modrm.clean();sib.clean();}
        rGroup getRegType()const{return (rGroup) regType.Reg;} 
	public:
		ModRM getModrm()const {return modrm;}
		SIB   getSib()const { return sib;}
		REX   getRex()const { return rex;}
        char getoff8()const{return off8;}
        int  getoff32()const{return off32;}
        I64  getoff64()const{return off64;}
	public:
#define Ckxx {if(checkScale(scale)==-1) return -1;}
		MemMod(){}
		//MemMod(const MemMod& o):rex(o.rex),modrm(o.modrm),sib(o.sib),off64(o.off64){}
	public:
		//[base]
		template<typename GPRT> MemMod(GPRT base)                                  {trans(base);};
		//[base + disp8]
		template<typename GPRT> MemMod(char off,  GPRT base)                       {trans(off, base);};
		//[base + disp32]
		template<typename GPRT>	MemMod(int  off,  GPRT base)                       {trans(off, base);};
		//[base+ index] 
		template<typename GPRT>	MemMod(GPRT  base, GPRT index)                     {trans(base, index);};
		//[base+ index*s]
		template<typename GPRT>	MemMod(GPRT  base, GPRT index, int scale)          {trans(base, index, scale);};
		//[base+ index  +off8]
		template<typename GPRT>	MemMod(char off,  GPRT base, GPRT index)           {trans(off,base, index);};
		//[base+ index  +off32]
		template<typename GPRT>	MemMod(int  off,  GPRT base, GPRT index)           {trans(off,base, index);};
		//[base+ index*s+off8]
		template<typename GPRT>	MemMod(char off,  GPRT base, GPRT index, int scale){trans(off,base,index,scale);};
		//[base+ index*s+off32]
		template<typename GPRT>	MemMod(int  off,  GPRT base, GPRT index, int scale){trans(off,base,index,scale);};
		//[ index*s+off32]
		template<typename GPRT>	MemMod(int  off,  GPRT index, int scale){trans(off,index,scale);};
		//[ off32]
		MemMod(int  off){trans(off);};
		void print()const {
			char buf[128];
			disasm(buf);
			printf("%s", buf);
		};	
	public:
        //! morm.R will be used as flag which group contains the reg
		template<typename GPRT>	void setRegType(GPRT src) { regType.setR( (src>>3) & 7) ;}
		void setRegType(GPRR base) { regType.setR( (base>>3) & 7);rex.setB((base & RGROUPMASK)==(regRext<<3));}
		template<typename GPRT>	void setRegType(GPRT base, GPRT index) {rex.setB((base&RGROUPMASK)==(regRext<<3)); rex.setX((index&RGROUPMASK)==(regRext<<3));}
		void setRegType(GPRE base, GPRE index) {setRegType(base);}
		void setRegType(GPRR base, GPRR index) {setRegType(base);rex.setB((base&RGROUPMASK)==(regRext<<3)); rex.setX((index&RGROUPMASK)==(regRext<<3)); }

		template<typename GPRT>	int trans(GPRT base) { setRegType(base); modrm.Mod=0; modrm.RM=base;	return 0;};
		template<typename GPRT>	int trans(char off, GPRT base){ setRegType(base);  modrm.Mod=1; modrm.RM=base; off8=off; return 0;}
		template<typename GPRT>	int transi32(int off, GPRT base){ setRegType(base);  modrm.Mod=2; modrm.RM=base; off32=off;return 0;}
		template<typename GPRT>	int trans(int  off,  GPRT base){ setRegType(base); 
				if( (off & ~0xff) == 0){ 
					return 	trans((char) off, base);}
				else{
					return transi32(off, base);
				}	
			}
		template<typename GPRT>	int trans(GPRT  base, GPRT index)           {  setRegType(base,index); 
				modrm.Mod=0; modrm.RM=4; sib.SS=0;     
				sib.Base= base; sib.Index=index;	return 0;
			}
		template<typename GPRT>	int trans(GPRT  base, GPRT index, int scale){ setRegType(base,index); 
				Ckxx; modrm.Mod=0; modrm.RM=4; sib.SS=sscode(scale); sib.Base= base; sib.Index=index;	return 0;
			};
		template<typename GPRT> int trans(char off,  GPRT base, GPRT index) {  setRegType(base,index); 
				modrm.Mod=1; modrm.RM=4; sib.SS=0;     
				sib.Base= base; sib.Index=index; off8 = off;	return 0;
			};
		template<typename GPRT>	int transi32(int  off, GPRT base, GPRT index) {  setRegType(base,index); 
				modrm.Mod=2; modrm.RM=4; sib.SS=0;     
				sib.Base= base; sib.Index=index; off32= off; return 0;
			}
		template<typename GPRT>	int trans(int  off,  GPRT base, GPRT index) {  setRegType(base,index); 
				if( (off & ~0xff) == 0){ 
					return 	trans((char)off, base, index);}
				else{
					return 	transi32(off, base, index);
				}
			};
		template<typename GPRT>	int trans(char off,  GPRT base, GPRT index, int scale){ setRegType(base,index); 
				Ckxx; modrm.Mod=1; modrm.RM=4; sib.SS=sscode(scale); 
				sib.Base= base; sib.Index=index; off8 = off;	return 0;
			};
		template<typename GPRT>	int transi32(int  off,  GPRT base, GPRT index, int scale){  setRegType(base,index); 
				Ckxx;modrm.Mod=2; modrm.RM=4; sib.SS=sscode(scale); 
				sib.Base= base; sib.Index=index; off32 = off; return 0;
			}
		template<typename GPRT>	int trans(int  off,  GPRT base, GPRT index, int scale){  setRegType(base,index); 
				if( (off & ~0xff) == 0){ 
					return 	trans((char)off, base, index, scale);}
				else{
					return 	transi32(off, base, index, scale);
				}
			};
		template<typename GPRT>	int trans(int off, GPRT index, int scale){ setRegType(index); 
            rex.setX((index&RGROUPMASK)==(regRext<<3)); 
				Ckxx; modrm.Mod=0; modrm.RM=4; 
                sib.SS   = (unsigned char)(unsigned int)sscode(scale);
                sib.Base = static_cast<unsigned int>( 7 & GPR_EBP ); 
                sib.Index= (unsigned char)(unsigned int)index; 
                off32 = off;	
                return 0;
			};
        int trans(int off ){
				modrm.Mod=0; modrm.RM=5;off32 = off; 
                return 0;
        }
        bool ismoff8()const{ return ( modrm.Mod==0 && modrm.RM==5 && ((unsigned int)off32 < 256));}
        bool ismoff16()const{ return ( modrm.Mod==0 && modrm.RM==5 && (unsigned int)(off32 < 65536));}
        bool ismoff32()const{ return ( modrm.Mod==0 && modrm.RM==5 );}
#undef Ckxx
		void resetRex(){rex.init();} 
		void disasm(char* buf)const{
			char* pbuf = buf;

			if(haveDisp() == 1){
				sprintf(buf, "0x%02x", off8);
				pbuf+=4;
			}
			else if(haveDisp() == 3){
				sprintf(buf, "0x%08x", off32);
				pbuf+=10;
			}
			if( haveSib()){
				//sprintf(pbuf, "(%s, %s, %d)", GPR_r_name[sib.Base], GPR_r_name[sib.Index], scale(sib.SS) );
				sprintf(pbuf, "(%s, %s, %d)", regNames[sib.Base | (regType.Reg <<3)], regNames[sib.Index| (regType.Reg <<3)], scale(sib.SS) );
			}else{
				//sprintf(pbuf, "(%s)", GPR_r_name[modrm.RM]);	
                if(modrm.RM == 5 && modrm.Mod == 0)
				sprintf(pbuf, "()");	
                else
				sprintf(pbuf, "(%s)", regNames[modrm.RM| (regType.Reg <<3)]);	
			}
		}
		int copyto(char* dst){
			int len=0;
			char* pdst = dst;
			//! copy 
			ModRM* pmodrm =(ModRM*) dst;		
			pmodrm -> Mod = modrm.Mod;
			pmodrm -> RM = modrm.RM;
			pdst++;
			if(haveSib()){
				len +=1;
				pdst[0] = sib.c;
				pdst++;
			}
			if(haveDisp() ==1){
				len +=1;
				pdst[0] = off8;
			}
			else if(haveDisp() == 3){
				len +=4;
				*(int*)pdst = off32;
			}
			return len;
		}

};


typedef union {
	char c;
	short w;
	int d;
	long long l;
    char a[8];
}Disp;

class Imm {
    public:
        union{
            unsigned char uc;
            unsigned char ucp[8];
            unsigned short uw;
            unsigned int ud;
            U64 ul;
            U64 uq;
            char c;
            short w;
            int d;
            I64 l;
            I64 q;
        };
        public:
        Imm(I64& _ul){ ul = _ul;}
        Imm(){l = 0;}
        int is8(){ return (uq & ~255) == 0;}
        int is16(){return (uq & ~0xffff) == 0;}
        int is32(){return (uq & ~0xffffffff) == 0;}
        int is64(){return (uq & ~0xffffffff) != 0;}
};


class Instr{
    private:
        Uchar pre0f;
        Uchar pre1;
        Uchar pre2;
        Uchar pre3;
        Uchar pre4;
        Uchar rex;
        Uchar opc1;
        Uchar opc2;
        Uchar opc3;
        Uchar opc4;
        Uchar rm;
        Uchar sib;
        Disp disp;
        Imm imm;
        bool foremt64;
    public:
        union {
            struct {
                unsigned int hasPre0f: 1;
                unsigned int hasPre1: 1;
                unsigned int hasPre2: 1;
                unsigned int hasPre3: 1;
                unsigned int hasPre4: 1;
                unsigned int hasRex: 1;
                unsigned int hasOpc1: 1;
                unsigned int hasOpc2: 1;
                unsigned int hasOpc3: 1;
                unsigned int hasOpc4: 1;
                unsigned int hasModRM: 1;
                unsigned int hasSib: 1;
                unsigned int hasDisp: 3;
                unsigned int hasImm: 3;
            };
            int flags;
        };
        
    public:
        Instr(){init(); foremt64= true;};
        Instr(ArchType t){ init(); foremt64 = (t == SYS_64);}
        void init(){ 
            Uchar* bytes = &pre1;
            for(int i=0;i<16;i++) bytes[i] =0; 
            flags = 0;
        }
        void clean(){flags=0;rex=0x40;}
    public:
        void setPre0f (Uchar s) {pre0f =s;hasPre0f= 1;}
        void setPre1  (Uchar s) {pre1 =s ;hasPre1 = 1;}
        void setPre2  (Uchar s) {pre2 =s ;hasPre2 = 1;}
        void setPre3  (Uchar s) {pre3 =s ;hasPre3 = 1;}
        void setPre4  (Uchar s) {pre4 =s ;hasPre4 = 1;}
        void setRex   (Uchar s) {rex  =s ;hasRex = 1; }
        void setRex   (REX& s)  {setRex(s.c);}
        int  setRex   (const MemMod& s); 
        void setOpc1  (Uchar s) {opc1  =s ;hasOpc1 = 1; }
        void setOpc1  (OPC1 s)  { setOpc1(s.c);}
        void setOpc2  (Uchar s) {opc2  =s ;hasOpc2  = 1;}
        void setOpc3  (Uchar s) {opc3  =s ;hasOpc3  = 1;}
        void setOpc4  (Uchar s) {opc4  =s ;hasOpc4  = 1;}
        void setRm    (Uchar s) {rm  =s; hasModRM=1;} 
        void setRm    (ModRM& s){setRm(s.c);} 
        void setSib   (Uchar s) { sib  =s; hasSib  =1;} 
        void setSib   (const SIB& s)  { setSib(s.c);} 
        void setDisp  (char s) {disp.c=s; hasDisp=1;}
        void setDisp  (short s) {disp.w=s; hasDisp=2;}
        void setDisp  (int s)   {disp.d=s; hasDisp=3;}
        void setDisp  (long long s)  {disp.l=s; hasDisp=4;}
        void setImm   (Uchar s) {imm.uc=s; hasImm =1;}
        void setImm   (short s) {imm.w=s; hasImm =2;}
        void setImm   (int s)   {imm.d=s; hasImm =3;}
        void setImm   (long long s)  {imm.l=s; hasImm =4;}
        void setPre   (PREFIX1 s){ setPre1(s);};
        void setPre   (PREFIX2 s){ setPre2(s);};
        void setPre   (PREFIX3 s){ setPre3(s);};
        void setPre   (PREFIX4 s){ setPre4(s);};
        void setPre   (Uchar s);
        void setModRmRm(GPR rm){}
        void setModRmR (GPR r){}
        void setModRmMod(int mod){}
        void setR2Rm(Uchar o){}
        void setRm2R(Uchar o){}
        void setRexW(Uchar o){rex &=(255-8); rex |= ((o&1)<<3);}
        void setRexR(Uchar o){rex &=(255-4); rex |= ((o&1)<<2);}
        void setRexX(Uchar o){rex &=(255-2); rex |= ((o&1)<<1);}
        void setRexB(Uchar o){rex &=(255-1); rex |= (o&1);}
        void setHasRex(){hasRex = 1;}
        int isOpcReg2RM(){ return (opc1 & 2);}
        void setReg2RM(){ opc1 = opc1 | 2;}
        void setRM2Reg(){ opc1 = opc1 & (~2);}
    public:
        int trans2bytes(Uchar* dst);
    public:
        //!
        int trans(MN x);
        //! src -> dst
        int trans(MN x, GPRR dst, GPRR src);
        int trans(MN x, GPRE dst, GPRE src);
        int trans(MN x, GPRW dst, GPRW src);
        int trans(MN x, GPRB dst, GPRB src);
        int trans(MN x, XMMS dst, XMMS src);
        int trans(MN x, GPR dst, GPR src);

        //!  src(imm) -> dst(mem) 
        int trans(MN x, GPRR dst, I64 src);
        int trans(MN x, GPRE dst, I64 src);
        int trans(MN x, GPRW dst, I64 src);
        int trans(MN x, GPRB dst, I64 src);
        int trans(MN x, XMMS dst, I64 src);
        int trans(MN x, GPR dst,  I64 src);


        //!  src(reg) -> dst(mem) 
        int trans(MN x, const MemMod& m, GPRR dst);
        int trans(MN x, const MemMod& m, GPRE dst);
        int trans(MN x, const MemMod& m, GPRW dst);
        int trans(MN x, const MemMod& m, GPRB dst);
        int trans(MN x, const MemMod& m, XMMS dst);
        int trans(MN x, const MemMod& m, GPR dst);

        //! src(mem) -> dst(reg)
        int trans(MN x, GPRR dst, const MemMod& m);
        int trans(MN x, GPRE dst, const MemMod& m);
        int trans(MN x, GPRW dst, const MemMod& m);
        int trans(MN x, GPRB dst, const MemMod& m);
        int trans(MN x, XMMS dst, const MemMod& m);
        int trans(MN x, GPR dst, const MemMod& m);
        //! src -> src
        int trans(MN x, GPRR src);
        int trans(MN x, GPRE src);
        int trans(MN x, GPRW src);
        int trans(MN x, GPRB src);
        int trans(MN x, XMMS src);
        int trans(MN x, GPR src);

        //!
        int trans(MN x, I64 i);

    private:
        int transReg2Reg(const OpInfo* opinfo, GPR dst, GPR src);
        int transMem2Reg(const OpInfo* opinfo, GPR dst, const MemMod& m);
        int transReg2Mem(const OpInfo* opinfo, const MemMod& m, GPR src);
        int transImm2Reg(const OpInfo* opinfo, GPR dst, I64 src);
        int transReg(const OpInfo* opinfo, GPR src);
        int setRex(GPRR dst, const MemMod& m);

        inline Uchar  mustChangeOprandSize(GPR r){
            if( getRegGroup(r) == regR)
                return 0x48;
            else if( getRegGroup(r) == regE)
                return 0;
            else if(getRegGroup(r) == regW)
                return 0x66;
            return 0;
        }
        template<typename T> inline Uchar  mustChangeOprandSize(T r){ return mustChangeOprandSize((GPR) r);}

        inline Uchar  mustChangeAddressSize(GPR r){
            if( (forx64() && ( getRegGroup(r) == regE)) 
                    || (forx32() && getRegGroup(r) == regW)){
                return 0x67;
            }
            return 0x0;
        }
        template<typename T> inline Uchar  mustChangeAddressSize(T r){ return mustChangeAddressSize((GPR) r);}
        OpInfo* getOpInfo(MN x, OPerKind dst, OPerKind src1 );
        OpInfo* getOpInfo(MN x, OPerKind dst);
        OpInfo* getOpInfo(MN x, const MemMod& m, OPerKind src);
        OpInfo* getOpInfo(MN x, OPerKind dst, const MemMod& m);
        OpInfo* getOpInfoImm(MN x, GPRR dst, I64 src);
    public:
        bool forx64(){return foremt64;}
        bool forx32(){return foremt64;}


};

class InstructionCoder
{
    public:
    public:
        Uchar code[32];
        int len;
        Instr m;
    public:
        InstructionCoder(){}
        InstructionCoder(ArchType t):m(t){}
        void setEmpty(){};
        void trans(char* asmStr);
        int transTo(char* asmStr ,void* dst);
        //!
        int trans(MN x){ m.trans(x); len = m.trans2bytes(code); return DM_SUCCESS; }

        //!
        int trans_r2r(MN x, GPRR dst, GPRR src){m.trans(x, dst, src);	len = m.trans2bytes(code); return DM_SUCCESS;};
        int trans_e2e(MN x, GPRE dst, GPRE src){m.trans(x, dst, src);	len = m.trans2bytes(code); return DM_SUCCESS;};
        int trans_w2w(MN x, GPRW dst, GPRW src){m.trans(x, dst, src);	len = m.trans2bytes(code); return DM_SUCCESS;};
        int trans_b2b(MN x, GPRB dst, GPRB src){m.trans(x, dst, src);	len = m.trans2bytes(code); return DM_SUCCESS;};
        int trans_X2X(MN x, XMMS dst, XMMS src){m.trans(x, dst, src);	len = m.trans2bytes(code); return DM_SUCCESS;};
        int trans(MN x, GPR dst, GPR src){ m.trans(x, dst, src); len = m.trans2bytes(code); return DM_SUCCESS;};
        //! 
        int trans_m2e(MN x, GPRE dst, const MemMod& src){m.trans(x, dst, src);	len = m.trans2bytes(code); return DM_SUCCESS;};
        int trans(MN x, GPR dst, const MemMod& src){m.trans(x, dst, src);	len = m.trans2bytes(code); return DM_SUCCESS;};
        //! 
        int trans(MN x, const MemMod& dst, GPR src){m.trans(x, dst, src);	len = m.trans2bytes(code); return DM_SUCCESS;};
        //!
        int trans_e(MN x, GPRE src){m.trans(x, src); len = m.trans2bytes(code); return DM_SUCCESS;}
        int trans(MN x, GPR src){ m.trans(x, src); len = m.trans2bytes(code); return DM_SUCCESS;};
        //!
        int trans(MN x, GPR dst , I64 i){m.trans(x, dst, i); len = m.trans2bytes(code); return DM_SUCCESS;}
        //!
        int trans(MN x, I64 i){m.trans(x, i); len = m.trans2bytes(code); return DM_SUCCESS;}

        int copyto(Uchar* dst){
            for(int i=0;i<len;i++){
                dst[i] =  code[i];
            }
            return len;
        }
        void print(MN x, GPR dst, GPR src){
            printf(" %-10s %-5s, %-5s:", MNnames[x], regNames[dst], regNames[src]);}
        void print(MN x, GPR dst, const MemMod& src){
            printf(" %-10s %-5s, ", MNnames[x], regNames[dst]);src.print();printf(":");}
        void print(MN x, const MemMod& dst, GPR src){
            printf(" %-10s ", MNnames[x]);dst.print();printf(",%-5s :", regNames[src]);}
        void print(MN x, GPR dst){printf(" %-10s %-5s:", MNnames[x], regNames[dst]);}
        void print(MN x, GPR dst, I64 src){printf(" %-10s %-5s, %llx:", MNnames[x], regNames[dst], src);}
        void print(MN x, I64 src){printf(" %-10s  %llx:", MNnames[x], src);}
        void print(){
            for(int i=0;i<len;i++){
                printf("%2x ", code[i]);
            }
        }
        bool isEq(Uchar* ref){
            for(int i=0;i<len;i++){
                if(code[i] != ref[i]) return false;
            }
            return true;
        }
    private:
};

class biTrans : public InstructionCoder
{
    public:
        char masm[128];
};

extern InstructionCoder m64;
extern InstructionCoder m32;
extern  InstructionCoder * const  pasm;

}
#endif
