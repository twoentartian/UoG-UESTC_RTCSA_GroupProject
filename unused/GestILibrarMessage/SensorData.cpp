#include "SensorData.h"

SensorData::SensorData()
    :GestICMsg(), touch(), gesture()
{}

SensorData::SensorData(GestICMsg * msg)
    :GestICMsg(), touch(), gesture()
{
    data = msg->gets();
    process();
}

bool SensorData::convert(GestICMsg * msg)
{
    if (msg == NULL)
        return false;

    if (msg->getID() != Sensor_Data_Output)
        return false;

    data = msg->gets();
    process();
    return true;
}

void SensorData::process()
{
    int temp = 8;
    if ((data[4] & 0x01) == 0x01) {
        _DSPStatus = temp;
        temp += 2;
    } else _DSPStatus =-1;

    if ((data[4] & 0x02) == 0x02) {
        _GestureInfo = temp;
        temp += 4;
    } else _GestureInfo =-1;

    if ((data[4] & 0x04) == 0x04) {
        _TouchInfo = temp;
        temp += 4;
    } else _TouchInfo =-1;

    if ((data[4] & 0x08) == 0x08) {
        _AirWheelInfo = temp;
        temp += 2;
    } else _AirWheelInfo =-1;

    if ((data[4] & 0x10) == 0x10) {
        _xyzPosition = temp;
        temp += 6;
    } else _xyzPosition =-1;

    if ((data[4] & 0x20) == 0x20) {
        _NoisePower = temp;
        temp += 4;
    } else _NoisePower =-1;

    if ((data[5] & 0x08) == 0x08) {
        _CICData = temp;
        temp += 20;
    } else _CICData =-1;

    if ((data[5] & 0x10) == 0x10) {
        _SDData = temp;
        temp += 20;
    } else _SDData =-1;

}
////////////////////////////////////////////////////////////////////////////////////
bool SensorData::isDSPStatus()
{
    if (_DSPStatus < 0)
        return false;
    else return true;
}

bool SensorData::isGestureInfo()
{
    if (_GestureInfo < 0)
        return false;
    else return true;
}

bool SensorData::isTouchInfo()
{
    if (_TouchInfo < 0)
        return false;
    else return true;
}

bool SensorData::isAirWheelInfo()
{
    if (_AirWheelInfo < 0)
        return false;
    else return true;
}

bool SensorData::isxyzPosition()
{
    if (_xyzPosition < 0)
        return false;
    else return true;
}

bool SensorData::isNoisePower()
{
    if (_NoisePower < 0)
        return false;
    else return true;
}

bool SensorData::isCICData()
{
    if (_CICData < 0)
        return false;
    else return true;
}

bool SensorData::isSDData()
{
    if (_SDData < 0)
        return false;
    else return true;
}

///////////////////////////////////////////////////////////////////////////
int SensorData::getTimeStamp()
{
    return data[6];
}

////////////////////////////////////////////////////////////////////////
bool SensorData::isPositionValid()
{
    if ((data[7] & 0x01) == 0x01)
        return true;
    else return false;
}

bool SensorData::isAirWheelValid()
{
    if ((data[7] & 0x02) == 0x02)
        return true;
    else return false;
}

bool SensorData::isRawDataValid()
{
    if ((data[7] & 0x04) == 0x04)
        return true;
    else return false;
}

bool SensorData::isNoisePowerValid()
{
    if ((data[7] & 0x08) == 0x08)
        return true;
    else return false;
}

bool SensorData::isEnvironmentalNoise()
{
    if ((data[7] & 0x10) == 0x10)
        return true;
    else return false;
}

bool SensorData::isClipping()
{
    if ((data[7] & 0x20) == 0x20)
        return true;
    else return false;
}

bool SensorData::isDSPRunning()
{
    if ((data[7] & 0x80) == 0x80)
        return true;
    else return false;
}


int * SensorData::getxyzPosition()
{
    if (_xyzPosition < 0)
        return NULL;

    if (!isPositionValid())
        return NULL;

    xyz[0] = (data[_xyzPosition + 1]<< 8) | data[_xyzPosition];
    xyz[1] = (data[_xyzPosition + 3]<< 8) | data[_xyzPosition + 2];
    xyz[2] = (data[_xyzPosition + 5]<< 8) | data[_xyzPosition + 4];

    return xyz;
}

TouchInfo * SensorData::getTouchInfo()
{
    if (_TouchInfo < 0)
        return NULL;

    touch.set((data[_TouchInfo] << 8) | data[_TouchInfo + 1], data[_TouchInfo + 2]);

    return &touch;
}

int * SensorData::getAirWheelInfo()
{
    if (_AirWheelInfo < 0)
        return NULL;

    if (!isAirWheelValid())
        return NULL;

    xyz[0] = data[_AirWheelInfo] >> 3;
    xyz[1] = data[_AirWheelInfo] & 0x07;

    return xyz;
}

float SensorData::getNoisePower()
{
    if (_NoisePower < 0)
        return 0;

    if (!isNoisePowerValid())
        return 0;

    float noise = -3;
    memcpy(&noise, data + _NoisePower, 4);
    return noise;
}

float * SensorData::getUncalibratedData()
{
    if (_CICData < 0)
        return NULL;

    if (!isRawDataValid())
        return NULL;

    memcpy(raw, data +_CICData , 20);

    return raw;
}

float * SensorData::getSignalDeviation()
{
    if (_SDData < 0)
        return NULL;

    if (!isRawDataValid())
        return NULL;

    memcpy(raw, data +_SDData , 20);

    return raw;
}

GestureInfo * SensorData::getGestureInfo()
{
    if (_GestureInfo < 0)
        return NULL;

    gesture.set(data + _GestureInfo);

    return &gesture;
}