/*
 * =====================================================================================
 *
 *       Filename:  node.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/22/2011 03:39:23 PM
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
#include "gimple.hxx"

FlowGraph* rootRegion=NULL;
FlowGraph* curRegion=NULL;
FunctionList* functionList=NULL;


void initParser()
{
    rootRegion = new FlowGraph();
    curRegion = rootRegion;
	extern FlowGraph* programGraph;
	programGraph=rootRegion;
    SymbolInfo* tmpSmbl;
    //! predefined FRAME
    tmpSmbl = rootRegion->newSymbol( "oFrame", atREF, oFrame); // 0 oFrame
    tmpSmbl = rootRegion->newSymbol( "frame[-1]", atFRAME, -1);
    tmpSmbl = rootRegion->newSymbol( "frame", atFRAME, 0);
    tmpSmbl = rootRegion->newSymbol( "frame[1]", atFRAME, 1);
    tmpSmbl = rootRegion->newSymbol("sobel",    atIMM,(size_t) Sobel   );   
    tmpSmbl = rootRegion->newSymbol("robert",   atIMM,(size_t) Robert  );  
    tmpSmbl = rootRegion->newSymbol("prewitt",  atIMM,(size_t) Prewitt );
    tmpSmbl = rootRegion->newSymbol("laplas",   atIMM,(size_t) LapLas  );
    tmpSmbl = rootRegion->newSymbol("freiChen", atIMM,(size_t) FreiChen);

    functionList = new FunctionList();
}

AstOpExpr::AstOpExpr(OpCode opc, AstExpression* oprand1, AstExpression* oprand2):
    opcode(opc), oprand1(oprand1), oprand2(oprand2){
        oprand0 = new AstVarExpr(curRegion->newtmpSymbol());
        VASMSG(log_create,"create AstExpression\n");
    }

GimpleNode* AstOpExpr::gimplify(FlowGraph* thisGraph){
    if(oprand1) oprand1->gimplify(thisGraph);
    if(oprand2) oprand2->gimplify(thisGraph);
    GimpleStatement* gimpleStmt = new GimpleStatement(opcode, oprand0->getSymbol(), oprand1->getSymbol(),oprand2->getSymbol());
    thisGraph->appandGimpleNode(gimpleStmt);
    return gimpleStmt;
}

GimpleNode* AstAssginState::gimplify(FlowGraph* thisGraph){
	//!Current Node
		if(rhv)
			rhv->gimplify(thisGraph);
        SymbolInfo lSymbol;
		if(lhv)
            lSymbol = lhv->getSymbol();
		else 
			lSymbol = lhVaVar;
		//!

    GimpleStatement* gimpleStmt = new GimpleAssign(lSymbol, rhv->getSymbol());
    thisGraph->appandGimpleNode(gimpleStmt);
    return gimpleStmt;
}


GimpleNode* AstFilterState::gimplify(FlowGraph* thisGraph){
    GimpleStatement* gimpleStmt = new GimpleStatement(OpCode('*'),outFrame, inFrame, filterKernel );
    thisGraph->appandGimpleNode(gimpleStmt);
    return gimpleStmt;
}


void GimpleGraphNode::codeGento(u8*& f) 
{ 
    m_Graph->codeGento(f);
};

void GimpleGraphNode:: dumpGimple(FILE* fp)const 
{ 
    m_Graph->dumpGimple(fp);
};
