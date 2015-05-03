/**
* =====================================================================================
*       @file    node.hxx
*
*       @brief   '
*
*       @author  DAI ZHENGHUA (), djx.zhenghua@gmail.com
*       @version 1.0
*       @date    01/30/2011 10:48:26 AM
*
*       Revision none
*       Compiler gcc
*       Company  
* =====================================================================================
*/

#ifndef  nodehxx_header_INC
#define  nodehxx_header_INC

#include "vacg.h"
#include "symbol.h"
#include "op.h"
#include "node.h"
#include "gimple.hxx"

typedef enum {

}astNodeType;


#define log_create 1 
#define log_dbg 0

class AstNode;
typedef std::vector<AstNode*> StatementsList;
class AstNode :public Node
{
public:
	AstNode(){
		VASDEBUG(log_dbg,numAstNode++);
		VASDEBUG(log_create,dumpAst(stdout));
	}
	~AstNode(){}
	virtual void codeGento(u8*& f){};
	virtual void dumpAst(FILE* fp)const { fprintf(fp, "AstNode:%p\n", this);};
	virtual void dump(FILE* fp)const { dumpAst(fp);};
	virtual NodeType getNodetype(){return nt_AstNode;}
public:
	//void codeGen(){ codeGento(gvacg.getf());} 
    virtual GimpleNode* gimplify(FlowGraph* thisGraph){return NULL;}
public:
};

class AstExpression:public AstNode 
{
public:
	AstExpression(){}
	virtual VaVar& getVar(){VaVar tmp; return *(VaVar*)NULL; }
    virtual SymbolInfo& getSymbol(){return *(SymbolInfo*)NULL;}

};

class AstOpExpr:public AstExpression
{
public:
	AstOpExpr():opcode((char*)NULL), oprand1(NULL), oprand2(NULL),oprand0(NULL){}
	AstOpExpr(OpCode opc, AstExpression* oprand1, AstExpression* oprand2);
public:
	virtual void codeGento(u8*& f)
	{
		if(oprand1) oprand1->codeGento(f);
		if(oprand2) oprand2->codeGento(f);
		switch(opcode.getop()){
            case '*':vaCG::call_Detect(f, oprand0->getVar(), oprand1->getVar(), oprand2->getVar());
                     break;
            default:
                     break;
		}
	};
	virtual void dumpAst(FILE* fp)const { 
		fprintf(fp, "(");
		fprintf(fp, "<op expression:%p> ", this);
		fprintf(fp, "(");
		if(oprand0) oprand0->dumpAst(fp);
		fprintf(fp, "=");
		if(oprand1) oprand1->dumpAst(fp);
		opcode.dump(fp);
		if(oprand2) oprand2->dumpAst(fp);
		fprintf(fp, ")");
		fprintf(fp, ");\n");
	}
	virtual NodeType getNodetype(){return nt_AstOpExpr;}
	virtual VaVar& getVar(){return oprand0-> getVar(); }
    virtual SymbolInfo& getSymbol(){return oprand0->getSymbol();}
    virtual GimpleNode* gimplify(FlowGraph* thisGraph);
private:
	OpCode opcode;
	AstExpression* oprand1;
	AstExpression* oprand2;
	AstExpression* oprand0;//dest
};


class AstVarExpr:public AstExpression
{
public:
	SymbolInfo var;
	AstVarExpr(SymbolInfo& v){var = v;VASMSG(log_create,"create AstVarExpr\n");}
	AstVarExpr(SymbolInfo* v){var =*v;VASMSG(log_create,"create AstVarExpr\n");}
	virtual void dumpAst(FILE* fp)const { 
		var.dump(fp);
	}
	virtual VaVar& getVar(){return  var.getVar(); }
    virtual SymbolInfo& getSymbol(){return var;}
};

class AstConstExpr:public AstExpression
{
public:
	VaVar var;
public:
	AstConstExpr(size_t v){ var.setValue((void*)v);VASMSG(log_create,"create AstConstExpr\n");}
	virtual void dumpAst(FILE* fp)const { fprintf(fp, "AstConstExpr:%p\n", this);};
	virtual VaVar& getVar(){return  var; }
    virtual SymbolInfo& getSymbol(){printf("HAHA \n");return *(SymbolInfo*)NULL;}
};

