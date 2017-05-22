/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC15F4K60S4 系列 软件复位举例----------------------------------*/
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

sfr IAP_CONTR   = 0xc7;         //IAP控制寄存器

sbit P10        = P1^0;

//-----------------------------------------------

void delay()                    //软件延时
{
    int i;
    
    for (i=0; i<10000; i++)
    {
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }
}

void main()
{
    P10 = !P10;                 //上电P1.0闪烁一次,便于观察
    delay();
    P10 = !P10;
    delay();

    IAP_CONTR = 0x20;           //软件复位,系统重新从用户代码区开始运行程序
//  IAP_CONTR = 0x60;           //软件复位,系统重新从ISP代码区开始运行程序

    while (1);
}
