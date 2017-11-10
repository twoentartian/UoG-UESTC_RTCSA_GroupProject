#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_GestuerInfo
#define UK_AC_HERTS_SMARTLAB_MGC3130_GestuerInfo

/** Recognized Gestures:
* The recognized gestures are results of the HMM classification. Edge detection
* can be used to further classify where the gesture has been done (Edge
* Flicks). Furthermore, gesture attributes give information about the direction of
* the flick.
*/
class GestureInfo
{
private:

    /// 4 bytes gesture information.
    unsigned char * data;
public:

    /** Set the internal memory, used by API itself.
    *
    * @param value 4 bytes char array
    */
    void set(unsigned char * value);

    /** Get the recognized gesture information.
    *
    * @returns
            0 No Gesture
            1 Garbage Model
            2 Flick West To East
            3 Flick East To West
            4 Flick South To North,
            5 Flick North To South
            6 Circle Clockwise, only active if AirWheel disabled
            7 Circle Counterclockwise, only active if AirWheel disabled
            8 WaveX
            9 WaveY
            64 Hold
            73 Presence
            65 Edge Flick West To East
            66 Edge Flick East To West
            67 Edge Flick South To North
            68 Edge Flick North To South
            69 Double Flick West To East
            70 Double Flick East To West
            71 Double Flick South To North
            72 Double Flick North To South
    */
    int getRecognizedGesture();

    /** Get the recognized gesture class.
    *
    * @returns
    *       0 Garbage Model
    *       1 Flick Gesture
    *       2 Circula Gesture
    */
    int getGestureClass();

    /** Check if the recognized gesture is classified as edge flick.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isEdgeFlick();
    
    /** Check if the user’s hand is within the sensing space.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isHandPresence();
    
    /** Check if the hand is not moving. Further dependencies can be adjusted inside Aurea Parametrization.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isHandHold();

    /** Check if the user’s hand is approximately above the sensor.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isHandInside();
    
    /** Check if the gesture recognition in progress. This bit is set when the Gesture Recognizer is active and Reset when the gesture is recognized and the Recognizer is Off.
    *
    * @returns
    *       true qualified
    *       false not qualified
    */
    bool isRecognitionInProcess();
};

#endif