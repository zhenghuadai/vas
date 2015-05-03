/*
 * =====================================================================================
 *
 *       Filename:  testopcode.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/08/2009 04:30:14 PM
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
int buf[1024];
int test()
{
	int eax;
	__asm__(
	"movl $0xFFFF, %%eax;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"incl %%ebx;"
	"movl $0xF2b3, %%ebx;"
	"incw %%ax;"
	//"incq %%rbx;"
	"xorl %%ebx, %%ebx;"
	"movl 4(%%esi, %%ebx, 4), %%eax;"
	"incb %%al;"
	"incw %%ax;"
	"incl %%eax;"
	//"incq %%rax;"
	//"incq %%r8;"
	//"incq %%r9;"
	//"incq %%r10;"
	//"incq %%r11;"
    "addb %%bl, %%al;"
    "addb $9, %%al;"
    //"addl %%ebx, %%eax;"
    //"addl (%%rbx), %%eax;"
    "addl (%%r8), %%eax;"
    "addl (%%ebx, %%ecx), %%eax;"
    "addw (%%ebx), %%ax;"
    "addw %%bx, %%ax;"
    //"addq %%rbx, %%rax;"
    //"addq %%r9, %%r8;"
    //"addq %%rbx, %%r8;"
	"addps %%xmm1, %%xmm2;"
	"pushq %%rbp;"
	"pushq %%r8;"
	"pushq %%rax;"
	//"pushl %%ebp;"
	"pushw %%bp;"
	:"=a"(eax)
	:"S"(buf)
	:"%ebx"
	);
	printf("%d\n",eax);
}
int test2()
{
	int eax;
	__asm__(
	"movl $0xFFFF, %%eax;"
    "addb %%bl, %%al;"
    "addb $9, %%al;"
    "addl (%%r9), %%eax;"
    "addq (%%r9), %%rax;"
    "addq  $0x11001100, %%rax;"
    "addq  $0x1100, %%rax;"
    //"addq  $0x11001100ff001100, %%rax;"
    "addl (%%ebx, %%ecx), %%eax;"
    "addw (%%ebx), %%ax;"
    "addw %%bx, %%ax;"
	"addps %%xmm1, %%xmm2;"
	:"=a"(eax)
	:"S"(buf)
	:"%ebx"
	);
	printf("%d\n",eax);
}
int main()
{
	test();
	test2();
	return 1;
}
