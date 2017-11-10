#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_TouchDetection
#define UK_AC_HERTS_SMARTLAB_MGC3130_TouchDetection

#include "Parameter.h"

class TouchDetection: public Parameter
{
public:
    TouchDetection(bool enable) {
        setRuntimeParameterID(0x97);
        if (enable)
            setArgument0(0x08);
        else
            setArgument0(0x00);
        setArgument1(0x08);
    }
};

#endif