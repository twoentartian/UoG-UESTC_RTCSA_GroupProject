
#include "rtos.h"
#include "mbed.h"

#define MAX_LED 3

DigitalOut led[MAX_LED] {LED1,LED2,LED3};

void toggle(void const *args)
{
    led[]=!led[];
}

int main()
{
    thread thread1(toggle);
    thread thread2(toggle);
    thread thread3(toggle);
    thread1.arg=0;
    thread2.arg=1;
    thread3.arg=2;

    while(1)
    {

    }
}
