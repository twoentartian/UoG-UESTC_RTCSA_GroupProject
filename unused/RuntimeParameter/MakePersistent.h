#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_MakePersistent
#define UK_AC_HERTS_SMARTLAB_MGC3130_MakePersistent

#include "Parameter.h"

/// Make the parameter set defined in Argument0 persistent (store to Flash memory).
class MakePersistent: public Parameter
{
public:
    /// The default setting will be Store RTPs for AFE Category.
    MakePersistent() {
        setRuntimeParameterID(0xFF00);
    }

    /// Store RTPs for AFE Category.
    void StoreRTPsAFECategory() {
        setArgument0(0x00000000);
    }

    /// Store RTPs for DSP Category.
    void StoreRTPsDSPCategory() {
        setArgument0(0x00000001);
    }

    /// Store RTPs for System Category.
    void StoreRTPsSystemCategory() {
        setArgument0(0x00000002);
    }
};

#endif