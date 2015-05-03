%name vasParser
%define LSP_NEEDED
%define ERROR_BODY = 0
%define LEX_BODY = 0

%header{
#include <iostream>
#include <fstream>
#define DZHDEB
#include "debprintf.h"
#include "vacg.h"
#include "node.hxx"
int yylex();
void yyerror(char*);
extern FlowGraph* programGraph;
#define YYPRINT() printf("Line:%d\n", __LINE__); 
%}
%union{
AstNode* node;
FlowGraph* graph;
Function*  function;
AstExpression* expr;
AstConstExpr* constExpr;
AstStatement* stmt;
int ival;
double dval;
float fval;
char* name;
}

%token <name> TK_IDENTIFIER%token <ival> TK_CONSTANT%token <name> TK_STRING_LITERAL%token TK_SIZEOF%token TK_PTR_OP%token TK_INC_OP%token TK_DEC_OP%token TK_LEFT_OP%token TK_RIGHT_OP%token TK_LE_OP%token TK_GE_OP%token TK_EQ_OP%token TK_NE_OP%token TK_AND_OP%token TK_OR_OP%token TK_MUL_ASSIGN%token TK_DIV_ASSIGN%token TK_MOD_ASSIGN%token TK_ADD_ASSIGN%token TK_SUB_ASSIGN%token TK_LEFT_ASSIGN%token TK_RIGHT_ASSIGN%token TK_AND_ASSIGN%token TK_XOR_ASSIGN%token TK_OR_ASSIGN%token TK_TYPE_NAME%token TK_TYPEDEF%token TK_EXTERN%token TK_STATIC%token TK_AUTO%token TK_REGISTER%token TK_CHAR%token TK_SHORT%token TK_INT%token TK_LONG%token TK_SIGNED%token TK_UNSIGNED%token TK_FLOAT%token TK_DOUBLE%token TK_CONST%token TK_VOLATILE%token TK_VOID%token TK_STRUCT%token TK_UNION%token TK_ENUM%token TK_ELIPSIS%token TK_RANGE%token TK_CASE%token TK_DEFAULT%token TK_IF%token TK_ELSE%token TK_SWITCH%token TK_WHILE%token TK_DO%token TK_FOR%token TK_GOTO%token TK_CONTINUE%token TK_BREAK%token TK_RETURN%token TK_ELLIPSIS%token TK_FRAME%token TK_OFRAME%token TK_SOBEL%token TK_ROBERT%token TK_PREWITT%token TK_LAPlAS%token TK_FREICHEN%token TK_INFILE%token TK_OUTFILE%token TK_DOLLAR%token TK_STDOUT

%left '-' '+'
%left '*' '/'
%nonassoc TK_UMINUS

%type <expr> expression filterkernel frame edge_operator argument_expression_list assignment_expression
%type <ival> constantexpression
%type <graph> program statement_list brace_statement0 brace_statement
%type <stmt> statement if_statement
%type <ival> type_specifier function_declarator parameter_list
%type <function> function_definition0 function_definition 
%%
program : statement_list 				{  /*programGraph = $1;*/}
        ;

brace_statement0 : '{' 					{ $$ = new FlowGraph();  $$->simplePush(); }
                 | brace_statement0 statement  		{ $$=$1; if($2) $1->appandNode($2);}
;

brace_statement: brace_statement0 '}'           	{ $1->pop();$$=$1; printf("Get a brace \n");}
;


statement_list:	statement 				{ /* $$= new FlowGraph();*/ $$=curRegion; if($1) $$->appandNode($1); }
	|	statement_list statement  		{  $$=$1; if($2 != NULL) $1->appandNode($2);}
;

statement:	expression '=' expression  ';'       	{  $$= new AstAssginState($1,$3);}
    |   TK_OFRAME '=' expression       ';'           	{  $$= new AstAssginState(oFrame_symblinfo ,$3); debprintf("oframe= expression \n");} 
    |   TK_OFRAME '=' TK_FRAME '*' edge_operator ';' 	{  $$= new AstFilterState(oFrame_symblinfo , curFrame_symblinfo ,((AstVarExpr*)$5)->var ); debprintf("Oframe=frame*sobel detect(oframe, frame, sobel); \n"); 
    delete $5;
    } 
    | ';' 						{  $$ = NULL;}
    | brace_statement 					{  $$= new AstGraphNode($1);}
    | if_statement    					{  $$= $1;}
    | function_definition 				{  $$= NULL; /*$$ = new AstGraphNode($1);*/ }
    | TK_IDENTIFIER '(' ')'           {  $$ = 0; 
    printf("func:%s\n", $1);
                                        Function* f = functionList->getFunction( $1 ); 
                                        if(f !=NULL) $$ = new AstGraphNode(f);   
                                        printf("get a call\n");}
    | TK_IDENTIFIER '(' argument_expression_list ')'  { $$ = 0; printf("get a call\n");}
    | TK_INFILE '=' TK_DOLLAR TK_CONSTANT ';' { $$ = 0; if($4 < gArgc - 1)gVideoIn = strdup(gArgv[$4+1]);}
    | TK_INFILE '=' TK_STRING_LITERAL     ';'  { $$ = 0; gVideoIn = $3;}
    | TK_OUTFILE '=' TK_DOLLAR TK_CONSTANT';' { $$ = 0; if($4 < gArgc - 1)gVideoOut = strdup(gArgv[$4+1]);}
    | TK_OUTFILE '=' TK_STRING_LITERAL    ';'  { $$ = 0; gVideoOut = $3;}
    | TK_OUTFILE '=' TK_STDOUT            ';'  { $$ = 0; gVideoOut = strdup("stdout");}
