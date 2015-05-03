/*
 * =====================================================================================
 *
 *       Filename:  op.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/11/2011 07:05:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  DAI ZHENGHUA (), djx.zhenghua@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef  opcode_header_INC
#define  opcode_header_INC

class OpCode
{
public:
	OpCode(char op){this->op = op;}
	OpCode(char* ){}
private:
	OpCode(){}
public:
	void dump(FILE* fp)const{
		fprintf(fp,"%c ", op);
	}
	char getop(){return op;}
private:
	char op;
};


#endif   /* ----- #ifndef opcode_header_INC  ----- */
