/*
 * =====================================================================================
 *
 *       Filename:  ccg.cpp
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  2009年05月10日 21时10分52秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghua Dai (Zhenghua Dai), djx.zhenghua@gmail.com
 *        Company:  dzh
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "ccg.h"
#include "opcodeDes.h"
namespace CCG{

bool System64Bits = true;    
/////////////////////////////////////////////////////////////    
OpInfo opDesTable32[] = {
decOPinfoList32
};

static int opDesTableSize32 = sizeof(opDesTable32)/sizeof(OpInfo);
int opIndex32[instructionNum];

/////////////////////////////////////////////////////////////    
OpInfo opDesTable[] = {
decOPinfoList64
};

static int opDesTableSize = sizeof(opDesTable)/sizeof(OpInfo);
int opIndex[instructionNum];
int initOpIndex(OpInfo opDesTable[], int opIndex[])
{
   for(int i=0;i<instructionNum-1;i++){
       opIndex[i] = -1;
   }
   for(int i=0;i<opDesTableSize -1;i++){
        if(opDesTable[i].mn != opDesTable[i+1].mn){
            opIndex[ opDesTable[i+1].mn] = i+1;
        }
   }

   for(int i=instructionNum-2; i>=0; i--){
       if(opIndex[i] == -1)
           opIndex[i] = opIndex[i+1];
   }

   return 0;
}

int initOpIndex()
{
    initOpIndex(opDesTable, opIndex);
    initOpIndex(opDesTable32, opIndex32);
	return 1;
}

int hasInit = initOpIndex();
InstructionCoder m64(SYS_64);
InstructionCoder m32(SYS_32);

#if ((defined _WIN64 ) || __WORDSIZE == 64)
InstructionCoder * const pasm =  &m64;
#else
InstructionCoder * const  pasm =  &m32;
#endif

#define EQ(d, s1)   ( d == oper_##s1 )
#define EQ2(d, s1, s2)   ( (d == oper_##s1) || ( d == oper_##s2))
#define EQ4(d, s1, s2, s3, s4) ( (d == oper_##s1) || ( d == oper_##s2)|| \
        (d == oper_##s3) || ( d == oper_##s4))
#define EQ6(d, s1, s2, s3, s4, s5, s6) ( (d == oper_##s1) || ( d == oper_##s2)|| \
        (d == oper_##s3) || ( d == oper_##s4)|| \
        (d == oper_##s5) || ( d == oper_##s6)) 
#define EQ7(d, s1, s2, s3, s4, s5, s6, s7) ( (d == oper_##s1) || ( d == oper_##s2)|| \
        (d == oper_##s3) || ( d == oper_##s4)|| \
        (d == oper_##s5) || ( d == oper_##s6)|| \
        (d == oper_##s7))
#define EQ8(d, s1, s2, s3, s4, s5, s6, s7, s8) ( (d == oper_##s1) || ( d == oper_##s2)|| \
        (d == oper_##s3) || ( d == oper_##s4)|| \
        (d == oper_##s5) || ( d == oper_##s6)|| \
        (d == oper_##s7)|| ( d == oper_##s8))
        
#define EQ10(d, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10) ( (d == oper_##s1) || ( d == oper_##s2)|| \
        (d == oper_##s3) || ( d == oper_##s4)|| \
        (d == oper_##s5) || ( d == oper_##s6)|| \
        (d == oper_##s7)|| ( d == oper_##s8)|| \
        (d == oper_##s9)|| ( d == oper_##s10))
        
int matchOperMem(OPerKind container, const  MemMod& m)
{
   if( container == oper_moffs8 && m.ismoff8() ) return 1;
   if( container == oper_moffsWD&& m.ismoff32() ) return 1;
   if(EQ10(container, m8,rm8,m16,rm16,m32,rm32,m64,rm64,rWDQ, mWDQ) ||
           EQ4(container, rmWDQ,rmWD,rmWQ,rmDQ)) return 1;
}

int matchOperMem(OPerKind container, OPerKind input )
{
    if(container == input) return 2;
    int g = input - oper_m8 ;
    switch(g){
        case 0: //! byte
            if((container == oper_m8) || (container == oper_rm8)) 
                return 1;
            break;
        case 1: //! w
            if( EQ7(container, m16, rm16, rWDQ, rmWDQ, mWD, rmWD,  rmWQ ))
                return 1;
            break;
        case 2: //! d
            if( EQ8(container, m32, rm32, mWDQ, rmWDQ, rDQ, rmDQ, mWD, rmWD))
                return 1;
            break;
        case 3: //! q
            if( EQ7(container, m64, rm64, mWDQ, rmWDQ, mDQ, rmDQ,  rmWQ  ))
                return 1;
            break;
        case 4: //! xmm
            if( EQ(container,  Xm128 ))
                return 1;
            break;
        case 5: //! m512 
            break;
        case 6: //! st
        default:
            break;
    }
    return 0;
}

int matchOperReg(OPerKind container, OPerKind input )
{
    if(container == input) return 2;
    if((((input == oper_EAX)||(input == oper_RAX)||(input ==oper_AX)) &&(container == oper_rAX))
            || (((input == oper_EAX)||(input ==oper_AX)) &&(container == oper_eAX)))
        return 1;
    int g = (input & (7<<3)) >> 3 ;
    switch(g){
        case 0: //! byte
            if((container == oper_r8) || (container == oper_rm8)) 
                return 1;
            break;
        case 1: //! w
            if( EQ8(container, r16, rm16, rWDQ, rmWDQ, rWD, rmWD, rWQ, rmWQ ))
                return 1;
            break;
        case 2: //! d
            if( EQ8(container, r32, rm32, rWDQ, rmWDQ, rDQ, rmDQ, rWD, rmWD))
                return 1;
            break;
        case 3: //! q
            if( EQ8(container, r64, rm64, rWDQ, rmWDQ, rDQ, rmDQ, rWQ, rmWQ  ))
                return 1;
            break;
        case 4: //! qext
            if( EQ8(container, r64, rm64, rWDQ, rmWDQ, rDQ, rmDQ, rWQ, rmWQ  ))
                return 1;
            break;
        case 5: //! xmm
            if( EQ2(container, xmm, Xm128 ))
                return 1;
            break;
        case 6: //! xmm ext
            if( EQ2(container, xmm, Xm128 ))
                return 1;
            break;
        case 7: //! st
        default:
            break;
    }
    return 0;
}

int matchOperImm(OPerKind container, OPerKind input )
{
    if(container == input) return 2;
    switch (input - operkind(i8)){
        case 0: //! i8
            //if(container >= operkind(i8) && container <= operkind(iWDQ))    return 1;
            if(container == operkind(i8)) return 1;
            break;
        case 1: //! i16
            //if(container >= operkind(i16) && container <= operkind(iWDQ))    return 1;
            if((container == operkind(i16)) || container == operkind(iWD) ||  container == operkind(iWDQ))  return 1;
            break;
        case 2: //! i32
            //if(container >= operkind(i32) && container <= operkind(iWDQ))    return 1;
            if((container == operkind(i32)) || container == operkind(iWD) ||  container == operkind(iWDQ))  return 1;
            break;
        case 3: //! i64
            if(container == operkind(i64) ||  container == operkind(iWDQ) || container == operkind(i128))  return 1;
            break;
        case 4: //! i128
            if(container == operkind(i128) )    return 1;
            break;
    }
    return 0;
}

int matchOper(OPerKind container, OPerKind input )
{
    if(container == input) return 2;
    if(input<128){//! register
        return matchOperReg(container, input);
    } else if(input >= operkind(i8) && input <= operkind(i128) ){//! oper is Imm
        return matchOperImm(container, input);
    } else{ // ! oper  is Mem 
        return matchOperMem(container, input);
    }
    return 0;
}

template<OpInfo opDesTable[], int opIndex[]>
OpInfo* GetOpInfo(MN x, OPerKind dst, OPerKind src1 )
{
    int start = opIndex[x];
    int end = opIndex[x+1];
    for(int i=start; i< end; i++){
        if( matchOper( (OPerKind)opDesTable[i].oper1, dst) && matchOper((OPerKind)opDesTable[i].oper2, src1)) 
            return &opDesTable[i];
    }
    return NULL;
}

template<OpInfo opDesTable[], int opIndex[]>
OpInfo* GetOpInfo(MN x, OPerKind dst)
{
    int start = opIndex[x];
    int end = opIndex[x+1];
    if(start == -1) return NULL;
    for(int i=start; i< end; i++){
        if( matchOper( (OPerKind)opDesTable[i].oper1, dst) && (opDesTable[i].isOper2Empty())) 
            return &opDesTable[i];
    }
    return NULL;
}

OpInfo* Instr::getOpInfo(MN x, OPerKind dst, OPerKind src1 )
{
    if(forx64())
        return GetOpInfo<opDesTable, opIndex>(x,dst,src1);
    else
        return GetOpInfo<opDesTable32, opIndex32>(x,dst,src1);
}

OpInfo* Instr::getOpInfo(MN x, OPerKind dst)
{
    if(forx64())
        return GetOpInfo<opDesTable, opIndex>(x,dst);
    else
        return GetOpInfo<opDesTable32, opIndex32>(x,dst);
}

/***********************************************************************
 *TTT
 * reg(src) -> reg(dst)
 *
 * *********************************************************************/
