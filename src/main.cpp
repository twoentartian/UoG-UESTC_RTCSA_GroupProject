// //Author:twoentartian
// //Date:11/6/2017 (MDY)

#include "mbed.h"
#include "rtos.h"

#include "button.h"

Serial pc(USBTX,USBRX);
Serial nano(PC_12,PD_2);

void Init()
{
    pc.baud(115200);
    nano.baud(115200);
}

void ButtonRefreshThreadFunc()
{
    while(true)
    {
        Button_RefreshButtonState();
        Thread::wait(50);
    }
}

void GestureInfoThreadFunc()
{
    while(true)
    {
        while(nano.readable())
        {
            pc.putc(nano.getc());
        }
        Thread::wait(100);
    }
}

int main()
{
    Init();
    DigitalOut SystemLed(LED1);

    //Start Thread
    Thread ButtonRefreshThread;
    Thread GestureInfoThread;
    
    ButtonRefreshThread.start(callback(ButtonRefreshThreadFunc));
    GestureInfoThread.start(callback(GestureInfoThreadFunc));

    while(true)
    {
        SystemLed=!SystemLed;
        Thread::wait(500);
    }
}

//Button Hook Functions
void Button_EnabledHook(int x,int y)
{
    pc.printf("%c\n",LookUpButtonTable(x,y));
}
