#include "mbed.h"
#include "rtos.h"

#define MAX_LED 3

DigitalOut led[MAX_LED] {LED1,LED2,LED3};
Serial pc(USBTX,USBRX);

void threadLedFunc(void)
{
    while(true)
    {
        for(int loc=0;loc<MAX_LED;loc++)
        {
            for(int i=0;i<MAX_LED;i++)
            {
                led[i]=0;
            }
            led[loc]=1;
            Thread::wait(100);
        }
        pc.printf("hfuadisfh");
    }
}

int main()
{
    pc.baud(115200);
    Thread threadLed;
    threadLed.start(threadLedFunc);
    while(true)
    {
        Thread::wait(1000);
    }
}
