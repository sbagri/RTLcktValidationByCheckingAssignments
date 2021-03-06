// Verilated -*- C++ -*- b12
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"              // For This
#include "Vtop__Syms.h"

//--------------------
// STATIC VARIABLES


//--------------------

VL_CTOR_IMP(Vtop)
{
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(this, name());
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values

    // Reset structure values
    clock = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    start = VL_RAND_RESET_I(1);
    k = VL_RAND_RESET_I(4);
    nloss = VL_RAND_RESET_I(1);
    nl = VL_RAND_RESET_I(4);
    speaker = VL_RAND_RESET_I(1);
    v__DOT__wr = VL_RAND_RESET_I(1);
    v__DOT__address = VL_RAND_RESET_I(5);
    v__DOT__data_in = VL_RAND_RESET_I(2);
    v__DOT__data_out = VL_RAND_RESET_I(2);
    v__DOT__num = VL_RAND_RESET_I(2);
    v__DOT__sound = VL_RAND_RESET_I(3);
    v__DOT__play = VL_RAND_RESET_I(1);
    v__DOT__s = VL_RAND_RESET_I(1);
    v__DOT__counter = VL_RAND_RESET_I(3);
    v__DOT__count = VL_RAND_RESET_I(2);
    {
        int __Vi0=0;
        for (; __Vi0<32; ++__Vi0)
        {
            v__DOT__memory[__Vi0] = VL_RAND_RESET_I(2);
        }
    }
    v__DOT__gamma = VL_RAND_RESET_I(5);
    v__DOT__ind = VL_RAND_RESET_I(2);
    v__DOT__scan = VL_RAND_RESET_I(5);
    v__DOT__max = VL_RAND_RESET_I(5);
    v__DOT__timebase = VL_RAND_RESET_I(6);
    v__DOT__count2 = VL_RAND_RESET_I(6);
    __Vclklast__TOP__clock = VL_RAND_RESET_I(1);
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first)
{
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    // Coverage Declarations
    __vlCoverInsert(&(vlSymsp->__Vcoverage[0]), first, "b12.v", 99, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[1]), first, "b12.v", 112, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[2]), first, "b12.v", 119, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[3]), first, "b12.v", 110, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[4]), first, "b12.v", 124, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[5]), first, "b12.v", 131, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[6]), first, "b12.v", 122, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[7]), first, "b12.v", 136, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[8]), first, "b12.v", 143, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[9]), first, "b12.v", 134, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[10]), first, "b12.v", 148, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[11]), first, "b12.v", 155, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[12]), first, "b12.v", 146, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[13]), first, "b12.v", 160, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[14]), first, "b12.v", 167, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[15]), first, "b12.v", 158, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[16]), first, "b12.v", 172, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[17]), first, "b12.v", 179, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[18]), first, "b12.v", 170, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[19]), first, "b12.v", 182, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[20]), first, "b12.v", 107, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[21]), first, "b12.v", 187, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[22]), first, "b12.v", 106, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[23]), first, "b12.v", 198, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[24]), first, "b12.v", 204, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[25]), first, "b12.v", 216, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[26]), first, "b12.v", 227, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[27]), first, "b12.v", 225, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[28]), first, "b12.v", 247, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[29]), first, "b12.v", 265, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[30]), first, "b12.v", 268, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[31]), first, "b12.v", 272, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[32]), first, "b12.v", 277, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[33]), first, "b12.v", 288, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[34]), first, "b12.v", 297, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[35]), first, "b12.v", 304, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[36]), first, "b12.v", 309, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[37]), first, "b12.v", 321, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[38]), first, "b12.v", 329, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[39]), first, "b12.v", 319, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[40]), first, "b12.v", 339, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[41]), first, "b12.v", 345, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[42]), first, "b12.v", 337, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[43]), first, "b12.v", 351, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[44]), first, "b12.v", 335, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[45]), first, "b12.v", 357, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[46]), first, "b12.v", 364, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[47]), first, "b12.v", 371, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[48]), first, "b12.v", 387, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[49]), first, "b12.v", 390, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[50]), first, "b12.v", 380, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[51]), first, "b12.v", 402, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[52]), first, "b12.v", 405, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[53]), first, "b12.v", 417, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[54]), first, "b12.v", 420, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[55]), first, "b12.v", 432, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[56]), first, "b12.v", 435, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[57]), first, "b12.v", 441, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[58]), first, "b12.v", 425, 0, ".v", "v_line/b12", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[59]), first, "b12.v", 410, 0, ".v", "v_line/b12", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[60]), first, "b12.v", 395, 0, ".v", "v_line/b12", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[61]), first, "b12.v", 378, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[62]), first, "b12.v", 369, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[63]), first, "b12.v", 445, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[64]), first, "b12.v", 453, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[65]), first, "b12.v", 461, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[66]), first, "b12.v", 451, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[67]), first, "b12.v", 471, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[68]), first, "b12.v", 483, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[69]), first, "b12.v", 476, 0, ".v", "v_line/b12", "elsif");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[70]), first, "b12.v", 469, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[71]), first, "b12.v", 491, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[72]), first, "b12.v", 467, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[73]), first, "b12.v", 497, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[74]), first, "b12.v", 505, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[75]), first, "b12.v", 513, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[76]), first, "b12.v", 503, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[77]), first, "b12.v", 521, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[78]), first, "b12.v", 527, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[79]), first, "b12.v", 519, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[80]), first, "b12.v", 533, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[81]), first, "b12.v", 539, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[82]), first, "b12.v", 544, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[83]), first, "b12.v", 556, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[84]), first, "b12.v", 564, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[85]), first, "b12.v", 554, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[86]), first, "b12.v", 574, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[87]), first, "b12.v", 580, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[88]), first, "b12.v", 572, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[89]), first, "b12.v", 589, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[90]), first, "b12.v", 570, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[91]), first, "b12.v", 597, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[92]), first, "b12.v", 605, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[93]), first, "b12.v", 595, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[94]), first, "b12.v", 613, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[95]), first, "b12.v", 622, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[96]), first, "b12.v", 611, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[97]), first, "b12.v", 630, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[98]), first, "b12.v", 638, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[99]), first, "b12.v", 628, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[100]), first, "b12.v", 646, 0, ".v", "v_line/b12", "if");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[101]), first, "b12.v", 655, 0, ".v", "v_line/b12", "else");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[102]), first, "b12.v", 644, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[103]), first, "b12.v", 661, 0, ".v", "v_line/b12", "case");
    __vlCoverInsert(&(vlSymsp->__Vcoverage[104]), first, "b12.v", 264, 0, ".v", "v_line/b12", "else");
}

