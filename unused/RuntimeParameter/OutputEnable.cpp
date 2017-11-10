#include "OutputEnable.h"

OutputEnable::OutputEnable()
{
    setRuntimeParameterID(0xA0);
}

OutputEnable * OutputEnable::enableDSPStatus(bool enable)
{
    if (enable)
        value[4] |= 0x01;
    else value[4] &= 0xFE;
    value[8] |= 0x01;
    return this;
}

OutputEnable * OutputEnable::enableGestureData(bool enable)
{
    if (enable)
        value[4] |= 0x02;
    else value[4] &= 0xFD;
    value[8] |= 0x02;
    return this;
}

OutputEnable * OutputEnable::enableTouchInfo(bool enable)
{
    if (enable)
        value[4] |= 0x04;
    else value[4] &= 0xFB;
    value[8] |= 0x04;
    return this;
}

OutputEnable * OutputEnable::enableAirWheelInfo(bool enable)
{
    if (enable)
        value[4] |= 0x08;
    else value[4] &= 0xF7;
    value[8] |= 0x08;
    return this;
}

OutputEnable * OutputEnable::enablexyzPosition(bool enable)
{
    if (enable)
        value[4] |= 0x10;
    else value[4] &= 0xEF;
    value[8] |= 0x10;
    return this;
}

OutputEnable * OutputEnable::enableNoisePower(bool enable)
{
    if (enable)
        value[4] |= 0x20;
    else value[4] &= 0xDF;
    value[8] |= 0x20;
    return this;
}

OutputEnable * OutputEnable::enableUncalibratedSignal(bool enable)
{
    if (enable)
        value[5] |= 0x08;
    else value[5] &= 0xF7;
    value[9] |= 0x08;
    return this;
}

OutputEnable * OutputEnable::enableSignalDeviation(bool enable)
{
    if (enable)
        value[5] |= 0x10;
    else value[5] &= 0xEF;
    value[9] |= 0x10;
    return this;
}

OutputEnable * OutputEnable::enableEnvironmentalNoise(bool enable)
{
    if (enable)
        value[6] |= 0x01;
    else value[6] &= 0xFE;
    value[10] |= 0x01;
    return this;
}

OutputEnable * OutputEnable::enableClipping(bool enable)
{
    if (enable)
        value[6] |= 0x02;
    else value[6] &= 0xFD;
    value[10] |= 0x02;
    return this;
}

OutputEnable * OutputEnable::enableDSP(bool enable)
{
    if (enable)
        value[6] |= 0x04;
    else value[6] &= 0xFB;
    value[10] |= 0x04;
    return this;
}

//If set, the AirWheel counter is decimated by the factor of 4
OutputEnable * OutputEnable::enableAirWheelCounterDecimation(bool enable)
{
    if (enable)
        value[6] |= 0x08;
    else value[6] &= 0xF7;
    value[10] |= 0x08;
    return this;
}

//This applies when AirWheel or Touch Detection is ongoing. If activated, a message will be sent when the counter in the payload element TimeStamp is overflowing (TimeStamp=0)
OutputEnable * OutputEnable::enableTimeStampOverflow(bool enable)
{
    if (enable)
        value[6] |= 0x10;
    else value[6] &= 0xEF;
    value[10] |= 0x10;
    return this;
}

//GesturesInfo status bits: If set to ‘1’, the reporting of a state change in the payload element GestureInfo is enabled.
OutputEnable * OutputEnable::enableHandPresence(bool enable)
{
    if (enable)
        value[7] |= 0x08;
    else value[7] &= 0xF7;
    value[11] |= 0x08;
    return this;
}

//GesturesInfo status bits: If set to ‘1’, the reporting of a state change in the payload element GestureInfo is enabled.
OutputEnable * OutputEnable::enableHandHold(bool enable)
{
    if (enable)
        value[7] |= 0x10;
    else value[7] &= 0xEF;
    value[11] |= 0x10;
    return this;
}

//GesturesInfo status bits: If set to ‘1’, the reporting of a state change in the payload element GestureInfo is enabled.
OutputEnable * OutputEnable::enableHandInside(bool enable)
{
    if (enable)
        value[7] |= 0x20;
    else value[7] &= 0xDF;
    value[11] |= 0x20;
    return this;
}

OutputEnable * OutputEnable::enableGestureInProgress(bool enable)
{
    if (enable)
        value[7] |= 0x80;
    else value[7] &= 0x7F;
    value[11] |= 0x80;
    return this;
}