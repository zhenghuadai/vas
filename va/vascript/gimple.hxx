/*
 * =====================================================================================
 *
 *       Filename:  gimple.hxx
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/11/2011 06:40:03 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  DAI ZHENGHUA (), djx.zhenghua@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */

#ifndef  gimplehxx_header_INC
#define  gimplehxx_header_INC

#include "vacg.h"
#include "symbol.h"
#include "op.h"
#include <vector>
#include "node.h"

class GimpleNode:public Node 
{
    public:
        GimpleNode(){}
    public:
        virtual void dumpGimple(FILE* fp)const {}
        virtual void dump(FILE* fp)const { dumpGimple(fp);};
        virtual NodeType getNodetype(){return nt_GimpleNode;}
};

class GimpleBase:public GimpleNode 
{
    public:

        GimpleBase(OpCode op, SymbolInfo ret, SymbolInfo src0)
            :    m_op(op),defuse(NULL)
        {
            m_args.push_back(ret);
            m_args.push_back(src0);
        }

        GimpleBase(OpCode op, SymbolInfo ret, SymbolInfo src0, SymbolInfo src1)
            :    m_op(op),defuse(NULL)
        {
            m_args.push_back(ret);
            m_args.push_back(src0);
            m_args.push_back(src1);
            ret.dump(stdout); src0.dump(stdout);src1.dump(stdout);
        }
    public:
        virtual void dumpGimple(FILE* fp)const { 
            fprintf(fp, "<gimple expression:%p> ", this);
            SymbolInfo oprand0 = m_args[0];
            SymbolInfo oprand1 = m_args[1];
            SymbolInfo oprand2 = m_args[2];
            oprand0.dump(fp);
            fprintf(fp, "=");
            oprand1.dump(fp);
            m_op.dump(fp);
            oprand2.dump(fp);
            fprintf(fp, ";\n");

        }
    public:
        SymbolInfo& getOprand(int idx) { return m_args[idx];}
        size_t getArgNum(){ return m_args.size();}
    protected:
        OpCode m_op;   
        std::vector<SymbolInfo> m_args;
    public:
        GimpleBase* defuse;
        //GimpleNode* usedef;
};

class GimpleStatement:public GimpleBase
{
    public:
        GimpleStatement(OpCode op, SymbolInfo ret, SymbolInfo src0, SymbolInfo src1):GimpleBase(op,ret,src0,src1){}
        GimpleStatement(OpCode op, SymbolInfo ret, SymbolInfo src0 ):GimpleBase(op,ret,src0){}
        virtual NodeType getNodetype(){return nt_GimpleStatementNode;}

        virtual void codeGento(u8*& f){
            switch(m_op.getop()){
                case '*':vaCG::call_Detect(f, getOprand(0).getVar(), getOprand(1).getVar(), getOprand(2).getVar());
                         break;
                case '+':
                         //if() 
                         printf("call Add\n");
                         break;
                case '-':vaCG::sub_frame(f, getOprand(0).getVar(), getOprand(1).getVar(), getOprand(2).getVar());
                         break;
                default:
                         break;
            }
        }
};

class GimpleAssign:public GimpleStatement
{
    public:
        GimpleAssign(SymbolInfo lval, SymbolInfo rval):GimpleStatement('=', lval, rval){}

        virtual void dumpGimple(FILE* fp)const { 
            fprintf(fp, "<gimple expression:%p> ", this);
            SymbolInfo oprand0 = m_args[0];
            SymbolInfo oprand1 = m_args[1];
            oprand0.dump(fp);
            fprintf(fp, "=");
            oprand1.dump(fp);
            fprintf(fp, ";\n");
        }

        virtual NodeType getNodetype(){return nt_GimpleAssignNode;}

        virtual void codeGento(u8*& f){
            //!Current Node
            vaCG::copy_frame(f, getOprand(0).getVar(), getOprand(1).getVar());
            //!
        }

};

class FlowGraph;
class GimpleGraphNode:public GimpleNode
{
    public:
        GimpleGraphNode(FlowGraph* graph):m_Graph(graph){}
    private:
        FlowGraph* m_Graph;
    public:
        virtual void codeGento(u8*& f);;
        virtual void dumpAst(FILE* fp)const { };
        virtual void dumpGimple(FILE* fp)const ; 
        virtual void dump(FILE* fp)const { dumpGimple(fp);};
        virtual NodeType getNodetype(){return nt_GimpleGraphNode ;}
    public:
        FlowGraph* getGraph(){ return m_Graph;}
    public:
        //void codeGen(){ codeGento(gvacg.getf());} 
};

inline bool isGimpleStatement(Node* gn) { return (gn->getNodetype()==nt_GimpleAssignNode || gn->getNodetype()== nt_GimpleStatementNode);}
typedef std::vector<GimpleStatement*> GimpleStatementsList;
#endif   /* ----- #ifndef gimplehxx_header_INC  ----- */