int Instr::transReg2Reg(const OpInfo* opinfo, GPR dst, GPR src)
{
    ModRM tModrm;//(3,dst,src);	
    tModrm.setMod(3);
    if(opinfo->isOper1RM()){
        tModrm.setRm(dst);
        tModrm.setR(src);
    }else{
        tModrm.setRm(src);
        tModrm.setR(dst);
    }
    this->setRm(tModrm);
    //!set prefix1 
    if( ! opinfo-> isPrefixEmpty()){
        this->setPre1(opinfo->prefix);
    }
    //!set prefix0f
    if( ! opinfo-> isPrefix2Empty()){
        this->setPre2( opinfo-> prefix0F);
    }
    //! set opc1
    OPC1 opc1= opinfo-> opc1;
    this->setOpc1( opc1.c);
    //printf("rm %d\n", tModrm.c);
    //printf("opc1 %d\n", opinfo->opc1.c);
    //printf(" %d\n",sizeof(OPC1));
    //! set opc2
    if( opinfo-> opc2 != NULLOPC2) 
        this->setOpc2 ( opinfo->opc2);
	return DM_SUCCESS;
}

#define GET_OPINFO1(x, dst) \
    d = getOpInfo(x, (OPerKind)dst);\
if(d == NULL) {\
    printf("no entry \n");\
    return -1;\
}

