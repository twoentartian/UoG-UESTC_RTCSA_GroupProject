// //Author:twoentartian
// //Date:11/6/2017 (MDY)

#include "mbed.h"
#include "rtos.h"
#include "TextLCD.h"

#include "button.h"
#include "LCD2004.h"

Serial pc(USBTX,USBRX);
Serial nano(PC_12,PD_2);
AnalogOut Speaker(PA_5);
AnalogIn Microphone(PB_1);

volatile bool ButtonRefreshThreadRunSign = true;
volatile bool GestureInfoThreadRunSign = true;
volatile bool LcdRefreshThreadRunSign = true;
volatile bool SpeakerThreadRunSign = true;
volatile bool MicrophoneThreadRunSign = true;

volatile int ButtonRefreshThreadDelayTime = 50;
volatile int GestureInfoThreadDelayTime = 100;
volatile int LcdRefreshThreadDelayTime = 500;
volatile int SpeakerThreadDelayTime = 1000;
volatile int MicrophoneThreadDelayTime = 1000;

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

void SpeakerThreadFunc()
{
    while(true)
    {
        if(SpeakerThreadRunSign)
        {

        }
        Thread::wait(SpeakerThreadDelayTime);
    }
}

void MicrophoneThreadFunc()
{
    while(true)
    {
        if(MicrophoneThreadRunSign)
        {

        }
        Thread::wait(MicrophoneThreadDelayTime);
    }
}

int main()
{
    Init();
    DigitalOut SystemLed(LED1);

    //Start Thread
    Thread ButtonRefreshThread;
    Thread GestureInfoThread;
    Thread LcdRefreshThread;
    Thread SpeakerThread;
    Thread MicrophoneThread;

    ButtonRefreshThread.start(callback(ButtonRefreshThreadFunc));
    GestureInfoThread.start(callback(GestureInfoThreadFunc));
    LcdRefreshThread.start(callback(LcdRefreshThreadFunc));
    SpeakerThread.start(callback(SpeakerThreadFunc));
    MicrophoneThread.start(callback(MicrophoneThreadFunc));

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
