#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_AirWheelDetection
#define UK_AC_HERTS_SMARTLAB_MGC3130_AirWheelDetection

#include "Parameter.h"

class AirWheelDetection: public Parameter
{
public:
    AirWheelDetection(bool enable) {
        setRuntimeParameterID(0x90);
        if (enable)
            setArgument0(0x20);
        else
            setArgument0(0x00);
        setArgument1(0x20);
    }
};

#endif