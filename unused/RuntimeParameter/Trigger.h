#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_Trigger
#define UK_AC_HERTS_SMARTLAB_MGC3130_Trigger

#include "Parameter.h"

class Trigger: public Parameter
{
public:
    /// The default setting will be force re-calibration.
    Trigger() {
        setRuntimeParameterID(0x1000);
    }

    /// Force re-calibration.
    void ForceRecalibration() {
        setArgument0(0x00);
    }

    /**
    *Enter Deep Sleep 1: The wake-up sources from
    *Deep Sleep 1 are I2C0 Start bit detection or
    *MCLR Reset.
    *The system will resume from Deep Sleep on any
    *I2C messages sent on the bus, and the first I2C
    *message will be lost.
    */
    void EnterDeepSleep1() {
        setArgument0(0x00000002);
    }

    /**
    *Enter Deep Sleep 2: The wake-up source from
    *Deep Sleep 2 is a falling edge on External Interrupt
    *(IRQ0) or MCLR Reset.
    *The IRQ0 (EIO2) should be tied to High when this
    *command is sent unless the MGC3X30 resumes
    *directly after receiving it.
    */
    void EnterDeepSleep2() {
        setArgument0(0x00000003);
    }
};

#endif