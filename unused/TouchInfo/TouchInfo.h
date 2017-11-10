#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_TouchInfo
#define UK_AC_HERTS_SMARTLAB_MGC3130_TouchInfo

/// Contains touch information
class TouchInfo
{
private:
    /** 2 bytes bit mask
    *Bit 0: Touch South electrode
    *Bit 1: Touch West electrode
    *Bit 2: Touch North electrode
    *Bit 3: Touch East electrode
    *Bit 4: Touch Center electrode
    *Bit 5: Tap South electrode
    *Bit 6: Tap West electrode
    *Bit 7: Tap North electrode
    *Bit 8: Tap East electrode
    *Bit 9: Tap Center electrode
    *Bit 10: Double Tap South electrode
    *Bit 11: Double Tap West electrode
    *Bit 12: Double Tap North electrode
    *Bit 13: Double Tap East electrode
    *Bit 14: Double Tap Center electrode
    *Bit 15: This bit is reserved.
    */
    int value;

    /** Bits 16...23:Touch Counter: 8-bit counter; this counter determines the
    *period between the time when the hand starts moving to
    *touch until it is detected. This period is equal to [Touch
    *Counter Value] x 5 (ms). The counter starts counting when
    *the minimum approach speed required to detect a touch
    *event is exceeded, until the touch is detected. After each
    *touch detection, the counter is reset.
    *Bits 24...31:These bits are reserved.
    */
    int count;
    
    static const int TouchSouthElectrode = 0x0100;
    static const int TouchWestElectrode = 0x0200;
    static const int TouchNorthElectrode = 0x0400;
    static const int TouchEastElectrode = 0x0800;
    static const int TouchCenterElectrode = 0x1000;
    static const int TapSouthElectrode = 0x2000;
    static const int TapWestElectrode = 0x4000;
    static const int TapNorthElectrode = 0x8000;
    static const int TapEastElectrode = 0x0001;
    static const int TapCenterElectrode = 0x0002;
    static const int DoubleTapSouthElectrode = 0x0004;
    static const int DoubleTapWestElectrode = 0x0008;
    static const int DoubleTapNorthElectrode = 0x0010;
    static const int DoubleTapEastElectrode = 0x0020;
    static const int DoubleTapCenterElectrode = 0x0040;

public:
    /** Set the internal memory, used by API itself.
    *
    * @param touchEvent 2 bytes bit mask
    * @param counter 1 byte
    */
    void set(int touchEvent, int counter);

    /**
    *Touch Counter: this counter determines the
    *period between the time when the hand starts moving to
    *touch until it is detected. This period is equal to [Touch
    *Counter Value] x 5 (ms). The counter starts counting when
    *the minimum approach speed required to detect a touch
    *event is exceeded, until the touch is detected. After each
    *touch detection, the counter is reset.
    *
    * @returns 8-bit counter
    */
    int getCounter();

    /** Check if touch south electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTouchSouthElectrode();

    /** Check if touch west electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTouchWestElectrode();

    /** Check if touch north electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTouchNorthElectrode();

    /** Check if touch east electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTouchEastElectrode();

    /** Check if touch center electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTouchCenterElectrode();

    /** Check if tap south electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTapSouthElectrode();

    /** Check if tap west electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTapWestElectrode();

    /** Check if tap north electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTapNorthElectrode();

    /** Check if tap east electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTapEastElectrode();

    /** Check if tap center electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isTapCenterElectrode();

    /** Check if double tap south electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isDoubleTapSouthElectrode();

    /** Check if double tap west electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isDoubleTapWestElectrode();

    /** Check if double tap north electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isDoubleTapNorthElectrode();

    /** Check if double tap east electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isDoubleTapEastElectrode();

    /** Check if double tap center electrode is detected.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isDoubleTapCenterElectrode();
};

#endif