class AstStatement:public AstNode 
{
public:
	virtual void dumpAst(FILE* fp)const { fprintf(fp, "AstStatement:%p\n", this);};
};

class AstFilterState:public AstStatement
{

private:
	SymbolInfo  outFrame;
	SymbolInfo  inFrame;
	SymbolInfo  filterKernel;
public:
	AstFilterState(SymbolInfo outF, SymbolInfo inF, SymbolInfo filterK):outFrame(outF), inFrame(inF), filterKernel(filterK){VASDEBUG(log_create,dumpAst(stdout));}
public:
	virtual void codeGento(u8*& f){ vaCG::call_Detect(f, outFrame.getVar(), inFrame.getVar(), filterKernel.getVar());};
	virtual void dumpAst(FILE* fp)const { 
        fprintf(fp, "AstFilterState:<%p>: ", this);
        outFrame.dump(fp);
        filterKernel.dump(fp);
        inFrame.dump(fp);
        fprintf(fp, "\n");
    };
    virtual GimpleNode* gimplify(FlowGraph* thisGraph);
};

class AstAssginState:public AstStatement
{
private:
	SymbolInfo lhVaVar;
	AstExpression* lhv;
	AstExpression* rhv;

public:
	AstAssginState(AstExpression* lhv, AstExpression* rhv){
		this->rhv = rhv;
		this->lhv =lhv;
		VASMSG(log_create, "crate AstAssginState\n");
	}
	AstAssginState(SymbolInfo lhv, AstExpression* rhv){
		lhVaVar= lhv;
		this->rhv = rhv;
		this->lhv =0;
		VASMSG(log_create, "crate AstAssginState\n");
	}

	virtual void dumpAst(FILE* fp)const { 
		fprintf(fp, "(<AstAssign:%p>", this);
		if(lhv)
			lhv->dumpAst(fp);
		else 
			lhVaVar.dump(fp);

		fprintf(fp, " = ");
		rhv->dumpAst(fp);
		fprintf(fp, ")\n");
	}

    virtual GimpleNode* gimplify(FlowGraph* thisGraph);

	virtual void codeGento(u8*& f){
		//!Current Node
		if(rhv)
			rhv->codeGento(f);
		if(lhv)
			vaCG::copy_frame(f, lhv->getVar(), rhv->getVar());
		else 
			vaCG::copy_frame(f, lhVaVar.getVar(), rhv->getVar());
		//!
	}
};

class AstIfNode:public AstStatement
{
    private:
        AstExpression* cond;
        AstStatement* ifnode;
        AstStatement* elsenode;
    public:
        AstIfNode(AstExpression* condition, AstStatement* ifStatement, AstStatement* elseStatement = NULL):
    cond(condition), ifnode(ifStatement), elsenode(elseStatement) { printf("this is if KKKKKKKKKKKKKK\n");}

};

class FlowGraph;
extern FlowGraph* rootRegion;
extern FlowGraph* curRegion;
#include "graph.hxx"
class AstGraphNode:public AstStatement
{
    public:
        AstGraphNode(FlowGraph* graph):m_Graph(graph){}
    private:
        FlowGraph* m_Graph;
    public:
	virtual void codeGento(u8*& f){ m_Graph->codeGento(f);};
	virtual void dumpAst(FILE* fp)const { m_Graph -> dumpAst(fp); fprintf(fp, "AstNode:%p\n", this);};
	virtual void dump(FILE* fp)const { dumpAst(fp);};
	virtual NodeType getNodetype(){return nt_AstNode;}
public:
	//void codeGen(){ codeGento(gvacg.getf());} 
    virtual GimpleNode* gimplify(FlowGraph* thisGraph){ 
        m_Graph->gimplify(NULL); 
        GimpleGraphNode* t = new GimpleGraphNode(m_Graph);
        thisGraph->appandGimpleNode(t);
        return t;
    }
};

#endif   /* ----- #ifndef nodehxx_header_INC  ----- */
