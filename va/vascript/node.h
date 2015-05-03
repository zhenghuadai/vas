/*
 * =====================================================================================
 *
 *       Filename:  node.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/29/2011 08:13:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  DAI ZHENGHUA (), djx.zhenghua@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef  node_header_INC
#define  node_header_INC

typedef enum {nt_undefined=0,
    nt_AstNode=1, nt_AstOpExpr,
    nt_GimpleNode=128, nt_GimpleStatementNode,nt_GimpleAssignNode, nt_GimpleGraphNode 
} NodeType;
inline bool isAstNode(NodeType t){ return ((t>0) && (t< 128));}
inline bool isGimpleNode(NodeType t){ return ((t> 128));}

class Node 
{
public:
	Node():next(NULL),prev(NULL){
	}
	~Node(){}
	virtual void codeGento(u8*& f){};
	virtual void dump(FILE* fp)const { fprintf(fp, "Node:%p\n", this);};
	virtual NodeType getNodetype(){return nt_undefined;}
public:
    void appand(Node* o) {o->prev = this; o->next = this->next; if(next){this->next->prev = o;} this->next = o;}
    Node*& getNext(){return next;}
    Node*& getPrev(){return prev;}
    void setNext(Node* o){ next = o;}
private:
    Node* next;
    Node* prev;
public:
	void codeGen(){ codeGento(gvacg.getf());} 
public:
};


#endif   /* ----- #ifndef node_header_INC  ----- */