;

expression:	expression '+' expression   {  $$= new AstOpExpr(OpCode('+'),$1,$3);debprintf("e+e\n");  }
    |	expression '-' expression       { $$= new AstOpExpr(OpCode('-'),$1,$3); }
    |	expression '*' expression       { $$= new AstOpExpr(OpCode('*'),$1,$3);}
    |	expression '/' expression    	{ $$= new AstOpExpr(OpCode('/'),$1,$3);}
    |	'-' expression %prec TK_UMINUS  { }
    |	'(' expression ')'		        { $$=$2 }
    |   constantexpression              { printf("ConstExpr\n");$$= new AstConstExpr($1); } //{ $$=$1;}
//    |	TK_CONSTANT                     { $$= new AstConstExpr($1); }
    |	TK_IDENTIFIER                   { SymbolInfo* var = curRegion-> getornewSymbolInfo($1); $$= new AstVarExpr(*var);}
    |   filterkernel                    { }
    |   frame                           { $$=$1 }  
    |   edge_operator                   { }    
;

filterkernel: 
            TK_FREICHEN                  {  $$=new AstVarExpr(FreiChen_symblinfo);debprintf("[%p]",FreiChen);}
;

frame:
       TK_FRAME                           {  $$=new AstVarExpr(curFrame_symblinfo );debprintf("frame[%d]",0);}
    |   TK_FRAME '[' '0' ']'              {  $$=new AstVarExpr(curFrame_symblinfo );debprintf("frame[%d]",0);}
    |   TK_FRAME '[' TK_CONSTANT ']'      {  $$=new AstVarExpr(nxtFrame_symblinfo );debprintf("frame[%d]",$3); }
    |   TK_FRAME '[' '-' TK_CONSTANT ']'  {  $$=new AstVarExpr(preFrame_symblinfo );debprintf("frame[%d]",$4); }
;

edge_operator: TK_SOBEL                     {  $$=new AstVarExpr(Sobel_symblinfo   );debprintf("[%p]",Sobel);}
             | TK_ROBERT                    {  $$=new AstVarExpr(Robert_symblinfo  );debprintf("[%p]",Robert);}  
             | TK_PREWITT                   {  $$=new AstVarExpr(Prewitt_symblinfo );debprintf("[%p]",Prewitt );}
             | TK_LAPlAS                    {  $$=new AstVarExpr(LapLas_symblinfo  );debprintf("[%p]",LapLas  );}
;

constantexpression:
    	TK_CONSTANT                     { $$= $1; }
    |   constantexpression '+' constantexpression           {  printf("%d + %d = %d\n", $1, $3, $1+$3);$$ = ($1 + $3); }
    |	constantexpression '-' constantexpression           {  $$ = ($1 - $3); }
    |	constantexpression '*' constantexpression           {  $$ = ($1 * $3); }
    |	constantexpression '/' constantexpression{	if($3 == 0.0)
                        yyerror("divide by zero");
                    else
                        $$ = ($1 / $3);
                }
;

if_statement:
            TK_IF '(' expression ')' statement               { $$= new AstIfNode($3, $5); printf("if()state;\n");}
        |   TK_IF '(' expression ')' statement TK_ELSE statement {  $$= new AstIfNode($3, $5, $7);printf("if()else;\n");}
;

type_specifier: TK_VOID {  $$ = 0; printf("VOID GET\n");}
	| TK_INT        {  $$ = 0;printf("INT GET\n");}
;

parameter_list: type_specifier TK_IDENTIFIER {}
	|       parameter_list ',' type_specifier TK_IDENTIFIER {}
;

function_declarator: type_specifier TK_IDENTIFIER '(' ')' {  $$ = 0; printf("Get a function declaretor");}
	|            type_specifier TK_IDENTIFIER '(' parameter_list ')' {$$ = 0; printf("Get a function declaretor2");}
; 

function_definition0
        : function_declarator  '{'             { $$ = new Function("abc");  $$->simplePush();  printf("find out a function\n");}
	| function_definition0 statement       { $$=$1;if($2) $1->appandNode($2);}
;

function_definition: function_definition0 '}' {  $1->pop(); $$ = $1; printf("finish out a function\n"); functionList->addFunction($1);}


argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

assignment_expression:expression
;

%%
FlowGraph* programGraph=rootRegion;
void yyerror(char* s)
{

}