#define GET_OPINFO(x, dst, src) \
    if(d == NULL){\
    d = getOpInfo(x, (OPerKind)dst, (OPerKind)src);\
        if(d == NULL) {\
            printf("no entry \n");\
            return -1;\
        }\
    }

OpInfo* Instr::getOpInfo(MN x, const MemMod& m, OPerKind src){
    OpInfo* d = NULL;
    if(m.ismoff8()){
        d = getOpInfo(x, operkind(moffs8), src);
        if(d == NULL)  
        d = getOpInfo(x, operkind(moffsWD), src);
    }else if(m.ismoff32()){
        d = getOpInfo(x, operkind(moffsWD), src);
    }
    return d;
}

OpInfo* Instr::getOpInfo(MN x, OPerKind dst, const MemMod& m){
    OpInfo* d = NULL;
    if(m.ismoff8()){
        d = getOpInfo(x, dst, operkind(moffs8));
        if(d == NULL)  
        d = getOpInfo(x, dst, operkind(moffsWD));
    }else if(m.ismoff32()){
        d = getOpInfo(x, dst, operkind(moffsWD));
    }
    return d;
}


#define GET_OPINFORM(x, m, src) \
    OpInfo* d = getOpInfo(x, (OPerKind)dst, (OPerKind)src);\
if(d == NULL) {\
    printf("no entry \n");\
    return -1;\
}

#define START_TRANS() this->clean(); OpInfo* d = NULL;
int Instr::trans(MN x, GPRR dst , GPRR src)
{
    START_TRANS();
    GET_OPINFO(x,dst,src); 
    transReg2Reg(d, (GPR)dst, (GPR)src);

    //! set r 
    REX tRex;	
    tRex.setW();
    if( isOpcReg2RM()){
        tRex.setR(isExt((GPR)src));
        tRex.setB(isExt((GPR)dst));
    } else {
        tRex.setR(isExt((GPR)dst));
        tRex.setB(isExt((GPR)src));
    }
    this->setRex(tRex);
    //! bytes
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRW dst, GPRW src)
{
    START_TRANS();
    GET_OPINFO(x,dst,src); 
    transReg2Reg(d, (GPR)dst, (GPR)src);
    setPre(PREFIX(bits16In32));
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRB dst, GPRB src)
{
    START_TRANS();
    GET_OPINFO(x,dst,src); 
    transReg2Reg(d, (GPR)dst, (GPR)src);
	return DM_SUCCESS;
}



int Instr::trans(MN x, GPRE dst, GPRE src)
{
    START_TRANS();
    GET_OPINFO(x,dst,src); 
    transReg2Reg(d, (GPR)dst, (GPR)src);
	return DM_SUCCESS;
}

