/**
 * =====================================================================================
 *       @file    symbol.h
 *
 *       @brief   
 *
 *       @author  DAI ZHENGHUA (), djx.zhenghua@gmail.com
 *       @version 1.0
 *       @date    05/22/2011 09:36:07 AM
 *
 *       Revision none
 *       Compiler gcc
 *       Company  
 * =====================================================================================
 */
#ifndef  symbol_INC
#define  symbol_INC
#include "vacg.h"
class FlowGraph;
class Symbol;
class GimpleNode;
class GimpleBase;
class SymbolInfo{
    private:
        FlowGraph* graph;
        int symbolID;
        argtype_t type;
    public:
        SymbolInfo(){}
        void set(FlowGraph* graph, int sid, argtype_t t){
            symbolID=sid;
            type=t;
            this->graph= graph;
        }; 
        SymbolInfo(const SymbolInfo& o){
            symbolID=o.symbolID;
            type=o.type;
            graph= o.graph;
        }
        VaVar& getVar();
        void dump(FILE* fp)const ; 
        argtype_t getType(){return type;}
        Symbol* getSymbol();
        int getSymbolID(){return symbolID;}

        void setReplace(SymbolInfo s);
        Symbol* getReplace();

        void setDefnode(GimpleBase*);
        GimpleBase* getDefnode();
        bool operator ==(SymbolInfo& s){ return ((this->graph == s.graph)&&(this->symbolID==s.symbolID)&&(this->type==s.type));}
        bool operator !=(SymbolInfo& s){ return ((this->graph != s.graph)||(this->symbolID!=s.symbolID)||(this->type!=s.type));}
};

class Symbol{
    public:
        SymbolInfo info;
    private:
        VaVar obj;
        char* name;
        unsigned int status:8;
    private:
        union{
            Symbol* replace;
            GimpleBase* def;
        };
    public:
        Symbol():replace(NULL){}
        Symbol(const Symbol& o){
            info = o.info;
            obj  = o.obj;
            name = o.name;
        }
    public:
        void setVar(VaVar var){
            obj = var;
        }
        void setobj(VaVar var){setVar(var);}
        void set(FlowGraph* graph, int sid, char* name, argtype_t t, int imm); 
        template<class T>
            void set(FlowGraph* graph, int sid, char* name,  argtype_t t, T*& ref)
            {

                info.set(graph, sid, t);
                //            this->name = (name == NULL? NULL: strdup(name));
                if(name !=NULL)
                    this-> name = strdup(name);
                else
                    this->name = NULL;
                obj = VaVar(t, ref);
            }
    public:
        SymbolInfo* getSymbolInfo(){return &info;}
        char* getName(){return name;}
        VaVar& getobj(){return obj;}
        argtype_t getType(){return info.getType();}
        void setReplace(Symbol* o){replace = o;}
        Symbol* getReplace(){return replace;}
        GimpleBase*& getDefnode(){return def;}
};

typedef std::vector<Symbol> VarTable;

#define oFrame_symblinfo   ((*(rootRegion->varTable))[0].info)
#define preFrame_symblinfo ((*(rootRegion->varTable))[1].info)
#define curFrame_symblinfo ((*(rootRegion->varTable))[2].info)
#define nxtFrame_symblinfo ((*(rootRegion->varTable))[3].info)
#define Sobel_symblinfo    ((*(rootRegion->varTable))[4].info)
#define Robert_symblinfo   ((*(rootRegion->varTable))[5].info)
#define Prewitt_symblinfo  ((*(rootRegion->varTable))[6].info)
#define LapLas_symblinfo   ((*(rootRegion->varTable))[7].info)
#define FreiChen_symblinfo ((*(rootRegion->varTable))[8].info)





#endif   /* ----- #ifndef symbol_INC  ----- */
