#include "GestureInfo.h"

void GestureInfo::set(unsigned char * value)
{
    data = value;
}

int GestureInfo::getRecognizedGesture()
{
    return data[0];
}

int GestureInfo::getGestureClass()
{
    return (data[1] & 0xF0) >> 4;
}

bool GestureInfo::isEdgeFlick()
{
    return (data[2] & 0x01) == 0x01? true: false;
}

bool GestureInfo::isHandPresence()
{
    return (data[3] & 0x08) == 0x08? true: false;
}

bool GestureInfo::isHandHold()
{
    return (data[3] & 0x10) == 0x10? true: false;
}

bool GestureInfo::isHandInside()
{
    return (data[3] & 0x20) == 0x20? true: false;
}

bool GestureInfo::isRecognitionInProcess()
{
    return (data[3] & 0x80) == 0x80? true: false;
}