int Instr::trans(MN x, XMMS dst, XMMS src)
{
    START_TRANS();
    GET_OPINFO(x,dst,src); 
    transReg2Reg(d, (GPR)dst, (GPR)src);
    //! set r 
    int dstIsExt = (getRegGroup((GPR)dst) == regXext);
    int srcIsExt = (getRegGroup((GPR)src) == regXext);
    if( dstIsExt || srcIsExt){
        REX tRex;	
        if( isOpcReg2RM()){
            tRex.setR(srcIsExt );
            tRex.setB(dstIsExt );
        } else {
            tRex.setR(dstIsExt );
            tRex.setB(srcIsExt );
        }
        this->setRex(tRex);
    }
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPR dst, GPR src)
{

    Uchar g = (src & (~7)) >> 3 ;
    switch(g){
        case 0:
            trans(x, (GPRB) dst, (GPRB) src);
            break;
        case 1:
            trans(x, (GPRW) dst, (GPRW) src);
            break;
        case 2:
            trans(x, (GPRE) dst, (GPRE) src);
            break;
        case 3:
        case 4:
            trans(x, (GPRR) dst, (GPRR) src);
            break;
        case 5:
        case 6:
            trans(x, (XMMS) dst, (XMMS) src);
            break;
        case 7:
        default:
            break;
    }
    //! Assert(rGroup(dst) == rGroup(src))
    if(mustChangeOprandSize(src))
        setPre(mustChangeOprandSize(src));
	return DM_SUCCESS;
}


/*****************************************************
 *TTT
 * Imm(src) -> reg(dst)
 * **************************************************/

int Instr::transImm2Reg(const OpInfo* opinfo, GPR dst, I64 src)
{
    //! set modrm
    if( opinfo-> isCodeOneByte() ){
        //! set opc1
        OPC1 opc1= opinfo-> opc1;
        opc1.setReg(dst);
        this->setOpc1( opc1.c);
    }else {
        if(! opinfo->isOpregEmpty()){
            ModRM tModrm;//(3,dst,src);	
            tModrm.setMod(3);
            if(opinfo->isOpregReg()){
                tModrm.setR(dst);
            }else{
                tModrm.setRm(dst);
                tModrm.setR(opinfo->opreg);
            }
            this->setRm(tModrm);
        }
        //! set opc1
        OPC1 opc1= opinfo-> opc1;
        this->setOpc1( opc1.c);
    }
    switch( opinfo -> oper2){
        case operkind(i8):  setImm( ((Imm) src).uc); break;
        case operkind(i16): setImm( ((Imm) src).w); break;
        case operkind(i32): setImm( ((Imm) src).d); break;
        case operkind(i64): setImm( ((Imm) src).q); break;
        //case operkind(i128):setImm( ((Imm) src).); break;
        case operkind(iWD): 
                            if(isRegW(dst))
                                setImm( ((Imm) src).w); 
                            else
                                setImm( ((Imm) src).d); 
                            break;
        case operkind(iWDQ):
                            if(isRegE(dst))
                            setImm( ((Imm) src).d); 
                            else if(isRegW(dst))
                                setImm( ((Imm) src).w); 
                            else
                                setImm( ((Imm) src).q); 
                            break;
    }
    //!set prefix1 
    if( ! opinfo-> isPrefixEmpty()){
        this->setPre1(opinfo->prefix);
    }
    //!set prefix0f
    if( ! opinfo-> isPrefix2Empty()){
        this->setPre2( opinfo-> prefix0F);
    }
    //! set opc2
    if( opinfo-> opc2 != NULLOPC2) 
        this->setOpc2 ( opinfo->opc2);

	return DM_SUCCESS;
}

OpInfo* Instr::getOpInfoImm(MN x, GPRR dst, I64 src)
{
    OpInfo* d = NULL;
    OPerKind immKind;
    if( Imm(src).is8()) 
        immKind = operkind(i8);
    else if (Imm(src).is16()) 
        immKind = operkind(i16);
    else if (Imm(src).is32()) 
        immKind = operkind(i32);
    else 
        immKind = operkind(i64);
    switch(immKind){
        case operkind(i8):
            d= getOpInfo(x, (OPerKind)dst, (OPerKind)operkind(i8));
            if(d) break;
        case operkind(i16):
            d= getOpInfo(x, (OPerKind)dst, (OPerKind)operkind(i16));
            if(d) break;
        case operkind(i32):
            d= getOpInfo(x, (OPerKind)dst, (OPerKind)operkind(i32));
            if(d) break;
        case operkind(i64):
            d= getOpInfo(x, (OPerKind)dst, (OPerKind)operkind(i64));
            if(d) break;
    }
    return d;
}

