#include "vacg.h"
#include "parserdriver.h"


static const int zero      = 0;
static const int cur_frame = CUR_FRAME;
static const int prv_frame = PRV_FRAME;
const int int_size = 4;// the least size of arg.
vaCG gvacg;
char* gVideoIn = NULL;
char* gVideoOut = NULL;
int gArgc = 1;
char** gArgv= NULL;

void vaCG::call_general(u8*& f, VaVarRef func, VaVarRef src2, VaVarRef src3,VaVarRef src4,VaVarRef src5)
{
	src5.push_arg(f);
	src4.push_arg(f);
	src3.push_arg(f);
	src2.push_arg(f);
	func.call(f);
	code_addespimm(f, 4*int_size);
	//code_ret(f);
}

void* vaCG::test_ccg()
{
	/** get the EIP
	offset | bytes (in hex) | mnemonics  
	03     | E8 00000000    | call next instruction  
	08     | 58             | pop  EAX  
	09     | 83C0 0D        | add  EAX, 0D  
	*/
 	u8* f0 = (u8*)vacgmalloc(64);
	f = f0;
 	

	/** cvSub(pFrames[Cur], pFrames[Prv], oFrame);
	* oFrame = Frame - Frame[-1];
	WRITE_2CHAR(f,	 0x6A, 0x00                    );          //00181C2D 6A 00               push        0    
	WRITE_1CHAR(f,	 0xA1) WRITE_1INT(f, &oFrame );            //00181C2F A1 1C E5 20 00      mov         eax,dword ptr [oFrame (20E51Ch)] 
	WRITE_1CHAR(f,	 0x50                        );            //00181C34 50                  push        eax  
	WRITE_2CHAR(f,	 0x8B, 0x0D) WRITE_1INT(f, &Prv);          //00181C35 8B 0D 20 E5 20 00   mov         ecx,dword ptr [Prv (20E520h)] 
	WRITE_3CHAR(f,	 0x8B, 0x14, 0x8D) WRITE_1INT(f, &pFrames);//00181C3B 8B 14 8D F0 E4 20 00mov         edx,dword ptr pFrames (20E4F0h)[ecx*4] 
	WRITE_1CHAR(f,	 0x52                        );            //00181C42 52                  push        edx  
	WRITE_1CHAR(f,	 0xA1) WRITE_1INT(f, &Cur);                //00181C43 A1 30 E0 18 00      mov         eax,dword ptr [Cur (18E030h)] 
	WRITE_3CHAR(f,	 0x8B, 0x0C, 0x85) WRITE_1INT(f, &pFrames);//00181C48 8B 0C 85 F0 E4 20 00mov         ecx,dword ptr pFrames (20E4F0h)[eax*4] 
	WRITE_1CHAR(f,	 0x51                        );            //00181C4F 51                  push        ecx  
	WRITE_1CHAR(f,	 0xB8) WRITE_1INT(f, cvSub  );             //mov eax, cvSubWrapper //00181C50 E8 91 F4 FF FF      call        @ILT+225(_cvSub) (1810E6h) 
	WRITE_2CHAR(f,   0xFF, 0xD0);                              // call eax;
	WRITE_3CHAR(f,	 0x83, 0xC4, 0x10             );           //00181C55 83 C4 10            add         esp,10h 
	WRITE_1CHAR(f,	 0xc3);//ret
	
	code_pushimm32(f, 0x00);
	code_pushVarible(f, (void*&)oFrame);
	code_pushPrvFrame(f);
	code_pushCurFrame(f);
	code_call(f, cvSub);
 	code_addespimm(f, 0x10);
	code_ret(f);
	*/

	//call_general(asig,(PVOID)&cvSub, (PVOID&)cur_frame,(PVOID&)prv_frame, (PVOID&)oFrame,(PVOID&)zero);
#if 1
	call_general(VaVar(atIMM, (pfunc)cvSub),
		VaVar(atFRAME, (size_t)0), 
		VaVar(atFRAME,-1), 
		VaVar(atREF,oFrame), 
		VaVar(atIMM,  (size_t)0));
#endif
	return (void*)f0;
}

void vaCG::sub_frame(u8*& f, VaVarRef dst, VaVarRef src1, VaVarRef src2)
{
	call_general(f,
            VaVar(atIMM, (pfunc)cvSub),
            src1, 
            src2,
            dst,
		VaVar(atIMM,  (size_t)0));
}

void vaCG::copy_frame(u8*& f, VaVarRef dst, VaVarRef src1)
{
    VaVar(atIMM, (pfunc)CopyFrame).push_arg(f);
	src1.push_arg(f);
	dst.push_arg(f);
	VaVar(atFUNC, (pfunc)Detect).call(f);
	code_addespimm(f, 3*int_size);
    debprintf("call_copy code\n");
}



void vaCG::call_Detect(u8*& f, VaVarRef dst, VaVarRef src1, VaVarRef oper)
{
	oper.push_arg(f);
	src1.push_arg(f);
	dst.push_arg(f);
	//! Be careful, the runtime function pointer can not be passed as ref
	//VaVar(atIMM, (void*&)Detect).call(f);
	VaVar(atFUNC, (pfunc)Detect).call(f);
	code_addespimm(f, 3*int_size);

    debprintf("call_Detect code\n");
}

void* vaCG::test_ccg2()
{
	u8* f0 = (u8*)vacgmalloc(64);
	f = f0;

	/** Detect(wrt, cur, Robert)
	*   oFrame = Frame * Robert
    *@code
	*code_pushimm32(f, (i32)Robert);
	*code_pushCurFrame(f);
	*code_pushVarible(f, (void*&)oFrame);
	*code_call(f, Detect);
	*code_addespimm(f, 0x0c);
	*code_ret(f);
	*/
	//call_Detect(asig,(PVOID&)oFrame,(PVOID&)cur_frame, (PVOID)&Robert);
	call_Detect(VaVar(atREF, oFrame),
		VaVar(atFRAME, (size_t)0),
		VaVar(atFUNC, (pfunc)Robert));
	return (void*)f0;
}

static char* script1 = "oframe = frame - frame[-1]";
static char* script2 = "oframe = frame * sobel";
void* compile_str(char* dmvascript )
{ 
	static char* default_str2= "tframe=frame*sobel ;oframe=tframe; ";
    if(dmvascript == NULL)
        dmvascript =  default_str2;
        
	vasParserDriver myparser;
  
    myparser.parse(dmvascript );
     
    gvacg.init();
	programGraph->optimize();
    
	programGraph->codeGen();

	gvacg.dumpCode();
	return (gvacg.getf0());
 
	//return gvacg.test_ccg();
}

void* compile_file(char* dmvascript )
{ 
    if(dmvascript == NULL)
        return compile_str();
        
	vasParserDriver myparser;
  
    myparser.parsefile(dmvascript );
     
    gvacg.init();
	programGraph->optimize();
    
	programGraph->codeGen();
    fprintf(stdout, "Dump Gimple>\n");
	programGraph->dumpGimple(stdout);
    fprintf(stdout, "Dump Gimple End>\n");

	
	return (gvacg.getf0());
 
	//return gvacg.test_ccg();
}
