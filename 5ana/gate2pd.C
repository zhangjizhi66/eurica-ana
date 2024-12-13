// Last Modified zhangjizhi, 20220609

#include "gate2.C"

void gate2pd()
{
    gate2();
    GateAxis = "Y";
    tpjm();
    GateAxis = "X";
}

void setaxis(TString AxisName)
{
    if (AxisName=="x") AxisName="X";
    if (AxisName=="y") AxisName="Y";
    if (AxisName!="X" && AxisName!="Y"){
        std::cout<<RED<<"wrong axis name!"<<RESET<<std::endl;
        return;
    }
    GateAxis = AxisName;
}

void gxs(float ge1,int npad = 4)
{
    GateAxis = "X";
    gs(ge1, npad);
}
void gys(float ge1,int npad = 4)
{
    GateAxis = "Y";
    gs(ge1, npad);
}

void gxscp(float ge1)
{
    GateAxis = "X";
    gscp(ge1);
}
void gyscp(float ge1)
{
    GateAxis = "Y";
    gscp(ge1);
}

void gxm(float ge1, float ge2 = -1000, float ge3 = -1000, float ge4 = -1000)
{
    GateAxis = "X";
    gm(ge1, ge2, ge3, ge4);
}
void gym(float ge1, float ge2 = -1000, float ge3 = -1000, float ge4 = -1000)
{
    GateAxis = "Y";
    gm(ge1, ge2, ge3, ge4);
}

void gxw(float ge1, float ge2)
{
    GateAxis = "X";
    gw(ge1, ge2);
}
void gyw(float ge1, float ge2)
{
    GateAxis = "Y";
    gw(ge1, ge2);
}

void gxand(float ge1, float ge2, float ge3 = -1000, float ge4 = -1000)
{
    GateAxis = "X";
    gand(ge1, ge2, ge3, ge4);
}
void gyand(float ge1, float ge2, float ge3 = -1000, float ge4 = -1000)
{
    GateAxis = "Y";
    gand(ge1, ge2, ge3, ge4);
}

void gxadd(float ge1, float ge2, float ge3 = -1000, float ge4 = -1000, float ge5 = -1000, float ge6 = -1000)
{
    GateAxis = "X";
    gadd(ge1, ge2, ge3, ge4, ge5, ge6);
}
void gyadd(float ge1, float ge2, float ge3 = -1000, float ge4 = -1000, float ge5 = -1000, float ge6 = -1000)
{
    GateAxis = "Y";
    gadd(ge1, ge2, ge3, ge4, ge5, ge6);
}

void gxsub(float ge1, float ge2, float ge3 = -1000, float ge4 = -1000)
{
    GateAxis = "X";
    gsub(ge1, ge2, ge3, ge4);
}
void gysub(float ge1, float ge2, float ge3 = -1000, float ge4 = -1000)
{
    GateAxis = "Y";
    gsub(ge1, ge2, ge3, ge4);
}

