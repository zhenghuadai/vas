/*
 * =====================================================================================
 *
 *       Filename:  graph.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/31/2011 03:52:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include "node.hxx"
SymbolInfo* FlowGraph::getSymbolInfo(FlowGraph* graph, char* name){

    for(int i=0;i<graph->lastSymbolID;i++){
        const char* refstr = (*(graph->varTable))[i].getName();
        if((refstr!=NULL)&&( strcmp(name, refstr) == 0)) {
            return ((*(graph->varTable))[i].getSymbolInfo());
        }
    }
    return NULL;
}

SymbolInfo* FlowGraph::getSymbolInfo(char* name){
    FlowGraph* graph = this;
    while(graph){
        SymbolInfo* sinfo = getSymbolInfo(graph, name);
        if(sinfo)
            return sinfo;
        graph = graph -> parent;
    }
    return NULL;
}

SymbolInfo* FlowGraph::getornewSymbolInfo(char* name){
    SymbolInfo* cur = getSymbolInfo(name);
    if (cur ==NULL){
        cur = newSymbol(name, atVarFRAME, 0);
    }
    return cur;
}

SymbolInfo* FlowGraph::newtmpSymbol()
{
    lastSymbolID ++;
    (*varTable)[lastSymbolID].set(this, lastSymbolID, NULL, atTmpFRAME, 0);
    return (*varTable)[lastSymbolID].getSymbolInfo();
}

SymbolInfo* FlowGraph::newSymbol(char* name, argtype_t t, size_t imm)
{
    lastSymbolID ++;
    (*varTable)[lastSymbolID].set(this, lastSymbolID, name, t, imm);
    return (*varTable)[lastSymbolID].getSymbolInfo();

}

void  FlowGraph::allocFrame(FlowGraph* graph){
    int curAvailableFrame = 0;
    for(int i=0;i<=graph->lastSymbolID;i++){
        Symbol& curSymb = (*(graph->varTable))[i];
        if( curSymb.getType() == atVarFRAME){
            if (curAvailableFrame> POOLSIZE){}
            curSymb.setVar(VaVar(atVarFRAME,&(pImagePool[curAvailableFrame ])));
            curAvailableFrame++; 
        }else if( curSymb.getType() == atTmpFRAME){
            if (curAvailableFrame> POOLSIZE){}
            curSymb.setVar(VaVar(atTmpFRAME,&(pImagePool[curAvailableFrame ])));
            curAvailableFrame++; 
        }
    }

    Node* cur = graph->getGimpleHeader();
    while(cur !=NULL){
        if(cur->getNodetype() == nt_GimpleGraphNode){
            allocFrame( ((GimpleGraphNode*)cur)->getGraph());

        }
        cur = cur->getNext();
    }
    return ;
}
void  FlowGraph::optimize(){
	gimplify(this);
    copyProp();
    dce();
    allocFrame(this);
}

#define GRAPH_RECURSIVE( x) \
do{\
    GimpleNode* cur = gimpleHeader;\
    while(cur !=NULL){\
        if((cur->getNodetype() == nt_GimpleGraphNode )){\
            GimpleGraphNode* graph = (GimpleGraphNode*) cur ;\
            graph -> getGraph()-> x ();\
        }\
        cur = cur->getNext();\
    }\
}while(0);

void  FlowGraph::copyProp(){
    Node* cur = gimpleHeader;
    for(int i=0;i< varTable->size(); i++) (*varTable)[i].setReplace(NULL);
    while(cur !=NULL){
        if(1){ //! must be statement
            if(isGimpleStatement(cur)){
                GimpleBase* gcur= (GimpleBase*) cur;
                for(size_t i=1;i< gcur-> getArgNum(); i++){
                    if( gcur->getOprand(i).getSymbol()->getReplace() != NULL) {
                        SymbolInfo newsi = *(gcur->getOprand(i).getSymbol()->getReplace()->getSymbolInfo());
                        gcur->getOprand(i) = newsi; 
                    }
                }
            }
        }
        if(cur -> getNodetype() == nt_GimpleAssignNode){
            GimpleAssign* gcur= (GimpleAssign*) cur;
            gcur->getOprand(0).setReplace(gcur->getOprand(1));
        }

        if((cur->getNodetype() == nt_GimpleGraphNode )){
            GimpleGraphNode* graph = (GimpleGraphNode*) cur ;
            graph -> getGraph()-> copyProp ();
        }

        cur = cur->getNext();
    }
}

void  FlowGraph::dce(){
    VarTable::iterator i;
    for(i = varTable->begin(); i!= varTable->end(); i++){
        Symbol& s = *i;
        s.getDefnode() = NULL;
    }

    GimpleNode* cur = gimpleHeader;
    while(cur !=NULL){
        if((cur->getNodetype() == nt_GimpleStatementNode)||(cur->getNodetype() == nt_GimpleAssignNode) ){ //! must be statement
            GimpleBase* gcur= (GimpleBase*) cur;
            gcur->defuse = NULL;
            gcur->getOprand(0).setDefnode(gcur);
            for(size_t i=1;i< gcur-> getArgNum(); i++){
                if(gcur->getOprand(i).getDefnode())
                gcur->getOprand(i).getDefnode()->defuse = gcur;
            }
        }else if((cur->getNodetype() == nt_GimpleGraphNode )){
            GimpleGraphNode* graph = (GimpleGraphNode*) cur ;
            graph -> getGraph()->dce();
        }
        cur = (GimpleNode*)cur->getNext();
    }

    cur = gimpleHeader;
    while(cur !=NULL){
        if((cur->getNodetype() == nt_GimpleStatementNode)||(cur->getNodetype() == nt_GimpleAssignNode) ){ //! must be statement
            GimpleBase* gcur= (GimpleBase*) cur;
             if((gcur->defuse==NULL)&&( gcur->getOprand(0) != oFrame_symblinfo)){
                 cur = (GimpleNode*)cur->getNext();
                 deleteGimpleNode(gcur);
                 continue;
             }
        }
        cur =  (GimpleNode*)cur->getNext();
    }


}
