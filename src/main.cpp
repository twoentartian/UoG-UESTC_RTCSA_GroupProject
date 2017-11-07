//Author:twoentartian
//Date:11/6/2017 (MDY)

#include "mbed.h"
#include "rtos.h"

#include "button.h"

Serial pc(USBTX,USBRX);

int main()
{
    pc.baud(115200);
    while(true)
    {
        RefreshButtonState();
        Thread::wait(20);
    }
}

//Button Hook Functions
void ButtonEnabledHook(int x,int y)
{
    pc.printf("%c\n",LookUpButtonTable(x,y));
}