#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_Parameter
#define UK_AC_HERTS_SMARTLAB_MGC3130_Parameter

#include "mbed.h"

class Parameter
{
protected:
    char value[12];

public:
    static const int Length = 12;

    char * gets() {
        return value;
    }

    void setRuntimeParameterID(int id) {
        value[0] = id;
        value[1] = id >> 8;
    }

    void setArgument0(long arg0) {
        value[4] = arg0;
        value[5] = arg0 >> 8;
        value[6] = arg0 >> 16;
        value[7] = arg0 >> 24;
    }

    void setArgument1(long arg1) {
        value[8] = arg1;
        value[9] = arg1 >> 8;
        value[10] = arg1 >> 16;
        value[11] = arg1 >> 24;
    }
};

#endif