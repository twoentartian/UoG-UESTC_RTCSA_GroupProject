

#include "rtos.h"
#include "mbed.h"
#include "MGC3130.h"

SensorData * msg = NULL;

MGC3130 device(D14,D15,PC_6,false);

void init()
{
    AirWheelDetection air(true);
    device.setRuntimeParameter(&air);

    TouchDetection touch(true);
    device.setRuntimeParameter(&touch);

    OutputEnable setting;
    setting.enableGestureData(true)->enableTouchInfo(true)->enableAirWheelInfo(true)->enableNoisePower(false)
    ->enablexyzPosition(false)->enableDSPStatus(false)->enableUncalibratedSignal(false)->enableSignalDeviation(false);
    device.setRuntimeParameter(&setting);
}

void touch()
{
    TouchInfo * info = msg->getTouchInfo();

    if (info == NULL)
        return;

    if (info->isTapCenterElectrode() == false)
        return;
}

void airWheel()
{
    int * wheel = msg->getAirWheelInfo();
    if (wheel == NULL)
        return;
}

void gesture()
{
    Serial pc(USBTX,USBRX);
    pc.baud(115200);

    GestureInfo * info = msg->getGestureInfo();

    if (info == NULL)
        return;

    switch (info->getRecognizedGesture()) {
            //Garbage Model
        case 1 :
            pc.printf("Right\n");
            break;
            //Flick West To East
        case 2 :
            pc.printf("Left\n");
            break;
            //Flick East To West
        case 3 :
            pc.printf("Up\n");
            break;
            //Flick South To North
        case 4 :
            pc.printf("Down\n");
            break;
            //Flick North To South
        case 5 :
            break;
    }
}

int main()
{
    Serial pc(USBTX,USBRX);
    pc.baud(115200);

    init();

    pc.printf("Enter loop\n");
    while(1)
    {
        msg = device.readSensorData();

        if (msg == NULL)
        {
            pc.printf("continue\n");
            continue;
        }
        touch();

        gesture();

        airWheel();

        pc.printf("loop finish\n");
    }
}