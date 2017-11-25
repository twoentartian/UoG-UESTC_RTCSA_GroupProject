// //Author:twoentartian
// //Date:11/6/2017 (MDY)

#include "mbed.h"
#include "rtos.h"
#include "TextLCD.h"

#include "button.h"
#include "LCD2004.h"

Serial pc(USBTX,USBRX);
Serial nano(PC_12,PD_2);
AnalogOut Speaker(PA_4);
AnalogIn Microphone(PB_1);

volatile bool ButtonRefreshThreadRunSign = true;
volatile bool GestureInfoThreadRunSign = true;
volatile bool LcdRefreshThreadRunSign = true;

volatile int ButtonRefreshThreadDelayTime = 50;
volatile int GestureInfoThreadDelayTime = 100;
volatile int LcdRefreshThreadDelayTime = 500;

void Init()
{
    pc.baud(115200);
    nano.baud(115200);
}

void ButtonRefreshThreadFunc()
{
    while(true)
    {
        if(ButtonRefreshThreadRunSign)
        {
            Button_RefreshButtonState();
        }
        Thread::wait(ButtonRefreshThreadDelayTime);
    }
}

void GestureInfoThreadFunc()
{
    while(true)
    {
        if(GestureInfoThreadRunSign)
        {
            while(nano.readable())
            {
                pc.putc(nano.getc());
            }
        }
        Thread::wait(GestureInfoThreadDelayTime);
    }
}

void LcdRefreshThreadFunc()
{
    char data='0';
    while(true)
    {
        if(LcdRefreshThreadRunSign)
        {
            LCD_Refresh();
            LCD_ChangeBuffer(0,0,data);
            if(data=='9')
            {
                data='0';
            }
            else
            {
                data++;
            }
        }
        Thread::wait(LcdRefreshThreadDelayTime);
    }
}

//////////////////////DEBUG//////////////////////
#define FilterQueueLength 6
//////////////////////DEBUG//////////////////////

int main()
{
    Init();
    DigitalOut SystemLed1(LED1);
    DigitalOut SystemLed2(LED2);

    //Start Thread
    Thread ButtonRefreshThread;
    Thread GestureInfoThread;
    Thread LcdRefreshThread;

    ButtonRefreshThread.start(callback(ButtonRefreshThreadFunc));
    GestureInfoThread.start(callback(GestureInfoThreadFunc));
    LcdRefreshThread.start(callback(LcdRefreshThreadFunc));

    //////////////////////DEBUG//////////////////////
    while(true)
    {
        Thread::wait(10);
    }

    //////////////////////DEBUG//////////////////////
}

//Button Hook Functions
void Button_EnabledHook(int x,int y)
{
    pc.printf("%c\n",LookUpButtonTable(x,y));
}
