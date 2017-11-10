#include "TouchInfo.h"

void TouchInfo::set(int touchEvent, int counter)
{
    value = touchEvent;
    count = counter;
}

/*
Touch Counter: 8-bit counter; this counter determines the
period between the time when the hand starts moving to
touch until it is detected. This period is equal to [Touch
Counter Value] x 5 (ms). The counter starts counting when
the minimum approach speed required to detect a touch
event is exceeded, until the touch is detected. After each
touch detection, the counter is reset.
*/
int TouchInfo::getCounter()
{
    return count;
}

bool TouchInfo::isTouchSouthElectrode()
{
    return (value & TouchSouthElectrode) == TouchSouthElectrode? true : false;
}

bool TouchInfo::isTouchWestElectrode()
{
    return (value & TouchWestElectrode) == TouchWestElectrode? true : false;
}

bool TouchInfo::isTouchNorthElectrode()
{
    return (value & TouchNorthElectrode) == TouchNorthElectrode? true : false;
}

bool TouchInfo::isTouchEastElectrode()
{
    return (value & TouchEastElectrode) == TouchEastElectrode? true : false;
}

bool TouchInfo::isTouchCenterElectrode()
{
    return (value & TouchCenterElectrode) == TouchCenterElectrode? true : false;
}

bool TouchInfo::isTapSouthElectrode()
{
    return (value & TapSouthElectrode) == TapSouthElectrode? true : false;
}

bool TouchInfo::isTapWestElectrode()
{
    return (value & TapWestElectrode) == TapWestElectrode? true : false;
}

bool TouchInfo::isTapNorthElectrode()
{
    return (value & TapNorthElectrode) == TapNorthElectrode? true : false;
}

bool TouchInfo::isTapEastElectrode()
{
    return (value & TapEastElectrode) == TapEastElectrode? true : false;
}

bool TouchInfo::isTapCenterElectrode()
{
    return (value & TapCenterElectrode) == TapCenterElectrode? true : false;
}

bool TouchInfo::isDoubleTapSouthElectrode()
{
    return (value & DoubleTapSouthElectrode) == DoubleTapSouthElectrode? true : false;
}

bool TouchInfo::isDoubleTapWestElectrode()
{
    return (value & DoubleTapWestElectrode) == DoubleTapWestElectrode? true : false;
}

bool TouchInfo::isDoubleTapNorthElectrode()
{
    return (value & DoubleTapNorthElectrode) == DoubleTapNorthElectrode? true : false;
}

bool TouchInfo::isDoubleTapEastElectrode()
{
    return (value & DoubleTapEastElectrode) == DoubleTapEastElectrode? true : false;
}

bool TouchInfo::isDoubleTapCenterElectrode()
{
    return (value & DoubleTapCenterElectrode) == DoubleTapCenterElectrode? true : false;
}