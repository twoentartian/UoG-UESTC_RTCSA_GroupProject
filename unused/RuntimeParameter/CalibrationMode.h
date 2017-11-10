#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_CalibrationMode
#define UK_AC_HERTS_SMARTLAB_MGC3130_CalibrationMode

#include "Parameter.h"

/** This parameter enables/disables the selected auto-calibration feature.
*If a bit in Argument0 is set to ‘0’, the respective auto-calibration feature will be enabled.
*If a bit in Argument0 is set to ‘1’ the respective auto-calibration feature will be disabled.
*/
class CalibrationMode: public Parameter
{
public:
    CalibrationMode() {
        setRuntimeParameterID(0x80);
    }

    /// Enable/disable gesture-triggered calibration.
    void enableGestureTriggered(bool enable) {
        if (enable)
            value[4] |= 0xFE;
        else value[4] &= 0x01;
        value[8] |= 0x01;
    }

    /// Enable/disable negative calibration.
    void enableNegative(bool enable) {
        if (enable)
            value[4] |= 0xFD;
        else value[4] &= 0x02;
        value[8] |= 0x02;
    }

    /// Enable/disable idle calibration.
    void enableIdle(bool enable) {
        if (enable)
            value[4] |= 0xFB;
        else value[4] &= 0x04;
        value[8] |= 0x04;
    }

    /// Enable/disable invalidity value calibration, if values are completely out of range.
    void enableInvalidityValue(bool enable) {
        if (enable)
            value[4] |= 0xF7;
        else value[4] &= 0x08;
        value[8] |= 0x08;
    }

    /// Enable/disable calibration triggered by AFA
    void enableTriggeredAFA(bool enable) {
        if (enable)
            value[4] |= 0xEF;
        else value[4] &= 0x10;
        value[8] |= 0x10;
    }
};

#endif