int Instr::trans(MN x, GPRR dst, I64 src)
{
    START_TRANS();
#if 0
    OPerKind immKind;
    if( Imm(src).is8()) 
        immKind = operkind(i8);
    else if (Imm(src).is16()) 
        immKind = operkind(i16);
    else if (Imm(src).is32()) 
        immKind = operkind(i32);
    else 
        immKind = operkind(i64);

    GET_OPINFO(x,dst,immKind); 
#endif
    d = getOpInfoImm(x, dst, src);
    transImm2Reg(d, (GPR) dst, src);
    //! set r 
    REX tRex;	
    tRex.setW();
    if(d->isOpregReg()){
        tRex.setR(isExt((GPR)dst));
    } else {
        tRex.setB(isExt((GPR)dst));
    }
    this->setRex(tRex);
	return DM_SUCCESS;

}

int Instr::trans(MN x, GPRE dst, I64 src)
{
    START_TRANS();
    d = getOpInfoImm(x, (GPRR)dst, src);
    //GET_OPINFO(x,dst,operkind(i32)); 
    transImm2Reg(d, (GPR) dst, src);
	return DM_SUCCESS;

}

int Instr::trans(MN x, GPRW dst, I64 src)
{
    START_TRANS();
    d = getOpInfoImm(x, (GPRR)dst, src);
    //GET_OPINFO(x,dst,operkind(i16)); 
    transImm2Reg(d, (GPR) dst, src);
    setPre(PREFIX(bits16In32));
	return DM_SUCCESS;

}

int Instr::trans(MN x, GPRB dst, I64 src)
{
    START_TRANS();
    d = getOpInfoImm(x, (GPRR)dst, src);
    //GET_OPINFO(x,dst,operkind(i8)); 
    transImm2Reg(d, (GPR) dst, src);
	return DM_SUCCESS;

}

int Instr::trans(MN x, XMMS dst, I64 src)
{
    START_TRANS();
    d = getOpInfoImm(x, (GPRR)dst, src);
    //GET_OPINFO(x,dst,operkind(i64)); 
    transImm2Reg(d, (GPR) dst, src);
	return DM_SUCCESS;

}

int Instr::trans(MN x, GPR dst,  I64 src)
{

    Uchar g = (dst & (~7)) >> 3 ;
    switch(g){
        case 0:
            trans(x, (GPRB) dst,  src);
            break;
        case 1:
            trans(x, (GPRW) dst,  src);
            break;
        case 2:
            trans(x, (GPRE) dst,  src);
            break;
        case 3:
        case 4:
            trans(x, (GPRR) dst,  src);
            break;
        case 5:
        case 6:
            trans(x, (XMMS) dst,  src);
            break;
        case 7:
        default:
            break;
    }
    //! Assert(rGroup(dst) == rGroup(src))
    if(mustChangeOprandSize(dst))
        setPre(mustChangeOprandSize(dst));
	return DM_SUCCESS;
}

/*****************************************************
 *TTT
 * mem(src) -> reg(dst)
 * **************************************************/

int Instr::transReg2Mem(const OpInfo* opinfo, const MemMod& m, GPR src)
{
    //! ModRM 
    if(!(opinfo->oper1 == oper_moffs8 || opinfo->oper1 == oper_moffsWD || opinfo->oper1 == oper_moffsWDQ) ){
        ModRM tModrm(m.getModrm());;//(3,dst,src);	
        //if(!opinfo->isOper1RM())
        tModrm.setR(src);
        this->setRm(tModrm);
        if(m.getModrm().Reg == regE) 
            setPre4(PREFIX(addr16In32));
    }

    //! SIB
    if(m.haveSib()) 
        this->setSib(m.getSib());
    //! DISP
    switch( m.haveDisp())
    {
        case 1:
            this->setDisp(m.getoff8());
            break;
        case 3:
            this->setDisp(m.getoff32());
            break;
        default:
            break;
    }
    //!set prefix1 
    if( ! opinfo-> isPrefixEmpty()){
        this->setPre1(opinfo->prefix);
    }
    //!set prefix0f
    if( ! opinfo-> isPrefix2Empty()){
        this->setPre2( opinfo-> prefix0F);
    }
    //! set opc1
    OPC1 opc1= opinfo-> opc1;
    this->setOpc1( opc1.c);
//    this->setRM2Reg();
    //! set opc2
    if( opinfo-> opc2 != NULLOPC2) 
        this->setOpc2 ( opinfo->opc2);
	return DM_SUCCESS;

}

