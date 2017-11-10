#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_OutputEnable
#define UK_AC_HERTS_SMARTLAB_MGC3130_OutputEnable

#include "Parameter.h"
/*
The Argument0 defines which Data need to be enabled or disabled.
The Argument1 defines the mask for the Data which need to be configured.

Bits 0...12: Payload elements: If set to ‘1’, payload elements will be part of the message
Bit 0: DSP Status
Bit 1: Gesture Data
Bit 2: TouchInfo
Bit 3: AirWheelInfo
Bit 4: xyzPosition
Bit 5: Noise Power
Bit 6...10: These bits are reserved and must be set to ‘0’
Bit 11: CICData (Uncalibrated Signal)
Bit 12: SDData (Signal Deviation)
Bits 13...15: These bits are reserved and must be set to ‘0’
Bits 16...17: SystemInfo status bits: If set to ‘1’, the reporting of a state change in the payload element SystemInfo is enabled
Bit 16: EnvironmentalNoise indication
Bit 17: Clipping indication
Bit 18: DSP running
Bits 19: AirWheelCounterDecimation: If set to ‘1’, the AirWheel counter is decimated by the factor of 4
Bit 20: TimeStampOverflow: This applies when AirWheel or Touch Detection is ongoing. If activated, a message will be sent when the counter in the payload element TimeStamp is overflowing (TimeStamp=0)
Bits 21...26: These bits are reserved
Bits 27...31: GesturesInfo status bits: If set to ‘1’, the reporting of a state change in the payload element GestureInfo is enabled.
Bit 27: HandPresence flag
Bit 28: HandHold flag
Bit 29: HandInside flag
Bit 30: This bit is reserved
Bit 31: GestureInProgress flag
*/
class OutputEnable: public Parameter
{
public:
    OutputEnable();

    OutputEnable * enableDSPStatus(bool enable);

    OutputEnable * enableGestureData(bool enable);

    OutputEnable * enableTouchInfo(bool enable);

    OutputEnable * enableAirWheelInfo(bool enable);

    OutputEnable * enablexyzPosition(bool enable);

    OutputEnable * enableNoisePower(bool enable);

    OutputEnable * enableUncalibratedSignal(bool enable);

    OutputEnable * enableSignalDeviation(bool enable);

    OutputEnable * enableEnvironmentalNoise(bool enable);

    OutputEnable * enableClipping(bool enable);

    OutputEnable * enableDSP(bool enable);

    //If set, the AirWheel counter is decimated by the factor of 4
    OutputEnable * enableAirWheelCounterDecimation(bool enable);

    //This applies when AirWheel or Touch Detection is ongoing. If activated, a message will be sent when the counter in the payload element TimeStamp is overflowing (TimeStamp=0)
    OutputEnable * enableTimeStampOverflow(bool enable);

    //GesturesInfo status bits: If set to ‘1’, the reporting of a state change in the payload element GestureInfo is enabled.
    OutputEnable * enableHandPresence(bool enable);

    //GesturesInfo status bits: If set to ‘1’, the reporting of a state change in the payload element GestureInfo is enabled.
    OutputEnable * enableHandHold(bool enable);

    //GesturesInfo status bits: If set to ‘1’, the reporting of a state change in the payload element GestureInfo is enabled.
    OutputEnable * enableHandInside(bool enable);

    OutputEnable * enableGestureInProgress(bool enable);
};

#endif