#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_GestureProcessing
#define UK_AC_HERTS_SMARTLAB_MGC3130_GestureProcessing

#include "Parameter.h"

/**
*This parameter enables the in-built gestures. Disabling one gesture will increase the
*recognition probability of the others.
*If a bit in Argument0 is set To ‘1’, the respective Gesture will be enabled. If a bit in
*Argument0 is set To ‘0’, the respective Gesture will be disabled.
*/
class GestureProcessing: public Parameter
{
public:
    GestureProcessing() {
        setRuntimeParameterID(0x85);
    }

    void enableGarbageModel(bool enable) {
        if (enable)
            value[4] |= 0x01;
        else value[4] &= 0xFE;
        value[8] |= 0x01;
    }

    void enableFlickWesToEast(bool enable) {
        if (enable)
            value[4] |= 0x02;
        else value[4] &= 0xFD;
        value[8] |= 0x02;
    }

    void enableFlickEastToWest(bool enable) {
        if (enable)
            value[4] |= 0x04;
        else value[4] &= 0xFB;
        value[8] |= 0x04;
    }

    void enableFlickSouthToNorth(bool enable) {
        if (enable)
            value[4] |= 0x08;
        else value[4] &= 0xF7;
        value[8] |= 0x08;
    }

    void enableFlickNorthToSouth(bool enable) {
        if (enable)
            value[4] |= 0x10;
        else value[4] &= 0xEF;
        value[8] |= 0x10;
    }

    void enableCircleClockwise(bool enable) {
        if (enable)
            value[4] |= 0x20;
        else value[4] &= 0xDF;
        value[8] |= 0x20;
    }

    void enableCircleCounterclockwise(bool enable) {
        if (enable)
            value[4] |= 0x40;
        else value[4] &= 0xBF;
        value[8] |= 0x40;
    }

    void enableWaveX(bool enable) {
        if (enable)
            value[4] |= 0x80;
        else value[4] &= 0x7F;
        value[8] |= 0x80;
    }

    void enableWaveY(bool enable) {
        if (enable)
            value[5] |= 0x01;
        else value[5] &= 0xFE;
        value[9] |= 0x01;
    }

    void enableHoldGesture(bool enable) {
        if (enable)
            value[6] |= 0x40;
        else value[6] &= 0xBF;
        value[10] |= 0x40;
    }

    void enablePresenceGesture(bool enable) {
        if (enable)
            value[6] |= 0x80;
        else value[6] &= 0x7F;
        value[10] |= 0x80;
    }

    void enableEdgeFlickWestToEast(bool enable) {
        if (enable)
            value[7] |= 0x01;
        else value[7] &= 0xFE;
        value[11] |= 0x01;
    }

    void enableEdgeFlickEastToWest(bool enable) {
        if (enable)
            value[7] |= 0x02;
        else value[7] &= 0xFD;
        value[11] |= 0x02;
    }

    void enableEdgeFlickSouthToNorth(bool enable) {
        if (enable)
            value[7] |= 0x04;
        else value[7] &= 0xFB;
        value[11] |= 0x04;
    }

    void enableEdgeFlickNorthToSouth(bool enable) {
        if (enable)
            value[7] |= 0x08;
        else value[7] &= 0xF7;
        value[11] |= 0x08;
    }

    void enableDoubleFlickWestToEast(bool enable) {
        if (enable)
            value[7] |= 0x10;
        else value[7] &= 0xEF;
        value[11] |= 0x10;
    }

    void enableDoubleFlickEastToWest(bool enable) {
        if (enable)
            value[7] |= 0x20;
        else value[7] &= 0xDF;
        value[11] |= 0x20;
    }

    void enableDoubleFlickSouthToNorth(bool enable) {
        if (enable)
            value[7] |= 0x40;
        else value[7] &= 0xBF;
        value[11] |= 0x40;
    }

    void enableDoubleFlickNorthToSouth(bool enable) {
        if (enable)
            value[7] |= 0x80;
        else value[7] &= 0x7F;
        value[11] |= 0x80;
    }
};

#endif