Vtop::~Vtop()
{
    delete __VlSymsp;
    __VlSymsp=NULL;
}

// Coverage
void Vtop::__vlCoverInsert(uint32_t* countp, bool enable, const char* filenamep, int lineno, int column,
                           const char* hierp, const char* pagep, const char* commentp)
{
    static uint32_t fake_zero_count = 0;
    if (!enable) countp = &fake_zero_count;
    *countp = 0;
    SP_COVER_INSERT(countp,  "filename",filenamep,  "lineno",lineno,  "column",column,
                    "hier",string(name())+hierp,  "page",pagep,  "comment",commentp);
}

//--------------------


void Vtop::eval()
{
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp; // Setup global symbol table
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    VL_DEBUG_IF(VL_PRINTF("\n----TOP Evaluate Vtop::eval\n"); );
    int __VclockLoop = 0;
    IData __Vchange=1;
    while (VL_LIKELY(__Vchange))
    {
        VL_DEBUG_IF(VL_PRINTF(" Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        __Vchange = _change_request(vlSymsp);
        if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't converge");
    }
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp)
{
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    int __VclockLoop = 0;
    IData __Vchange=1;
    while (VL_LIKELY(__Vchange))
    {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        __Vchange = _change_request(vlSymsp);
        if (++__VclockLoop > 100) vl_fatal(__FILE__,__LINE__,__FILE__,"Verilated model didn't DC converge");
    }
}

//--------------------
// Internal Methods

void Vtop::_sequent__TOP__1(Vtop__Syms* __restrict vlSymsp)
{
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_sequent__TOP__1\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    VL_SIG8(__Vdly__v__DOT__data_out,1,0);
    //char	__VpadToAlign5[3];
    // Body
    __Vdly__v__DOT__data_out = vlTOPp->v__DOT__data_out;
    // ALWAYS at b12.v:97
    if (vlTOPp->reset)
    {
        ++(vlSymsp->__Vcoverage[0]);
        vlTOPp->v__DOT__s = 0;
        vlTOPp->v__DOT__counter = 0;
        vlTOPp->speaker = 0;
    }
    else
    {
        ++(vlSymsp->__Vcoverage[22]);
        if (vlTOPp->v__DOT__play)
        {
            ++(vlSymsp->__Vcoverage[20]);
            if ((0 == (IData)(vlTOPp->v__DOT__sound)))
            {
                ++(vlSymsp->__Vcoverage[3]);
                if (((IData)(vlTOPp->v__DOT__counter) > 2))
                {
                    vlTOPp->v__DOT__s = (1 & (~ (IData)(vlTOPp->v__DOT__s)));
                    ++(vlSymsp->__Vcoverage[1]);
                    vlTOPp->v__DOT__counter = 0;
                    vlTOPp->speaker = vlTOPp->v__DOT__s;
                }
                else
                {
                    vlTOPp->v__DOT__counter = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__counter)));
                    ++(vlSymsp->__Vcoverage[2]);
                }
            }
            else
            {
                if ((1 == (IData)(vlTOPp->v__DOT__sound)))
                {
                    ++(vlSymsp->__Vcoverage[6]);
                    if (((IData)(vlTOPp->v__DOT__counter) > 3))
                    {
                        vlTOPp->v__DOT__s = (1 & (~ (IData)(vlTOPp->v__DOT__s)));
                        ++(vlSymsp->__Vcoverage[4]);
                        vlTOPp->v__DOT__counter = 0;
                        vlTOPp->speaker = vlTOPp->v__DOT__s;
                    }
                    else
                    {
                        vlTOPp->v__DOT__counter = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__counter)));
                        ++(vlSymsp->__Vcoverage[5]);
                    }
                }
                else
                {
                    if ((2 == (IData)(vlTOPp->v__DOT__sound)))
                    {
                        ++(vlSymsp->__Vcoverage[9]);
                        if (((IData)(vlTOPp->v__DOT__counter) > 4))
                        {
                            vlTOPp->v__DOT__s = (1 & (~ (IData)(vlTOPp->v__DOT__s)));
                            ++(vlSymsp->__Vcoverage[7]);
                            vlTOPp->v__DOT__counter = 0;
                            vlTOPp->speaker = vlTOPp->v__DOT__s;
                        }
                        else
                        {
                            vlTOPp->v__DOT__counter = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__counter)));
                            ++(vlSymsp->__Vcoverage[8]);
                        }
                    }
                    else
                    {
                        if ((3 == (IData)(vlTOPp->v__DOT__sound)))
                        {
                            ++(vlSymsp->__Vcoverage[12]);
                            if (((IData)(vlTOPp->v__DOT__counter) > 5))
                            {
                                vlTOPp->v__DOT__s = (1 & (~ (IData)(vlTOPp->v__DOT__s)));
                                ++(vlSymsp->__Vcoverage[10]);
                                vlTOPp->v__DOT__counter = 0;
                                vlTOPp->speaker = vlTOPp->v__DOT__s;
                            }
                            else
                            {
                                vlTOPp->v__DOT__counter = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__counter)));
                                ++(vlSymsp->__Vcoverage[11]);
                            }
                        }
                        else
                        {
                            if ((4 == (IData)(vlTOPp->v__DOT__sound)))
                            {
                                ++(vlSymsp->__Vcoverage[15]);
                                if (((IData)(vlTOPp->v__DOT__counter) > 6))
                                {
                                    vlTOPp->v__DOT__s = (1 & (~ (IData)(vlTOPp->v__DOT__s)));
                                    ++(vlSymsp->__Vcoverage[13]);
                                    vlTOPp->v__DOT__counter = 0;
                                    vlTOPp->speaker = vlTOPp->v__DOT__s;
                                }
                                else
                                {
                                    vlTOPp->v__DOT__counter = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__counter)));
                                    ++(vlSymsp->__Vcoverage[14]);
                                }
                            }
                            else
                            {
                                if ((5 == (IData)(vlTOPp->v__DOT__sound)))
                                {
                                    ++(vlSymsp->__Vcoverage[18]);
                                    if (((IData)(vlTOPp->v__DOT__counter) > 1))
                                    {
                                        vlTOPp->v__DOT__s = (1 &(~ (IData)(vlTOPp->v__DOT__s)));
                                        ++(vlSymsp->__Vcoverage[16]);
                                        vlTOPp->v__DOT__counter = 0;
                                        vlTOPp->speaker = vlTOPp->v__DOT__s;
                                    }
                                    else
                                    {
                                        vlTOPp->v__DOT__counter = (7 & ((IData)(1) + (IData)(vlTOPp->v__DOT__counter)));
                                        ++(vlSymsp->__Vcoverage[17]);
                                    }
                                }
                                else
                                {
                                    ++(vlSymsp->__Vcoverage[19]);
                                    vlTOPp->v__DOT__counter = 0;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            ++(vlSymsp->__Vcoverage[21]);
            vlTOPp->v__DOT__counter = 0;
            vlTOPp->speaker = 0;
        }
    }
    // ALWAYS at b12.v:214
    if (vlTOPp->reset)
    {
        ++(vlSymsp->__Vcoverage[25]);
        vlTOPp->v__DOT__memory[0] = 0;
        __Vdly__v__DOT__data_out = 0;
        vlTOPp->v__DOT__memory[1] = 0;
        vlTOPp->v__DOT__memory[2] = 0;
        vlTOPp->v__DOT__memory[3] = 0;
        vlTOPp->v__DOT__memory[4] = 0;
        vlTOPp->v__DOT__memory[5] = 0;
        vlTOPp->v__DOT__memory[6] = 0;
        vlTOPp->v__DOT__memory[7] = 0;
        vlTOPp->v__DOT__memory[8] = 0;
        vlTOPp->v__DOT__memory[9] = 0;
        vlTOPp->v__DOT__memory[0xa] = 0;
        vlTOPp->v__DOT__memory[0xb] = 0;
        vlTOPp->v__DOT__memory[0xc] = 0;
        vlTOPp->v__DOT__memory[0xd] = 0;
        vlTOPp->v__DOT__memory[0xe] = 0;
        vlTOPp->v__DOT__memory[0xf] = 0;
        vlTOPp->v__DOT__memory[0x10] = 0;
        vlTOPp->v__DOT__memory[0x11] = 0;
        vlTOPp->v__DOT__memory[0x12] = 0;
        vlTOPp->v__DOT__memory[0x13] = 0;
        vlTOPp->v__DOT__memory[0x14] = 0;
        vlTOPp->v__DOT__memory[0x15] = 0;
        vlTOPp->v__DOT__memory[0x16] = 0;
        vlTOPp->v__DOT__memory[0x17] = 0;
        vlTOPp->v__DOT__memory[0x18] = 0;
        vlTOPp->v__DOT__memory[0x19] = 0;
        vlTOPp->v__DOT__memory[0x1a] = 0;
        vlTOPp->v__DOT__memory[0x1b] = 0;
        vlTOPp->v__DOT__memory[0x1c] = 0;
        vlTOPp->v__DOT__memory[0x1d] = 0;
        vlTOPp->v__DOT__memory[0x1e] = 0;
        vlTOPp->v__DOT__memory[0x1f] = 0;
    }
    else
    {
        ++(vlSymsp->__Vcoverage[27]);
        __Vdly__v__DOT__data_out = (IData)(vlTOPp->v__DOT__memory)[(IData)(vlTOPp->v__DOT__address)];
        if (vlTOPp->v__DOT__wr)
        {
            ++(vlSymsp->__Vcoverage[26]);
            vlTOPp->v__DOT__memory[(IData)(vlTOPp->v__DOT__address)] = vlTOPp->v__DOT__data_in;
        }
    }
    // ALWAYS at b12.v:245
    if (vlTOPp->reset)
    {
        ++(vlSymsp->__Vcoverage[28]);
        vlTOPp->v__DOT__scan = 0;
        vlTOPp->v__DOT__max = 0;
        vlTOPp->v__DOT__ind = 0;
        vlTOPp->v__DOT__timebase = 0;
        vlTOPp->v__DOT__count2 = 0;
        vlTOPp->v__DOT__gamma = 0;
        vlTOPp->nloss = 0;
        vlTOPp->v__DOT__play = 0;
        vlTOPp->v__DOT__wr = 0;
        vlTOPp->v__DOT__sound = 0;
        vlTOPp->v__DOT__address = 0;
        vlTOPp->v__DOT__data_in = 0;
        vlTOPp->nl = 0;
    }
    else
    {
        ++(vlSymsp->__Vcoverage[104]);
        if (vlTOPp->start)
        {
            ++(vlSymsp->__Vcoverage[29]);
            vlTOPp->v__DOT__gamma = 1;
        }
        else
        {
            ++(vlSymsp->__Vcoverage[30]);
        }
        if (((((((((0 == (IData)(vlTOPp->v__DOT__gamma)) | (1 == (IData)(vlTOPp->v__DOT__gamma))) | (2 == (IData)(vlTOPp->v__DOT__gamma))) | (3 == (IData)(vlTOPp->v__DOT__gamma))) | (4 == (IData)(vlTOPp->v__DOT__gamma))) | (5 == (IData)(vlTOPp->v__DOT__gamma))) | (6 == (IData)(vlTOPp->v__DOT__gamma))) | (7 == (IData)(vlTOPp->v__DOT__gamma))))
        {
            if ((0 == (IData)(vlTOPp->v__DOT__gamma)))
            {
                ++(vlSymsp->__Vcoverage[31]);
                vlTOPp->v__DOT__gamma = 0;
            }
            else
            {
                if ((1 == (IData)(vlTOPp->v__DOT__gamma)))
                {
                    ++(vlSymsp->__Vcoverage[32]);
                    vlTOPp->v__DOT__max = 0;
                    vlTOPp->v__DOT__timebase = 0x21;
                    vlTOPp->v__DOT__gamma = 2;
                    vlTOPp->nloss = 0;
                    vlTOPp->v__DOT__play = 0;
                    vlTOPp->v__DOT__wr = 0;
                    vlTOPp->nl = 0;
                }
                else
                {
                    if ((2 == (IData)(vlTOPp->v__DOT__gamma)))
                    {
                        ++(vlSymsp->__Vcoverage[33]);
                        vlTOPp->v__DOT__scan = 0;
                        vlTOPp->v__DOT__gamma = 3;
                        vlTOPp->v__DOT__wr = 1;
                        vlTOPp->v__DOT__address = vlTOPp->v__DOT__max;
                        vlTOPp->v__DOT__data_in = vlTOPp->v__DOT__num;
                    }
                    else
                    {
                        if ((3 == (IData)(vlTOPp->v__DOT__gamma)))
                        {
                            ++(vlSymsp->__Vcoverage[34]);
                            vlTOPp->v__DOT__gamma = 4;
                            vlTOPp->v__DOT__wr = 0;
                            vlTOPp->v__DOT__address = vlTOPp->v__DOT__scan;
                        }
                        else
                        {
                            if ((4 == (IData)(vlTOPp->v__DOT__gamma)))
                            {
                                ++(vlSymsp->__Vcoverage[35]);
                                vlTOPp->v__DOT__gamma = 5;
                            }
                            else
                            {
                                if ((5 == (IData)(vlTOPp->v__DOT__gamma)))
                                {
                                    ++(vlSymsp->__Vcoverage[36]);
                                    vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                    vlTOPp->v__DOT__gamma = 6;
                                    vlTOPp->nl = ((IData)(vlTOPp->nl) | ((IData)(1) << (IData)(vlTOPp->v__DOT__data_out)));
                                    vlTOPp->v__DOT__play = 1;
                                    vlTOPp->v__DOT__sound = vlTOPp->v__DOT__data_out;
                                }
                                else
                                {
                                    if ((6 == (IData)(vlTOPp->v__DOT__gamma)))
                                    {
                                        ++(vlSymsp->__Vcoverage[39]);
                                        if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                                        {
                                            ++(vlSymsp->__Vcoverage[37]);
                                            vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                            vlTOPp->v__DOT__gamma = 7;
                                            vlTOPp->nl = 0;
                                            vlTOPp->v__DOT__play = 0;
                                        }
                                        else
                                        {
                                            vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                            ++(vlSymsp->__Vcoverage[38]);
                                            vlTOPp->v__DOT__gamma = 6;
                                        }
                                    }
                                    else
                                    {
                                        ++(vlSymsp->__Vcoverage[44]);
                                        if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                                        {
                                            ++(vlSymsp->__Vcoverage[42]);
                                            if (((IData)(vlTOPp->v__DOT__scan) != (IData)(vlTOPp->v__DOT__max)))
                                            {
                                                vlTOPp->v__DOT__scan = (0x1f & ((IData)(1) + (IData)(vlTOPp->v__DOT__scan)));
                                                ++(vlSymsp->__Vcoverage[40]);
                                                vlTOPp->v__DOT__gamma = 3;
                                            }
                                            else
                                            {
                                                ++(vlSymsp->__Vcoverage[41]);
                                                vlTOPp->v__DOT__scan = 0;
                                                vlTOPp->v__DOT__gamma = 8;
                                            }
                                        }
                                        else
                                        {
                                            vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                            ++(vlSymsp->__Vcoverage[43]);
                                            vlTOPp->v__DOT__gamma = 7;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if (((((((((8 == (IData)(vlTOPp->v__DOT__gamma)) | (9 == (IData)(vlTOPp->v__DOT__gamma))) | (0xa == (IData)(vlTOPp->v__DOT__gamma))) | (0xb == (IData)(vlTOPp->v__DOT__gamma))) | (0xc == (IData)(vlTOPp->v__DOT__gamma))) | (0xd == (IData)(vlTOPp->v__DOT__gamma))) | (0xe == (IData)(vlTOPp->v__DOT__gamma))) | (0xf == (IData)(vlTOPp->v__DOT__gamma))))
            {
                if ((8 == (IData)(vlTOPp->v__DOT__gamma)))
                {
                    ++(vlSymsp->__Vcoverage[45]);
                    vlTOPp->v__DOT__count2 = 0x21;
                    vlTOPp->v__DOT__gamma = 9;
                    vlTOPp->v__DOT__address = vlTOPp->v__DOT__scan;
                }
                else
                {
                    if ((9 == (IData)(vlTOPp->v__DOT__gamma)))
                    {
                        ++(vlSymsp->__Vcoverage[46]);
                        vlTOPp->v__DOT__gamma = 0xa;
                    }
                    else
                    {
                        if ((0xa == (IData)(vlTOPp->v__DOT__gamma)))
                        {
                            ++(vlSymsp->__Vcoverage[62]);
                            if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                            {
                                ++(vlSymsp->__Vcoverage[47]);
                                vlTOPp->v__DOT__max = 0;
                                vlTOPp->v__DOT__gamma = 0x11;
                                vlTOPp->nloss = 1;
                            }
                            else
                            {
                                vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                ++(vlSymsp->__Vcoverage[61]);
                                if ((1 == (1 & (IData)(vlTOPp->k))))
                                {
                                    ++(vlSymsp->__Vcoverage[50]);
                                    vlTOPp->v__DOT__ind = 0;
                                    vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                    vlTOPp->v__DOT__sound = 0;
                                    vlTOPp->v__DOT__play = 1;
                                    if ((0 == (IData)(vlTOPp->v__DOT__data_out)))
                                    {
                                        ++(vlSymsp->__Vcoverage[48]);
                                        vlTOPp->v__DOT__gamma = 0xb;
                                    }
                                    else
                                    {
                                        ++(vlSymsp->__Vcoverage[49]);
                                        vlTOPp->v__DOT__gamma = 0xe;
                                        vlTOPp->nloss = 1;
                                    }
                                }
                                else
                                {
                                    ++(vlSymsp->__Vcoverage[60]);
                                    if ((1 == (1 & ((IData)(vlTOPp->k) >> 1))))
                                    {
                                        vlTOPp->v__DOT__ind = 1;
                                        vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                        vlTOPp->v__DOT__sound = 1;
                                        vlTOPp->v__DOT__play = 1;
                                        if ((1 == (IData)(vlTOPp->v__DOT__data_out)))
                                        {
                                            ++(vlSymsp->__Vcoverage[51]);
                                            vlTOPp->v__DOT__gamma = 0xb;
                                        }
                                        else
                                        {
                                            ++(vlSymsp->__Vcoverage[52]);
                                            vlTOPp->v__DOT__gamma = 0xe;
                                            vlTOPp->nloss = 1;
                                        }
                                    }
                                    else
                                    {
                                        ++(vlSymsp->__Vcoverage[59]);
                                        if ((1 == (1 & ((IData)(vlTOPp->k) >> 2))))
                                        {
                                            vlTOPp->v__DOT__ind = 2;
                                            vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                            vlTOPp->v__DOT__sound = 2;
                                            vlTOPp->v__DOT__play = 1;
                                            if ((2 == (IData)(vlTOPp->v__DOT__data_out)))
                                            {
                                                ++(vlSymsp->__Vcoverage[53]);
                                                vlTOPp->v__DOT__gamma = 0xb;
                                            }
                                            else
                                            {
                                                ++(vlSymsp->__Vcoverage[54]);
                                                vlTOPp->v__DOT__gamma = 0xe;
                                                vlTOPp->nloss = 1;
                                            }
                                        }
                                        else
                                        {
                                            ++(vlSymsp->__Vcoverage[58]);
                                            if ((1 == (1 & ((IData)(vlTOPp->k) >> 3))))
                                            {
                                                vlTOPp->v__DOT__ind = 3;
                                                vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                                vlTOPp->v__DOT__sound = 3;
                                                vlTOPp->v__DOT__play = 1;
                                                if ((3 == (IData)(vlTOPp->v__DOT__data_out)))
                                                {
                                                    ++(vlSymsp->__Vcoverage[55]);
                                                    vlTOPp->v__DOT__gamma = 0xb;
                                                }
                                                else
                                                {
                                                    ++(vlSymsp->__Vcoverage[56]);
                                                    vlTOPp->v__DOT__gamma = 0xe;
                                                    vlTOPp->nloss = 1;
                                                }
                                            }
                                            else
                                            {
                                                ++(vlSymsp->__Vcoverage[57]);
                                                vlTOPp->v__DOT__gamma = 0xa;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if ((0xb == (IData)(vlTOPp->v__DOT__gamma)))
                            {
                                ++(vlSymsp->__Vcoverage[63]);
                                vlTOPp->v__DOT__gamma = 0xc;
                                vlTOPp->nl = ((IData)(vlTOPp->nl) | ((IData)(1) << (IData)(vlTOPp->v__DOT__ind)));
                            }
                            else
                            {
                                if ((0xc == (IData)(vlTOPp->v__DOT__gamma)))
                                {
                                    ++(vlSymsp->__Vcoverage[66]);
                                    if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                                    {
                                        ++(vlSymsp->__Vcoverage[64]);
                                        vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                        vlTOPp->v__DOT__gamma = 0xd;
                                        vlTOPp->nl = 0;
                                        vlTOPp->v__DOT__play = 0;
                                    }
                                    else
                                    {
                                        vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                        ++(vlSymsp->__Vcoverage[65]);
                                        vlTOPp->v__DOT__gamma = 0xc;
                                    }
                                }
                                else
                                {
                                    if ((0xd == (IData)(vlTOPp->v__DOT__gamma)))
                                    {
                                        ++(vlSymsp->__Vcoverage[72]);
                                        if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                                        {
                                            ++(vlSymsp->__Vcoverage[70]);
                                            if (((IData)(vlTOPp->v__DOT__scan) != (IData)(vlTOPp->v__DOT__max)))
                                            {
                                                vlTOPp->v__DOT__scan = (0x1f & ((IData)(1) + (IData)(vlTOPp->v__DOT__scan)));
                                                ++(vlSymsp->__Vcoverage[67]);
                                                vlTOPp->v__DOT__gamma = 8;
                                            }
                                            else
                                            {
                                                ++(vlSymsp->__Vcoverage[69]);
                                                if ((0x1f != (IData)(vlTOPp->v__DOT__max)))
                                                {
                                                    vlTOPp->v__DOT__max = (0x1f & ((IData)(1) + (IData)(vlTOPp->v__DOT__max)));
                                                    vlTOPp->v__DOT__timebase = (0x3f & ((IData)(vlTOPp->v__DOT__timebase) - (IData)(1)));
                                                    vlTOPp->v__DOT__gamma = 2;
                                                }
                                                else
                                                {
                                                    ++(vlSymsp->__Vcoverage[68]);
                                                    vlTOPp->v__DOT__count2 = 8;
                                                    vlTOPp->v__DOT__gamma = 0x18;
                                                    vlTOPp->v__DOT__play = 1;
                                                    vlTOPp->v__DOT__sound = 4;
                                                }
                                            }
                                        }
                                        else
                                        {
                                            vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                            ++(vlSymsp->__Vcoverage[71]);
                                            vlTOPp->v__DOT__gamma = 0xd;
                                        }
                                    }
                                    else
                                    {
                                        if ((0xe == (IData)(vlTOPp->v__DOT__gamma)))
                                        {
                                            ++(vlSymsp->__Vcoverage[73]);
                                            vlTOPp->v__DOT__gamma = 0xf;
                                            vlTOPp->nl = ((IData)(vlTOPp->nl) | ((IData)(1) << (IData)(vlTOPp->v__DOT__ind)));
                                        }
                                        else
                                        {
                                            ++(vlSymsp->__Vcoverage[76]);
                                            if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                                            {
                                                ++(vlSymsp->__Vcoverage[74]);
                                                vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                                vlTOPp->v__DOT__gamma = 0x10;
                                                vlTOPp->nl = 0;
                                                vlTOPp->v__DOT__play = 0;
                                            }
                                            else
                                            {
                                                vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                                ++(vlSymsp->__Vcoverage[75]);
                                                vlTOPp->v__DOT__gamma = 0xf;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if (((((((((0x10 == (IData)(vlTOPp->v__DOT__gamma)) | (0x11 == (IData)(vlTOPp->v__DOT__gamma))) | (0x12 == (IData)(vlTOPp->v__DOT__gamma))) | (0x13 == (IData)(vlTOPp->v__DOT__gamma))) | (0x14 == (IData)(vlTOPp->v__DOT__gamma))) | (0x15 == (IData)(vlTOPp->v__DOT__gamma))) | (0x16 == (IData)(vlTOPp->v__DOT__gamma))) | (0x17 == (IData)(vlTOPp->v__DOT__gamma))))
                {
                    if ((0x10 == (IData)(vlTOPp->v__DOT__gamma)))
                    {
                        ++(vlSymsp->__Vcoverage[79]);
                        if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                        {
                            ++(vlSymsp->__Vcoverage[77]);
                            vlTOPp->v__DOT__max = 0;
                            vlTOPp->v__DOT__gamma = 0x11;
                        }
                        else
                        {
                            vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                            ++(vlSymsp->__Vcoverage[78]);
                            vlTOPp->v__DOT__gamma = 0x10;
                        }
                    }
                    else
                    {
                        if ((0x11 == (IData)(vlTOPp->v__DOT__gamma)))
                        {
                            ++(vlSymsp->__Vcoverage[80]);
                            vlTOPp->v__DOT__gamma = 0x12;
                            vlTOPp->v__DOT__address = vlTOPp->v__DOT__max;
                        }
                        else
                        {
                            if ((0x12 == (IData)(vlTOPp->v__DOT__gamma)))
                            {
                                ++(vlSymsp->__Vcoverage[81]);
                                vlTOPp->v__DOT__gamma = 0x13;
                            }
                            else
                            {
                                if ((0x13 == (IData)(vlTOPp->v__DOT__gamma)))
                                {
                                    ++(vlSymsp->__Vcoverage[82]);
                                    vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                    vlTOPp->v__DOT__gamma = 0x14;
                                    vlTOPp->nl = ((IData)(vlTOPp->nl) | ((IData)(1) << (IData)(vlTOPp->v__DOT__data_out)));
                                    vlTOPp->v__DOT__play = 1;
                                    vlTOPp->v__DOT__sound = vlTOPp->v__DOT__data_out;
                                }
                                else
                                {
                                    if ((0x14 == (IData)(vlTOPp->v__DOT__gamma)))
                                    {
                                        ++(vlSymsp->__Vcoverage[85]);
                                        if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                                        {
                                            ++(vlSymsp->__Vcoverage[83]);
                                            vlTOPp->v__DOT__count2 = vlTOPp->v__DOT__timebase;
                                            vlTOPp->v__DOT__gamma = 0x15;
                                            vlTOPp->nl = 0;
                                            vlTOPp->v__DOT__play = 0;
                                        }
                                        else
                                        {
                                            vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                            ++(vlSymsp->__Vcoverage[84]);
                                            vlTOPp->v__DOT__gamma = 0x14;
                                        }
                                    }
                                    else
                                    {
                                        if ((0x15 == (IData)(vlTOPp->v__DOT__gamma)))
                                        {
                                            ++(vlSymsp->__Vcoverage[90]);
                                            if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                                            {
                                                ++(vlSymsp->__Vcoverage[88]);
                                                if (((IData)(vlTOPp->v__DOT__max) != (IData)(vlTOPp->v__DOT__scan)))
                                                {
                                                    vlTOPp->v__DOT__max = (0x1f & ((IData)(1) + (IData)(vlTOPp->v__DOT__max)));
                                                    ++(vlSymsp->__Vcoverage[86]);
                                                    vlTOPp->v__DOT__gamma = 0x11;
                                                }
                                                else
                                                {
                                                    ++(vlSymsp->__Vcoverage[87]);
                                                    vlTOPp->v__DOT__count2 = 8;
                                                    vlTOPp->v__DOT__gamma = 0x16;
                                                    vlTOPp->nl = ((IData)(vlTOPp->nl) | ((IData)(1) << (IData)(vlTOPp->v__DOT__data_out)));
                                                    vlTOPp->v__DOT__play = 1;
                                                    vlTOPp->v__DOT__sound = 5;
                                                }
                                            }
                                            else
                                            {
                                                vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                                ++(vlSymsp->__Vcoverage[89]);
                                                vlTOPp->v__DOT__gamma = 0x15;
                                            }
                                        }
                                        else
                                        {
                                            if ((0x16 == (IData)(vlTOPp->v__DOT__gamma)))
                                            {
                                                ++(vlSymsp->__Vcoverage[93]);
                                                if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                                                {
                                                    ++(vlSymsp->__Vcoverage[91]);
                                                    vlTOPp->v__DOT__count2 = 8;
                                                    vlTOPp->v__DOT__gamma = 0x17;
                                                    vlTOPp->nl = 0;
                                                    vlTOPp->v__DOT__play = 0;
                                                }
                                                else
                                                {
                                                    vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                                    ++(vlSymsp->__Vcoverage[92]);
                                                    vlTOPp->v__DOT__gamma = 0x16;
                                                }
                                            }
                                            else
                                            {
                                                ++(vlSymsp->__Vcoverage[96]);
                                                if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                                                {
                                                    ++(vlSymsp->__Vcoverage[94]);
                                                    vlTOPp->v__DOT__count2 = 8;
                                                    vlTOPp->v__DOT__gamma = 0x16;
                                                    vlTOPp->nl = ((IData)(vlTOPp->nl) | ((IData)(1) << (IData)(vlTOPp->v__DOT__data_out)));
                                                    vlTOPp->v__DOT__play = 1;
                                                    vlTOPp->v__DOT__sound = 5;
                                                }
                                                else
                                                {
                                                    vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                                    ++(vlSymsp->__Vcoverage[95]);
                                                    vlTOPp->v__DOT__gamma = 0x17;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if ((0x18 == (IData)(vlTOPp->v__DOT__gamma)))
                    {
                        ++(vlSymsp->__Vcoverage[99]);
                        if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                        {
                            ++(vlSymsp->__Vcoverage[97]);
                            vlTOPp->v__DOT__count2 = 8;
                            vlTOPp->v__DOT__gamma = 0x19;
                            vlTOPp->nl = 1;
                            vlTOPp->v__DOT__play = 0;
                        }
                        else
                        {
                            vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                            ++(vlSymsp->__Vcoverage[98]);
                            vlTOPp->v__DOT__gamma = 0x18;
                        }
                    }
                    else
                    {
                        if ((0x19 == (IData)(vlTOPp->v__DOT__gamma)))
                        {
                            ++(vlSymsp->__Vcoverage[102]);
                            if ((0 == (IData)(vlTOPp->v__DOT__count2)))
                            {
                                ++(vlSymsp->__Vcoverage[100]);
                                vlTOPp->v__DOT__count2 = 8;
                                vlTOPp->v__DOT__gamma = 0x18;
                                vlTOPp->nl = 0;
                                vlTOPp->v__DOT__play = 1;
                                vlTOPp->v__DOT__sound = 4;
                            }
                            else
                            {
                                vlTOPp->v__DOT__count2 = (0x3f & ((IData)(vlTOPp->v__DOT__count2) - (IData)(1)));
                                ++(vlSymsp->__Vcoverage[101]);
                                vlTOPp->v__DOT__gamma = 0x19;
                            }
                        }
                        else
                        {
                            ++(vlSymsp->__Vcoverage[103]);
                            vlTOPp->v__DOT__gamma = 1;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->v__DOT__data_out = __Vdly__v__DOT__data_out;
    // ALWAYS at b12.v:196
    if (vlTOPp->reset)
    {
        ++(vlSymsp->__Vcoverage[23]);
        vlTOPp->v__DOT__count = 0;
        vlTOPp->v__DOT__num = 0;
    }
    else
    {
        vlTOPp->v__DOT__count = (3 & VL_MODDIV_III(32, ((IData)(1) + (IData)(vlTOPp->v__DOT__count)), (IData)(4)));
        ++(vlSymsp->__Vcoverage[24]);
        vlTOPp->v__DOT__num = vlTOPp->v__DOT__count;
    }
}

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp)
{
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clock) & (~ (IData)(vlTOPp->__Vclklast__TOP__clock))))
    {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__clock = vlTOPp->clock;
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp)
{
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval_initial\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::final()
{
    VL_DEBUG_IF(VL_PRINTF("    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp)
{
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_eval_settle\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

IData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp)
{
    VL_DEBUG_IF(VL_PRINTF("    Vtop::_change_request\n"); );
    Vtop* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    IData __req = false;  // Logically a bool
    return __req;
}
