#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_ApproachDetection
#define UK_AC_HERTS_SMARTLAB_MGC3130_AirWheelDetection

#include "Parameter.h"

class ApproachDetection: public Parameter
{
public:
    ApproachDetection(bool enable) {
        setRuntimeParameterID(0x97);
        if (enable)
            setArgument0(0x01);
        else
            setArgument0(0x00);
        setArgument1(0x01);
    }
};

#endif