/*
 * =====================================================================================
 *
 *       Filename:  symbol.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/23/2011 06:34:46 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  DAI ZHENGHUA (), djx.zhenghua@gmail.com
 *        Company:  
 *
 * =====================================================================================
 */
#include "node.hxx"
#include "symbol.h"
/*  
SymbolInfo::SymbolInfo(FlowGraph* graph, argtype_t t, int imm)
{
    symbolID = graph->lastSymbolID++;
    type=t;
    graph->varTable[symbolID].setVar(VaVar(atREF, oFrame));
}

template<class T>
SymbolInfo::SymbolInfo(FlowGraph* graph, argtype_t t, T*& ref)
{
    symbolID = graph->lastSymbolID++;
    type=t;
    graph->varTable[symbolID].setVar(VaVar(atREF, oFrame));
}
*/

void Symbol::set(FlowGraph* graph, int sid, char* name, argtype_t t, int imm) 
{
    info.set(graph, sid, t);
    //    this-> name = strdup(name);
    this->name = (name == NULL? NULL: strdup(name));
    obj = VaVar(t, imm);
}

VaVar& SymbolInfo::getVar()
{
    return graph->getVar(this->symbolID);
}

Symbol* SymbolInfo::getSymbol(){return graph->getSymbol(*this);}

void SymbolInfo::dump(FILE* fp)const{
    Symbol& smbl = ((*(this->graph->varTable))[this->symbolID]);
    fprintf(fp, "{ID:%3d, %6s", symbolID, smbl.getName()?smbl.getName():"NULL");
    smbl.getobj().dump(fp);
    fprintf(fp, "}");
    fflush(fp);
}

void SymbolInfo::setReplace(SymbolInfo s)
{
    return (getSymbol())->setReplace( s.getSymbol());
}

void SymbolInfo::setDefnode(GimpleBase* gnode)
{
    (getSymbol())->getDefnode() = gnode;
}

GimpleBase* SymbolInfo::getDefnode()
{
    return (getSymbol())->getDefnode();
}
