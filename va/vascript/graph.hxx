/*
 * =====================================================================================
 *
 *       Filename:  graph.hxx
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/31/2011 03:23:38 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#ifndef  graph_header_INC
#define  graph_header_INC
#include "node.hxx"
#include "gimple.hxx"
class FlowGraph
{
public:
	std::vector<AstNode*> stmts;
    GimpleNode* gimpleHeader;
    GimpleNode* gimpleTail;
private:
	FlowGraph *parent;
	FlowGraph *child;
	FlowGraph *lastChild;
	FlowGraph *nextSib;
	int lastSymbolID ;
public:
	VarTable* varTable;
public:
	void init(){gimpleHeader=gimpleTail = NULL; parent=0; child=0;nextSib=0; lastChild=0;lastSymbolID = -1;varTable = new VarTable(100);}
	FlowGraph(){init();VASMSG(log_create,"create FlowGraph\n");}
	~FlowGraph(){ delete varTable;}
public:
    bool gimplified() { return getGimpleHeader() != NULL;}
    GimpleNode* getGimpleHeader(){return gimpleHeader;}
    GimpleNode* getGimpleTail(){return gimpleTail;}
	void appandNode(AstNode* nodep){stmts.push_back(nodep);}
    void appandGimpleNode(GimpleNode* gimpleNode){
        if(gimpleHeader ==NULL){
            gimpleHeader = gimpleTail = gimpleNode;
        }else{
            gimpleTail->appand((Node*)gimpleNode);
            gimpleTail = gimpleNode;
        }
    }
    void deleteGimpleNode(GimpleNode* gnode){
        if(gnode == gimpleHeader){
            gimpleHeader = (GimpleNode*)gimpleHeader->getNext();
            gimpleHeader->getPrev() = NULL;
        }else if(gnode == gimpleTail){
            gimpleTail=  (GimpleNode*)gimpleTail->getPrev();
            //gimpleTail->getNext() = NULL;
            gimpleTail->setNext(NULL);
        }else{
            gnode->getPrev()->getNext()=gnode->getNext();
            gnode->getNext()->getPrev()=gnode->getPrev();
        }
        delete gnode;
    }

    virtual void dumpAst(FILE* fp)const { 
        StatementsList::const_iterator it;
        fprintf(fp, "FlowGraph:%p\n", this);
        int i = 0;
        for(it= stmts.begin(); it != stmts.end(); it++){
            fprintf(fp, "%d::", i++);
            (*it) -> dumpAst(fp);
        }
    };
    virtual GimpleNode* gimplify(FlowGraph* thisGraph){
        if(gimplified()) return getGimpleHeader();
        StatementsList::const_iterator it;
        int i = 0;
        for(it= stmts.begin(); it != stmts.end(); it++){
            printf("\nGimplify <%p>\n", this);
            (*it) -> gimplify(this);
            printf("\nGimplify <%p> End\n", this);
        }
        return getGimpleHeader();
    }
    virtual void dumpGimple(FILE* fp)const { 
        Node* cur = gimpleHeader;
        while(cur !=NULL){
            //((GimpleStatement*)cur) -> dumpGimple(fp);
            cur -> dump(fp);
            cur = cur->getNext();
        }
    };

    void gimpleCodeGento(u8*& f){ 
        Node* cur = gimpleHeader;
        while(cur !=NULL){
            //((GimpleStatement*)cur) -> dumpGimple(fp);
            cur -> codeGento(f);
            cur = cur->getNext();
        }
    };

    void astCodeGento(u8*& f){
        //!
        StatementsList::const_iterator it;
        for(it= stmts.begin(); it != stmts.end(); it++){
            (*it) -> codeGento(f);
        }

    };

    virtual void codeGento(u8*& f){
        if(gimpleHeader)
            gimpleCodeGento(f);
        else
            astCodeGento(f);
        //!At the end of script, appand ret instuction
        if (parent == NULL){
            vaCG::code_ret(gvacg.getf());
        }

    }

public:
    void codeGen(){ codeGento(gvacg.getf());} 
public:
    //!building
    void addChild( FlowGraph* _child){ 
        if(this->child == NULL) {
            this->child= _child;
            this->lastChild= _child;
        }else{
            this->lastChild->nextSib=_child;
            this->lastChild=_child;
        }
        _child->parent = this;
    }
    void simplePush(){
        this->parent = curRegion;
        curRegion= this;
    }
    void push(){
        this->parent = curRegion;
        if(curRegion )
            curRegion->addChild(this);
        curRegion= this;
    }
    static void pop(){ curRegion= curRegion->parent;}
public:
    //! optimization
    void copyProp();
    void dce();
    void ssa();
    void optimize();
    static void allocFrame(FlowGraph* grahp);
public:
    SymbolInfo* getSymbolInfo(char* name);
    SymbolInfo* getornewSymbolInfo(char* name);
    static SymbolInfo* getSymbolInfo(FlowGraph* graph, char* name);
    SymbolInfo* newtmpSymbol();
    SymbolInfo* newSymbol(char* name, argtype_t t, size_t imm);
    template<class T>
        SymbolInfo* newSymbol(char* name, argtype_t t, T*& ref){
            lastSymbolID ++;
            varTable->push_back(Symbol());
            (*varTable)[lastSymbolID].set(this, lastSymbolID, name, t, ref);
            return (*varTable)[lastSymbolID].getSymbolInfo();

        }
    VaVar& getVar(int idx){ return (*varTable)[idx].getobj();}
    Symbol* getSymbol(SymbolInfo s){ return &((*varTable)[s.getSymbolID()]);}
public:
};

class Function:public FlowGraph
{
private:
    int   m_retType;
    char* m_fn;
    int   m_params;
public:
    Function(char* fn):m_fn(fn){}
    bool is(char* fn) {return strcmp(fn, m_fn) == 0;}
};

class FunctionList
{
private:
    std::vector<Function*> * m_functions;
public:
    FunctionList(){ m_functions = new std::vector<Function*>();}
    void addFunction(Function* f) { m_functions -> push_back(f);}
    Function* getFunction(char* name) {
        std::vector<Function*> ::const_iterator it;
        for(it= m_functions->begin(); it != m_functions->end(); it++){
		if((*it)->is(name)) return *it;
        }
    }
};

extern FunctionList* functionList;
#endif   /* ----- #ifndef graph_header_INC  ----- */
