/*
 * =====================================================================================
 *
 *       Filename:  testccg.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/10/2009 20:19:17 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Zhenghua Dai (Zhenghua Dai), djx.zhenghua@gamil.com
 *        Company:  dzh
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "ccg.h"
namespace CCG{
void trans(MN mn, int arg1, int arg2)
{


}

};
using namespace CCG;

class OpCodeRef
{
    public:
        Uchar code[16];
        int len;
        OpCodeRef():len(0){code[0] = 0;}
        OpCodeRef(Uchar c0):len(1){code[0] = c0;}
        OpCodeRef(Uchar c0,Uchar c1):len(2){code[0] = c0;code[1]=c1;}
        OpCodeRef(Uchar c0,Uchar c1, Uchar c2):len(3){code[0] = c0;code[1]=c1;code[2]=c2;}
        OpCodeRef(Uchar c0,Uchar c1, Uchar c2,Uchar c3):len(4){code[0] = c0;code[1]=c1;code[2]=c2;code[3]=c3;}
        OpCodeRef(Uchar c0,Uchar c1, Uchar c2,Uchar c3,Uchar c4):len(5){code[0] = c0;code[1]=c1;code[2]=c2;code[3]=c3;code[4]=c4;}
        OpCodeRef(Uchar c0,Uchar c1, Uchar c2,Uchar c3,Uchar c4,Uchar c5):len(6){code[0] = c0;code[1]=c1;code[2]=c2;code[3]=c3;code[4]=c4;code[5]=c5;}
        OpCodeRef(Uchar c0,Uchar c1, Uchar c2,Uchar c3,Uchar c4,Uchar c5,Uchar c6):len(7){code[0] = c0;code[1]=c1;code[2]=c2;code[3]=c3;code[4]=c4;code[5]=c5;code[6]=c6;}
        OpCodeRef(Uchar c0,Uchar c1, Uchar c2,Uchar c3,Uchar c4,Uchar c5,Uchar c6,Uchar c7):len(8){code[0] = c0;code[1]=c1;code[2]=c2;code[3]=c3;code[4]=c4;code[5]=c5;code[6]=c6;code[7]=c7;}
        OpCodeRef(Uchar c0,Uchar c1, Uchar c2,Uchar c3,Uchar c4,Uchar c5,Uchar c6,Uchar c7,Uchar c8,Uchar c9):len(10){code[0] = c0;code[1]=c1;code[2]=c2;code[3]=c3;code[4]=c4;code[5]=c5;code[6]=c6;code[7]=c7;code[8]=c8;code[9]=c9;}
        void print(){ for(int i=0;i<len;i++) printf("%2x ", code[i]);}

};

OpCodeRef refDefault;

template <typename T>
void test ( MN mn, T src, OpCodeRef ref = refDefault)
{
InstructionCoder& is= Is64System()?m64:m32;
	is.trans(mn, (GPR)src);
	is.print(mn, (GPR)src);
	is.print();
    if(is.isEq(ref.code))printf("=="); else printf("!=");
    ref.print();
	printf("\n");
}

void test ( MN mn, I64 src, OpCodeRef ref = refDefault)
{
InstructionCoder& is= Is64System()?m64:m32;
	is.trans(mn, src);
	is.print(mn, src);
	is.print();
    if(is.isEq(ref.code))printf("=="); else printf("!=");
    ref.print();
	printf("\n");
}


template <typename T>
void test ( MN mn, T dst, T src, OpCodeRef ref = refDefault)
{
InstructionCoder& is= Is64System()?m64:m32;
	is.trans(mn, (GPR)dst,(GPR) src);
	is.print(mn, (GPR)dst,(GPR) src);
	is.print();
    if(is.isEq(ref.code))printf("=="); else printf("!=");
    ref.print();
	printf("\n");
}

template <typename T>
void test( MN mn, const MemMod& m, T src, OpCodeRef ref = refDefault)
{
InstructionCoder& is= Is64System()?m64:m32;
	is.trans(mn, m, (GPR)src); 
	is.print(mn,m, (GPR)src);
    is.print();
    if(is.isEq(ref.code))printf("=="); else printf("!=");
    ref.print();
	printf("\n");

}


template <typename T>
void test( MN mn, T dst, const MemMod& m, OpCodeRef ref = refDefault)
{
InstructionCoder& is= Is64System()?m64:m32;
	is.trans(mn, (GPR)dst, m); 
	is.print(mn, (GPR)dst, m);
    is.print();
    if(is.isEq(ref.code))printf("=="); else printf("!=");
    ref.print();
	printf("\n");

}

template <typename T>
void test( MN mn, T dst, I64 i, OpCodeRef ref = refDefault)
{
InstructionCoder& is= Is64System()?m64:m32;
	is.trans(mn, (GPR)dst, i); 
	is.print(mn, (GPR)dst, i);
    is.print();
    if(is.isEq(ref.code))printf("=="); else printf("!=");
    ref.print();
	printf("\n");

}


void testMemMod1()
{
InstructionCoder& is= Is64System()?m64:m32;
	MemMod m( 8, GPR_RAX, GPR_RBX, scale8);
	m.print();
	printf("\n");
	m.trans(0x80008,GPR_RAX, GPR_RBX, scale8);
	m.print();
	//m.trans(0x80008,GPR_RAX, GPR_RBX, 3);
	m.trans(GPR_RAX, GPR_RBX, scale8);
	m.print();
	m.trans(GPR_RAX, GPR_RBX );
	m.print();
	m.trans(GPR_RAX );
	m.print();
	printf("\n");

	is.trans_b2b(MN_ADD, GPR_AL, GPR_BL);
	is.print(MN_ADD,(GPR)GPR_AL, (GPR)GPR_BL);
	is.print();
	printf("\n");

	is.trans_w2w(MN_ADD, GPR_AX, GPR_BX);
	is.print(MN_ADD, (GPR)GPR_AX, (GPR)GPR_BX);
	is.print();
	printf("\n");

	is.trans_e2e(MN_ADD, GPR_EAX, GPR_EBX);
	is.print(MN_ADD, (GPR)GPR_EAX, (GPR)GPR_EBX);
	is.print();
	printf("\n");

	is.trans_r2r(MN_ADD, GPR_RAX, GPR_RBX);
	is.print(MN_ADD, (GPR)GPR_RAX, (GPR)GPR_RBX);
	is.print();
	printf("\n");

	is.trans_r2r(MN_ADD, GPR_R8, GPR_R9);
	is.print(MN_ADD, (GPR)GPR_R8, (GPR)GPR_R9);
	is.print();
	printf("\n");

	is.trans_r2r(MN_ADD, GPR_R8, GPR_RBX);
	is.print(MN_ADD, (GPR)GPR_R8, (GPR)GPR_RBX);
	is.print();
	printf("\n");

	is.trans_X2X(MN_ADDPS, xmm2, xmm1);
	is.print(MN_ADDPS, (GPR)xmm2, (GPR)xmm1);
	is.print();
	printf("\n");

    is.trans_e(MN_PUSH, GPR_EAX);
    is.print(MN_PUSH, (GPR)GPR_EAX);
    is.print();
	printf("\n");

    is.trans_e(MN_DEC, GPR_EAX);
    is.print(MN_DEC, (GPR)GPR_EAX);
    is.print();
	printf("\n");

	MemMod m2(GPR_EBX);
	is.trans_m2e(MN_ADD, GPR_EAX, MemMod(GPR_EBX)); 
	is.trans_m2e(MN_ADD, GPR_EAX, m2); 
	is.print(MN_ADD, (GPR)GPR_EAX, m2);
    is.print();
	printf("\n");

}

void testMemMod32()
{
    Set32System();
    printf("32 Bits system\n");
    test(MN_INC, GPR_EAX, OpCodeRef(0x40));
    test(MN_PUSH, GPR_AX,  OpCodeRef(0x66,0x50));
    test(MN_PUSH, GPR_EBP, OpCodeRef(0x55));

    test(MN_ADD, GPR_AX, (I64)0x1, OpCodeRef(0x66,0x83,0xc0,0x01));
	test(MN_ADD, GPR_EAX, 1, OpCodeRef(0x83, 0xc0,0x01)); 
	test(MN_ADD, GPR_ESP, 1, OpCodeRef(0x83, 0xc4,0x01)); 
    
	test(MN_ADDPD, xmm2, xmm1, OpCodeRef(0x66, 0xf,0x58,0xd1));

    test(MN_MOV, GPR_ECX, MemMod((I32)0xfff0,GPR_EAX,4), OpCodeRef(0x8b, 0x0c,0x85,0xf0,0xff,0x00,0x00));
	test(MN_MOV, GPR_EAX, 1, OpCodeRef(0xb8, 0x01,0x00,0x00,0x00)); 
	test(MN_MOV, GPR_ESP, 1, OpCodeRef(0xbc, 0x01,0x00,0x00,0x00)); 
	test(MN_MOV, GPR_EBX, GPR_EAX, OpCodeRef(0x89, 0xc3)); 
	test(MN_MOV, GPR_EAX, GPR_EBX, OpCodeRef(0x89, 0xd8)); 
	test(MN_MOV, GPR_EAX, MemMod((I32)0xEEFFEEFF), OpCodeRef(0x8b,0x0d,0xFF,0xEE,0xFF,0xEE)); 
	test(MN_MOV, GPR_ECX, MemMod((I32)0xEEFFEEFF), OpCodeRef(0x8b,0x0d,0xFF,0xEE,0xFF,0xEE)); 
    test(MN_MOV, GPR_EAX, (I64)1, OpCodeRef(0xb8,0x01,0x00,0x00,0x00));
	test(MN_CALL, GPR_EAX, OpCodeRef(0xff, 0xd0)); 
    test(MN_PUSH, (I64)0x0e, OpCodeRef(0xff,0xff));
}


void testMemMod64()
{
    Set64System();
    printf("64 Bits system\n");
    test(MN_INC, GPR_EAX, OpCodeRef(0xff,0xc0));
    test(MN_INC, GPR_RAX, OpCodeRef(0x48, 0xff,0xc0));
    test(MN_INC, GPR_R8, OpCodeRef(0x49, 0xff,0xc0));
    test(MN_PUSH, GPR_AX, OpCodeRef(0x66,0x50));
    test(MN_PUSH, GPR_RAX, OpCodeRef(0x50));
    test(MN_PUSH, GPR_EAX, OpCodeRef(0x50));
    test(MN_PUSH, GPR_R8, OpCodeRef(0x41, 0x50));

    test(MN_ADD, MemMod(GPR_RBX), GPR_EAX, OpCodeRef(0x01,0x03));

    test(MN_ADD, GPR_EAX, MemMod(GPR_R8), OpCodeRef(0x41,0x03,0x00));
    test(MN_ADD, GPR_EAX, (I64)0x1, OpCodeRef(0x83,0xc0,0x01));
    test(MN_ADD, GPR_AX, (I64)0x1, OpCodeRef(0x66,0x83,0xc0,0x01));
    test(MN_ADD, GPR_RAX, (I64)0x1, OpCodeRef(0x48,0x83,0xc0,0x01));
    test(MN_ADD, GPR_R8, (I64)0x1, OpCodeRef(0x49,0x83,0xc0,0x01));
    test(MN_ADD, MemMod(GPR_EBX), GPR_EAX, OpCodeRef(0x67,0x01,0x03));
    test(MN_ADD, GPR_EAX, MemMod(GPR_EBX), OpCodeRef(0x67,0x03,0x03));
    test(MN_ADD, MemMod(GPR_RBX), GPR_RAX, OpCodeRef(0x48,0x01,0x03));
    test(MN_ADD, GPR_RCX, MemMod(GPR_RBX), OpCodeRef(0x48,0x03,0x0b));
	test(MN_ADD, GPR_EAX, 1, OpCodeRef(0x83, 0xc0,0x01)); 
	test(MN_ADD, GPR_ESP, 1, OpCodeRef(0x83, 0xc4,0x01)); 
	test(MN_ADD, MemMod(GPR_EBX,GPR_ECX),GPR_AX, OpCodeRef(0x67, 0x66,0x01,0x04,0x0b)); 
	test(MN_ADD, MemMod(GPR_RBX),GPR_AX, OpCodeRef(0x66,0x01,0x03)); 
	test(MN_ADD, MemMod(GPR_EBX),GPR_RAX, OpCodeRef(0x67,0x48,0x01,0x03)); 
	test(MN_ADD, MemMod(GPR_RBX),GPR_EAX, OpCodeRef(0x01,0x03)); 
	test(MN_ADD, GPR_RCX, (I64)0xFFEEFF, OpCodeRef(0x48,0x81,0xc1,0xff,0xee,0xff,0x00)); 
    
	test(MN_ADDPD, xmm2, xmm1, OpCodeRef(0x66, 0xf,0x58,0xd1));

    test(MN_MOV, GPR_ECX, MemMod((I32)0xfff0,GPR_EAX,4), OpCodeRef(0x67, 0x8b, 0x0c,0x85,0xf0,0xff,0x00,0x00));
	test(MN_MOV, GPR_RCX, MemMod(GPR_RBX), OpCodeRef(0x48,0x8b,0x0b)); 
	test(MN_MOV, MemMod(GPR_RBX), GPR_RCX, OpCodeRef(0x48,0x89,0x0b)); 
	test(MN_MOV, GPR_EAX, 1, OpCodeRef(0xb8, 0x01,0x00,0x00,0x00)); 
	test(MN_MOV, GPR_ESP, 1, OpCodeRef(0xbc, 0x01,0x00,0x00,0x00)); 
	test(MN_MOV, GPR_EBX, GPR_EAX, OpCodeRef(0x89, 0xc3)); 
	test(MN_MOV, GPR_EAX, GPR_EBX, OpCodeRef(0x89, 0xd8)); 
	test(MN_MOV, GPR_RBX, GPR_RAX, OpCodeRef(0x48,0x89, 0xc3)); 
	test(MN_MOV, GPR_RAX, GPR_RBX, OpCodeRef(0x48,0x89, 0xd8)); 
	test(MN_MOV, GPR_ECX, MemMod((I32)0xEEFFEEFF)); 
	test(MN_MOV, GPR_RCX, (I64)0xFFEEFFEEFF, OpCodeRef(0x48, 0xb9,0xff,0xee,0xff,0xee,0xff,0x00,0x00,0x00)); 
	test(MN_MOV, GPR_ECX, (I64)0xEEFFEEFF, OpCodeRef(0xb9,0xff,0xee,0xff,0xee)); 
    test(MN_MOV, GPR_EAX, (I64)1, OpCodeRef(0xb8,0x01,0x00,0x00,0x00));
    test(MN_MOV, GPR_RAX, (I64)1, OpCodeRef(0x48,0xc7,0xc0, 0x01,0x00,0x00,0x00));
	test(MN_CALL, GPR_EAX); 
	test(MN_CALL, GPR_RAX, OpCodeRef(0xff, 0xd0)); 
}

void testMemMod()
{
    testMemMod1();
    testMemMod64();
    testMemMod32();
}

void testX2X()
{
    //trans(add, GPR_RAX, GPR_RBX);
}

int main()
{
    testMemMod();
}
