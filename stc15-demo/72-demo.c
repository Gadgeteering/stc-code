/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC15F4K60S4 系列 掉电模式举例----------------------------------*/
/* --- Mobile: (86)13922805190 -------------- -------------------------*/
/* --- Fax: 86-755-82905966 -------------------------------------------*/
/* --- Tel: 86-755-82948412 -------------------------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了宏晶科技的资料及程序   */
/* 如果要在文章中应用此代码,请在文章中注明使用了宏晶科技的资料及程序   */
/*---------------------------------------------------------------------*/

//本示例在Keil开发环境下请选择Intel的8058芯片型号进行编译
//假定测试芯片的工作频率为18.432MHz

#include "reg51.h"
#include "intrins.h"

//-----------------------------------------------

void main()
{
    while (1)
    {
        PCON |= 0x02;           //将STOP(PCON.1)置1,MCU将进入掉电模式
        _nop_();                //此时CPU无时钟,不执行指令,且所欲外设停止工作
        _nop_();                //外部中断信号和外部复位信号可以终止掉电模式
        _nop_();
        _nop_();
    }
}
