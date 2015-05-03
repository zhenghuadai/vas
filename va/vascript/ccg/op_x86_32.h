#ifndef __OP_x86_32__header__
#define __OP_x86_32__header__
#define  decOPinfoList32 \
decOP( AAA       , AL          , AH          ,        , ,      ,     ,     , 0x37,     , , , , , , , oooooaoo, oooszapc, oooooaoc, oooszopo, , "ASCII Adjust After Addition") \
decOP( AAD       , AL          , AH          ,        , ,      ,     ,     , 0xD5, 0x0A, , , , , , , , oooszapc, oooszopo, oooooaoc, , "ASCII Adjust AX Before Division") \
decOP( AAM       , AL          , AH          ,        , ,      ,     ,     , 0xD4, 0x0A, , , , , , , , oooszapc, oooszopo, oooooaoc, , "ASCII Adjust AX After Multiply") \
decOP( AAS       , AL          , AH          ,        , ,      ,     ,     , 0x3F,     , , , , , , , oooooaoo, oooszapc, oooooaoc, oooszopo, , "ASCII Adjust AL After Subtraction") \
decOP( ADC       , rm8         , r8          ,        , ,      ,     ,     , 0x10,     , r, , , , , L, oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADC       , rmWD        , rWD         ,        , ,      ,     ,     , 0x11,     , r, , , , , L, oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADC       , r8          , rm8         ,        , ,      ,     ,     , 0x12,     , r, , , , , , oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADC       , rWD         , rmWD        ,        , ,      ,     ,     , 0x13,     , r, , , , , , oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADC       , AL          , imm8        ,        , ,      ,     ,     , 0x14,     , , , , , , , oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADC       , eAX         , immWD       ,        , ,      ,     ,     , 0x15,     , , , , , , , oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADC       , rm8         , imm8        ,        , ,      ,     ,     , 0x80,     , 2, , , , , L, oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADC       , rmWD        , immWD       ,        , ,      ,     ,     , 0x81,     , 2, , , , , L, oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADC       , rm8         , imm8        ,        , ,      ,     ,     , 0x82,     , 2, , , , , L, oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADC       , rmWD        , imm8        ,        , ,      ,     ,     , 0x83,     , 2, , , , , L, oooooooc, oooszapc, oooszapc, , , "Add with Carry") \
decOP( ADD       , rm8         , r8          ,        , ,      ,     ,     , 0x00,     , r, , , , , L, , oooszapc, oooszapc, , , "Add") \
decOP( ADD       , rmWD        , rWD         ,        , ,      ,     ,     , 0x01,     , r, , , , , L, , oooszapc, oooszapc, , , "Add") \
decOP( ADD       , r8          , rm8         ,        , ,      ,     ,     , 0x02,     , r, , , , , , , oooszapc, oooszapc, , , "Add") \
decOP( ADD       , rWD         , rmWD        ,        , ,      ,     ,     , 0x03,     , r, , , , , , , oooszapc, oooszapc, , , "Add") \
decOP( ADD       , AL          , imm8        ,        , ,      ,     ,     , 0x04,     , , , , , , , , oooszapc, oooszapc, , , "Add") \
decOP( ADD       , eAX         , immWD       ,        , ,      ,     ,     , 0x05,     , , , , , , , , oooszapc, oooszapc, , , "Add") \
decOP( ADD       , rm8         , imm8        ,        , ,      ,     ,     , 0x80,     , 0, , , , , L, , oooszapc, oooszapc, , , "Add") \
decOP( ADD       , rmWD        , immWD       ,        , ,      ,     ,     , 0x81,     , 0, , , , , L, , oooszapc, oooszapc, , , "Add") \
decOP( ADD       , rm8         , imm8        ,        , ,      ,     ,     , 0x82,     , 0, , , , , L, , oooszapc, oooszapc, , , "Add") \
decOP( ADD       , rmWD        , imm8        ,        , ,      ,     ,     , 0x83,     , 0, , , , , L, , oooszapc, oooszapc, , , "Add") \
decOP( ADDPD     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x58,     , r, P4+, , , , , , , , , , "Add Packed Double-FP Values") \
decOP( ADDPS     , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x58,     , r, P3+, , , , , , , , , , "Add Packed Single-FP Values") \
decOP( ADDSD     , xmm         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x58,     , r, P4+, , , , , , , , , , "Add Scalar Double-FP Values") \
decOP( ADDSS     , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x58,     , r, P3+, , , , , , , , , , "Add Scalar Single-FP Values") \
decOP( ADDSUBPD  , xmm         , Xm128       ,        , , sse3 , 0x66, 0x0F, 0xD0,     , r, P4++, , , , , , , , , , "Packed Double-FP AddoSubtract") \
decOP( ADDSUBPS  , xmm         , Xm128       ,        , , sse3 , 0xF2, 0x0F, 0xD0,     , r, P4++, , , , , , , , , , "Packed Single-FP AddoSubtract") \
decOP( ADX       , AL          , AH          , imm8   , ,      ,     ,     , 0xD5,     , , , , , , , , oooszapc, oooszopo, oooooaoc, , "Adjust AX Before Division") \
decOP( ALTER     ,             ,             ,        , ,      , 0x64,     ,     ,     , , P4+, U1, , , , , , , , , "Alternating branch prefix (used only with Jcc instructions)") \
decOP( AMX       , AL          , AH          , imm8   , ,      ,     ,     , 0xD4,     , , , , , , , , oooszapc, oooszopo, oooooaoc, , "Adjust AX After Multiply") \
decOP( AND       , rm8         , r8          ,        , ,      ,     ,     , 0x20,     , r, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( AND       , rmWD        , rWD         ,        , ,      ,     ,     , 0x21,     , r, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( AND       , r8          , rm8         ,        , ,      ,     ,     , 0x22,     , r, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( AND       , rWD         , rmWD        ,        , ,      ,     ,     , 0x23,     , r, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( AND       , AL          , imm8        ,        , ,      ,     ,     , 0x24,     , , , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( AND       , eAX         , immWD       ,        , ,      ,     ,     , 0x25,     , , , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( AND       , rm8         , imm8        ,        , ,      ,     ,     , 0x80,     , 4, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( AND       , rmWD        , immWD       ,        , ,      ,     ,     , 0x81,     , 4, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( AND       , rm8         , imm8        ,        , ,      ,     ,     , 0x82,     , 4, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( AND       , rmWD        , imm8        ,        , ,      ,     ,     , 0x83,     , 4, 03+, , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical AND") \
decOP( ANDNPD    , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x55,     , r, P4+, , , , , , , , , , "Bitwise Logical AND NOT of Packed Double-FP Values") \
decOP( ANDNPS    , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x55,     , r, P3+, , , , , , , , , , "Bitwise Logical AND NOT of Packed Single-FP Values") \
decOP( ANDPD     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x54,     , r, P4+, , , , , , , , , , "Bitwise Logical AND of Packed Double-FP Values") \
decOP( ANDPS     , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x54,     , r, P3+, , , , , , , , , , "Bitwise Logical AND of Packed Single-FP Values") \
decOP( ARPL      , rm16        , r16         ,        , ,      ,     ,     , 0x63,     , r, 02+, , , , , , oooozooo, oooozooo, , , "Adjust RPL Field of Segment Selector") \
decOP( BOUND     , rWD         , mWD         , eFlags , ,      ,     ,     , 0x62,     , r, 01+, , , f, , , ooiooooo, ooiooooo, , ooiooooo, "Check Array Index Against Bounds") \
decOP( BSF       , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0xBC,     , , 03+, , , , , , oooszapc, oooozooo, ooosoapc, , "Bit Scan Forward") \
decOP( BSR       , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0xBD,     , , 03+, , , , , , oooszapc, oooozooo, ooosoapc, , "Bit Scan Reverse") \
decOP( BSWAP     , rWD         ,             ,        , ,      ,     , 0x0F, 0xC8,     , s, 04+, , , , , , , , , , "Byte Swap") \
decOP( BT        , rmWD        , rWD         ,        , ,      ,     , 0x0F, 0xA3,     , , 03+, , , , , , oooszapc, oooooooc, oooszapo, , "Bit Test") \
decOP( BT        , rmWD        , imm8        ,        , ,      ,     , 0x0F, 0xBA,     , 4, 03+, , , , , , oooszapc, oooooooc, oooszapo, , "Bit Test") \
decOP( BTC       , rmWD        , imm8        ,        , ,      ,     , 0x0F, 0xBA,     , 7, 03+, , , , L, , oooszapc, oooooooc, oooszapo, , "Bit Test and Complement") \
decOP( BTC       , rmWD        , rWD         ,        , ,      ,     , 0x0F, 0xBB,     , , 03+, , , , L, , oooszapc, oooooooc, oooszapo, , "Bit Test and Complement") \
decOP( BTR       , rmWD        , rWD         ,        , ,      ,     , 0x0F, 0xB3,     , , 03+, , , , L, , oooszapc, oooooooc, oooszapo, , "Bit Test and Reset") \
decOP( BTR       , rmWD        , imm8        ,        , ,      ,     , 0x0F, 0xBA,     , 6, 03+, , , , L, , oooszapc, oooooooc, oooszapo, , "Bit Test and Reset") \
decOP( BTS       , rmWD        , rWD         ,        , ,      ,     , 0x0F, 0xAB,     , , 03+, , , , L, , oooszapc, oooooooc, oooszapo, , "Bit Test and Set") \
decOP( BTS       , rmWD        , imm8        ,        , ,      ,     , 0x0F, 0xBA,     , 5, 03+, , , , L, , oooszapc, oooooooc, oooszapo, , "Bit Test and Set") \
decOP( CALL      , relWD       ,             ,        , ,      ,     ,     , 0xE8,     , , , , , , , , , , , , "Call Procedure") \
decOP( CALL      , rmWD        ,             ,        , ,      ,     ,     , 0xFF,     , 2, , , , , , , , , , , "Call Procedure") \
decOP( CALLF     , ptr16OWD    ,             ,        , ,      ,     ,     , 0x9A,     , , , , , , , , , , , , "Call Procedure") \
decOP( CALLF     , m16OWD      ,             ,        , ,      ,     ,     , 0xFF,     , 3, , , , , , , , , , , "Call Procedure") \
decOP( CBW       , AH          , AL          ,        , ,      ,     ,     , 0x98,     , , , , , , , , , , , , "Convert Byte to Word") \
decOP( CDQ       , EDX         , EAX         ,        , ,      ,     ,     , 0x99,     , , 03+, , , , , , , , , , "Convert Doubleword to Quadword") \
decOP( CLC       ,             ,             ,        , ,      ,     ,     , 0xF8,     , , , , , , , , oooooooc, oooooooc, , oooooooc, "Clear Carry Flag") \
decOP( CLD       ,             ,             ,        , ,      ,     ,     , 0xFC,     , , , , , , , , odoooooo, odoooooo, , odoooooo, "Clear Direction Flag") \
decOP( CLFLUSH   , m8          ,             ,        , , sse2 ,     , 0x0F, 0xAE,     , 7, P4+, , , , , , , , , , "Flush Cache Line") \
decOP( CLI       ,             ,             ,        , ,      ,     ,     , 0xFA,     , , , , , f1, , , ooiooooo, ooiooooo, , ooiooooo, "Clear Interrupt Flag") \
decOP( CLTS      , CR0         ,             ,        , ,      ,     , 0x0F, 0x06,     , , 02+, , , 0, , , , , , , "Clear Task-Switched Flag in CR0") \
decOP( CMC       ,             ,             ,        , ,      ,     ,     , 0xF5,     , , , , , , , oooooooc, oooooooc, oooooooc, , , "Complement Carry Flag") \
decOP( CMOVB     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x42,     , r, PP+, , , , , oooooooc, , , , , "Conditional Move - belowonot above or equalocarry (CF=1)") \
decOP( CMOVNAE   , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x42,     , r, PP+, , , , , oooooooc, , , , , "Conditional Move - belowonot above or equalocarry (CF=1)") \
decOP( CMOVC     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x42,     , r, PP+, , , , , oooooooc, , , , , "Conditional Move - belowonot above or equalocarry (CF=1)") \
decOP( CMOVBE    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x46,     , r, PP+, , , , , oooozooc, , , , , "Conditional Move - below or equalonot above (CF=1 AND ZF=1)") \
decOP( CMOVNA    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x46,     , r, PP+, , , , , oooozooc, , , , , "Conditional Move - below or equalonot above (CF=1 AND ZF=1)") \
decOP( CMOVL     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4C,     , r, PP+, , , , , ooosoooo, , , , , "Conditional Move - lessonot greater (SF!=OF)") \
decOP( CMOVNGE   , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4C,     , r, PP+, , , , , ooosoooo, , , , , "Conditional Move - lessonot greater (SF!=OF)") \
decOP( CMOVLE    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4E,     , r, PP+, , , , , oooszooo, , , , , "Conditional Move - less or equalonot greater ((ZF=1) OR (SF!=OF))") \
decOP( CMOVNG    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4E,     , r, PP+, , , , , oooszooo, , , , , "Conditional Move - less or equalonot greater ((ZF=1) OR (SF!=OF))") \
decOP( CMOVNB    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x43,     , r, PP+, , , , , oooooooc, , , , , "Conditional Move - not belowoabove or equalonot carry (CF=0)") \
decOP( CMOVAE    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x43,     , r, PP+, , , , , oooooooc, , , , , "Conditional Move - not belowoabove or equalonot carry (CF=0)") \
decOP( CMOVNC    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x43,     , r, PP+, , , , , oooooooc, , , , , "Conditional Move - not belowoabove or equalonot carry (CF=0)") \
decOP( CMOVNBE   , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x47,     , r, PP+, , , , , oooozooc, , , , , "Conditional Move - not below or equaloabove (CF=0 AND ZF=0)") \
decOP( CMOVA     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x47,     , r, PP+, , , , , oooozooc, , , , , "Conditional Move - not below or equaloabove (CF=0 AND ZF=0)") \
decOP( CMOVNL    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4D,     , r, PP+, , , , , ooosoooo, , , , , "Conditional Move - not lessogreater or equal (SF=OF)") \
decOP( CMOVGE    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4D,     , r, PP+, , , , , ooosoooo, , , , , "Conditional Move - not lessogreater or equal (SF=OF)") \
decOP( CMOVNLE   , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4F,     , r, PP+, , , , , oooszooo, , , , , "Conditional Move - not less nor equalogreater ((ZF=0) AND (SF=OF))") \
decOP( CMOVG     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4F,     , r, PP+, , , , , oooszooo, , , , , "Conditional Move - not less nor equalogreater ((ZF=0) AND (SF=OF))") \
decOP( CMOVNO    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x41,     , r, PP+, , , , , oooooooo, , , , , "Conditional Move - not overflow (OF=0)") \
decOP( CMOVNP    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4B,     , r, PP+, , , , , oooooopo, , , , , "Conditional Move - not parityoparity odd") \
decOP( CMOVPO    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4B,     , r, PP+, , , , , oooooopo, , , , , "Conditional Move - not parityoparity odd") \
decOP( CMOVNS    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x49,     , r, PP+, , , , , ooosoooo, , , , , "Conditional Move - not sign (SF=0)") \
decOP( CMOVNZ    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x45,     , r, PP+, , , , , oooozooo, , , , , "Conditional Move - not zeroonot equal (ZF=1)") \
decOP( CMOVNE    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x45,     , r, PP+, , , , , oooozooo, , , , , "Conditional Move - not zeroonot equal (ZF=1)") \
decOP( CMOVO     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x40,     , r, PP+, , , , , oooooooo, , , , , "Conditional Move - overflow (OF=1)") \
decOP( CMOVP     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4A,     , r, PP+, , , , , oooooopo, , , , , "Conditional Move - parityoparity even (PF=1)") \
decOP( CMOVPE    , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x4A,     , r, PP+, , , , , oooooopo, , , , , "Conditional Move - parityoparity even (PF=1)") \
decOP( CMOVS     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x48,     , r, PP+, , , , , ooosoooo, , , , , "Conditional Move - sign (SF=1)") \
decOP( CMOVZ     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x44,     , r, PP+, , , , , oooozooo, , , , , "Conditional Move - zerooequal (ZF=0)") \
decOP( CMOVE     , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0x44,     , r, PP+, , , , , oooozooo, , , , , "Conditional Move - zerooequal (ZF=0)") \
decOP( CMP       , rm8         , r8          ,        , ,      ,     ,     , 0x38,     , r, , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMP       , rmWD        , rWD         ,        , ,      ,     ,     , 0x39,     , r, , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMP       , r8          , rm8         ,        , ,      ,     ,     , 0x3A,     , r, , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMP       , rWD         , rmWD        ,        , ,      ,     ,     , 0x3B,     , r, , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMP       , AL          , imm8        ,        , ,      ,     ,     , 0x3C,     , , , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMP       , eAX         , immWD       ,        , ,      ,     ,     , 0x3D,     , , , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMP       , rm8         , imm8        ,        , ,      ,     ,     , 0x80,     , 7, , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMP       , rmWD        , immWD       ,        , ,      ,     ,     , 0x81,     , 7, , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMP       , rm8         , imm8        ,        , ,      ,     ,     , 0x82,     , 7, , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMP       , rmWD        , imm8        ,        , ,      ,     ,     , 0x83,     , 7, , , , , , , oooszapc, oooszapc, , , "Compare Two Operands") \
decOP( CMPPD     , xmm         , Xm128       , imm8   , , sse2 , 0x66, 0x0F, 0xC2,     , r, P4+, , , , , , , , , , "Compare Packed Double-FP Values") \
decOP( CMPPS     , xmm         , Xm128       , imm8   , , sse1 ,     , 0x0F, 0xC2,     , r, P3+, , , , , , , , , , "Compare Packed Single-FP Values") \
decOP( CMPS      , m8          , m8          ,        , ,      ,     ,     , 0xA6,     , , , , , , , odoooooo, oooszapc, oooszapc, , , "Compare String Operands") \
decOP( CMPSB     , m8          , m8          ,        , ,      ,     ,     , 0xA6,     , , , , , , , odoooooo, oooszapc, oooszapc, , , "Compare String Operands") \
decOP( CMPS      , m16         , m16         ,        , ,      ,     ,     , 0xA7,     , , , , , , , odoooooo, oooszapc, oooszapc, , , "Compare String Operands") \
decOP( CMPSW     , m16         , m16         ,        , ,      ,     ,     , 0xA7,     , , , , , , , odoooooo, oooszapc, oooszapc, , , "Compare String Operands") \
decOP( CMPS      , mWD         , mWD         ,        , ,      ,     ,     , 0xA7,     , , 03+, , , , , odoooooo, oooszapc, oooszapc, , , "Compare String Operands") \
decOP( CMPSD     , m32         , m32         ,        , ,      ,     ,     , 0xA7,     , , 03+, , , , , odoooooo, oooszapc, oooszapc, , , "Compare String Operands") \
decOP( CMPSD     , xmm         , Xm64        , imm8   , , sse2 , 0xF2, 0x0F, 0xC2,     , r, P4+, , , , , , , , , , "Compare Scalar Double-FP Values") \
decOP( CMPSS     , xmm         , Xm32        , imm8   , , sse1 , 0xF3, 0x0F, 0xC2,     , r, P3+, , , , , , , , , , "Compare Scalar Single-FP Values") \
decOP( CMPXCHG   , rm8         , AL          , r8     , ,      ,     , 0x0F, 0xB0,     , r, 04+, , , , L, , oooszapc, oooszapc, , , "Compare and Exchange") \
decOP( CMPXCHG   , rmWD        , eAX         , rWD    , ,      ,     , 0x0F, 0xB1,     , r, 04+, , , , L, , oooszapc, oooszapc, , , "Compare and Exchange") \
decOP( CMPXCHG8B , m64         , EAX         , EDX    , ooo ,      ,     , 0x0F, 0xC7,     , 1, P1+, , , , L, , oooozooo, oooozooo, , , "Compare and Exchange Bytes") \
decOP( COMISD    , xmm         , Xm64        ,        , , sse2 , 0x66, 0x0F, 0x2F,     , r, P4+, , , , , , oooozopc, oooozopc, , , "Compare Scalar Ordered Double-FP Values and Set EFLAGS") \
decOP( COMISS    , xmm         , Xm32        ,        , , sse1 ,     , 0x0F, 0x2F,     , r, P3+, , , , , , oooozopc, oooozopc, , , "Compare Scalar Ordered Single-FP Values and Set EFLAGS") \
decOP( CPUID     , IA32_BIOooo , EAX         , ECX    , ooo ,      ,     , 0x0F, 0xA2,     , , 04++, , , , , , , , , , "CPU Identification") \
decOP( CS        , CS          ,             ,        , ,      , 0x2E,     ,     ,     , , , , , , , , , , , , "CS segment override prefix") \
decOP( CVTDQ2PD  , xmm         , Xm128       ,        , , sse2 , 0xF3, 0x0F, 0xE6,     , r, P4+, , , , , , , , , , "Convert Packed DW Integers to Packed Double-FP Values") \
decOP( CVTDQ2PS  , xmm         , Xm128       ,        , , sse2 ,     , 0x0F, 0x5B,     , r, P4+, , , , , , , , , , "Convert Packed DW Integers to Packed Single-FP Values") \
decOP( CVTPD2DQ  , xmm         , Xm128       ,        , , sse2 , 0xF2, 0x0F, 0xE6,     , r, P4+, , , , , , , , , , "Convert Packed Double-FP Values to Packed DW Integers") \
decOP( CVTPD2PI  , mm          , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x2D,     , r, P4+, , , , , , , , , , "Convert Packed Double-FP Values to Packed DW Integers") \
decOP( CVTPD2PS  , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x5A,     , r, P4+, , , , , , , , , , "Convert Packed Double-FP Values to Packed Single-FP Values") \
decOP( CVTPI2PD  , xmm         , Mm64        ,        , , sse2 , 0x66, 0x0F, 0x2A,     , r, P4+, , , , , , , , , , "Convert Packed DW Integers to Packed Double-FP Values") \
decOP( CVTPI2PS  , xmm         , Mm64        ,        , , sse1 ,     , 0x0F, 0x2A,     , r, P3+, , , , , , , , , , "Convert Packed DW Integers to Packed Single-FP Values") \
decOP( CVTPS2DQ  , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x5B,     , r, P4+, , , , , , , , , , "Convert Packed Single-FP Values to Packed DW Integers") \
decOP( CVTPS2PD  , xmm         , Xm128       ,        , , sse2 ,     , 0x0F, 0x5A,     , r, P4+, , , , , , , , , , "Convert Packed Single-FP Values to Packed Double-FP Values") \
decOP( CVTPS2PI  , mm          , Xm64        ,        , , sse1 ,     , 0x0F, 0x2D,     , r, P3+, , , , , , , , , , "Convert Packed Single-FP Values to Packed DW Integers") \
decOP( CVTSD2SI  , r32         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x2D,     , r, P4+, , , , , , , , , , "Convert Scalar Double-FP Value to DW Integer") \
decOP( CVTSD2SS  , xmm         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x5A,     , r, P4+, , , , , , , , , , "Convert Scalar Double-FP Value to Scalar Single-FP Value") \
decOP( CVTSI2SD  , xmm         , rm32        ,        , , sse2 , 0xF2, 0x0F, 0x2A,     , r, P4+, , , , , , , , , , "Convert DW Integer to Scalar Double-FP Value") \
decOP( CVTSI2SS  , xmm         , rm32        ,        , , sse1 , 0xF3, 0x0F, 0x2A,     , r, P3+, , , , , , , , , , "Convert DW Integer to Scalar Single-FP Value") \
decOP( CVTSS2SD  , xmm         , Xm32        ,        , , sse2 , 0xF3, 0x0F, 0x5A,     , r, P4+, , , , , , , , , , "Convert Scalar Single-FP Value to Scalar Double-FP Value ") \
decOP( CVTSS2SI  , r32         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x2D,     , r, P3+, , , , , , , , , , "Convert Scalar Single-FP Value to DW Integer") \
decOP( CVTTPD2DQ , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0xE6,     , r, P4+, , , , , , , , , , "Convert with Trunco Packed Double-FP Values to Packed DW Integers") \
decOP( CVTTPD2PI , mm          , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x2C,     , r, P4+, , , , , , , , , , "Convert with Trunco Packed Double-FP Values to Packed DW Integers") \
decOP( CVTTPS2DQ , xmm         , Xm128       ,        , , sse2 , 0xF3, 0x0F, 0x5B,     , r, P4+, , , , , , , , , , "Convert with Trunco Packed Single-FP Values to Packed DW Integers") \
decOP( CVTTPS2PI , mm          , Xm64        ,        , , sse1 ,     , 0x0F, 0x2C,     , r, P3+, , , , , , , , , , "Convert with Trunco Packed Single-FP Values to Packed DW Integers") \
decOP( CVTTSD2SI , r32         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x2C,     , r, P4+, , , , , , , , , , "Convert with Trunco Scalar Double-FP Value to Signed DW Integer") \
decOP( CVTTSS2SI , r32         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x2C,     , r, P3+, , , , , , , , , , "Convert with Trunco Scalar Single-FP Value to DW Integer") \
decOP( CWD       , DX          , AX          ,        , ,      ,     ,     , 0x99,     , , , , , , , , , , , , "Convert Word to Doubleword") \
decOP( CWDE      , EAX         , AX          ,        , ,      ,     ,     , 0x98,     , , 03+, , , , , , , , , , "Convert Word to Doubleword") \
decOP( DAA       , AL          ,             ,        , ,      ,     ,     , 0x27,     , , , , , , , oooooaoc, oooszapc, oooszapc, oooooooo, , "Decimal Adjust AL after Addition") \
decOP( DAS       , AL          ,             ,        , ,      ,     ,     , 0x2F,     , , , , , , , oooooaoc, oooszapc, oooszapc, oooooooo, , "Decimal Adjust AL after Subtraction") \
decOP( DEC       , rWD         ,             ,        , ,      ,     ,     , 0x48,     , s, , , , , , , oooszapo, oooszapo, , , "Decrement by 1") \
decOP( DEC       , rm8         ,             ,        , ,      ,     ,     , 0xFE,     , 1, , , , , , , oooszapo, oooszapo, , , "Decrement by 1") \
decOP( DEC       , rmWD        ,             ,        , ,      ,     ,     , 0xFF,     , 1, , , , , , , oooszapo, oooszapo, , , "Decrement by 1") \
decOP( DIV       , AL          , AH          , AX     , rm8,      ,     ,     , 0xF6,     , 6, , , , , , , oooszapc, , oooszapc, , "Unsigned Divide") \
decOP( DIV       , eDX         , eAX         , rmWD   , ,      ,     ,     , 0xF7,     , 6, , , , , , , oooszapc, , oooszapc, , "Unsigned Divide") \
decOP( DIVPD     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x5E,     , r, P4+, , , , , , , , , , "Divide Packed Double-FP Values") \
decOP( DIVPS     , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x5E,     , r, P3+, , , , , , , , , , "Divide Packed Single-FP Values") \
decOP( DIVSD     , xmm         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x5E,     , r, P4+, , , , , , , , , , "Divide Scalar Double-FP Values") \
decOP( DIVSS     , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x5E,     , r, P3+, , , , , , , , , , "Divide Scalar Single-FP Values") \
decOP( DS        , DS          ,             ,        , ,      , 0x3E,     ,     ,     , , , , , , , , , , , , "DS segment override prefix") \
decOP( EMMS      ,             ,             ,        , , mmx  ,     , 0x0F, 0x77,     , , PX+, , , , , , , , , , "Empty MMX Technology State") \
decOP( ENTER     , eBP         , i16         , imm8   , ,      ,     ,     , 0xC8,     , , 01+, , , , , , , , , , "Make Stack Frame for Procedure Parameters") \
decOP( ES        , ES          ,             ,        , ,      , 0x26,     ,     ,     , , , , , , , , , , , , "ES segment override prefix") \
decOP( F2XM1     , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xF0, 6, , , , , , , 0123, o1oo, 0o23, , "Compute 2 x-1") \
decOP( FABS      , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xE1, 4, , , , , , , 0123, o1oo, 0o23, , "Absolute Value") \
decOP( FADD      , ST          , m32f        ,        , ,      ,     ,     , 0xD8,     , 0, , , , , , , 0123, o1oo, 0o23, , "Add") \
decOP( FADD      , ST          , STi         ,        , ,      ,     ,     , 0xD8,     , 0, , , , , , , 0123, o1oo, 0o23, , "Add") \
decOP( FADD      , ST          , m64f        ,        , ,      ,     ,     , 0xDC,     , 0, , , , , , , 0123, o1oo, 0o23, , "Add") \
decOP( FADD      , STi         , ST          ,        , ,      ,     ,     , 0xDC,     , 0, , , , , , , 0123, o1oo, 0o23, , "Add") \
decOP( FADDP     , STi         , ST          ,        , ,      ,     ,     , 0xDE,     , 0, , , , , p, , 0123, o1oo, 0o23, , "Add and Pop") \
decOP( FADDP     , ST1         , ST          ,        , ,      ,     ,     , 0xDE, 0xC1, 0, , , , , p, , 0123, o1oo, 0o23, , "Add and Pop") \
decOP( FBLD      , ST          , m80dec      ,        , ,      ,     ,     , 0xDF,     , 4, , , , , s, , 0123, o1oo, 0o23, , "Load Binary Coded Decimal") \
decOP( FBSTP     , m80dec      , ST          ,        , ,      ,     ,     , 0xDF,     , 6, , , , , p, , 0123, o1oo, 0o23, , "Store BCD Integer and Pop") \
decOP( FCHS      , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xE0, 4, , , , , , , 0123, o1oo, 0o23, , "Change Sign") \
decOP( FCLEX     ,             ,             ,        , ,      , 0x9B,     , 0xDB, 0xE2, 4, , , , , , , 0123, , 0123, , "Clear Exceptions") \
decOP( FCMOVB    , ST          , STi         ,        , ,      ,     ,     , 0xDA,     , 0, PP+, , , , , oooooooc, 0123, o1oo, 0o23, , "Floating-Point Conditional Move - below (CF=1)") \
decOP( FCMOVBE   , ST          , STi         ,        , ,      ,     ,     , 0xDA,     , 2, PP+, , , , , oooozooo, 0123, o1oo, 0o23, , "Floating-Point Conditional Move - below or equal (CF=1 or ZF=1)") \
decOP( FCMOVE    , ST          , STi         ,        , ,      ,     ,     , 0xDA,     , 1, PP+, , , , , oooozooo, 0123, o1oo, 0o23, , "Floating-Point Conditional Move - equal (ZF=1)") \
decOP( FCMOVNB   , ST          , STi         ,        , ,      ,     ,     , 0xDB,     , 0, PP+, , , , , oooooooc, 0123, o1oo, 0o23, , "Floating-Point Conditional Move - not below (CF=0)") \
decOP( FCMOVNBE  , ST          , STi         ,        , ,      ,     ,     , 0xDB,     , 2, PP+, , , , , oooozooo, 0123, o1oo, 0o23, , "Floating-Point Conditional Move - below or equal (CF=0 and ZF=0)") \
decOP( FCMOVNE   , ST          , STi         ,        , ,      ,     ,     , 0xDB,     , 1, PP+, , , , , oooozooo, 0123, o1oo, 0o23, , "Floating-Point Conditional Move - not equal (ZF=0)") \
decOP( FCMOVNU   , ST          , STi         ,        , ,      ,     ,     , 0xDB,     , 3, PP+, , , , , oooooopo, 0123, o1oo, 0o23, , "Floating-Point Conditional Move - not unordered (PF=0)") \
decOP( FCMOVU    , ST          , STi         ,        , ,      ,     ,     , 0xDA,     , 3, PP+, , , , , oooooopo, 0123, o1oo, 0o23, , "Floating-Point Conditional Move - unordered (PF=1)") \
decOP( FCOM      , ST          , STiom32f    ,        , ,      ,     ,     , 0xD8,     , 2, , , , , , , 0123, 0123, , , "Compare Real") \
decOP( FCOM      , ST          , ST1         ,        , ,      ,     ,     , 0xD8, 0xD1, 2, , , , , , , 0123, 0123, , , "Compare Real") \
decOP( FCOM      , ST          , m64f        ,        , ,      ,     ,     , 0xDC,     , 2, , , , , , , 0123, 0123, , , "Compare Real") \
decOP( FCOM2     , ST          , STi         ,        , ,      ,     ,     , 0xDC,     , 2, , D7, , , , , 0123, 0123, , , "Compare Real") \
decOP( FCOM2     , ST          , STi         ,        , ,      ,     ,     , 0xDC,     , 2, 03+, U11, , , , , 0123, 0123, , , "Compare Real") \
decOP( FCOMI     , ST          , STi         ,        , ,      ,     ,     , 0xDB,     , 6, PP+, , , , , , oooozopc o1oo, oooozopc o1oo, , oooooooo, "Compare Floating Point Values and Set EFLAGS") \
decOP( FCOMIP    , ST          , STi         ,        , ,      ,     ,     , 0xDF,     , 6, PP+, , , , p, , oooozopc o1oo, oooozopc o1oo, , oooooooo, "Compare Floating Point Values and Set EFLAGS and Pop") \
decOP( FCOMP     , ST          , STiom32f    ,        , ,      ,     ,     , 0xD8,     , 3, , , , , p, , 0123, 0123, , , "Compare Real and Pop") \
decOP( FCOMP     , ST          , ST1         ,        , ,      ,     ,     , 0xD8, 0xD9, 3, , , , , p, , 0123, 0123, , , "Compare Real and Pop") \
decOP( FCOMP     , ST          , m64f        ,        , ,      ,     ,     , 0xDC,     , 3, , , , , p, , 0123, 0123, , , "Compare Real and Pop") \
decOP( FCOMP3    , ST          , STi         ,        , ,      ,     ,     , 0xDC,     , 3, , D8, , , p, , 0123, 0123, , , "Compare Real and Pop") \
decOP( FCOMP3    , ST          , STi         ,        , ,      ,     ,     , 0xDC,     , 3, 03+, U11, , , p, , 0123, 0123, , , "Compare Real and Pop") \
decOP( FCOMP5    , ST          , STi         ,        , ,      ,     ,     , 0xDE,     , 2, , D8, , , p, , 0123, 0123, , , "Compare Real and Pop") \
decOP( FCOMP5    , ST          , STi         ,        , ,      ,     ,     , 0xDE,     , 2, 03+, U11, , , p, , 0123, 0123, , , "Compare Real and Pop") \
decOP( FCOMPP    , ST          , ST1         ,        , ,      ,     ,     , 0xDE, 0xD9, 3, , , , , P, , 0123, 0123, , , "Compare Real and Pop Twice") \
decOP( FCOS      , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xFF, 7, , , , , , , 0123, o12o, 0oo3, , "Cosine") \
decOP( FDECSTP   ,             ,             ,        , ,      ,     ,     , 0xD9, 0xF6, 6, , , , , , , 0123, o1oo, 0o23, o0oo, "Decrement Stack-Top Pointer") \
decOP( FDIV      , ST          , m32f        ,        , ,      ,     ,     , 0xD8,     , 6, , , , , , , 0123, o1oo, 0o23, , "Divide") \
decOP( FDIV      , ST          , STi         ,        , ,      ,     ,     , 0xD8,     , 6, , , , , , , 0123, o1oo, 0o23, , "Divide") \
decOP( FDIV      , ST          , m64f        ,        , ,      ,     ,     , 0xDC,     , 6, , , , , , , 0123, o1oo, 0o23, , "Divide") \
decOP( FDIV      , STi         , ST          ,        , ,      ,     ,     , 0xDC,     , 7, , , , , , , 0123, o1oo, 0o23, , "Divide and Pop") \
decOP( FDIVP     , STi         , ST          ,        , ,      ,     ,     , 0xDE,     , 7, , , , , p, , 0123, o1oo, 0o23, , "Divide and Pop") \
decOP( FDIVP     , ST1         , ST          ,        , ,      ,     ,     , 0xDE, 0xF9, 7, , , , , p, , 0123, o1oo, 0o23, , "Divide and Pop") \
decOP( FDIVR     , ST          , m32f        ,        , ,      ,     ,     , 0xD8,     , 7, , , , , , , 0123, o1oo, 0o23, , "Reverse Divide") \
decOP( FDIVR     , ST          , STi         ,        , ,      ,     ,     , 0xD8,     , 7, , , , , , , 0123, o1oo, 0o23, , "Reverse Divide") \
decOP( FDIVR     , STi         , ST          ,        , ,      ,     ,     , 0xDC,     , 6, , , , , , , 0123, o1oo, 0o23, , "Reverse Divide") \
decOP( FDIVR     , ST          , m64f        ,        , ,      ,     ,     , 0xDC,     , 7, , , , , , , 0123, o1oo, 0o23, , "Reverse Divide") \
decOP( FDIVRP    , STi         , ST          ,        , ,      ,     ,     , 0xDE,     , 6, , , , , p, , 0123, o1oo, 0o23, , "Reverse Divide and Pop") \
decOP( FDIVRP    , ST1         , ST          ,        , ,      ,     ,     , 0xDE, 0xF1, 6, , , , , p, , 0123, o1oo, 0o23, , "Reverse Divide and Pop") \
decOP( FFREE     , STi         ,             ,        , ,      ,     ,     , 0xDD,     , 0, , , , , , , 0123, , 0123, , "Free Floating-Point Register") \
decOP( FFREEP    , STi         ,             ,        , ,      ,     ,     , 0xDF,     , 0, , D10, , , p, , 0123, , 0123, , "Free Floating-Point Register and Pop") \
decOP( FIADD     , ST          , m32int      ,        , ,      ,     ,     , 0xDA,     , 0, , , , , , , 0123, o1oo, 0o23, , "Add") \
decOP( FIADD     , ST          , m16int      ,        , ,      ,     ,     , 0xDE,     , 0, , , , , , , 0123, o1oo, 0o23, , "Add") \
decOP( FICOM     , ST          , m32int      ,        , ,      ,     ,     , 0xDA,     , 2, , , , , , , 0123, 0123, , , "Compare Integer") \
decOP( FICOM     , ST          , m16int      ,        , ,      ,     ,     , 0xDE,     , 2, , , , , , , 0123, 0123, , , "Compare Integer") \
decOP( FICOMP    , ST          , m32int      ,        , ,      ,     ,     , 0xDA,     , 3, , , , , p, , 0123, 0123, , , "Compare Integer and Pop") \
decOP( FICOMP    , ST          , m16int      ,        , ,      ,     ,     , 0xDE,     , 3, , , , , p, , 0123, 0123, , , "Compare Integer and Pop") \
decOP( FIDIV     , ST          , m32int      ,        , ,      ,     ,     , 0xDA,     , 6, , , , , , , 0123, o1oo, 0o23, , "Divide") \
decOP( FIDIV     , ST          , m16int      ,        , ,      ,     ,     , 0xDE,     , 6, , , , , , , 0123, o1oo, 0o23, , "Divide") \
decOP( FIDIVR    , ST          , m32int      ,        , ,      ,     ,     , 0xDA,     , 7, , , , , , , 0123, o1oo, 0o23, , "Reverse Divide") \
decOP( FIDIVR    , ST          , m16int      ,        , ,      ,     ,     , 0xDE,     , 7, , , , , , , 0123, o1oo, 0o23, , "Reverse Divide") \
decOP( FILD      , ST          , m32int      ,        , ,      ,     ,     , 0xDB,     , 0, , , , , s, , 0123, o1oo, 0o23, , "Load Integer") \
decOP( FILD      , ST          , m16int      ,        , ,      ,     ,     , 0xDF,     , 0, , , , , s, , 0123, o1oo, 0o23, , "Load Integer") \
decOP( FILD      , ST          , m64int      ,        , ,      ,     ,     , 0xDF,     , 5, , , , , s, , 0123, o1oo, 0o23, , "Load Integer") \
decOP( FIMUL     , ST          , m32int      ,        , ,      ,     ,     , 0xDA,     , 1, , , , , , , 0123, o1oo, 0o23, , "Multiply") \
decOP( FIMUL     , ST          , m16int      ,        , ,      ,     ,     , 0xDE,     , 1, , , , , , , 0123, o1oo, 0o23, , "Multiply") \
decOP( FINCSTP   ,             ,             ,        , ,      ,     ,     , 0xD9, 0xF7, 6, , , , , , , 0123, o1oo, 0o23, o0oo, "Increment Stack-Top Pointer") \
decOP( FINIT     ,             ,             ,        , ,      , 0x9B,     , 0xDB, 0xE3, 4, , , , , , , 0123, , , 0000, "Initialize Floating-Point Unit") \
decOP( FIST      , m32int      , ST          ,        , ,      ,     ,     , 0xDB,     , 2, , , , , , , 0123, o1oo, 0o23, , "Store Integer") \
decOP( FIST      , m16int      , ST          ,        , ,      ,     ,     , 0xDF,     , 2, , , , , , , 0123, o1oo, 0o23, , "Store Integer") \
decOP( FISTP     , m32int      , ST          ,        , ,      ,     ,     , 0xDB,     , 3, , , , , p, , 0123, o1oo, 0o23, , "Store Integer and Pop") \
decOP( FISTP     , m16int      , ST          ,        , ,      ,     ,     , 0xDF,     , 3, , , , , p, , 0123, o1oo, 0o23, , "Store Integer and Pop") \
decOP( FISTP     , m64int      , ST          ,        , ,      ,     ,     , 0xDF,     , 7, , , , , p, , 0123, o1oo, 0o23, , "Store Integer and Pop") \
decOP( FISTTP    , m32int      , ST          ,        , , sse3 ,     ,     , 0xDB,     , 1, P4++, , , , p, , 0123, o1oo, 0o23, o0oo, "Store Integer with Truncation and Pop") \
decOP( FISTTP    , m64int      , ST          ,        , , sse3 ,     ,     , 0xDD,     , 1, P4++, , , , p, , 0123, o1oo, 0o23, o0oo, "Store Integer with Truncation and Pop") \
decOP( FISTTP    , m16int      , ST          ,        , , sse3 ,     ,     , 0xDF,     , 1, P4++, , , , p, , 0123, o1oo, 0o23, o0oo, "Store Integer with Truncation and Pop") \
decOP( FISUB     , ST          , m32int      ,        , ,      ,     ,     , 0xDA,     , 4, , , , , , , 0123, o1oo, 0o23, , "Subtract") \
decOP( FISUB     , ST          , m16int      ,        , ,      ,     ,     , 0xDE,     , 4, , , , , , , 0123, o1oo, 0o23, , "Subtract") \
decOP( FISUBR    , ST          , m32int      ,        , ,      ,     ,     , 0xDA,     , 5, , , , , , , 0123, o1oo, 0o23, , "Reverse Subtract") \
decOP( FISUBR    , ST          , m16int      ,        , ,      ,     ,     , 0xDE,     , 5, , , , , , , 0123, o1oo, 0o23, , "Reverse Subtract") \
decOP( FLD       , ST          , STiom32f    ,        , ,      ,     ,     , 0xD9,     , 0, , , , , s, , 0123, o1oo, 0o23, , "Load Floating Point Value") \
decOP( FLD       , ST          , m80real     ,        , ,      ,     ,     , 0xDB,     , 5, , , , , s, , 0123, o1oo, 0o23, , "Load Floating Point Value") \
decOP( FLD       , ST          , m64f        ,        , ,      ,     ,     , 0xDD,     , 0, , , , , s, , 0123, o1oo, 0o23, , "Load Floating Point Value") \
decOP( FLD1      , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xE8, 5, , , , , s, , 0123, o1oo, 0o23, , "Load Constant +1o0") \
decOP( FLDCW     , m16         ,             ,        , ,      ,     ,     , 0xD9,     , 5, , , , , , , 0123, , 0123, , "Load x87 FPU Control Word") \
decOP( FLDENV    , m14o28      ,             ,        , ,      ,     ,     , 0xD9,     , 4, , , , , , , 0123, 0123, , , "Load x87 FPU Environment") \
decOP( FLDL2E    , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xEA, 5, , , , , s, , 0123, o1oo, 0o23, , "Load Constant log 2e") \
decOP( FLDL2T    , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xE9, 5, , , , , s, , 0123, o1oo, 0o23, , "Load Constant log 210") \
decOP( FLDLG2    , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xEC, 5, , , , , s, , 0123, o1oo, 0o23, , "Load Constant log 102") \
decOP( FLDLN2    , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xED, 5, , , , , s, , 0123, o1oo, 0o23, , "Load Constant log e2") \
decOP( FLDPI     , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xEB, 5, , , , , s, , 0123, o1oo, 0o23, , "Load Constant &#960;") \
decOP( FLDZ      , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xEE, 5, , , , , s, , 0123, o1oo, 0o23, , "Load Constant +0o0") \
decOP( FMUL      , ST          , m32f        ,        , ,      ,     ,     , 0xD8,     , 1, , , , , , , 0123, o1oo, 0o23, , "Multiply") \
decOP( FMUL      , ST          , STi         ,        , ,      ,     ,     , 0xD8,     , 1, , , , , , , 0123, o1oo, 0o23, , "Multiply") \
decOP( FMUL      , ST          , m64f        ,        , ,      ,     ,     , 0xDC,     , 1, , , , , , , 0123, o1oo, 0o23, , "Multiply") \
decOP( FMUL      , STi         , ST          ,        , ,      ,     ,     , 0xDC,     , 1, , , , , , , 0123, o1oo, 0o23, , "Multiply") \
decOP( FMULP     , STi         , ST          ,        , ,      ,     ,     , 0xDE,     , 1, , , , , p, , 0123, o1oo, 0o23, , "Multiply and Pop") \
decOP( FMULP     , ST1         , ST          ,        , ,      ,     ,     , 0xDE, 0xC9, 1, , , , , p, , 0123, o1oo, 0o23, , "Multiply and Pop") \
decOP( FNCLEX    ,             ,             ,        , ,      ,     ,     , 0xDB, 0xE2, 4, , , , , , , 0123, , 0123, , "Clear Exceptions") \
decOP( nop       ,             ,             ,        , ,      ,     ,     , 0xDB, 0xE1, 4, 01+, D5, , , , , , , , , "Treated as Integer NOP") \
decOP( nop       ,             ,             ,        , ,      ,     ,     , 0xDB, 0xE0, 4, 01+, D5, , , , , , , , , "Treated as Integer NOP") \
decOP( FNINIT    ,             ,             ,        , ,      ,     ,     , 0xDB, 0xE3, 4, , , , , , , 0123, , , 0000, "Initialize Floating-Point Unit") \
decOP( FNOP      ,             ,             ,        , ,      ,     ,     , 0xD9, 0xD0, 2, , , , , , , 0123, , 0123, , "No Operation") \
decOP( FNSAVE    , m94o108     , ST          , ST1    , ooo ,      ,     ,     , 0xDD,     , 6, , , , , , , 0123, 0123, , 0000, "Store x87 FPU State") \
decOP( nop       ,             ,             ,        , ,      ,     ,     , 0xDB, 0xE4, 4, 03+, D6, , , , , , , , , "Treated as Integer NOP") \
decOP( FNSTCW    , m16         ,             ,        , ,      ,     ,     , 0xD9,     , 7, , , , , , , 0123, , 0123, , "Store x87 FPU Control Word") \
decOP( FNSTENV   , m14o28      ,             ,        , ,      ,     ,     , 0xD9,     , 6, , , , , , , 0123, , 0123, , "Store x87 FPU Environment") \
decOP( FNSTSW    , m16         ,             ,        , ,      ,     ,     , 0xDD,     , 7, , , , , , , 0123, , 0123, , "Store x87 FPU Status Word") \
decOP( FNSTSW    , AX          ,             ,        , ,      ,     ,     , 0xDF, 0xE0, 4, 02+, , , , , , 0123, , 0123, , "Store x87 FPU Status Word") \
decOP( FPATAN    , ST1         , ST          ,        , ,      ,     ,     , 0xD9, 0xF3, 6, , , , , p, , 0123, o1oo, 0o23, , "Partial Arctangent and Pop") \
decOP( FPREM     , ST          , ST1         ,        , ,      ,     ,     , 0xD9, 0xF8, 7, , , , , , , 0123, 0123, , , "Partial Remainder (for compatibility with i8087 and i287)") \
decOP( FPREM1    , ST          , ST1         ,        , ,      ,     ,     , 0xD9, 0xF5, 6, , , , , , , 0123, 0123, , , "IEEE Partial Remainder") \
decOP( FPTAN     , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xF2, 6, , , , , s, , 0123, o12o, 0oo3, , "Partial Tangent") \
decOP( FRNDINT   , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xFC, 7, , , , , , , 0123, o1oo, 0o23, , "Round to Integer") \
decOP( FRSTOR    , ST          , ST1         , ST2    , ooo ,      ,     ,     , 0xDD,     , 4, , , , , , , 0123, 0123, , , "Restore x87 FPU State") \
decOP( FS        , FS          ,             ,        , ,      , 0x64,     ,     ,     , , 03+, , , , , , , , , , "FS segment override prefix") \
decOP( FSAVE     , m94o108     , ST          , ST1    , ooo ,      , 0x9B,     , 0xDD,     , 6, , , , , , , 0123, 0123, , 0000, "Store x87 FPU State") \
decOP( FSCALE    , ST          , ST1         ,        , ,      ,     ,     , 0xD9, 0xFD, 7, , , , , , , 0123, o1oo, 0o23, , "Scale") \
decOP( FSIN      , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xFE, 7, , , , , , , 0123, o12o, 0oo3, , "Sine") \
decOP( FSINCOS   , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xFB, 7, , , , , s, , 0123, o12o, 0oo3, , "Sine and Cosine") \
decOP( FSQRT     , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xFA, 7, , , , , , , 0123, o1oo, 0o23, , "Square Root") \
decOP( FST       , m32f        , ST          ,        , ,      ,     ,     , 0xD9,     , 2, , , , , , , 0123, o1oo, 0o23, , "Store Floating Point Value") \
decOP( FST       , m64f        , ST          ,        , ,      ,     ,     , 0xDD,     , 2, , , , , , , 0123, o1oo, 0o23, , "Store Floating Point Value") \
decOP( FST       , ST          , STi         ,        , ,      ,     ,     , 0xDD,     , 2, , , , , , , 0123, o1oo, 0o23, , "Store Floating Point Value") \
decOP( FSTCW     , m16         ,             ,        , ,      , 0x9B,     , 0xD9,     , 7, , , , , , , 0123, , 0123, , "Store x87 FPU Control Word") \
decOP( FSTENV    , m14o28      ,             ,        , ,      , 0x9B,     , 0xD9,     , 6, , , , , , , 0123, , 0123, , "Store x87 FPU Environment") \
decOP( FSTP      , m32f        , ST          ,        , ,      ,     ,     , 0xD9,     , 3, , , , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTP      , m80real     , ST          ,        , ,      ,     ,     , 0xDB,     , 7, , , , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTP      , m64f        , ST          ,        , ,      ,     ,     , 0xDD,     , 3, , , , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTP      , ST          , STi         ,        , ,      ,     ,     , 0xDD,     , 3, , , , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTP1     , STi         , ST          ,        , ,      ,     ,     , 0xD9,     , 3, , D4, , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTP1     , STi         , ST          ,        , ,      ,     ,     , 0xD9,     , 3, 03+, U11, , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTP8     , STi         , ST          ,        , ,      ,     ,     , 0xDF,     , 2, , D4, , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTP8     , STi         , ST          ,        , ,      ,     ,     , 0xDF,     , 2, 03+, U11, , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTP9     , STi         , ST          ,        , ,      ,     ,     , 0xDF,     , 3, , D4, , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTP9     , STi         , ST          ,        , ,      ,     ,     , 0xDF,     , 3, 03+, U11, , , p, , 0123, o1oo, 0o23, , "Store Floating Point Value and Pop") \
decOP( FSTSW     , m16         ,             ,        , ,      , 0x9B,     , 0xDD,     , 7, , , , , , , 0123, , 0123, , "Store x87 FPU Status Word") \
decOP( FSTSW     , AX          ,             ,        , ,      , 0x9B,     , 0xDF, 0xE0, 4, 02+, , , , , , 0123, , 0123, , "Store x87 FPU Status Word") \
decOP( FSUB      , ST          , m32f        ,        , ,      ,     ,     , 0xD8,     , 4, , , , , , , 0123, o1oo, 0o23, , "Subtract") \
decOP( FSUB      , ST          , STi         ,        , ,      ,     ,     , 0xD8,     , 4, , , , , , , 0123, o1oo, 0o23, , "Subtract") \
decOP( FSUB      , ST          , m64f        ,        , ,      ,     ,     , 0xDC,     , 4, , , , , , , 0123, o1oo, 0o23, , "Subtract") \
decOP( FSUB      , STi         , ST          ,        , ,      ,     ,     , 0xDC,     , 5, , , , , , , 0123, o1oo, 0o23, , "Subtract") \
decOP( FSUBP     , STi         , ST          ,        , ,      ,     ,     , 0xDE,     , 5, , , , , p, , 0123, o1oo, 0o23, , "Subtract and Pop") \
decOP( FSUBP     , ST1         , ST          ,        , ,      ,     ,     , 0xDE, 0xE9, 5, , , , , p, , 0123, o1oo, 0o23, , "Subtract and Pop") \
decOP( FSUBR     , ST          , m32f        ,        , ,      ,     ,     , 0xD8,     , 5, , , , , , , 0123, o1oo, 0o23, , "Reverse Subtract") \
decOP( FSUBR     , ST          , STi         ,        , ,      ,     ,     , 0xD8,     , 5, , , , , , , 0123, o1oo, 0o23, , "Reverse Subtract") \
decOP( FSUBR     , STi         , ST          ,        , ,      ,     ,     , 0xDC,     , 4, , , , , , , 0123, o1oo, 0o23, , "Reverse Subtract") \
decOP( FSUBR     , ST          , m64f        ,        , ,      ,     ,     , 0xDC,     , 5, , , , , , , 0123, o1oo, 0o23, , "Reverse Subtract") \
decOP( FSUBRP    , STi         , ST          ,        , ,      ,     ,     , 0xDE,     , 4, , , , , p, , 0123, o1oo, 0o23, , "Reverse Subtract and Pop") \
decOP( FSUBRP    , ST1         , ST          ,        , ,      ,     ,     , 0xDE, 0xE1, 4, , , , , p, , 0123, o1oo, 0o23, , "Reverse Subtract and Pop") \
decOP( FTST      , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xE4, 4, , , , , , , 0123, 0123, , , "Test") \
decOP( FUCOM     , ST          , STi         ,        , ,      ,     ,     , 0xDD,     , 4, 03+, , , , , , 0123, 0123, , , "Unordered Compare Floating Point Values") \
decOP( FUCOM     , ST          , ST1         ,        , ,      ,     ,     , 0xDD, 0xE1, 4, 03+, , , , , , 0123, 0123, , , "Unordered Compare Floating Point Values") \
decOP( FUCOMI    , ST          , STi         ,        , ,      ,     ,     , 0xDB,     , 5, PP+, , , , , , oooozopc o1oo, oooozopc o1oo, , oooooooo, "Unordered Compare Floating Point Values and Set EFLAGS") \
decOP( FUCOMIP   , ST          , STi         ,        , ,      ,     ,     , 0xDF,     , 5, PP+, , , , p, , oooozopc o1oo, oooozopc o1oo, , oooooooo, "Unordered Compare Floating Point Values and Set EFLAGS and Pop") \
decOP( FUCOMP    , ST          , STi         ,        , ,      ,     ,     , 0xDD,     , 5, 03+, , , , p, , 0123, 0123, , , "Unordered Compare Floating Point Values and Pop") \
decOP( FUCOMP    , ST          , ST1         ,        , ,      ,     ,     , 0xDD, 0xE9, 5, 03+, , , , p, , 0123, 0123, , , "Unordered Compare Floating Point Values and Pop") \
decOP( FUCOMPP   , ST          , ST1         ,        , ,      ,     ,     , 0xDA, 0xE9, 5, 03+, , , , P, , 0123, 0123, , , "Unordered Compare Floating Point Values and Pop Twice") \
decOP( FWAIT     ,             ,             ,        , ,      ,     ,     , 0x9B,     , , , , , , , , 0123, , 0123, , "Check pending unmasked floating-point exceptions") \
decOP( WAIT      ,             ,             ,        , ,      ,     ,     , 0x9B,     , , , , , , , , 0123, , 0123, , "Check pending unmasked floating-point exceptions") \
decOP( FXAM      , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xE5, 4, , , , , , , 0123, 0123, , , "Examine") \
decOP( FXCH      , ST          , STi         ,        , ,      ,     ,     , 0xD9,     , 1, , , , , , , 0123, o1oo, 0o23, , "Exchange Register Contents") \
decOP( FXCH      , ST          , ST1         ,        , ,      ,     ,     , 0xD9, 0xC9, 1, , , , , , , 0123, o1oo, 0o23, , "Exchange Register Contents") \
decOP( FXCH4     , ST          , STi         ,        , ,      ,     ,     , 0xDD,     , 1, , D9, , , , , 0123, o1oo, 0o23, , "Exchange Register Contents") \
decOP( FXCH4     , ST          , STi         ,        , ,      ,     ,     , 0xDD,     , 1, 03+, U11, , , , , 0123, o1oo, 0o23, , "Exchange Register Contents") \
decOP( FXCH7     , ST          , STi         ,        , ,      ,     ,     , 0xDF,     , 1, , D9, , , , , 0123, o1oo, 0o23, , "Exchange Register Contents") \
decOP( FXCH7     , ST          , STi         ,        , ,      ,     ,     , 0xDF,     , 1, 03+, U11, , , , , 0123, o1oo, 0o23, , "Exchange Register Contents") \
decOP( FXRSTOR   , ST          , ST1         , ST2    , ooo ,      ,     , 0x0F, 0xAE,     , 1, P2++, , , , , , , , , , "Restore x87 FPU, MMX, XMM, and MXCSR State") \
decOP( FXSAVE    , m512        , ST          , ST1    , ooo ,      ,     , 0x0F, 0xAE,     , 0, P2++, , , , , , , , , , "Save x87 FPU, MMX, XMM, and MXCSR State") \
decOP( FXTRACT   , ST          ,             ,        , ,      ,     ,     , 0xD9, 0xF4, 6, , , , , s, , 0123, o1oo, 0o23, , "Extract Exponent and Significand") \
decOP( FYL2X     , ST1         , ST          ,        , ,      ,     ,     , 0xD9, 0xF1, 6, , , , , p, , 0123, o1oo, 0o23, , "Compute y × log 2x and Pop") \
decOP( FYL2XP1   , ST1         , ST          ,        , ,      ,     ,     , 0xD9, 0xF9, 7, , , , , p, , 0123, o1oo, 0o23, , "Compute y × log 2(x+1) and Pop") \
decOP( GS        , GS          ,             ,        , ,      , 0x65,     ,     ,     , , 03+, , , , , , , , , , "GS segment override prefix") \
decOP( HADDPD    , xmm         , Xm128       ,        , , sse3 , 0x66, 0x0F, 0x7C,     , r, P4++, , , , , , , , , , "Packed Double-FP Horizontal Add") \
decOP( HADDPS    , xmm         , Xm128       ,        , , sse3 , 0xF2, 0x0F, 0x7C,     , r, P4++, , , , , , , , , , "Packed Single-FP Horizontal Add") \
decOP( HLT       ,             ,             ,        , ,      ,     ,     , 0xF4,     , , , , , 0, , , , , , , "Halt") \
decOP( HSUBPD    , xmm         , Xm128       ,        , , sse3 , 0x66, 0x0F, 0x7D,     , r, P4++, , , , , , , , , , "Packed Double-FP Horizontal Subtract") \
decOP( HSUBPS    , xmm         , Xm128       ,        , , sse3 , 0x66, 0x0F, 0x7D,     , r, P4++, , , , , , , , , , "Packed Single-FP Horizontal Subtract") \
decOP( IDIV      , AL          , AH          , AX     , rm8,      ,     ,     , 0xF6,     , 7, , , , , , , oooszapc, , oooszapc, , "Signed Divide") \
decOP( IDIV      , eDX         , eAX         , rmWD   , ,      ,     ,     , 0xF7,     , 7, , , , , , , oooszapc, , oooszapc, , "Signed Divide") \
decOP( IMUL      , rWD         , rmWD        , immWD  , ,      ,     ,     , 0x69,     , , 01+, , , , , , oooszapc, oooooooc, oooszapo, , "Signed Multiply") \
decOP( IMUL      , rWD         , rmWD        , imm8   , ,      ,     ,     , 0x6B,     , , 01+, , , , , , oooszapc, oooooooc, oooszapo, , "Signed Multiply") \
decOP( IMUL      , AX          , AL          , rm8    , ,      ,     ,     , 0xF6,     , 5, , , , , , , oooszapc, oooooooc, oooszapo, , "Signed Multiply") \
decOP( IMUL      , eDX         , eAX         , rmWD   , ,      ,     ,     , 0xF7,     , 5, , , , , , , oooszapc, oooooooc, oooszapo, , "Signed Multiply") \
decOP( IMUL      , rWD         , rmWD        ,        , ,      ,     , 0x0F, 0xAF,     , r, 03+, , , , , , oooszapc, oooooooc, oooszapo, , "Signed Multiply") \
decOP( IN        , AL          , imm8        ,        , ,      ,     ,     , 0xE4,     , , , , , f1, , , , , , , "Input from Port") \
decOP( IN        , eAX         , imm8        ,        , ,      ,     ,     , 0xE5,     , , , , , f1, , , , , , , "Input from Port") \
decOP( IN        , AL          , DX          ,        , ,      ,     ,     , 0xEC,     , , , , , f1, , , , , , , "Input from Port") \
decOP( IN        , eAX         , DX          ,        , ,      ,     ,     , 0xED,     , , , , , f1, , , , , , , "Input from Port") \
decOP( INC       , rWD         ,             ,        , ,      ,     ,     , 0x40,     , s, , , , , , , oooszapo, oooszapo, , , "Increment by 1") \
decOP( INC       , rm8         ,             ,        , ,      ,     ,     , 0xFE,     , 0, , , , , , , oooszapo, oooszapo, , , "Increment by 1") \
decOP( INC       , rmWD        ,             ,        , ,      ,     ,     , 0xFF,     , 0, , , , , , , oooszapo, oooszapo, , , "Increment by 1") \
decOP( INS       , m8          , DX          ,        , ,      ,     ,     , 0x6C,     , , 01+, , , f1, , odoooooo, , , , , "Input from Port to String") \
decOP( INSB      , m8          , DX          ,        , ,      ,     ,     , 0x6C,     , , 01+, , , f1, , odoooooo, , , , , "Input from Port to String") \
decOP( INS       , m16         , DX          ,        , ,      ,     ,     , 0x6D,     , , 01+, , , f1, , odoooooo, , , , , "Input from Port to String") \
decOP( INSW      , m16         , DX          ,        , ,      ,     ,     , 0x6D,     , , 01+, , , f1, , odoooooo, , , , , "Input from Port to String") \
decOP( INS       , mWD         , DX          ,        , ,      ,     ,     , 0x6D,     , , 03+, , , f1, , odoooooo, , , , , "Input from Port to String") \
decOP( INSD      , m32         , DX          ,        , ,      ,     ,     , 0x6D,     , , 03+, , , f1, , odoooooo, , , , , "Input from Port to String") \
decOP( INT       , 3           , eFlags      ,        , ,      ,     ,     , 0xCC,     , , , , , f, , , ooiooooo, ooiooooo, , ooiooooo, "Call to Interrupt Procedure") \
decOP( INT       , imm8        , eFlags      ,        , ,      ,     ,     , 0xCD,     , , , , , f, , , ooiooooo, ooiooooo, , ooiooooo, "Call to Interrupt Procedure") \
decOP( INT1      , eFlags      ,             ,        , ,      ,     ,     , 0xF1,     , , 03+, U12, , , , , ooiooooo, ooiooooo, , ooiooooo, "Call to Interrupt Procedure") \
decOP( ICEBP     , eFlags      ,             ,        , ,      ,     ,     , 0xF1,     , , 03+, U12, , , , , ooiooooo, ooiooooo, , ooiooooo, "Call to Interrupt Procedure") \
decOP( INTO      , eFlags      ,             ,        , ,      ,     ,     , 0xCE,     , , , , , f, , oooooooo, ooiooooo, ooiooooo, , ooiooooo, "Call to Interrupt Procedure") \
decOP( INVD      ,             ,             ,        , ,      ,     , 0x0F, 0x08,     , , 04+, , , 0, , , , , , , "Invalidate Internal Caches") \
decOP( INVLPG    , m           ,             ,        , ,      ,     , 0x0F, 0x01,     , 7, 04+, , , 0, , , , , , , "Invalidate TLB Entry") \
decOP( IRET      , Flags       ,             ,        , ,      ,     ,     , 0xCF,     , , , , , f, , , odiszapc, odiszapc, , , "Interrupt Return") \
decOP( IRETD     , EFlags      ,             ,        , ,      ,     ,     , 0xCF,     , , 03+, , , f, , , odiszapc, odiszapc, , , "Interrupt Return") \
decOP( JB        , rel8        ,             ,        , ,      ,     ,     , 0x72,     , , , , , , , oooooooc, , , , , "Jump short if belowonot above or equalocarry (CF=1)") \
decOP( JNAE      , rel8        ,             ,        , ,      ,     ,     , 0x72,     , , , , , , , oooooooc, , , , , "Jump short if belowonot above or equalocarry (CF=1)") \
decOP( JC        , rel8        ,             ,        , ,      ,     ,     , 0x72,     , , , , , , , oooooooc, , , , , "Jump short if belowonot above or equalocarry (CF=1)") \
decOP( JB        , relWD       ,             ,        , ,      ,     , 0x0F, 0x82,     , , 03+, , , , , oooooooc, , , , , "Jump short if belowonot above or equalocarry (CF=1)") \
decOP( JNAE      , relWD       ,             ,        , ,      ,     , 0x0F, 0x82,     , , 03+, , , , , oooooooc, , , , , "Jump short if belowonot above or equalocarry (CF=1)") \
decOP( JC        , relWD       ,             ,        , ,      ,     , 0x0F, 0x82,     , , 03+, , , , , oooooooc, , , , , "Jump short if belowonot above or equalocarry (CF=1)") \
decOP( JBE       , rel8        ,             ,        , ,      ,     ,     , 0x76,     , , , , , , , oooozooc, , , , , "Jump short if below or equalonot above (CF=1 AND ZF=1)") \
decOP( JNA       , rel8        ,             ,        , ,      ,     ,     , 0x76,     , , , , , , , oooozooc, , , , , "Jump short if below or equalonot above (CF=1 AND ZF=1)") \
decOP( JBE       , relWD       ,             ,        , ,      ,     , 0x0F, 0x86,     , , 03+, , , , , oooozooc, , , , , "Jump short if below or equalonot above (CF=1 AND ZF=1)") \
decOP( JNA       , relWD       ,             ,        , ,      ,     , 0x0F, 0x86,     , , 03+, , , , , oooozooc, , , , , "Jump short if below or equalonot above (CF=1 AND ZF=1)") \
decOP( JCXZ      , rel8        , CX          ,        , ,      ,     ,     , 0xE3,     , , , , , , , , , , , , "Jump short if eCX register is 0") \
decOP( JECXZ     , rel8        , ECX         ,        , ,      ,     ,     , 0xE3,     , , , , , , , , , , , , "Jump short if eCX register is 0") \
decOP( JL        , rel8        ,             ,        , ,      ,     ,     , 0x7C,     , , , , , , , ooosoooo, , , , , "Jump short if lessonot greater (SF!=OF)") \
decOP( JNGE      , rel8        ,             ,        , ,      ,     ,     , 0x7C,     , , , , , , , ooosoooo, , , , , "Jump short if lessonot greater (SF!=OF)") \
decOP( JL        , relWD       ,             ,        , ,      ,     , 0x0F, 0x8C,     , , 03+, , , , , ooosoooo, , , , , "Jump short if lessonot greater (SF!=OF)") \
decOP( JNGE      , relWD       ,             ,        , ,      ,     , 0x0F, 0x8C,     , , 03+, , , , , ooosoooo, , , , , "Jump short if lessonot greater (SF!=OF)") \
decOP( JLE       , rel8        ,             ,        , ,      ,     ,     , 0x7E,     , , , , , , , oooszooo, , , , , "Jump short if less or equalonot greater ((ZF=1) OR (SF!=OF))") \
decOP( JNG       , rel8        ,             ,        , ,      ,     ,     , 0x7E,     , , , , , , , oooszooo, , , , , "Jump short if less or equalonot greater ((ZF=1) OR (SF!=OF))") \
decOP( JLE       , relWD       ,             ,        , ,      ,     , 0x0F, 0x8E,     , , 03+, , , , , oooszooo, , , , , "Jump short if less or equalonot greater ((ZF=1) OR (SF!=OF))") \
decOP( JNG       , relWD       ,             ,        , ,      ,     , 0x0F, 0x8E,     , , 03+, , , , , oooszooo, , , , , "Jump short if less or equalonot greater ((ZF=1) OR (SF!=OF))") \
decOP( JMP       , relWD       ,             ,        , ,      ,     ,     , 0xE9,     , , , , , , , , , , , , "Jump") \
decOP( JMP       , rel8        ,             ,        , ,      ,     ,     , 0xEB,     , , , , , , , , , , , , "Jump") \
decOP( JMP       , rmWD        ,             ,        , ,      ,     ,     , 0xFF,     , 4, , , , , , , , , , , "Jump") \
decOP( JMPF      , ptr16OWD    ,             ,        , ,      ,     ,     , 0xEA,     , , , , , , , , , , , , "Jump") \
decOP( JMPF      , m16OWD      ,             ,        , ,      ,     ,     , 0xFF,     , 5, , , , , , , , , , , "Jump") \
decOP( JNB       , rel8        ,             ,        , ,      ,     ,     , 0x73,     , , , , , , , oooooooc, , , , , "Jump short if not belowoabove or equalonot carry (CF=0)") \
decOP( JAE       , rel8        ,             ,        , ,      ,     ,     , 0x73,     , , , , , , , oooooooc, , , , , "Jump short if not belowoabove or equalonot carry (CF=0)") \
decOP( JNC       , rel8        ,             ,        , ,      ,     ,     , 0x73,     , , , , , , , oooooooc, , , , , "Jump short if not belowoabove or equalonot carry (CF=0)") \
decOP( JNB       , relWD       ,             ,        , ,      ,     , 0x0F, 0x83,     , , 03+, , , , , oooooooc, , , , , "Jump short if not belowoabove or equalonot carry (CF=0)") \
decOP( JAE       , relWD       ,             ,        , ,      ,     , 0x0F, 0x83,     , , 03+, , , , , oooooooc, , , , , "Jump short if not belowoabove or equalonot carry (CF=0)") \
decOP( JNC       , relWD       ,             ,        , ,      ,     , 0x0F, 0x83,     , , 03+, , , , , oooooooc, , , , , "Jump short if not belowoabove or equalonot carry (CF=0)") \
decOP( JNBE      , rel8        ,             ,        , ,      ,     ,     , 0x77,     , , , , , , , oooozooc, , , , , "Jump short if not below or equaloabove (CF=0 AND ZF=0)") \
decOP( JA        , rel8        ,             ,        , ,      ,     ,     , 0x77,     , , , , , , , oooozooc, , , , , "Jump short if not below or equaloabove (CF=0 AND ZF=0)") \
decOP( JNBE      , relWD       ,             ,        , ,      ,     , 0x0F, 0x87,     , , 03+, , , , , oooozooc, , , , , "Jump short if not below or equaloabove (CF=0 AND ZF=0)") \
decOP( JA        , relWD       ,             ,        , ,      ,     , 0x0F, 0x87,     , , 03+, , , , , oooozooc, , , , , "Jump short if not below or equaloabove (CF=0 AND ZF=0)") \
decOP( JNL       , rel8        ,             ,        , ,      ,     ,     , 0x7D,     , , , , , , , ooosoooo, , , , , "Jump short if not lessogreater or equal (SF=OF)") \
decOP( JGE       , rel8        ,             ,        , ,      ,     ,     , 0x7D,     , , , , , , , ooosoooo, , , , , "Jump short if not lessogreater or equal (SF=OF)") \
decOP( JNL       , relWD       ,             ,        , ,      ,     , 0x0F, 0x8D,     , , 03+, , , , , ooosoooo, , , , , "Jump short if not lessogreater or equal (SF=OF)") \
decOP( JGE       , relWD       ,             ,        , ,      ,     , 0x0F, 0x8D,     , , 03+, , , , , ooosoooo, , , , , "Jump short if not lessogreater or equal (SF=OF)") \
decOP( JNLE      , rel8        ,             ,        , ,      ,     ,     , 0x7F,     , , , , , , , oooszooo, , , , , "Jump short if not less nor equalogreater ((ZF=0) AND (SF=OF))") \
decOP( JG        , rel8        ,             ,        , ,      ,     ,     , 0x7F,     , , , , , , , oooszooo, , , , , "Jump short if not less nor equalogreater ((ZF=0) AND (SF=OF))") \
decOP( JNLE      , relWD       ,             ,        , ,      ,     , 0x0F, 0x8F,     , , 03+, , , , , oooszooo, , , , , "Jump short if not less nor equalogreater ((ZF=0) AND (SF=OF))") \
decOP( JG        , relWD       ,             ,        , ,      ,     , 0x0F, 0x8F,     , , 03+, , , , , oooszooo, , , , , "Jump short if not less nor equalogreater ((ZF=0) AND (SF=OF))") \
decOP( JNO       , rel8        ,             ,        , ,      ,     ,     , 0x71,     , , , , , , , oooooooo, , , , , "Jump short if not overflow (OF=0)") \
decOP( JNO       , relWD       ,             ,        , ,      ,     , 0x0F, 0x81,     , , 03+, , , , , oooooooo, , , , , "Jump short if not overflow (OF=0)") \
decOP( JNP       , rel8        ,             ,        , ,      ,     ,     , 0x7B,     , , , , , , , oooooopo, , , , , "Jump short if not parityoparity odd") \
decOP( JPO       , rel8        ,             ,        , ,      ,     ,     , 0x7B,     , , , , , , , oooooopo, , , , , "Jump short if not parityoparity odd") \
decOP( JNP       , relWD       ,             ,        , ,      ,     , 0x0F, 0x8B,     , , 03+, , , , , oooooopo, , , , , "Jump short if not parityoparity odd") \
decOP( JPO       , relWD       ,             ,        , ,      ,     , 0x0F, 0x8B,     , , 03+, , , , , oooooopo, , , , , "Jump short if not parityoparity odd") \
decOP( JNS       , rel8        ,             ,        , ,      ,     ,     , 0x79,     , , , , , , , ooosoooo, , , , , "Jump short if not sign (SF=0)") \
decOP( JNS       , relWD       ,             ,        , ,      ,     , 0x0F, 0x89,     , , 03+, , , , , ooosoooo, , , , , "Jump short if not sign (SF=0)") \
decOP( JNZ       , rel8        ,             ,        , ,      ,     ,     , 0x75,     , , , , , , , oooozooo, , , , , "Jump short if not zeroonot equal (ZF=1)") \
decOP( JNE       , rel8        ,             ,        , ,      ,     ,     , 0x75,     , , , , , , , oooozooo, , , , , "Jump short if not zeroonot equal (ZF=1)") \
decOP( JNZ       , relWD       ,             ,        , ,      ,     , 0x0F, 0x85,     , , 03+, , , , , oooozooo, , , , , "Jump short if not zeroonot equal (ZF=1)") \
decOP( JNE       , relWD       ,             ,        , ,      ,     , 0x0F, 0x85,     , , 03+, , , , , oooozooo, , , , , "Jump short if not zeroonot equal (ZF=1)") \
decOP( JO        , rel8        ,             ,        , ,      ,     ,     , 0x70,     , , , , , , , oooooooo, , , , , "Jump short if overflow (OF=1)") \
decOP( JO        , relWD       ,             ,        , ,      ,     , 0x0F, 0x80,     , , 03+, , , , , oooooooo, , , , , "Jump short if overflow (OF=1)") \
decOP( JP        , rel8        ,             ,        , ,      ,     ,     , 0x7A,     , , , , , , , oooooopo, , , , , "Jump short if parityoparity even (PF=1)") \
decOP( JPE       , rel8        ,             ,        , ,      ,     ,     , 0x7A,     , , , , , , , oooooopo, , , , , "Jump short if parityoparity even (PF=1)") \
decOP( JP        , relWD       ,             ,        , ,      ,     , 0x0F, 0x8A,     , , 03+, , , , , oooooopo, , , , , "Jump short if parityoparity even (PF=1)") \
decOP( JPE       , relWD       ,             ,        , ,      ,     , 0x0F, 0x8A,     , , 03+, , , , , oooooopo, , , , , "Jump short if parityoparity even (PF=1)") \
decOP( JS        , rel8        ,             ,        , ,      ,     ,     , 0x78,     , , , , , , , ooosoooo, , , , , "Jump short if sign (SF=1)") \
decOP( JS        , relWD       ,             ,        , ,      ,     , 0x0F, 0x88,     , , 03+, , , , , ooosoooo, , , , , "Jump short if sign (SF=1)") \
decOP( JZ        , rel8        ,             ,        , ,      ,     ,     , 0x74,     , , , , , , , oooozooo, , , , , "Jump short if zerooequal (ZF=0)") \
decOP( JE        , rel8        ,             ,        , ,      ,     ,     , 0x74,     , , , , , , , oooozooo, , , , , "Jump short if zerooequal (ZF=0)") \
decOP( JZ        , relWD       ,             ,        , ,      ,     , 0x0F, 0x84,     , , 03+, , , , , oooozooo, , , , , "Jump short if zerooequal (ZF=0)") \
decOP( JE        , relWD       ,             ,        , ,      ,     , 0x0F, 0x84,     , , 03+, , , , , oooozooo, , , , , "Jump short if zerooequal (ZF=0)") \
decOP( LAHF      , AH          ,             ,        , ,      ,     ,     , 0x9F,     , , , , , , , oooszapc, , , , , "Load Status Flags into AH Register") \
decOP( LAR       , rWD         , m16         ,        , ,      ,     , 0x0F, 0x02,     , , 02+, , P, , , , oooozooo, oooozooo, , , "Load Access Rights Byte") \
decOP( LAR       , rWD         , rWD         ,        , ,      ,     , 0x0F, 0x02,     , , 02+, , P, , , , oooozooo, oooozooo, , , "Load Access Rights Byte") \
decOP( LDDQU     , xmm         , m128        ,        , , sse3 , 0xF2, 0x0F, 0xF0,     , r, P4++, , , , , , , , , , "Load Unaligned Integer 128 Bits") \
decOP( LDMXCSR   , m32         ,             ,        , , sse1 ,     , 0x0F, 0xAE,     , 2, P3+, , , , , , , , , , "Load MXCSR Register") \
decOP( LDS       , DS          , rWD         , m16OWD , ,      ,     ,     , 0xC5,     , r, , , , , , , , , , , "Load Far Pointer") \
decOP( LEA       , rWD         , m           ,        , ,      ,     ,     , 0x8D,     , r, , , , , , , , , , , "Load Effective Address") \
decOP( LEAVE     , eBP         ,             ,        , ,      ,     ,     , 0xC9,     , , 01+, , , , , , , , , , "High Level Procedure Exit") \
decOP( LES       , ES          , rWD         , m16OWD , ,      ,     ,     , 0xC4,     , r, , , , , , , , , , , "Load Far Pointer") \
decOP( LFENCE    ,             ,             ,        , , sse2 ,     , 0x0F, 0xAE,     , 5, P4+, , , , , , , , , , "Load Fence") \
decOP( LFS       , FS          , rWD         , m16OWD , ,      ,     , 0x0F, 0xB4,     , r, 03+, , , , , , , , , , "Load Far Pointer") \
decOP( LGDT      , GDTR        , m           ,        , ,      ,     , 0x0F, 0x01,     , 2, 02+, , , 0, , , , , , , "Load Global Descriptor Table Register") \
decOP( LGS       , GS          , rWD         , m16OWD , ,      ,     , 0x0F, 0xB5,     , r, 03+, , , , , , , , , , "Load Far Pointer") \
decOP( LIDT      , IDTR        , m           ,        , ,      ,     , 0x0F, 0x01,     , 3, 02+, , , 0, , , , , , , "Load Interrupt Descriptor Table Register") \
decOP( LLDT      , LDTR        , rm16        ,        , ,      ,     , 0x0F, 0x00,     , 2, 02+, , P, 0, , , , , , , "Load Local Descriptor Table Register") \
decOP( LMSW      , MSW         , rm16        ,        , ,      ,     , 0x0F, 0x01,     , 6, 02+, , , , , , , , , , "Load Machine Status Word") \
decOP( LOCK      ,             ,             ,        , ,      , 0xF0,     ,     ,     , , , , , , , , , , , , "Assert LOCK# Signal Prefix") \
decOP( LODS      , AL          , m8          ,        , ,      ,     ,     , 0xAC,     , , , , , , , odoooooo, , , , , "Load String") \
decOP( LODSB     , AL          , m8          ,        , ,      ,     ,     , 0xAC,     , , , , , , , odoooooo, , , , , "Load String") \
decOP( LODS      , AX          , m16         ,        , ,      ,     ,     , 0xAD,     , , , , , , , odoooooo, , , , , "Load String") \
decOP( LODSW     , AX          , m16         ,        , ,      ,     ,     , 0xAD,     , , , , , , , odoooooo, , , , , "Load String") \
decOP( LODS      , eAX         , mWD         ,        , ,      ,     ,     , 0xAD,     , , 03+, , , , , odoooooo, , , , , "Load String") \
decOP( LODSD     , EAX         , m32         ,        , ,      ,     ,     , 0xAD,     , , 03+, , , , , odoooooo, , , , , "Load String") \
decOP( LOOP      , eCX         , rel8        ,        , ,      ,     ,     , 0xE2,     , , , , , , , , , , , , "Decrement count; Jump short if count!=0") \
decOP( LOOPNZ    , eCX         , rel8        ,        , ,      ,     ,     , 0xE0,     , , , , , , , oooozooo, , , , , "Decrement count; Jump short if count!=0 and ZF=0") \
decOP( LOOPNE    , eCX         , rel8        ,        , ,      ,     ,     , 0xE0,     , , , , , , , oooozooo, , , , , "Decrement count; Jump short if count!=0 and ZF=0") \
decOP( LOOPZ     , eCX         , rel8        ,        , ,      ,     ,     , 0xE1,     , , , , , , , oooozooo, , , , , "Decrement count; Jump short if count!=0 and ZF=1") \
decOP( LOOPE     , eCX         , rel8        ,        , ,      ,     ,     , 0xE1,     , , , , , , , oooozooo, , , , , "Decrement count; Jump short if count!=0 and ZF=1") \
decOP( LSL       , rWD         , m16         ,        , ,      ,     , 0x0F, 0x03,     , , 02+, , P, , , , oooozooo, oooozooo, , , "Load Segment Limit") \
decOP( LSL       , rWD         , rWD         ,        , ,      ,     , 0x0F, 0x03,     , , 02+, , P, , , , oooozooo, oooozooo, , , "Load Segment Limit") \
decOP( LSS       , SS          , rWD         , m16OWD , ,      ,     , 0x0F, 0xB2,     , r, 03+, , , , , , , , , , "Load Far Pointer") \
decOP( LTR       , TR          , rm16        ,        , ,      ,     , 0x0F, 0x00,     , 3, 02+, , P, 0, , , , , , , "Load Task Register") \
decOP( MASKMOVDQU, m128        , xmm         , xmm    , , sse2 , 0x66, 0x0F, 0xF7,     , r, P4+, , , , , , , , , , "Store Selected Bytes of Double Quadword") \
decOP( MASKMOVQ  , m64         , mm          , mm     , , sse1 ,     , 0x0F, 0xF7,     , r, P3+, , , , , , , , , , "Store Selected Bytes of Quadword") \
decOP( MAXPD     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x5F,     , r, P4+, , , , , , , , , , "Return Maximum Packed Double-FP Values") \
decOP( MAXPS     , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x5F,     , r, P3+, , , , , , , , , , "Return Maximum Packed Single-FP Values") \
decOP( MAXSD     , xmm         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x5F,     , r, P4+, , , , , , , , , , "Return Maximum Scalar Double-FP Value") \
decOP( MAXSS     , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x5F,     , r, P3+, , , , , , , , , , "Return Maximum Scalar Single-FP Value") \
decOP( MFENCE    ,             ,             ,        , , sse2 ,     , 0x0F, 0xAE,     , 6, P4+, , , , , , , , , , "Memory Fence") \
decOP( MINPD     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x5D,     , r, P4+, , , , , , , , , , "Return Minimum Packed Double-FP Values") \
decOP( MINPS     , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x5D,     , r, P3+, , , , , , , , , , "Return Minimum Packed Single-FP Values") \
decOP( MINSD     , xmm         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x5D,     , r, P4+, , , , , , , , , , "Return Minimum Scalar Double-FP Value") \
decOP( MINSS     , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x5D,     , r, P3+, , , , , , , , , , "Return Minimum Scalar Single-FP Value") \
decOP( MONITOR   , m           , ECX         , EDX    , , sse3 ,     , 0x0F, 0x01, 0xC8, 1, P4++, , , 0, , , , , , , "Set Up Monitor Address") \
decOP( MOV       , AL          , moffs8      ,        , ,      ,     ,     , 0xA0,     , , , , , , , , , , , , "Move") \
decOP( MOV       , eAX         , moffsWD     ,        , ,      ,     ,     , 0xA1,     , , , , , , , , , , , , "Move") \
decOP( MOV       , moffs8      , AL          ,        , ,      ,     ,     , 0xA2,     , , , , , , , , , , , , "Move") \
decOP( MOV       , moffsWD     , eAX         ,        , ,      ,     ,     , 0xA3,     , , , , , , , , , , , , "Move") \
decOP( MOV       , rm8         , r8          ,        , ,      ,     ,     , 0x88,     , r, , , , , , , , , , , "Move") \
decOP( MOV       , rmWD        , rWD         ,        , ,      ,     ,     , 0x89,     , r, , , , , , , , , , , "Move") \
decOP( MOV       , r8          , rm8         ,        , ,      ,     ,     , 0x8A,     , r, , , , , , , , , , , "Move") \
decOP( MOV       , rWD         , rmWD        ,        , ,      ,     ,     , 0x8B,     , r, , , , , , , , , , , "Move") \
decOP( MOV       , rmWD        , Sreg        ,        , ,      ,     ,     , 0x8C,     , r, , , , , , , , , , , "Move") \
decOP( MOV       , Sreg        , rmWD        ,        , ,      ,     ,     , 0x8E,     , r, , , , , , , , , , , "Move") \
decOP( MOV       , r8          , imm8        ,        , ,      ,     ,     , 0xB0,     , s, , , , , , , , , , , "Move") \
decOP( MOV       , rWD         , immWD       ,        , ,      ,     ,     , 0xB8,     , s, , , , , , , , , , , "Move") \
decOP( MOV       , rm8         , imm8        ,        , ,      ,     ,     , 0xC6,     , 0, , , , , , , , , , , "Move") \
decOP( MOV       , rmWD        , immWD       ,        , ,      ,     ,     , 0xC7,     , 0, , , , , , , , , , , "Move") \
decOP( MOV       , r32         , CRn         ,        , ,      ,     , 0x0F, 0x20,     , r, 03+, , , 0, , , oooszapc, , oooszapc, , "Move toofrom Control Registers") \
decOP( MOV       , r32         , CRn         ,        , ,      ,     , 0x0F, 0x20,     , r, 03+, U15, , 0, , , oooszapc, , oooszapc, , "Move toofrom Control Registers") \
decOP( MOV       , r32         , DRn         ,        , ,      ,     , 0x0F, 0x21,     , r, 03+, , , 0, , , oooszapc, , oooszapc, , "Move toofrom Debug Registers") \
decOP( MOV       , r32         , DRn         ,        , ,      ,     , 0x0F, 0x21,     , r, 03+, U15, , 0, , , oooszapc, , oooszapc, , "Move toofrom Debug Registers") \
decOP( MOV       , CRn         , r32         ,        , ,      ,     , 0x0F, 0x22,     , r, 03+, , , 0, , , oooszapc, , oooszapc, , "Move toofrom Control Registers") \
decOP( MOV       , CRn         , r32         ,        , ,      ,     , 0x0F, 0x22,     , r, 03+, U15, , 0, , , oooszapc, , oooszapc, , "Move toofrom Control Registers") \
decOP( MOV       , DRn         , r32         ,        , ,      ,     , 0x0F, 0x23,     , r, 03+, , , 0, , , oooszapc, , oooszapc, , "Move toofrom Debug Registers") \
decOP( MOV       , DRn         , r32         ,        , ,      ,     , 0x0F, 0x23,     , r, 03+, U15, , 0, , , oooszapc, , oooszapc, , "Move toofrom Debug Registers") \
decOP( MOVAPD    , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x28,     , r, P4+, , , , , , , , , , "Move Aligned Packed Double-FP Values") \
decOP( MOVAPD    , Xm128       , xmm         ,        , , sse2 , 0x66, 0x0F, 0x29,     , r, P4+, , , , , , , , , , "Move Aligned Packed Double-FP Values") \
decOP( MOVAPS    , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x28,     , r, P3+, , , , , , , , , , "Move Aligned Packed Single-FP Values") \
decOP( MOVAPS    , Xm128       , xmm         ,        , , sse1 ,     , 0x0F, 0x29,     , r, P3+, , , , , , , , , , "Move Aligned Packed Single-FP Values") \
decOP( MOVD      , mm          , rm32        ,        , , mmx  ,     , 0x0F, 0x6E,     , r, PX+, , , , , , , , , , "Move Doubleword") \
decOP( MOVD      , rm32        , mm          ,        , , mmx  ,     , 0x0F, 0x7E,     , r, PX+, , , , , , , , , , "Move Doubleword") \
decOP( MOVDDUP   , xmm         , Xm64        ,        , , sse3 , 0xF2, 0x0F, 0x12,     , r, P4++, , , , , , , , , , "Move One Double-FP and Duplicate") \
decOP( MOVDQ2Q   , mm          , xmm         ,        , , sse2 , 0xF2, 0x0F, 0xD6,     , r, P4+, , , , , , , , , , "Move Quadword from XMM to MMX Technology Register") \
decOP( MOVDQA    , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x6F,     , r, P4+, , , , , , , , , , "Move Aligned Double Quadword") \
decOP( MOVDQA    , Xm128       , xmm         ,        , , sse2 , 0x66, 0x0F, 0x7F,     , r, P4+, , , , , , , , , , "Move Aligned Double Quadword") \
decOP( MOVDQU    , xmm         , Xm128       ,        , , sse2 , 0xF3, 0x0F, 0x6F,     , r, P4+, , , , , , , , , , "Move Unaligned Double Quadword") \
decOP( MOVDQU    , Xm128       , xmm         ,        , , sse2 , 0xF3, 0x0F, 0x7F,     , r, P4+, , , , , , , , , , "Move Unaligned Double Quadword") \
decOP( MOVHLPS   , xmm         , xmm         ,        , , sse1 ,     , 0x0F, 0x12,     , r, P3+, , , , , , , , , , "Move Packed Single-FP Values High to Low") \
decOP( MOVHPD    , xmm         , m64         ,        , , sse2 , 0x66, 0x0F, 0x16,     , r, P4+, , , , , , , , , , "Move High Packed Double-FP Value") \
decOP( MOVHPD    , m64         , xmm         ,        , , sse2 , 0x66, 0x0F, 0x17,     , r, P4+, , , , , , , , , , "Move High Packed Double-FP Value") \
decOP( MOVHPS    , xmm         , m64         ,        , , sse1 ,     , 0x0F, 0x16,     , r, P3+, , , , , , , , , , "Move High Packed Single-FP Values") \
decOP( MOVHPS    , m64         , xmm         ,        , , sse1 ,     , 0x0F, 0x17,     , r, P3+, , , , , , , , , , "Move High Packed Single-FP Values") \
decOP( MOVLHPS   , xmm         , xmm         ,        , , sse1 ,     , 0x0F, 0x16,     , r, P3+, , , , , , , , , , "Move Packed Single-FP Values Low to High") \
decOP( MOVLPD    , xmm         , m64         ,        , , sse2 , 0x66, 0x0F, 0x12,     , r, P4+, , , , , , , , , , "Move Low Packed Double-FP Value") \
decOP( MOVLPD    , m64         , xmm         ,        , , sse2 , 0x66, 0x0F, 0x13,     , r, P4+, , , , , , , , , , "Move Low Packed Double-FP Value") \
decOP( MOVLPS    , xmm         , m64         ,        , , sse1 ,     , 0x0F, 0x12,     , r, P3+, , , , , , , , , , "Move Low Packed Single-FP Values") \
decOP( MOVLPS    , m64         , xmm         ,        , , sse1 ,     , 0x0F, 0x13,     , r, P3+, , , , , , , , , , "Move Low Packed Single-FP Values") \
decOP( MOVMSKPD  , r32         , xmm         ,        , , sse2 , 0x66, 0x0F, 0x50,     , r, P4+, , , , , , , , , , "Extract Packed Double-FP Sign Mask") \
decOP( MOVMSKPS  , r32         , xmm         ,        , , sse1 ,     , 0x0F, 0x50,     , r, P3+, , , , , , , , , , "Extract Packed Single-FP Sign Mask") \
decOP( MOVNTDQ   , m128        , xmm         ,        , , sse2 , 0x66, 0x0F, 0xE7,     , r, P4+, , , , , , , , , , "Store Double Quadword Using Non-Temporal Hint") \
decOP( MOVNTI    , m32         , r32         ,        , , sse2 ,     , 0x0F, 0xC3,     , r, P4+, , , , , , , , , , "Store Doubleword Using Non-Temporal Hint") \
decOP( MOVNTPD   , m128        , xmm         ,        , , sse2 , 0x66, 0x0F, 0x2B,     , r, P4+, , , , , , , , , , "Store Packed Double-FP Values Using Non-Temporal Hint") \
decOP( MOVNTPS   , m128        , xmm         ,        , , sse1 ,     , 0x0F, 0x2B,     , r, P3+, , , , , , , , , , "Store Packed Single-FP Values Using Non-Temporal Hint") \
decOP( MOVNTQ    , m64         , mm          ,        , , sse1 ,     , 0x0F, 0xE7,     , r, P3+, , , , , , , , , , "Store of Quadword Using Non-Temporal Hint") \
decOP( MOVQ      , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x6F,     , r, PX+, , , , , , , , , , "Move Quadword") \
decOP( MOVQ      , Mm64        , mm          ,        , , mmx  ,     , 0x0F, 0x7F,     , r, PX+, , , , , , , , , , "Move Quadword") \
decOP( MOVQ2DQ   , xmm         , mm          ,        , , sse2 , 0xF3, 0x0F, 0xD6,     , r, P4+, , , , , , , , , , "Move Quadword from MMX Technology to XMM Register") \
decOP( MOVS      , m8          , m8          ,        , ,      ,     ,     , 0xA4,     , , , , , , , odoooooo, , , , , "Move Data from String to String") \
decOP( MOVSB     , m8          , m8          ,        , ,      ,     ,     , 0xA4,     , , , , , , , odoooooo, , , , , "Move Data from String to String") \
decOP( MOVS      , m16         , m16         ,        , ,      ,     ,     , 0xA5,     , , , , , , , odoooooo, , , , , "Move Data from String to String") \
decOP( MOVSW     , m16         , m16         ,        , ,      ,     ,     , 0xA5,     , , , , , , , odoooooo, , , , , "Move Data from String to String") \
decOP( MOVS      , mWD         , mWD         ,        , ,      ,     ,     , 0xA5,     , , 03+, , , , , odoooooo, , , , , "Move Data from String to String") \
decOP( MOVSD     , m32         , m32         ,        , ,      ,     ,     , 0xA5,     , , 03+, , , , , odoooooo, , , , , "Move Data from String to String") \
decOP( MOVSD     , xmm         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x10,     , r, P4+, , , , , , , , , , "Move Scalar Double-FP Value") \
decOP( MOVSD     , Xm64        , xmm         ,        , , sse2 , 0xF2, 0x0F, 0x11,     , r, P4+, , , , , , , , , , "Move Scalar Double-FP Value") \
decOP( MOVSHDUP  , xmm         , Xm64        ,        , , sse3 , 0xF3, 0x0F, 0x16,     , r, P4++, , , , , , , , , , "Move Packed Single-FP High and Duplicate") \
decOP( MOVSLDUP  , xmm         , Xm64        ,        , , sse3 , 0xF3, 0x0F, 0x12,     , r, P4++, , , , , , , , , , "Move Packed Single-FP Low and Duplicate") \
decOP( MOVSS     , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x10,     , r, P3+, , , , , , , , , , "Move Scalar Single-FP Values") \
decOP( MOVSS     , Xm32        , xmm         ,        , , sse1 , 0xF3, 0x0F, 0x11,     , r, P3+, , , , , , , , , , "Move Scalar Single-FP Values") \
decOP( MOVSX     , rWD         , rm8         ,        , ,      ,     , 0x0F, 0xBE,     , r, 03+, , , , , , , , , , "Move with Sign-Extension") \
decOP( MOVSX     , rWD         , rm16        ,        , ,      ,     , 0x0F, 0xBF,     , r, 03+, , , , , , , , , , "Move with Sign-Extension") \
decOP( MOVUPD    , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x10,     , r, P4+, , , , , , , , , , "Move Unaligned Packed Double-FP Value") \
decOP( MOVUPD    , Xm128       , xmm         ,        , , sse2 , 0x66, 0x0F, 0x11,     , r, P4+, , , , , , , , , , "Move Unaligned Packed Double-FP Values") \
decOP( MOVUPS    , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x10,     , r, P3+, , , , , , , , , , "Move Unaligned Packed Single-FP Values") \
decOP( MOVUPS    , Xm128       , xmm         ,        , , sse1 ,     , 0x0F, 0x11,     , r, P3+, , , , , , , , , , "Move Unaligned Packed Single-FP Values") \
decOP( MOVZX     , rWD         , rm8         ,        , ,      ,     , 0x0F, 0xB6,     , r, 03+, , , , , , , , , , "Move with Zero-Extend") \
decOP( MOVZX     , rWD         , rm16        ,        , ,      ,     , 0x0F, 0xB7,     , r, 03+, , , , , , , , , , "Move with Zero-Extend") \
decOP( MUL       , AX          , AL          , rm8    , ,      ,     ,     , 0xF6,     , 4, , , , , , , oooszapc, oooooooc, oooszapo, , "Unsigned Multiply") \
decOP( MUL       , eDX         , eAX         , rmWD   , ,      ,     ,     , 0xF7,     , 4, , , , , , , oooszapc, oooooooc, oooszapo, , "Unsigned Multiply") \
decOP( MULPD     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x59,     , r, P4+, , , , , , , , , , "Multiply Packed Double-FP Values") \
decOP( MULPS     , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x59,     , r, P3+, , , , , , , , , , "Multiply Packed Single-FP Values") \
decOP( MULSD     , xmm         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x59,     , r, P4+, , , , , , , , , , "Multiply Scalar Double-FP Values") \
decOP( MULSS     , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x59,     , r, P3+, , , , , , , , , , "Multiply Scalar Single-FP Value") \
decOP( MWAIT     , EAX         , ECX         ,        , , sse3 ,     , 0x0F, 0x01, 0xC9, 1, P4++, , , 0, , , , , , , "Monitor Wait") \
decOP( NEG       , rm8         ,             ,        , ,      ,     ,     , 0xF6,     , 3, , , , , , , oooszapc, oooszapc, , , "Two's Complement Negation") \
decOP( NEG       , rmWD        ,             ,        , ,      ,     ,     , 0xF7,     , 3, , , , , , , oooszapc, oooszapc, , , "Two's Complement Negation") \
decOP( NOP       ,             ,             ,        , ,      ,     ,     , 0x90,     , , , , , , , , , , , , "No Operation") \
decOP( NOP       , rmWD        ,             ,        , ,      ,     , 0x0F, 0x0D,     , , PP+, M14, , , , , , , , , "No Operation") \
decOP( NOP       , rmWD        ,             ,        , ,      ,     , 0x0F, 0x1F,     , , P4++, , , , , , , , , , "No Operation") \
decOP( NOT       , rm8         ,             ,        , ,      ,     ,     , 0xF6,     , 2, , , , , , , , , , , "One's Complement Negation") \
decOP( NOT       , rmWD        ,             ,        , ,      ,     ,     , 0xF7,     , 2, , , , , , , , , , , "One's Complement Negation") \
decOP( NTAKEN    ,             ,             ,        , ,      , 0x2E,     ,     ,     , , P4+, , , , , , , , , , "Branch not taken prefix (used only with Jcc instructions)") \
decOP( OR        , rm8         , r8          ,        , ,      ,     ,     , 0x08,     , r, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( OR        , rmWD        , rWD         ,        , ,      ,     ,     , 0x09,     , r, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( OR        , r8          , rm8         ,        , ,      ,     ,     , 0x0A,     , r, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( OR        , rWD         , rmWD        ,        , ,      ,     ,     , 0x0B,     , r, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( OR        , AL          , imm8        ,        , ,      ,     ,     , 0x0C,     , , , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( OR        , eAX         , immWD       ,        , ,      ,     ,     , 0x0D,     , , , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( OR        , rm8         , imm8        ,        , ,      ,     ,     , 0x80,     , 1, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( OR        , rmWD        , immWD       ,        , ,      ,     ,     , 0x81,     , 1, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( OR        , rm8         , imm8        ,        , ,      ,     ,     , 0x82,     , 1, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( OR        , rmWD        , imm8        ,        , ,      ,     ,     , 0x83,     , 1, 03+, , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Inclusive OR") \
decOP( ORPD      , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x56,     , r, P4+, , , , , , , , , , "Bitwise Logical OR of Double-FP Values") \
decOP( ORPS      , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x56,     , r, P3+, , , , , , , , , , "Bitwise Logical OR of Single-FP Values") \
decOP( OUT       , imm8        , AL          ,        , ,      ,     ,     , 0xE6,     , , , , , f1, , , , , , , "Output to Port") \
decOP( OUT       , imm8        , eAX         ,        , ,      ,     ,     , 0xE7,     , , , , , f1, , , , , , , "Output to Port") \
decOP( OUT       , DX          , AL          ,        , ,      ,     ,     , 0xEE,     , , , , , f1, , , , , , , "Output to Port") \
decOP( OUT       , DX          , eAX         ,        , ,      ,     ,     , 0xEF,     , , , , , f1, , , , , , , "Output to Port") \
decOP( OUTS      , DX          , m8          ,        , ,      ,     ,     , 0x6E,     , , 01+, , , f1, , odoooooo, , , , , "Output String to Port") \
decOP( OUTSB     , DX          , m8          ,        , ,      ,     ,     , 0x6E,     , , 01+, , , f1, , odoooooo, , , , , "Output String to Port") \
decOP( OUTS      , DX          , m16         ,        , ,      ,     ,     , 0x6F,     , , 01+, , , f1, , odoooooo, , , , , "Output String to Port") \
decOP( OUTSW     , DX          , m16         ,        , ,      ,     ,     , 0x6F,     , , 01+, , , f1, , odoooooo, , , , , "Output String to Port") \
decOP( OUTS      , DX          , mWD         ,        , ,      ,     ,     , 0x6F,     , , 03+, , , f1, , odoooooo, , , , , "Output String to Port") \
decOP( OUTSD     , DX          , m32         ,        , ,      ,     ,     , 0x6F,     , , 03+, , , f1, , odoooooo, , , , , "Output String to Port") \
decOP( PABSB     , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x1C, r, C2+, , , , , , , , , , "Packed Absolute Value") \
decOP( PABSB     , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x1C, r, C2+, , , , , , , , , , "Packed Absolute Value") \
decOP( PABSD     , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x1E, r, C2+, , , , , , , , , , "Packed Absolute Value") \
decOP( PABSD     , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x1E, r, C2+, , , , , , , , , , "Packed Absolute Value") \
decOP( PABSW     , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x1D, r, C2+, , , , , , , , , , "Packed Absolute Value") \
decOP( PABSW     , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x1D, r, C2+, , , , , , , , , , "Packed Absolute Value") \
decOP( PACKSSDW  , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x6B,     , r, PX+, , , , , , , , , , "Pack with Signed Saturation") \
decOP( PACKSSWB  , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x63,     , r, PX+, , , , , , , , , , "Pack with Signed Saturation") \
decOP( PACKUSWB  , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x67,     , r, PX+, , , , , , , , , , "Pack with Unsigned Saturation") \
decOP( PADDB     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xFC,     , r, PX+, , , , , , , , , , "Add Packed Integers") \
decOP( PADDD     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xFE,     , r, PX+, , , , , , , , , , "Add Packed Integers") \
decOP( PADDQ     , mm          , Mm64        ,        , , sse2 ,     , 0x0F, 0xD4,     , r, P4+, , , , , , , , , , "Add Packed Quadword Integers") \
decOP( PADDQ     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0xD4,     , r, P4+, , , , , , , , , , "Add Packed Quadword Integers") \
decOP( PADDSB    , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xEC,     , r, PX+, , , , , , , , , , "Add Packed Signed Integers with Signed Saturation") \
decOP( PADDSW    , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xED,     , r, PX+, , , , , , , , , , "Add Packed Signed Integers with Signed Saturation") \
decOP( PADDUSB   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xDC,     , r, PX+, , , , , , , , , , "Add Packed Unsigned Integers with Unsigned Saturation") \
decOP( PADDUSW   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xDD,     , r, PX+, , , , , , , , , , "Add Packed Unsigned Integers with Unsigned Saturation") \
decOP( PADDW     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xFD,     , r, PX+, , , , , , , , , , "Add Packed Integers") \
decOP( PALIGNR   , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x3A, 0x0F, r, C2+, , , , , , , , , , "Packed Align Right") \
decOP( PALIGNR   , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x3A, 0x0F, r, C2+, , , , , , , , , , "Packed Align Right") \
decOP( PAND      , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xDB,     , r, PX+, , , , , , , , , , "Logical AND") \
decOP( PANDN     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xDF,     , r, PX+, , , , , , , , , , "Logical AND NOT") \
decOP( PAUSE     ,             ,             ,        , , sse2 , 0xF3,     , 0x90,     , , P4+, , , , , , , , , , "Spin Loop Hint") \
decOP( PAVGB     , mm          , Mm64        ,        , , sse1 ,     , 0x0F, 0xE0,     , r, P3+, , , , , , , , , , "Average Packed Integers") \
decOP( PAVGB     , xmm         , Xm128       ,        , , sse1 , 0x66, 0x0F, 0xE0,     , r, P3+, , , , , , , , , , "Average Packed Integers") \
decOP( PAVGW     , mm          , Mm64        ,        , , sse1 ,     , 0x0F, 0xE3,     , r, P3+, , , , , , , , , , "Average Packed Integers") \
decOP( PAVGW     , xmm         , Xm128       ,        , , sse1 , 0x66, 0x0F, 0xE3,     , r, P3+, , , , , , , , , , "Average Packed Integers") \
decOP( PCMPEQB   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x74,     , r, PX+, , , , , , , , , , "Compare Packed Data for Equal") \
decOP( PCMPEQD   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x76,     , r, PX+, , , , , , , , , , "Compare Packed Data for Equal") \
decOP( PCMPEQW   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x75,     , r, PX+, , , , , , , , , , "Compare Packed Data for Equal") \
decOP( PCMPGTB   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x64,     , r, PX+, , , , , , , , , , "Compare Packed Signed Integers for Greater Than") \
decOP( PCMPGTD   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x66,     , r, PX+, , , , , , , , , , "Compare Packed Signed Integers for Greater Than") \
decOP( PCMPGTW   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x65,     , r, PX+, , , , , , , , , , "Compare Packed Signed Integers for Greater Than") \
decOP( PEXTRW    , r32         , mm          , imm8   , , sse1 ,     , 0x0F, 0xC5,     , r, P3+, , , , , , , , , , "Extract Word") \
decOP( PEXTRW    , r32         , xmm         , imm8   , , sse1 , 0x66, 0x0F, 0xC5,     , r, P3+, , , , , , , , , , "Extract Word") \
decOP( PHADDD    , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x02, r, C2+, , , , , , , , , , "Packed Horizontal Add") \
decOP( PHADDD    , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x02, r, C2+, , , , , , , , , , "Packed Horizontal Add") \
decOP( PHADDSW   , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x03, r, C2+, , , , , , , , , , "Packed Horizontal Add and Saturate") \
decOP( PHADDSW   , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x03, r, C2+, , , , , , , , , , "Packed Horizontal Add and Saturate") \
decOP( PHADDW    , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x01, r, C2+, , , , , , , , , , "Packed Horizontal Add") \
decOP( PHADDW    , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x01, r, C2+, , , , , , , , , , "Packed Horizontal Add") \
decOP( PHSUBD    , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x06, r, C2+, , , , , , , , , , "Packed Horizontal Subtract") \
decOP( PHSUBD    , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x06, r, C2+, , , , , , , , , , "Packed Horizontal Subtract") \
decOP( PHSUBSW   , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x07, r, C2+, , , , , , , , , , "Packed Horizontal Subtract and Saturate") \
decOP( PHSUBSW   , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x07, r, C2+, , , , , , , , , , "Packed Horizontal Subtract and Saturate") \
decOP( PHSUBW    , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x05, r, C2+, , , , , , , , , , "Packed Horizontal Subtract") \
decOP( PHSUBW    , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x05, r, C2+, , , , , , , , , , "Packed Horizontal Subtract") \
decOP( PINSRW    , mm          , r32         , imm8   , , sse1 ,     , 0x0F, 0xC4,     , r, P3+, , , , , , , , , , "Insert Word") \
decOP( PINSRW    , mm          , m16         , imm8   , , sse1 ,     , 0x0F, 0xC4,     , r, P3+, , , , , , , , , , "Insert Word") \
decOP( PINSRW    , xmm         , r32         , imm8   , , sse1 , 0x66, 0x0F, 0xC4,     , r, P3+, , , , , , , , , , "Insert Word") \
decOP( PINSRW    , xmm         , m16         , imm8   , , sse1 , 0x66, 0x0F, 0xC4,     , r, P3+, , , , , , , , , , "Insert Word") \
decOP( PMADDUBSW , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x04, r, C2+, , , , , , , , , , "Multiply and Add Packed Signed and Unsigned Bytes") \
decOP( PMADDUBSW , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x04, r, C2+, , , , , , , , , , "Multiply and Add Packed Signed and Unsigned Bytes") \
decOP( PMADDWD   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xF5,     , r, PX+, , , , , , , , , , "Multiply and Add Packed Integers") \
decOP( PMAXSW    , mm          , Mm64        ,        , , sse1 ,     , 0x0F, 0xEE,     , r, P3+, , , , , , , , , , "Maximum of Packed Signed Word Integers") \
decOP( PMAXSW    , xmm         , Xm128       ,        , , sse1 , 0x66, 0x0F, 0xEE,     , r, P3+, , , , , , , , , , "Maximum of Packed Signed Word Integers") \
decOP( PMAXUB    , mm          , Mm64        ,        , , sse1 ,     , 0x0F, 0xDE,     , r, P3+, , , , , , , , , , "Maximum of Packed Unsigned Byte Integers") \
decOP( PMAXUB    , xmm         , Xm128       ,        , , sse1 , 0x66, 0x0F, 0xDE,     , r, P3+, , , , , , , , , , "Maximum of Packed Unsigned Byte Integers") \
decOP( PMINSW    , mm          , Mm64        ,        , , sse1 ,     , 0x0F, 0xEA,     , r, P3+, , , , , , , , , , "Minimum of Packed Signed Word Integers") \
decOP( PMINSW    , xmm         , Xm128       ,        , , sse1 , 0x66, 0x0F, 0xEA,     , r, P3+, , , , , , , , , , "Minimum of Packed Signed Word Integers") \
decOP( PMINUB    , mm          , Mm64        ,        , , sse1 ,     , 0x0F, 0xDA,     , r, P3+, , , , , , , , , , "Minimum of Packed Unsigned Byte Integers") \
decOP( PMINUB    , xmm         , Xm128       ,        , , sse1 , 0x66, 0x0F, 0xDA,     , r, P3+, , , , , , , , , , "Minimum of Packed Unsigned Byte Integers") \
decOP( PMOVMSKB  , r32         , mm          ,        , , sse1 ,     , 0x0F, 0xD7,     , r, P3+, , , , , , , , , , "Move Byte Mask") \
decOP( PMOVMSKB  , r32         , xmm         ,        , , sse1 , 0x66, 0x0F, 0xD7,     , r, P3+, , , , , , , , , , "Move Byte Mask") \
decOP( PMULHRSW  , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x0B, r, C2+, , , , , , , , , , "Packed Multiply High with Round and Scale") \
decOP( PMULHRSW  , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x0B, r, C2+, , , , , , , , , , "Packed Multiply High with Round and Scale") \
decOP( PMULHUW   , mm          , Mm64        ,        , , sse1 ,     , 0x0F, 0xE4,     , r, P3+, , , , , , , , , , "Multiply Packed Unsigned Integers and Store High Result") \
decOP( PMULHUW   , xmm         , Xm128       ,        , , sse1 , 0x66, 0x0F, 0xE4,     , r, P3+, , , , , , , , , , "Multiply Packed Unsigned Integers and Store High Result") \
decOP( PMULHW    , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xE5,     , r, PX+, , , , , , , , , , "Multiply Packed Signed Integers and Store High Result") \
decOP( PMULLW    , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xD5,     , r, PX+, , , , , , , , , , "Multiply Packed Signed Integers and Store Low Result") \
decOP( PMULUDQ   , mm          , Mm64        ,        , , sse2 ,     , 0x0F, 0xF4,     , r, P4+, , , , , , , , , , "Multiply Packed Unsigned DW Integers") \
decOP( PMULUDQ   , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0xF4,     , r, P4+, , , , , , , , , , "Multiply Packed Unsigned DW Integers") \
decOP( POP       , ES          ,             ,        , ,      ,     ,     , 0x07,     , , , , , , , , , , , , "Pop a Value from the Stack") \
decOP( POP       , SS          ,             ,        , ,      ,     ,     , 0x17,     , , , , , , , , , , , , "Pop a Value from the Stack") \
decOP( POP       , DS          ,             ,        , ,      ,     ,     , 0x1F,     , , , , , , , , , , , , "Pop a Value from the Stack") \
decOP( POP       , rWD         ,             ,        , ,      ,     ,     , 0x58,     , s, , , , , , , , , , , "Pop a Value from the Stack") \
decOP( POP       , rmWD        ,             ,        , ,      ,     ,     , 0x8F,     , 0, , , , , , , , , , , "Pop a Value from the Stack") \
decOP( POP       , FS          ,             ,        , ,      ,     , 0x0F, 0xA1,     , , 03+, , , , , , , , , , "Pop a Value from the Stack") \
decOP( POP       , GS          ,             ,        , ,      ,     , 0x0F, 0xA9,     , , 03+, , , , , , , , , , "Pop a Value from the Stack") \
decOP( POPA      , DI          , SI          , BP     , ooo ,      ,     ,     , 0x61,     , , 01+, , , , , , , , , , "Pop All General-Purpose Registers") \
decOP( POPA      , DI          , SI          , BP     , ooo ,      ,     ,     , 0x61,     , , 03+, , , , , , , , , , "Pop All General-Purpose Registers") \
decOP( POPAD     , EDI         , ESI         , EBP    , ooo ,      ,     ,     , 0x61,     , , 03+, , , , , , , , , , "Pop All General-Purpose Registers") \
decOP( POPF      , Flags       ,             ,        , ,      ,     ,     , 0x9D,     , , , , , , , , odiszapc, odiszapc, , , "Pop Stack into FLAGS Register") \
decOP( POPF      , Flags       ,             ,        , ,      ,     ,     , 0x9D,     , , 03+, , , , , , odiszapc, odiszapc, , , "Pop Stack into eFLAGS Register") \
decOP( POPFD     , EFlags      ,             ,        , ,      ,     ,     , 0x9D,     , , 03+, , , , , , odiszapc, odiszapc, , , "Pop Stack into eFLAGS Register") \
decOP( POR       , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xEB,     , r, PX+, , , , , , , , , , "Bitwise Logical OR") \
decOP( PREFETCHNTA, m8          ,             ,        , , sse1 ,     , 0x0F, 0x18,     , 0, P3+, , , , , , , , , , "Prefetch Data Into Caches") \
decOP( PREFETCHT0, m8          ,             ,        , , sse1 ,     , 0x0F, 0x18,     , 1, P3+, , , , , , , , , , "Prefetch Data Into Caches") \
decOP( PREFETCHT1, m8          ,             ,        , , sse1 ,     , 0x0F, 0x18,     , 2, P3+, , , , , , , , , , "Prefetch Data Into Caches") \
decOP( PREFETCHT2, m8          ,             ,        , , sse1 ,     , 0x0F, 0x18,     , 3, P3+, , , , , , , , , , "Prefetch Data Into Caches") \
decOP( PSADBW    , mm          , Mm64        ,        , , sse1 ,     , 0x0F, 0xF6,     , r, P3+, , , , , , , , , , "Compute Sum of Absolute Differences") \
decOP( PSADBW    , xmm         , Xm128       ,        , , sse1 , 0x66, 0x0F, 0xF6,     , r, P3+, , , , , , , , , , "Compute Sum of Absolute Differences") \
decOP( PSHUFB    , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x00, r, C2+, , , , , , , , , , "Packed Shuffle Bytes") \
decOP( PSHUFB    , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x00, r, C2+, , , , , , , , , , "Packed Shuffle Bytes") \
decOP( PSHUFD    , xmm         , Xm128       , imm8   , , sse2 , 0x66, 0x0F, 0x70,     , r, P4+, , , , , , , , , , "Shuffle Packed Doublewords") \
decOP( PSHUFHW   , xmm         , Xm128       , imm8   , , sse2 , 0xF3, 0x0F, 0x70,     , r, P4+, , , , , , , , , , "Shuffle Packed High Words") \
decOP( PSHUFLW   , xmm         , Xm128       , imm8   , , sse2 , 0xF2, 0x0F, 0x70,     , r, P4+, , , , , , , , , , "Shuffle Packed Low Words") \
decOP( PSHUFW    , mm          , Mm64        , imm8   , , sse1 ,     , 0x0F, 0x70,     , r, P3+, , , , , , , , , , "Shuffle Packed Words") \
decOP( PSIGNB    , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x08, r, C2+, , , , , , , , , , "Packed SIGN") \
decOP( PSIGNB    , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x08, r, C2+, , , , , , , , , , "Packed SIGN") \
decOP( PSIGND    , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x0A, r, C2+, , , , , , , , , , "Packed SIGN") \
decOP( PSIGND    , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x0A, r, C2+, , , , , , , , , , "Packed SIGN") \
decOP( PSIGNW    , mm          , Mm64        ,        , , ssse3,     , 0x0F, 0x38, 0x09, r, C2+, , , , , , , , , , "Packed SIGN") \
decOP( PSIGNW    , xmm         , Xm128       ,        , , ssse3, 0x66, 0x0F, 0x38, 0x09, r, C2+, , , , , , , , , , "Packed SIGN") \
decOP( PSLLD     , mm          , imm8        ,        , , mmx  ,     , 0x0F, 0x72,     , 6, PX+, , , , , , , , , , "Shift Packed Data Left Logical") \
decOP( PSLLD     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xF2,     , r, PX+, , , , , , , , , , "Shift Packed Data Left Logical") \
decOP( PSLLDQ    , xmm         , imm8        ,        , , sse2 , 0x66, 0x0F, 0x73,     , 7, P4+, , , , , , , , , , "Shift Double Quadword Left Logical") \
decOP( PSLLQ     , mm          , imm8        ,        , , mmx  ,     , 0x0F, 0x73,     , 6, PX+, , , , , , , , , , "Shift Packed Data Left Logical") \
decOP( PSLLQ     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xF3,     , r, PX+, , , , , , , , , , "Shift Packed Data Left Logical") \
decOP( PSLLW     , mm          , imm8        ,        , , mmx  ,     , 0x0F, 0x71,     , 6, PX+, , , , , , , , , , "Shift Packed Data Left Logical") \
decOP( PSLLW     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xF1,     , r, PX+, , , , , , , , , , "Shift Packed Data Left Logical") \
decOP( PSRAD     , mm          , imm8        ,        , , mmx  ,     , 0x0F, 0x72,     , 4, PX+, , , , , , , , , , "Shift Packed Data Right Arithmetic") \
decOP( PSRAD     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xE2,     , r, PX+, , , , , , , , , , "Shift Packed Data Right Arithmetic") \
decOP( PSRAW     , mm          , imm8        ,        , , mmx  ,     , 0x0F, 0x71,     , 4, PX+, , , , , , , , , , "Shift Packed Data Right Arithmetic") \
decOP( PSRAW     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xE1,     , r, PX+, , , , , , , , , , "Shift Packed Data Right Arithmetic") \
decOP( PSRLD     , mm          , imm8        ,        , , mmx  ,     , 0x0F, 0x72,     , 2, PX+, , , , , , , , , , "Shift Double Quadword Right Logical") \
decOP( PSRLD     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xD2,     , r, PX+, , , , , , , , , , "Shift Packed Data Right Logical") \
decOP( PSRLDQ    , xmm         , imm8        ,        , , sse2 , 0x66, 0x0F, 0x73,     , 3, P4+, , , , , , , , , , "Shift Double Quadword Right Logical") \
decOP( PSRLQ     , mm          , imm8        ,        , , mmx  ,     , 0x0F, 0x73,     , 2, PX+, , , , , , , , , , "Shift Packed Data Right Logical") \
decOP( PSRLQ     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xD3,     , r, PX+, , , , , , , , , , "Shift Packed Data Right Logical") \
decOP( PSRLW     , mm          , imm8        ,        , , mmx  ,     , 0x0F, 0x71,     , 2, PX+, , , , , , , , , , "Shift Packed Data Right Logical") \
decOP( PSRLW     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xD1,     , r, PX+, , , , , , , , , , "Shift Packed Data Right Logical") \
decOP( PSUBB     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xF8,     , r, PX+, , , , , , , , , , "Subtract Packed Integers") \
decOP( PSUBD     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xFA,     , r, PX+, , , , , , , , , , "Subtract Packed Integers") \
decOP( PSUBQ     , mm          , Mm64        ,        , , sse2 ,     , 0x0F, 0xFB,     , r, P4+, , , , , , , , , , "Subtract Packed Quadword Integers") \
decOP( PSUBQ     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0xFB,     , r, P4+, , , , , , , , , , "Subtract Packed Quadword Integers") \
decOP( PSUBSB    , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xE8,     , r, PX+, , , , , , , , , , "Subtract Packed Signed Integers with Signed Saturation") \
decOP( PSUBSW    , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xE9,     , r, PX+, , , , , , , , , , "Subtract Packed Signed Integers with Signed Saturation") \
decOP( PSUBUSB   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xD8,     , r, PX+, , , , , , , , , , "Subtract Packed Unsigned Integers with Unsigned Saturation") \
decOP( PSUBUSW   , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xD9,     , r, PX+, , , , , , , , , , "Subtract Packed Unsigned Integers with Unsigned Saturation") \
decOP( PSUBW     , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xF9,     , r, PX+, , , , , , , , , , "Subtract Packed Integers") \
decOP( PUNPCKHBW , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x68,     , r, PX+, , , , , , , , , , "Unpack High Data") \
decOP( PUNPCKHDQ , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x6A,     , r, PX+, , , , , , , , , , "Unpack High Data") \
decOP( PUNPCKHQDQ, xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x6D,     , r, P4+, , , , , , , , , , "Unpack High Data") \
decOP( PUNPCKHWD , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x69,     , r, PX+, , , , , , , , , , "Unpack High Data") \
decOP( PUNPCKLBW , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x60,     , r, PX+, , , , , , , , , , "Unpack Low Data") \
decOP( PUNPCKLDQ , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x62,     , r, PX+, , , , , , , , , , "Unpack Low Data") \
decOP( PUNPCKLQDQ, xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x6C,     , r, P4+, , , , , , , , , , "Unpack Low Data") \
decOP( PUNPCKLWD , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0x61,     , r, PX+, , , , , , , , , , "Unpack Low Data") \
decOP( PUSH      , ES          ,             ,        , ,      ,     ,     , 0x06,     , , , , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSH      , CS          ,             ,        , ,      ,     ,     , 0x0E,     , , , , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSH      , SS          ,             ,        , ,      ,     ,     , 0x16,     , , , , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSH      , DS          ,             ,        , ,      ,     ,     , 0x1E,     , , , , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSH      , rWD         ,             ,        , ,      ,     ,     , 0x50,     , s, , , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSH      , immWD       ,             ,        , ,      ,     ,     , 0x68,     , , 01+, , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSH      , imm8        ,             ,        , ,      ,     ,     , 0x6A,     , , 01+, , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSH      , rmWD        ,             ,        , ,      ,     ,     , 0xFF,     , 6, , , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSH      , FS          ,             ,        , ,      ,     , 0x0F, 0xA0,     , , 03+, , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSH      , GS          ,             ,        , ,      ,     , 0x0F, 0xA8,     , , 03+, , , , , , , , , , "Push Word, Doubleword or Quadword Onto the Stack") \
decOP( PUSHA     , AX          , CX          , DX     , ooo ,      ,     ,     , 0x60,     , , 01+, , , , , , , , , , "Push All General-Purpose Registers") \
decOP( PUSHA     , AX          , CX          , DX     , ooo ,      ,     ,     , 0x60,     , , 03+, , , , , , , , , , "Push All General-Purpose Registers") \
decOP( PUSHAD    , EAX         , ECX         , EDX    , ooo ,      ,     ,     , 0x60,     , , 03+, , , , , , , , , , "Push All General-Purpose Registers") \
decOP( PUSHF     , Flags       ,             ,        , ,      ,     ,     , 0x9C,     , , , , , , , odiszapc, , , , , "Push FLAGS Register onto the Stack") \
decOP( PUSHF     , Flags       ,             ,        , ,      ,     ,     , 0x9C,     , , 03+, , , , , odiszapc, , , , , "Push eFLAGS Register onto the Stack") \
decOP( PUSHFD    , EFlags      ,             ,        , ,      ,     ,     , 0x9C,     , , 03+, , , , , odiszapc, , , , , "Push eFLAGS Register onto the Stack") \
decOP( PXOR      , mm          , Mm64        ,        , , mmx  ,     , 0x0F, 0xEF,     , r, PX+, , , , , , , , , , "Logical Exclusive OR") \
decOP( RCL       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 2, 01+, , , , , oooooooc, oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( RCL       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 2, 01+, , , , , oooooooc, oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( RCL       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 2, , , , , , oooooooc, oooszapc, oooszapc, , , "Rotate") \
decOP( RCL       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 2, , , , , , oooooooc, oooszapc, oooszapc, , , "Rotate") \
decOP( RCL       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 2, , , , , , oooooooc, oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( RCL       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 2, , , , , , oooooooc, oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( RCPPS     , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x53,     , r, P3+, , , , , , , , , , "Compute Reciprocals of Packed Single-FP Values") \
decOP( RCPSS     , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x53,     , r, P3+, , , , , , , , , , "Compute Reciprocal of Scalar Single-FP Values") \
decOP( RCR       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 3, 01+, , , , , oooooooc, oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( RCR       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 3, 01+, , , , , oooooooc, oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( RCR       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 3, , , , , , oooooooc, oooszapc, oooszapc, , , "Rotate") \
decOP( RCR       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 3, , , , , , oooooooc, oooszapc, oooszapc, , , "Rotate") \
decOP( RCR       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 3, , , , , , oooooooc, oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( RCR       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 3, , , , , , oooooooc, oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( RDMSR     , eAX         , eDX         , eCX    , MSR,      ,     , 0x0F, 0x32,     , , P1+, , , 0, , , , , , , "Read from Model Specific Register") \
decOP( RDPMC     , EAX         , EDX         , PMC    , ,      ,     , 0x0F, 0x33,     , , PX+, , , f3, , , , , , , "Read Performance-Monitoring Counters") \
decOP( RDTSC     , EAX         , EDX         , IA32_Tooo, ,      ,     , 0x0F, 0x31,     , , P1+, , , f2, , , , , , , "Read Time-Stamp Counter") \
decOP( REP       , eCX         ,             ,        , ,      , 0xF2,     ,     ,     , , , U, , , , , , , , , "Repeat String Operation Prefix") \
decOP( REP       , eCX         ,             ,        , ,      , 0xF3,     ,     ,     , , , , , , , , , , , , "Repeat String Operation Prefix") \
decOP( REPNZ     , eCX         ,             ,        , ,      , 0xF2,     ,     ,     , , , , , , , oooozooo, , , , , "Repeat String Operation Prefix") \
decOP( REPNE     , eCX         ,             ,        , ,      , 0xF2,     ,     ,     , , , , , , , oooozooo, , , , , "Repeat String Operation Prefix") \
decOP( REPZ      , eCX         ,             ,        , ,      , 0xF3,     ,     ,     , , , , , , , oooozooo, , , , , "Repeat String Operation Prefix") \
decOP( REPE      , eCX         ,             ,        , ,      , 0xF3,     ,     ,     , , , , , , , oooozooo, , , , , "Repeat String Operation Prefix") \
decOP( RETF      , i16         ,             ,        , ,      ,     ,     , 0xCA,     , , , , , f, , , , , , , "Return from procedure") \
decOP( RETF      ,             ,             ,        , ,      ,     ,     , 0xCB,     , , , , , f, , , , , , , "Return from procedure") \
decOP( RETN      , i16         ,             ,        , ,      ,     ,     , 0xC2,     , , , , , , , , , , , , "Return from procedure") \
decOP( RETN      ,             ,             ,        , ,      ,     ,     , 0xC3,     , , , , , , , , , , , , "Return from procedure") \
decOP( ROL       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 0, 01+, , , , , , oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( ROL       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 0, 01+, , , , , , oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( ROL       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 0, , , , , , , oooszapc, oooszapc, , , "Rotate") \
decOP( ROL       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 0, , , , , , , oooszapc, oooszapc, , , "Rotate") \
decOP( ROL       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 0, , , , , , , oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( ROL       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 0, , , , , , , oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( ROR       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 1, 01+, , , , , , oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( ROR       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 1, 01+, , , , , , oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( ROR       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 1, , , , , , , oooszapc, oooszapc, , , "Rotate") \
decOP( ROR       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 1, , , , , , , oooszapc, oooszapc, , , "Rotate") \
decOP( ROR       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 1, , , , , , , oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( ROR       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 1, , , , , , , oooszapc, oooszapc, oooooooo, , "Rotate") \
decOP( RSM       , Flags       ,             ,        , ,      ,     , 0x0F, 0xAA,     , , 03++, , S, , , , odiszapc, odiszapc, , , "Resume from System Management Mode") \
decOP( RSQRTPS   , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x52,     , r, P3+, , , , , , , , , , "Compute Reciprocals of Square Roots of Packed Single-FP Values") \
decOP( RSQRTSS   , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x52,     , r, P3+, , , , , , , , , , "Compute Reciprocal of Square Root of Scalar Single-FP Value") \
decOP( SAHF      , AH          ,             ,        , ,      ,     ,     , 0x9E,     , , , , , , , , oooszapc, oooszapc, , , "Store AH into Flags") \
decOP( SAL       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 6, 01+, U2, , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHL       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 6, 01+, U2, , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SAL       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 6, 01+, U2, , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHL       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 6, 01+, U2, , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SAL       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 6, , U2, , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SHL       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 6, , U2, , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SAL       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 6, , U2, , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SHL       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 6, , U2, , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SAL       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 6, , U2, , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHL       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 6, , U2, , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SAL       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 6, , U2, , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHL       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 6, , U2, , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SALC      , AL          ,             ,        , ,      ,     ,     , 0xD6,     , , 02+, U3, , , , oooooooc, , , , , "Set AL If Carry") \
decOP( SETALC    , AL          ,             ,        , ,      ,     ,     , 0xD6,     , , 02+, U3, , , , oooooooc, , , , , "Set AL If Carry") \
decOP( SAR       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 7, 01+, , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SAR       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 7, 01+, , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SAR       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 7, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SAR       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 7, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SAR       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 7, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SAR       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 7, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SBB       , rm8         , r8          ,        , ,      ,     ,     , 0x18,     , r, , , , , L, oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SBB       , rmWD        , rWD         ,        , ,      ,     ,     , 0x19,     , r, , , , , L, oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SBB       , r8          , rm8         ,        , ,      ,     ,     , 0x1A,     , r, , , , , , oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SBB       , rWD         , rmWD        ,        , ,      ,     ,     , 0x1B,     , r, , , , , , oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SBB       , AL          , imm8        ,        , ,      ,     ,     , 0x1C,     , , , , , , , oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SBB       , eAX         , immWD       ,        , ,      ,     ,     , 0x1D,     , , , , , , , oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SBB       , rm8         , imm8        ,        , ,      ,     ,     , 0x80,     , 3, , , , , L, oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SBB       , rmWD        , immWD       ,        , ,      ,     ,     , 0x81,     , 3, , , , , L, oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SBB       , rm8         , imm8        ,        , ,      ,     ,     , 0x82,     , 3, , , , , L, oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SBB       , rmWD        , imm8        ,        , ,      ,     ,     , 0x83,     , 3, , , , , L, oooooooc, oooszapc, oooszapc, , , "Integer Subtraction with Borrow") \
decOP( SCAS      , m8          , AL          ,        , ,      ,     ,     , 0xAE,     , , , , , , , odoooooo, oooszapc, oooszapc, , , "Scan String") \
decOP( SCASB     , m8          , AL          ,        , ,      ,     ,     , 0xAE,     , , , , , , , odoooooo, oooszapc, oooszapc, , , "Scan String") \
decOP( SCAS      , m16         , AX          ,        , ,      ,     ,     , 0xAF,     , , , , , , , odoooooo, oooszapc, oooszapc, , , "Scan String") \
decOP( SCASW     , m16         , AX          ,        , ,      ,     ,     , 0xAF,     , , , , , , , odoooooo, oooszapc, oooszapc, , , "Scan String") \
decOP( SCAS      , mWD         , eAX         ,        , ,      ,     ,     , 0xAF,     , , 03+, , , , , odoooooo, oooszapc, oooszapc, , , "Scan String") \
decOP( SCASD     , m32         , EAX         ,        , ,      ,     ,     , 0xAF,     , , 03+, , , , , odoooooo, oooszapc, oooszapc, , , "Scan String") \
decOP( SETB      , rm8         ,             ,        , ,      ,     , 0x0F, 0x92,     , 0, 03+, D17, , , , oooooooc, , , , , "Set Byte on Condition - belowonot above or equalocarry (CF=1)") \
decOP( SETNAE    , rm8         ,             ,        , ,      ,     , 0x0F, 0x92,     , 0, 03+, D17, , , , oooooooc, , , , , "Set Byte on Condition - belowonot above or equalocarry (CF=1)") \
decOP( SETC      , rm8         ,             ,        , ,      ,     , 0x0F, 0x92,     , 0, 03+, D17, , , , oooooooc, , , , , "Set Byte on Condition - belowonot above or equalocarry (CF=1)") \
decOP( SETBE     , rm8         ,             ,        , ,      ,     , 0x0F, 0x96,     , 0, 03+, D17, , , , oooozooc, , , , , "Set Byte on Condition - below or equalonot above (CF=1 AND ZF=1)") \
decOP( SETNA     , rm8         ,             ,        , ,      ,     , 0x0F, 0x96,     , 0, 03+, D17, , , , oooozooc, , , , , "Set Byte on Condition - below or equalonot above (CF=1 AND ZF=1)") \
decOP( SETL      , rm8         ,             ,        , ,      ,     , 0x0F, 0x9C,     , 0, 03+, D17, , , , ooosoooo, , , , , "Set Byte on Condition - lessonot greater (SF!=OF)") \
decOP( SETNGE    , rm8         ,             ,        , ,      ,     , 0x0F, 0x9C,     , 0, 03+, D17, , , , ooosoooo, , , , , "Set Byte on Condition - lessonot greater (SF!=OF)") \
decOP( SETLE     , rm8         ,             ,        , ,      ,     , 0x0F, 0x9E,     , 0, 03+, D17, , , , oooszooo, , , , , "Set Byte on Condition - less or equalonot greater ((ZF=1) OR (SF!=OF))") \
decOP( SETNG     , rm8         ,             ,        , ,      ,     , 0x0F, 0x9E,     , 0, 03+, D17, , , , oooszooo, , , , , "Set Byte on Condition - less or equalonot greater ((ZF=1) OR (SF!=OF))") \
decOP( SETNB     , rm8         ,             ,        , ,      ,     , 0x0F, 0x93,     , 0, 03+, D17, , , , oooooooc, , , , , "Set Byte on Condition - not belowoabove or equalonot carry (CF=0)") \
decOP( SETAE     , rm8         ,             ,        , ,      ,     , 0x0F, 0x93,     , 0, 03+, D17, , , , oooooooc, , , , , "Set Byte on Condition - not belowoabove or equalonot carry (CF=0)") \
decOP( SETNC     , rm8         ,             ,        , ,      ,     , 0x0F, 0x93,     , 0, 03+, D17, , , , oooooooc, , , , , "Set Byte on Condition - not belowoabove or equalonot carry (CF=0)") \
decOP( SETNBE    , rm8         ,             ,        , ,      ,     , 0x0F, 0x97,     , 0, 03+, D17, , , , oooozooc, , , , , "Set Byte on Condition - not below or equaloabove (CF=0 AND ZF=0)") \
decOP( SETA      , rm8         ,             ,        , ,      ,     , 0x0F, 0x97,     , 0, 03+, D17, , , , oooozooc, , , , , "Set Byte on Condition - not below or equaloabove (CF=0 AND ZF=0)") \
decOP( SETNL     , rm8         ,             ,        , ,      ,     , 0x0F, 0x9D,     , 0, 03+, D17, , , , ooosoooo, , , , , "Set Byte on Condition - not lessogreater or equal (SF=OF)") \
decOP( SETGE     , rm8         ,             ,        , ,      ,     , 0x0F, 0x9D,     , 0, 03+, D17, , , , ooosoooo, , , , , "Set Byte on Condition - not lessogreater or equal (SF=OF)") \
decOP( SETNLE    , rm8         ,             ,        , ,      ,     , 0x0F, 0x9F,     , 0, 03+, D17, , , , oooszooo, , , , , "Set Byte on Condition - not less nor equalogreater ((ZF=0) AND (SF=OF))") \
decOP( SETG      , rm8         ,             ,        , ,      ,     , 0x0F, 0x9F,     , 0, 03+, D17, , , , oooszooo, , , , , "Set Byte on Condition - not less nor equalogreater ((ZF=0) AND (SF=OF))") \
decOP( SETNO     , rm8         ,             ,        , ,      ,     , 0x0F, 0x91,     , 0, 03+, D17, , , , oooooooo, , , , , "Set Byte on Condition - not overflow (OF=0)") \
decOP( SETNP     , rm8         ,             ,        , ,      ,     , 0x0F, 0x9B,     , 0, 03+, D17, , , , oooooopo, , , , , "Set Byte on Condition - not parityoparity odd") \
decOP( SETPO     , rm8         ,             ,        , ,      ,     , 0x0F, 0x9B,     , 0, 03+, D17, , , , oooooopo, , , , , "Set Byte on Condition - not parityoparity odd") \
decOP( SETNS     , rm8         ,             ,        , ,      ,     , 0x0F, 0x99,     , 0, 03+, D17, , , , ooosoooo, , , , , "Set Byte on Condition - not sign (SF=0)") \
decOP( SETNZ     , rm8         ,             ,        , ,      ,     , 0x0F, 0x95,     , 0, 03+, D17, , , , oooozooo, , , , , "Set Byte on Condition - not zeroonot equal (ZF=1)") \
decOP( SETNE     , rm8         ,             ,        , ,      ,     , 0x0F, 0x95,     , 0, 03+, D17, , , , oooozooo, , , , , "Set Byte on Condition - not zeroonot equal (ZF=1)") \
decOP( SETO      , rm8         ,             ,        , ,      ,     , 0x0F, 0x90,     , 0, 03+, D17, , , , oooooooo, , , , , "Set Byte on Condition - overflow (OF=1)") \
decOP( SETP      , rm8         ,             ,        , ,      ,     , 0x0F, 0x9A,     , 0, 03+, D17, , , , oooooopo, , , , , "Set Byte on Condition - parityoparity even (PF=1)") \
decOP( SETPE     , rm8         ,             ,        , ,      ,     , 0x0F, 0x9A,     , 0, 03+, D17, , , , oooooopo, , , , , "Set Byte on Condition - parityoparity even (PF=1)") \
decOP( SETS      , rm8         ,             ,        , ,      ,     , 0x0F, 0x98,     , 0, 03+, D17, , , , ooosoooo, , , , , "Set Byte on Condition - sign (SF=1)") \
decOP( SETZ      , rm8         ,             ,        , ,      ,     , 0x0F, 0x94,     , 0, 03+, D17, , , , oooozooo, , , , , "Set Byte on Condition - zerooequal (ZF=0)") \
decOP( SETE      , rm8         ,             ,        , ,      ,     , 0x0F, 0x94,     , 0, 03+, D17, , , , oooozooo, , , , , "Set Byte on Condition - zerooequal (ZF=0)") \
decOP( SFENCE    ,             ,             ,        , , sse1 ,     , 0x0F, 0xAE,     , 7, P3+, , , , , , , , , , "Store Fence") \
decOP( SGDT      , m           , GDTR        ,        , ,      ,     , 0x0F, 0x01,     , 0, 02+, , , , , , , , , , "Store Global Descriptor Table Register") \
decOP( SHL       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 4, 01+, , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SAL       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 4, 01+, , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHL       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 4, 01+, , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SAL       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 4, 01+, , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHL       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 4, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SAL       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 4, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SHL       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 4, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SAL       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 4, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SHL       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 4, , , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SAL       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 4, , , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHL       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 4, , , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SAL       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 4, , , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHLD      , rmWD        , rWD         , imm8   , ,      ,     , 0x0F, 0xA4,     , , 03+, , , , , , oooszapc, oooszopc, oooooaoc, , "Double Precision Shift Left") \
decOP( SHLD      , rmWD        , rWD         , CL     , ,      ,     , 0x0F, 0xA5,     , , 03+, , , , , , oooszapc, oooszopc, oooooaoc, , "Double Precision Shift Left") \
decOP( SHR       , rm8         , imm8        ,        , ,      ,     ,     , 0xC0,     , 5, 01+, , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHR       , rmWD        , imm8        ,        , ,      ,     ,     , 0xC1,     , 5, 01+, , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHR       , rm8         , 1           ,        , ,      ,     ,     , 0xD0,     , 5, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SHR       , rmWD        , 1           ,        , ,      ,     ,     , 0xD1,     , 5, , , , , , , oooszapc, oooszopc, oooooaoo, , "Shift") \
decOP( SHR       , rm8         , CL          ,        , ,      ,     ,     , 0xD2,     , 5, , , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHR       , rmWD        , CL          ,        , ,      ,     ,     , 0xD3,     , 5, , , , , , , oooszapc, oooszopc, oooooaoc, , "Shift") \
decOP( SHRD      , rmWD        , rWD         , imm8   , ,      ,     , 0x0F, 0xAC,     , , 03+, , , , , , oooszapc, oooszopc, oooooaoc, , "Double Precision Shift Right") \
decOP( SHRD      , rmWD        , rWD         , CL     , ,      ,     , 0x0F, 0xAD,     , , 03+, , , , , , oooszapc, oooszopc, oooooaoc, , "Double Precision Shift Right") \
decOP( SHUFPD    , xmm         , Xm128       , imm8   , , sse2 , 0x66, 0x0F, 0xC6,     , r, P4+, , , , , , , , , , "Shuffle Packed Double-FP Values") \
decOP( SHUFPS    , xmm         , Xm128       , imm8   , , sse1 ,     , 0x0F, 0xC6,     , r, P3+, , , , , , , , , , "Shuffle Packed Single-FP Values") \
decOP( SIDT      , m           , IDTR        ,        , ,      ,     , 0x0F, 0x01,     , 1, 02+, , , , , , , , , , "Store Interrupt Descriptor Table Register") \
decOP( SLDT      , m16         , LDTR        ,        , ,      ,     , 0x0F, 0x00,     , 0, 02+, , P, , , , , , , , "Store Local Descriptor Table Register") \
decOP( SLDT      , rWD         , LDTR        ,        , ,      ,     , 0x0F, 0x00,     , 0, 02+, , P, , , , , , , , "Store Local Descriptor Table Register") \
decOP( SMSW      , m16         , MSW         ,        , ,      ,     , 0x0F, 0x01,     , 4, 02+, , , , , , , , , , "Store Machine Status Word") \
decOP( SMSW      , rWD         , MSW         ,        , ,      ,     , 0x0F, 0x01,     , 4, 02+, , , , , , , , , , "Store Machine Status Word") \
decOP( SQRTPD    , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x51,     , r, P4+, , , , , , , , , , "Compute Square Roots of Packed Double-FP Values") \
decOP( SQRTPS    , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x51,     , r, P3+, , , , , , , , , , "Compute Square Roots of Packed Single-FP Values") \
decOP( SQRTSD    , xmm         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x51,     , r, P4+, , , , , , , , , , "Compute Square Root of Scalar Double-FP Value") \
decOP( SQRTSS    , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x51,     , r, P3+, , , , , , , , , , "Compute Square Root of Scalar Single-FP Value") \
decOP( SS        , SS          ,             ,        , ,      , 0x36,     ,     ,     , , , , , , , , , , , , "SS segment override prefix") \
decOP( STC       ,             ,             ,        , ,      ,     ,     , 0xF9,     , , , , , , , , oooooooc, oooooooc, , oooooooC, "Set Carry Flag") \
decOP( STD       ,             ,             ,        , ,      ,     ,     , 0xFD,     , , , , , , , , odoooooo, odoooooo, , oDoooooo, "Set Direction Flag") \
decOP( STI       ,             ,             ,        , ,      ,     ,     , 0xFB,     , , , , , f1, , , ooiooooo, ooiooooo, , ooIooooo, "Set Interrupt Flag") \
decOP( STMXCSR   , m32         ,             ,        , , sse1 ,     , 0x0F, 0xAE,     , 3, P3+, , , , , , , , , , "Store MXCSR Register State") \
decOP( STOS      , m8          , AL          ,        , ,      ,     ,     , 0xAA,     , , , , , , , odoooooo, , , , , "Store String") \
decOP( STOSB     , m8          , AL          ,        , ,      ,     ,     , 0xAA,     , , , , , , , odoooooo, , , , , "Store String") \
decOP( STOS      , m16         , AX          ,        , ,      ,     ,     , 0xAB,     , , , , , , , odoooooo, , , , , "Store String") \
decOP( STOSW     , m16         , AX          ,        , ,      ,     ,     , 0xAB,     , , , , , , , odoooooo, , , , , "Store String") \
decOP( STOS      , mWD         , eAX         ,        , ,      ,     ,     , 0xAB,     , , 03+, , , , , odoooooo, , , , , "Store String") \
decOP( STOSD     , m32         , EAX         ,        , ,      ,     ,     , 0xAB,     , , 03+, , , , , odoooooo, , , , , "Store String") \
decOP( STR       , m16         , TR          ,        , ,      ,     , 0x0F, 0x00,     , 1, 02+, , P, , , , , , , , "Store Task Register") \
decOP( STR       , rWD         , TR          ,        , ,      ,     , 0x0F, 0x00,     , 1, 02+, , P, , , , , , , , "Store Task Register") \
decOP( SUB       , rm8         , r8          ,        , ,      ,     ,     , 0x28,     , r, , , , , L, , oooszapc, oooszapc, , , "Subtract") \
decOP( SUB       , rmWD        , rWD         ,        , ,      ,     ,     , 0x29,     , r, , , , , L, , oooszapc, oooszapc, , , "Subtract") \
decOP( SUB       , r8          , rm8         ,        , ,      ,     ,     , 0x2A,     , r, , , , , , , oooszapc, oooszapc, , , "Subtract") \
decOP( SUB       , rWD         , rmWD        ,        , ,      ,     ,     , 0x2B,     , r, , , , , , , oooszapc, oooszapc, , , "Subtract") \
decOP( SUB       , AL          , imm8        ,        , ,      ,     ,     , 0x2C,     , , , , , , , , oooszapc, oooszapc, , , "Subtract") \
decOP( SUB       , eAX         , immWD       ,        , ,      ,     ,     , 0x2D,     , , , , , , , , oooszapc, oooszapc, , , "Subtract") \
decOP( SUB       , rm8         , imm8        ,        , ,      ,     ,     , 0x80,     , 5, , , , , L, , oooszapc, oooszapc, , , "Subtract") \
decOP( SUB       , rmWD        , immWD       ,        , ,      ,     ,     , 0x81,     , 5, , , , , L, , oooszapc, oooszapc, , , "Subtract") \
decOP( SUB       , rm8         , imm8        ,        , ,      ,     ,     , 0x82,     , 5, , , , , L, , oooszapc, oooszapc, , , "Subtract") \
decOP( SUB       , rmWD        , imm8        ,        , ,      ,     ,     , 0x83,     , 5, , , , , L, , oooszapc, oooszapc, , , "Subtract") \
decOP( SUBPD     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x5C,     , r, P4+, , , , , , , , , , "Subtract Packed Double-FP Values") \
decOP( SUBPS     , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x5C,     , r, P3+, , , , , , , , , , "Subtract Packed Single-FP Values") \
decOP( SUBSD     , xmm         , Xm64        ,        , , sse2 , 0xF2, 0x0F, 0x5C,     , r, P4+, , , , , , , , , , "Subtract Scalar Double-FP Values") \
decOP( SUBSS     , xmm         , Xm32        ,        , , sse1 , 0xF3, 0x0F, 0x5C,     , r, P3+, , , , , , , , , , "Subtract Scalar Single-FP Values") \
decOP( SYSENTER  , IA32_SYSooo , IA32_SYSEooo, IA32_Sooo, ,      ,     , 0x0F, 0x34,     , , P2+, D16, P, , , , ooiooooo, ooiooooo, , ooiooooo, "Fast System Call") \
decOP( SYSEXIT   , IA32_SYSooo , eCX         , eDX    , ,      ,     , 0x0F, 0x35,     , , P2+, , P, 0, , , , , , , "Fast Return from Fast System Call") \
decOP( TAKEN     ,             ,             ,        , ,      , 0x3E,     ,     ,     , , P4+, , , , , , , , , , "Branch taken prefix (used only with Jcc instructions)") \
decOP( TEST      , rm8         , r8          ,        , ,      ,     ,     , 0x84,     , r, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Compare") \
decOP( TEST      , rmWD        , rWD         ,        , ,      ,     ,     , 0x85,     , r, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Compare") \
decOP( TEST      , AL          , imm8        ,        , ,      ,     ,     , 0xA8,     , , , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Compare") \
decOP( TEST      , eAX         , immWD       ,        , ,      ,     ,     , 0xA9,     , , , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Compare") \
decOP( TEST      , rm8         , imm8        ,        , ,      ,     ,     , 0xF6,     , 0, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Compare") \
decOP( TEST      , rm8         , imm8        ,        , ,      ,     ,     , 0xF6,     , 1, , U13, , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Compare") \
decOP( TEST      , rmWD        , immWD       ,        , ,      ,     ,     , 0xF7,     , 0, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Compare") \
decOP( TEST      , rmWD        , immWD       ,        , ,      ,     ,     , 0xF7,     , 1, , U13, , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Compare") \
decOP( UCOMISD   , xmm         , Xm64        ,        , , sse2 , 0x66, 0x0F, 0x2E,     , r, P4+, , , , , , oooozopc, oooozopc, , , "Unordered Compare Scalar Double-FP Values and Set EFLAGS") \
decOP( UCOMISS   , xmm         , Xm32        ,        , , sse1 ,     , 0x0F, 0x2E,     , r, P3+, , , , , , oooozopc, oooozopc, , , "Unordered Compare Scalar Single-FP Values and Set EFLAGS") \
decOP( UD        , r           , rm          ,        , ,      ,     , 0x0F, 0xB9,     , , 02+, M18, , , , , , , , , "Undefined Instruction") \
decOP( UD2       ,             ,             ,        , ,      ,     , 0x0F, 0x0B,     , , 02+, , , , , , , , , , "Undefined Instruction") \
decOP( UNPCKHPD  , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x15,     , r, P4+, , , , , , , , , , "Unpack and Interleave High Packed Double-FP Values") \
decOP( UNPCKHPS  , xmm         , Xm64        ,        , , sse1 ,     , 0x0F, 0x15,     , r, P3+, , , , , , , , , , "Unpack and Interleave High Packed Single-FP Values") \
decOP( UNPCKLPD  , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x14,     , r, P4+, , , , , , , , , , "Unpack and Interleave Low Packed Double-FP Values") \
decOP( UNPCKLPS  , xmm         , Xm64        ,        , , sse1 ,     , 0x0F, 0x14,     , r, P3+, , , , , , , , , , "Unpack and Interleave Low Packed Single-FP Values") \
decOP( VERR      , rm16        ,             ,        , ,      ,     , 0x0F, 0x00,     , 4, 02+, , P, , , , oooozooo, oooozooo, , , "Verify a Segment for Reading") \
decOP( VERW      , rm16        ,             ,        , ,      ,     , 0x0F, 0x00,     , 5, 02+, , P, , , , oooozooo, oooozooo, , , "Verify a Segment for Writing") \
decOP( WBINVD    ,             ,             ,        , ,      ,     , 0x0F, 0x09,     , , 04+, , , 0, , , , , , , "Write Back and Invalidate Cache") \
decOP( WRMSR     , MSR         , eCX         , eAX    , eDX,      ,     , 0x0F, 0x30,     , , P1+, , , 0, , , , , , , "Write to Model Specific Register") \
decOP( XADD      , rm8         , r8          ,        , ,      ,     , 0x0F, 0xC0,     , r, 04+, , , , L, , oooszapc, oooszapc, , , "Exchange and Add") \
decOP( XADD      , rmWD        , rWD         ,        , ,      ,     , 0x0F, 0xC1,     , r, 04+, , , , L, , oooszapc, oooszapc, , , "Exchange and Add") \
decOP( XCHG      , r8          , rm8         ,        , ,      ,     ,     , 0x86,     , r, , , , , L, , , , , , "Exchange RegisteroMemory with Register") \
decOP( XCHG      , rWD         , rmWD        ,        , ,      ,     ,     , 0x87,     , r, , , , , L, , , , , , "Exchange RegisteroMemory with Register") \
decOP( XCHG      , rWD         , eAX         ,        , ,      ,     ,     , 0x90,     , s, , , , , , , , , , , "Exchange RegisteroMemory with Register") \
decOP( XLAT      , AL          , m           ,        , ,      ,     ,     , 0xD7,     , , , , , , , , , , , , "Table Look-up Translation") \
decOP( XLATB     , AL          , m           ,        , ,      ,     ,     , 0xD7,     , , , , , , , , , , , , "Table Look-up Translation") \
decOP( XOR       , rm8         , r8          ,        , ,      ,     ,     , 0x30,     , r, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XOR       , rmWD        , rWD         ,        , ,      ,     ,     , 0x31,     , r, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XOR       , r8          , rm8         ,        , ,      ,     ,     , 0x32,     , r, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XOR       , rWD         , rmWD        ,        , ,      ,     ,     , 0x33,     , r, , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XOR       , AL          , imm8        ,        , ,      ,     ,     , 0x34,     , , , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XOR       , eAX         , immWD       ,        , ,      ,     ,     , 0x35,     , , , , , , , , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XOR       , rm8         , imm8        ,        , ,      ,     ,     , 0x80,     , 6, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XOR       , rmWD        , immWD       ,        , ,      ,     ,     , 0x81,     , 6, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XOR       , rm8         , imm8        ,        , ,      ,     ,     , 0x82,     , 6, , , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XOR       , rmWD        , imm8        ,        , ,      ,     ,     , 0x83,     , 6, 03+, , , , L, , oooszapc, oooszopc, oooooaoo, oooooooc, "Logical Exclusive OR") \
decOP( XORPD     , xmm         , Xm128       ,        , , sse2 , 0x66, 0x0F, 0x57,     , r, P4+, , , , , , , , , , "Bitwise Logical XOR for Double-FP Values") \
decOP( XORPS     , xmm         , Xm128       ,        , , sse1 ,     , 0x0F, 0x57,     , r, P3+, , , , , , , , , , "Bitwise Logical XOR for Single-FP Values") \

#define opNameList32_(opName) \
opName( AAA ) \
opName( AAD ) \
opName( AAM ) \
opName( AAS ) \
opName( ADC ) \
opName( ADD ) \
opName( ADDPD ) \
opName( ADDPS ) \
opName( ADDSD ) \
opName( ADDSS ) \
opName( ADDSUBPD ) \
opName( ADDSUBPS ) \
opName( ADX ) \
opName( ALTER ) \
opName( AMX ) \
opName( AND ) \
opName( ANDNPD ) \
opName( ANDNPS ) \
opName( ANDPD ) \
opName( ANDPS ) \
opName( ARPL ) \
opName( BOUND ) \
opName( BSF ) \
opName( BSR ) \
opName( BSWAP ) \
opName( BT ) \
opName( BTC ) \
opName( BTR ) \
opName( BTS ) \
opName( CALL ) \
opName( CALLF ) \
opName( CBW ) \
opName( CDQ ) \
opName( CLC ) \
opName( CLD ) \
opName( CLFLUSH ) \
opName( CLI ) \
opName( CLTS ) \
opName( CMC ) \
opName( CMOVA ) \
opName( CMOVAE ) \
opName( CMOVB ) \
opName( CMOVBE ) \
opName( CMOVC ) \
opName( CMOVE ) \
opName( CMOVG ) \
opName( CMOVGE ) \
opName( CMOVL ) \
opName( CMOVLE ) \
opName( CMOVNA ) \
opName( CMOVNAE ) \
opName( CMOVNB ) \
opName( CMOVNBE ) \
opName( CMOVNC ) \
opName( CMOVNE ) \
opName( CMOVNG ) \
opName( CMOVNGE ) \
opName( CMOVNL ) \
opName( CMOVNLE ) \
opName( CMOVNO ) \
opName( CMOVNP ) \
opName( CMOVNS ) \
opName( CMOVNZ ) \
opName( CMOVO ) \
opName( CMOVP ) \
opName( CMOVPE ) \
opName( CMOVPO ) \
opName( CMOVS ) \
opName( CMOVZ ) \
opName( CMP ) \
opName( CMPPD ) \
opName( CMPPS ) \
opName( CMPS ) \
opName( CMPSB ) \
opName( CMPSD ) \
opName( CMPSS ) \
opName( CMPSW ) \
opName( CMPXCHG ) \
opName( CMPXCHG8B ) \
opName( COMISD ) \
opName( COMISS ) \
opName( CPUID ) \
opName( CS ) \
opName( CVTDQ2PD ) \
opName( CVTDQ2PS ) \
opName( CVTPD2DQ ) \
opName( CVTPD2PI ) \
opName( CVTPD2PS ) \
opName( CVTPI2PD ) \
opName( CVTPI2PS ) \
opName( CVTPS2DQ ) \
opName( CVTPS2PD ) \
opName( CVTPS2PI ) \
opName( CVTSD2SI ) \
opName( CVTSD2SS ) \
opName( CVTSI2SD ) \
opName( CVTSI2SS ) \
opName( CVTSS2SD ) \
opName( CVTSS2SI ) \
opName( CVTTPD2DQ ) \
opName( CVTTPD2PI ) \
opName( CVTTPS2DQ ) \
opName( CVTTPS2PI ) \
opName( CVTTSD2SI ) \
opName( CVTTSS2SI ) \
opName( CWD ) \
opName( CWDE ) \
opName( DAA ) \
opName( DAS ) \
opName( DEC ) \
opName( DIV ) \
opName( DIVPD ) \
opName( DIVPS ) \
opName( DIVSD ) \
opName( DIVSS ) \
opName( DS ) \
opName( EMMS ) \
opName( ENTER ) \
opName( ES ) \
opName( F2XM1 ) \
opName( FABS ) \
opName( FADD ) \
opName( FADDP ) \
opName( FBLD ) \
opName( FBSTP ) \
opName( FCHS ) \
opName( FCLEX ) \
opName( FCMOVB ) \
opName( FCMOVBE ) \
opName( FCMOVE ) \
opName( FCMOVNB ) \
opName( FCMOVNBE ) \
opName( FCMOVNE ) \
opName( FCMOVNU ) \
opName( FCMOVU ) \
opName( FCOM ) \
opName( FCOM2 ) \
opName( FCOMI ) \
opName( FCOMIP ) \
opName( FCOMP ) \
opName( FCOMP3 ) \
opName( FCOMP5 ) \
opName( FCOMPP ) \
opName( FCOS ) \
opName( FDECSTP ) \
opName( FDIV ) \
opName( FDIVP ) \
opName( FDIVR ) \
opName( FDIVRP ) \
opName( FFREE ) \
opName( FFREEP ) \
opName( FIADD ) \
opName( FICOM ) \
opName( FICOMP ) \
opName( FIDIV ) \
opName( FIDIVR ) \
opName( FILD ) \
opName( FIMUL ) \
opName( FINCSTP ) \
opName( FINIT ) \
opName( FIST ) \
opName( FISTP ) \
opName( FISTTP ) \
opName( FISUB ) \
opName( FISUBR ) \
opName( FLD ) \
opName( FLD1 ) \
opName( FLDCW ) \
opName( FLDENV ) \
opName( FLDL2E ) \
opName( FLDL2T ) \
opName( FLDLG2 ) \
opName( FLDLN2 ) \
opName( FLDPI ) \
opName( FLDZ ) \
opName( FMUL ) \
opName( FMULP ) \
opName( FNCLEX ) \
opName( FNINIT ) \
opName( FNOP ) \
opName( FNSAVE ) \
opName( FNSTCW ) \
opName( FNSTENV ) \
opName( FNSTSW ) \
opName( FPATAN ) \
opName( FPREM ) \
opName( FPREM1 ) \
opName( FPTAN ) \
opName( FRNDINT ) \
opName( FRSTOR ) \
opName( FS ) \
opName( FSAVE ) \
opName( FSCALE ) \
opName( FSIN ) \
opName( FSINCOS ) \
opName( FSQRT ) \
opName( FST ) \
opName( FSTCW ) \
opName( FSTENV ) \
opName( FSTP ) \
opName( FSTP1 ) \
opName( FSTP8 ) \
opName( FSTP9 ) \
opName( FSTSW ) \
opName( FSUB ) \
opName( FSUBP ) \
opName( FSUBR ) \
opName( FSUBRP ) \
opName( FTST ) \
opName( FUCOM ) \
opName( FUCOMI ) \
opName( FUCOMIP ) \
opName( FUCOMP ) \
opName( FUCOMPP ) \
opName( FWAIT ) \
opName( FXAM ) \
opName( FXCH ) \
opName( FXCH4 ) \
opName( FXCH7 ) \
opName( FXRSTOR ) \
opName( FXSAVE ) \
opName( FXTRACT ) \
opName( FYL2X ) \
opName( FYL2XP1 ) \
opName( GS ) \
opName( HADDPD ) \
opName( HADDPS ) \
opName( HLT ) \
opName( HSUBPD ) \
opName( HSUBPS ) \
opName( ICEBP ) \
opName( IDIV ) \
opName( IMUL ) \
opName( IN ) \
opName( INC ) \
opName( INS ) \
opName( INSB ) \
opName( INSD ) \
opName( INSW ) \
opName( INT ) \
opName( INT1 ) \
opName( INTO ) \
opName( INVD ) \
opName( INVLPG ) \
opName( IRET ) \
opName( IRETD ) \
opName( JA ) \
opName( JAE ) \
opName( JB ) \
opName( JBE ) \
opName( JC ) \
opName( JCXZ ) \
opName( JE ) \
opName( JECXZ ) \
opName( JG ) \
opName( JGE ) \
opName( JL ) \
opName( JLE ) \
opName( JMP ) \
opName( JMPF ) \
opName( JNA ) \
opName( JNAE ) \
opName( JNB ) \
opName( JNBE ) \
opName( JNC ) \
opName( JNE ) \
opName( JNG ) \
opName( JNGE ) \
opName( JNL ) \
opName( JNLE ) \
opName( JNO ) \
opName( JNP ) \
opName( JNS ) \
opName( JNZ ) \
opName( JO ) \
opName( JP ) \
opName( JPE ) \
opName( JPO ) \
opName( JS ) \
opName( JZ ) \
opName( LAHF ) \
opName( LAR ) \
opName( LDDQU ) \
opName( LDMXCSR ) \
opName( LDS ) \
opName( LEA ) \
opName( LEAVE ) \
opName( LES ) \
opName( LFENCE ) \
opName( LFS ) \
opName( LGDT ) \
opName( LGS ) \
opName( LIDT ) \
opName( LLDT ) \
opName( LMSW ) \
opName( LOCK ) \
opName( LODS ) \
opName( LODSB ) \
opName( LODSD ) \
opName( LODSW ) \
opName( LOOP ) \
opName( LOOPE ) \
opName( LOOPNE ) \
opName( LOOPNZ ) \
opName( LOOPZ ) \
opName( LSL ) \
opName( LSS ) \
opName( LTR ) \
opName( MASKMOVDQU ) \
opName( MASKMOVQ ) \
opName( MAXPD ) \
opName( MAXPS ) \
opName( MAXSD ) \
opName( MAXSS ) \
opName( MFENCE ) \
opName( MINPD ) \
opName( MINPS ) \
opName( MINSD ) \
opName( MINSS ) \
opName( MONITOR ) \
opName( MOV ) \
opName( MOVAPD ) \
opName( MOVAPS ) \
opName( MOVD ) \
opName( MOVDDUP ) \
opName( MOVDQ2Q ) \
opName( MOVDQA ) \
opName( MOVDQU ) \
opName( MOVHLPS ) \
opName( MOVHPD ) \
opName( MOVHPS ) \
opName( MOVLHPS ) \
opName( MOVLPD ) \
opName( MOVLPS ) \
opName( MOVMSKPD ) \
opName( MOVMSKPS ) \
opName( MOVNTDQ ) \
opName( MOVNTI ) \
opName( MOVNTPD ) \
opName( MOVNTPS ) \
opName( MOVNTQ ) \
opName( MOVQ ) \
opName( MOVQ2DQ ) \
opName( MOVS ) \
opName( MOVSB ) \
opName( MOVSD ) \
opName( MOVSHDUP ) \
opName( MOVSLDUP ) \
opName( MOVSS ) \
opName( MOVSW ) \
opName( MOVSX ) \
opName( MOVUPD ) \
opName( MOVUPS ) \
opName( MOVZX ) \
opName( MUL ) \
opName( MULPD ) \
opName( MULPS ) \
opName( MULSD ) \
opName( MULSS ) \
opName( MWAIT ) \
opName( NEG ) \
opName( nop ) \
opName( NOP ) \
opName( NOT ) \
opName( NTAKEN ) \
opName( OR ) \
opName( ORPD ) \
opName( ORPS ) \
opName( OUT ) \
opName( OUTS ) \
opName( OUTSB ) \
opName( OUTSD ) \
opName( OUTSW ) \
opName( PABSB ) \
opName( PABSD ) \
opName( PABSW ) \
opName( PACKSSDW ) \
opName( PACKSSWB ) \
opName( PACKUSWB ) \
opName( PADDB ) \
opName( PADDD ) \
opName( PADDQ ) \
opName( PADDSB ) \
opName( PADDSW ) \
opName( PADDUSB ) \
opName( PADDUSW ) \
opName( PADDW ) \
opName( PALIGNR ) \
opName( PAND ) \
opName( PANDN ) \
opName( PAUSE ) \
opName( PAVGB ) \
opName( PAVGW ) \
opName( PCMPEQB ) \
opName( PCMPEQD ) \
opName( PCMPEQW ) \
opName( PCMPGTB ) \
opName( PCMPGTD ) \
opName( PCMPGTW ) \
opName( PEXTRW ) \
opName( PHADDD ) \
opName( PHADDSW ) \
opName( PHADDW ) \
opName( PHSUBD ) \
opName( PHSUBSW ) \
opName( PHSUBW ) \
opName( PINSRW ) \
opName( PMADDUBSW ) \
opName( PMADDWD ) \
opName( PMAXSW ) \
opName( PMAXUB ) \
opName( PMINSW ) \
opName( PMINUB ) \
opName( PMOVMSKB ) \
opName( PMULHRSW ) \
opName( PMULHUW ) \
opName( PMULHW ) \
opName( PMULLW ) \
opName( PMULUDQ ) \
opName( POP ) \
opName( POPA ) \
opName( POPAD ) \
opName( POPF ) \
opName( POPFD ) \
opName( POR ) \
opName( PREFETCHNTA ) \
opName( PREFETCHT0 ) \
opName( PREFETCHT1 ) \
opName( PREFETCHT2 ) \
opName( PSADBW ) \
opName( PSHUFB ) \
opName( PSHUFD ) \
opName( PSHUFHW ) \
opName( PSHUFLW ) \
opName( PSHUFW ) \
opName( PSIGNB ) \
opName( PSIGND ) \
opName( PSIGNW ) \
opName( PSLLD ) \
opName( PSLLDQ ) \
opName( PSLLQ ) \
opName( PSLLW ) \
opName( PSRAD ) \
opName( PSRAW ) \
opName( PSRLD ) \
opName( PSRLDQ ) \
opName( PSRLQ ) \
opName( PSRLW ) \
opName( PSUBB ) \
opName( PSUBD ) \
opName( PSUBQ ) \
opName( PSUBSB ) \
opName( PSUBSW ) \
opName( PSUBUSB ) \
opName( PSUBUSW ) \
opName( PSUBW ) \
opName( PUNPCKHBW ) \
opName( PUNPCKHDQ ) \
opName( PUNPCKHQDQ ) \
opName( PUNPCKHWD ) \
opName( PUNPCKLBW ) \
opName( PUNPCKLDQ ) \
opName( PUNPCKLQDQ ) \
opName( PUNPCKLWD ) \
opName( PUSH ) \
opName( PUSHA ) \
opName( PUSHAD ) \
opName( PUSHF ) \
opName( PUSHFD ) \
opName( PXOR ) \
opName( RCL ) \
opName( RCPPS ) \
opName( RCPSS ) \
opName( RCR ) \
opName( RDMSR ) \
opName( RDPMC ) \
opName( RDTSC ) \
opName( REP ) \
opName( REPE ) \
opName( REPNE ) \
opName( REPNZ ) \
opName( REPZ ) \
opName( RETF ) \
opName( RETN ) \
opName( ROL ) \
opName( ROR ) \
opName( RSM ) \
opName( RSQRTPS ) \
opName( RSQRTSS ) \
opName( SAHF ) \
opName( SAL ) \
opName( SALC ) \
opName( SAR ) \
opName( SBB ) \
opName( SCAS ) \
opName( SCASB ) \
opName( SCASD ) \
opName( SCASW ) \
opName( SETA ) \
opName( SETAE ) \
opName( SETALC ) \
opName( SETB ) \
opName( SETBE ) \
opName( SETC ) \
opName( SETE ) \
opName( SETG ) \
opName( SETGE ) \
opName( SETL ) \
opName( SETLE ) \
opName( SETNA ) \
opName( SETNAE ) \
opName( SETNB ) \
opName( SETNBE ) \
opName( SETNC ) \
opName( SETNE ) \
opName( SETNG ) \
opName( SETNGE ) \
opName( SETNL ) \
opName( SETNLE ) \
opName( SETNO ) \
opName( SETNP ) \
opName( SETNS ) \
opName( SETNZ ) \
opName( SETO ) \
opName( SETP ) \
opName( SETPE ) \
opName( SETPO ) \
opName( SETS ) \
opName( SETZ ) \
opName( SFENCE ) \
opName( SGDT ) \
opName( SHL ) \
opName( SHLD ) \
opName( SHR ) \
opName( SHRD ) \
opName( SHUFPD ) \
opName( SHUFPS ) \
opName( SIDT ) \
opName( SLDT ) \
opName( SMSW ) \
opName( SQRTPD ) \
opName( SQRTPS ) \
opName( SQRTSD ) \
opName( SQRTSS ) \
opName( SS ) \
opName( STC ) \
opName( STD ) \
opName( STI ) \
opName( STMXCSR ) \
opName( STOS ) \
opName( STOSB ) \
opName( STOSD ) \
opName( STOSW ) \
opName( STR ) \
opName( SUB ) \
opName( SUBPD ) \
opName( SUBPS ) \
opName( SUBSD ) \
opName( SUBSS ) \
opName( SYSENTER ) \
opName( SYSEXIT ) \
opName( TAKEN ) \
opName( TEST ) \
opName( UCOMISD ) \
opName( UCOMISS ) \
opName( UD ) \
opName( UD2 ) \
opName( UNPCKHPD ) \
opName( UNPCKHPS ) \
opName( UNPCKLPD ) \
opName( UNPCKLPS ) \
opName( VERR ) \
opName( VERW ) \
opName( WAIT ) \
opName( WBINVD ) \
opName( WRMSR ) \
opName( XADD ) \
opName( XCHG ) \
opName( XLAT ) \
opName( XLATB ) \
opName( XOR ) \
opName( XORPD ) \
opName( XORPS ) \

#endif