int Instr::trans(MN x, const MemMod& m, GPRR src)
{
    START_TRANS();
    d = getOpInfo(x, m, (OPerKind)src);
    GET_OPINFO(x,operkind(m64),src); 
    transReg2Mem(d, m, (GPR)src);
    setRex(src, m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, const MemMod& m, GPRE src)
{
    START_TRANS();
    d = getOpInfo(x, m, (OPerKind)src);
    GET_OPINFO(x,operkind(m32),src); 
    transReg2Mem(d, m, (GPR)src);
    setRex(m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, const MemMod& m, GPRW src)
{
    START_TRANS();
    d = getOpInfo(x, m, (OPerKind)src);
    GET_OPINFO(x,operkind(m16),src); 
    transReg2Mem(d, m, (GPR)src);
    setRex(m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, const MemMod& m, GPRB src)
{
    START_TRANS();
    d = getOpInfo(x, m, (OPerKind)src);
    GET_OPINFO(x,operkind(m8),src); 
    transReg2Mem(d, m, (GPR)src);
    setRex(m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, const MemMod& m, XMMS src)
{
    START_TRANS();
    d = getOpInfo(x, m, (OPerKind)src);
    GET_OPINFO(x,operkind(m128),src); 
    transReg2Mem(d, m, (GPR)src);
    setRex(m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, const MemMod& m, GPR src)
{

    Uchar g = (src& (~7)) >> 3 ;
    switch(g){
        case 0:
            trans(x, m,  (GPRB) src);
            break;                
        case 1:                   
            trans(x, m,  (GPRW) src);
            break;                
        case 2:                   
            trans(x, m,  (GPRE) src);
            break;                
        case 3:                   
        case 4:                   
            trans(x, m,  (GPRR) src);
            break;                
        case 5:                   
        case 6:                   
            trans(x, m,  (XMMS) src);
            break;
        case 7:
        default:
            break;
    }
    //! Assert(rGroup(dst) == rGroup(src))
    if(mustChangeOprandSize(src))
        setPre(mustChangeOprandSize(src));
    if(mustChangeAddressSize(m.getRegType()<<3))
        setPre(mustChangeAddressSize(m.getRegType()<<3));
	return DM_SUCCESS;
}



/*****************************************************
 *TTT
 * mem(src) -> reg(dst)
 * **************************************************/

int Instr::transMem2Reg(const OpInfo* opinfo, GPR dst, const MemMod& m)
{
    //! ModRM 
    if(!(opinfo->oper2 == oper_moffs8 || opinfo->oper2 == oper_moffsWD || opinfo->oper2 == oper_moffsWDQ) ){
        ModRM tModrm(m.getModrm());;//(3,dst,src);	
        //if(!opinfo->isOper2RM())
        tModrm.setR(dst);
        this->setRm(tModrm);
        if(m.getModrm().Reg == regE) 
            setPre4(PREFIX(addr16In32));
    }

    //! SIB
    if(m.haveSib()) 
        this->setSib(m.getSib());
    //! DISP
    switch( m.haveDisp())
    {
        case 1:
            this->setDisp(m.getoff8());
            break;
        case 3:
            this->setDisp(m.getoff32());
            break;
        default:
            break;
    }
    //!set prefix1 
    if( ! opinfo-> isPrefixEmpty()){
        this->setPre1(opinfo->prefix);
    }
    //!set prefix0f
    if( ! opinfo-> isPrefix2Empty()){
        this->setPre2( opinfo-> prefix0F);
    }
    //! set opc1
    OPC1 opc1= opinfo-> opc1;
    this->setOpc1( opc1.c);
    //! set opc2
    if( opinfo-> opc2 != NULLOPC2) 
        this->setOpc2 ( opinfo->opc2);
	return DM_SUCCESS;

}

int Instr::setRex(const MemMod& m)
{
    //! set r 
    if(m.getRex().c == 0x40) return 1;
    if((m.getRegType() != regR) &&( m.getRegType() != regRext)) return 1;
    //! 
    this->setHasRex();
    //! setRexX
    this->setRexX( (m.getRex().c & 2) >>1) ;
    //! setRexB
    this->setRexB( m.getRex().c & 1 ) ;
	return DM_SUCCESS;

}


int Instr::setRex(GPRR dst, const MemMod& m)
{
    //! set r 
    REX tRex(m.getRex());	
    tRex.setW();
    tRex.setR((dst & RGROUPMASK  == 4) | (dst& RGROUPMASK ==6));
    this->setRex(tRex);
    setRex(m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRR dst, const MemMod& m)
{
    START_TRANS();
    d = getOpInfo(x, (OPerKind)dst, m);
    GET_OPINFO(x,dst,operkind(m32)); 
    transMem2Reg(d, (GPR)dst, m);
    setRex(dst, m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRE dst, const MemMod& m)
{
    START_TRANS();
    d = getOpInfo(x, (OPerKind)dst, m);
    GET_OPINFO(x,dst,operkind(m32)); 
    fflush(stdout);
    transMem2Reg(d, (GPR)dst, m);
    setRex(m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRW dst, const MemMod& m)
{
    START_TRANS();
    d = getOpInfo(x, (OPerKind)dst, m);
    GET_OPINFO(x,dst,operkind(m32)); 
    transMem2Reg(d, (GPR)dst, m);
    setRex(m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRB dst, const MemMod& m)
{
    START_TRANS();
    d = getOpInfo(x, (OPerKind)dst, m);
    GET_OPINFO(x,dst,operkind(m32)); 
    transMem2Reg(d, (GPR)dst, m);
    setRex(m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, XMMS dst, const MemMod& m)
{
    START_TRANS();
    d = getOpInfo(x, (OPerKind)dst, m);
    GET_OPINFO(x,dst,operkind(m32)); 
    transMem2Reg(d, (GPR)dst, m);
    setRex(m);
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPR dst, const MemMod& m)
{

    Uchar g = (dst & (~7)) >> 3 ;
    switch(g){
        case 0:
            trans(x, (GPRB) dst,  m);
            break;
        case 1:
            trans(x, (GPRW) dst,  m);
            break;
        case 2:
            trans(x, (GPRE) dst,  m);
            break;
        case 3:
        case 4:
            trans(x, (GPRR) dst,  m);
            break;
        case 5:
        case 6:
            trans(x, (XMMS) dst,  m);
            break;
        case 7:
        default:
            break;
    }
    //! Assert(rGroup(dst) == rGroup(src))
    if(mustChangeOprandSize(dst))
        setPre(mustChangeOprandSize(dst));
    if(mustChangeAddressSize(m.getRegType()<<3))
        setPre(mustChangeAddressSize(m.getRegType()<<3));
	return DM_SUCCESS;		
}


/*****************************************************
 *TTT
 * src -> src
 * **************************************************/
int Instr::transReg(const OpInfo* d, GPR src)
{
    if(d -> isCodeOneByte() ){
        //! set opc1
        OPC1 opc1= d-> opc1;
        opc1.setReg(src);
        this->setOpc1( opc1.c);
        return 0;
    }

    OPC1 opc1= d-> opc1;
    this->setOpc1( opc1.c);

    ModRM tModrm;//(3,dst,src);	
    tModrm.setMod(3);
    tModrm.setRm(src);
    tModrm.setR(d->opreg);
    this->setRm(tModrm);
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRB src)
{
    START_TRANS();
    GET_OPINFO1(x,src); 
    transReg(d, (GPR)src);
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRW src)
{
    START_TRANS();
    GET_OPINFO1(x,src); 
    transReg(d, (GPR)src);
    setPre(PREFIX(bits16In32));
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRE src)
{
    START_TRANS();
    GET_OPINFO1(x,src); 
    transReg(d, (GPR)src);
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPRR src)
{
    START_TRANS();
    GET_OPINFO1(x,src); 
    transReg(d, (GPR)src);
	if(d -> isCodeOneByte() && (! isRegRext((GPR) src))){
		return 0;
	}
	//! set r 
	REX tRex;	
	tRex.setW();
	tRex.setB(isExt((GPR)src) );
	this->setRex(tRex);
	return DM_SUCCESS;

}

int Instr::trans(MN x, XMMS src)
{
	START_TRANS();
	GET_OPINFO1(x,src); 
	transReg(d, (GPR)src);
	return DM_SUCCESS;
}

int Instr::trans(MN x, GPR src)
{

	Uchar g = (src & (~7)) >> 3 ;
	switch(g){
		case 0:
			trans(x, (GPRB) src);
			break;
		case 1:
			trans(x, (GPRW) src);
			break;
		case 2:
			trans(x, (GPRE) src);
			break;
		case 3:
		case 4:
			trans(x, (GPRR) src);
			break;
		case 5:
		case 6:
			trans(x, (XMMS) src);
			break;
		case 7:
		default:
			break;
	}
	return DM_SUCCESS;
}


/*****************************************************
 *TTT
 * 
 * **************************************************/
int Instr::trans(MN x, I64 i)
{
	START_TRANS();
	OPerKind opk;
    Imm imm(i);
    if ( imm.is8()){
        opk = operkind(i8);
    }else if(imm.is16()){
		opk = operkind(i16);
    }else if(imm.is32()){
		opk = operkind(i32);
    }else if(imm.is64()){
		opk = operkind(i64);
    }

	GET_OPINFO1(x,opk);
    OPC1 opc1= d-> opc1;
    this->setOpc1( opc1.c);
    if ( imm.is8()){
        setImm( imm.uc); 
    }else if(imm.is16()){
        setImm( imm.w);
    }else if(imm.is32()){
        setImm( imm.d);
    }else if(imm.is64()){
        setImm( imm.q);
    }
	return DM_SUCCESS;
}

/*****************************************************
 *
 * **************************************************/
int Instr::trans(MN x)
{
	switch (x) {
		//case opName(RET):
		case opName(NOP):
		case opName(CPUID):
		case opName(LEAVE):
		default:
			break;
	}
	return DM_SUCCESS;
}

/*****************************************************
 *
 * **************************************************/
int trans_r2r(MN x, GPRR dst, GPRR src)
{
	m64.trans_r2r(x, src, dst);
	return DM_SUCCESS;
}


int trans_GPR_one(char* dst, MN x, GPR r)
{
	unsigned char c;
	dst[0] = opcode(x) + r;
	return DM_SUCCESS;
}

int trans_SSE_X2X(char* dst, MN x, XMMS d, XMMS s)
{
	return DM_SUCCESS;
}

int trans_x87_x(char* dst, MN x)
{
	return DM_SUCCESS;
}

/********************************************************************
 *
 *
 * ******************************************************************/
int Instr::trans2bytes(Uchar* dst){
	int f = flags;
	int k=0;
	Uchar* bytes = (Uchar*) this;
	for(int i=0;i<12;i++){
		if((f &1) ==1){
			dst[k++] = bytes[i]; 

		}
		f = f>> 1;
	}
	switch (hasDisp){
		case 1:
			dst[k++] = disp.a[0]; 
			break;
		case 2:
			dst[k++] = disp.a[0]; 
			dst[k++] = disp.a[1]; 
			break;
		case 3:
			dst[k++] = disp.a[0]; 
			dst[k++] = disp.a[1]; 
			dst[k++] = disp.a[2]; 
			dst[k++] = disp.a[3]; 
			break;
		case 4:
			break;
		default:
			break;
	}
	switch (hasImm){
		case 1:
			dst[k++] = imm.ucp[0]; 
			break;
		case 2:
			dst[k++] = imm.ucp[0]; 
			dst[k++] = imm.ucp[1]; 
			break;
		case 3:
			dst[k++] = imm.ucp[0]; 
			dst[k++] = imm.ucp[1]; 
			dst[k++] = imm.ucp[2]; 
			dst[k++] = imm.ucp[3]; 
			break;
		case 4:
			dst[k++] = imm.ucp[0]; 
			dst[k++] = imm.ucp[1]; 
			dst[k++] = imm.ucp[2]; 
			dst[k++] = imm.ucp[3]; 
			dst[k++] = imm.ucp[4]; 
			dst[k++] = imm.ucp[5]; 
			dst[k++] = imm.ucp[6]; 
			dst[k++] = imm.ucp[7]; 
			break;
		default:
			break;
	}
	return k;
}

void 	Instr::setPre 		(Uchar s){
	switch(s){
		case PREFIX(LOCK):  
		case PREFIX(REPNZ ):
		case PREFIX(REP ):	 
			setPre1(s);
			break;
		case PREFIX(CS ):	 
		case PREFIX(SS ):	 
		case PREFIX(DS ):	 
		case PREFIX(ES ):	 
		case PREFIX(FS ):	 
		case PREFIX(GS ):	 
			setPre2(s);
			break;
		case PREFIX(bits16In32):
			setPre3(s);
			break;
		case PREFIX(addr16In32):
			setPre4(s);
			break;
		default:
			break;

	}
}

}
