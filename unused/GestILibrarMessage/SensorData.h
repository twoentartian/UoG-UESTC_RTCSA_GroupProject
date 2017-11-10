#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_SensorData
#define UK_AC_HERTS_SMARTLAB_MGC3130_SensorData

#include "GestICMsg.h"
#include "TouchInfo.h"
#include "GestureInfo.h"

/** This message contains the sensor data output of the MGC3X30. The content of the
*message can be configured via bit mask.The elements DataOutputConfigMask, TimeStamp, and SystemInfo are always part of the
*message. The inclusion of further payload elements depends on the Configuration, and the
*actual Configuration can be read from the payload element. DataOutputConfigMask.
*/
class SensorData : public GestICMsg
{
private:
    /** -1 means value not included, so that is... can return false
    * to convet the value is... valid still required
    *
    *   Bit 0: DSPStatus field.
    *   Bit 1: GestureInfo field.
    *   Bit 2: TouchInfo field.
    *   Bit 3: AirWheelInfo field.
    *   Bit 4: xyzPosition field.
    *   Bit 5: NoisePower field.
    *   Bit 6...10: These bits are reserved.
    *   Bit 11: CICData field.
    *   Bit 12: SDData field.
    *   Bit 13...15: These bits are reserved.
    */
    int _DSPStatus; // 2 bytes
    int _GestureInfo; // 4 bytes
    int _TouchInfo; // 4 bytes
    int _AirWheelInfo; // 2 bytes
    int _xyzPosition; // 6 bytes
    int _NoisePower; // 4 bytes
    int _CICData; // 20 bytes
    int _SDData; // 20 bytes

    /** set is... when converting from GestICMsg to SensorData
    *
    *Bit mask indicating if the respective sensor data is valid. In an application, the sensor data output should only be further processed if the respective bits are set to ‘1’.
    *The following bits are used:
    *Bit 0: PositionValid, if set indicates that the position in the xyzPosition field is valid.
    *Bit 1: AirWheelValid, if set indicates that the AirWheel is active and the data in the AirWheelInfo field is valid.
    *Bit 2: RawDataValid, if set indicates that the data of the CICData and SDData fields are valid; otherwise those fields must be ignored.
    *Bit 3: NoisePowerValid, if set indicates that the NoisePower field is valid.
    *Bit 4: EnvironmentalNoise, if set indicates that environmental noise has been detected.
    *Bit 5: Clipping, if set indicates that the ADCs are clipping.
    *Bit 6: This bit is reserved.
    *Bit 7: DSPRunning, if set indicates that the system is currently running. If not set, the system is about to go to Sleep.
    */
    void process();

    int xyz[3];
    TouchInfo touch;
    float raw[5];
    GestureInfo gesture;

public:
    /// Construct a empty message.
    SensorData();
    
    /** Construct a message with existing @GestICMsg as its base.
    *
    * @param msg received @GestICMsg message
    *
    */
    SensorData(GestICMsg * msg);

    /** Apply existing @GestICMsg as its content.
    *
    * @param msg received @GestICMsg message, used by API itself.
    *
    * @returns
    *   true current @GestICMsg is a sensor payload and content has been updated.
    *   false current @GestICMsg is not sensor payload and content not affected.
    *
    */
    bool convert(GestICMsg * msg);


    /** Check if DPS status information is included.
    *
    * @returns
    *       true included
    *       false not included
    */
    bool isDSPStatus();

    /** Check if the gesture information is included.
    *
    * @returns
    *       true included
    *       false not included
    */
    bool isGestureInfo();

    /** Check if touch information is included.
    *
    * @returns
    *       true included
    *       false not included
    */
    bool isTouchInfo();

    /** Check if air wheel information is included.
    *
    * @returns
    *       true included
    *       false not included
    */
    bool isAirWheelInfo();

    /** Check if xyz position information is included.
    *
    * @returns
    *       true included
    *       false not included
    */
    bool isxyzPosition();

    /** Check if noise power information is included.
    *
    * @returns
    *       true included
    *       false not included
    */
    bool isNoisePower();

    /** Check if uncalibrated sensor data is included.
    *
    * @returns
    *       true included
    *       false not included
    */
    bool isCICData();

    /** Check if signal deviation dtat is included.
    *
    * @returns
    *       true included
    *       false not included
    */
    bool isSDData();

  
    /** Check if the position in the xyzPosition field is valid.
    *
    * @returns
    *       true valid
    *       false not valid
    */
    bool isPositionValid();
    
    /** Check if the AirWheel is active and the data in the AirWheelInfo field is valid.
    *
    * @returns
    *       true valid
    *       false not valid
    */
    bool isAirWheelValid();
    
    /** Check if raw data is valid, if set indicates that the data of the CICData and SDData fields are valid; otherwise those fields must be ignored.
    *
    * @returns
    *       true valid
    *       false not valid
    */
    bool isRawDataValid();
    
    /** Check if the NoisePower field is valid.
    *
    * @returns
    *       true valid
    *       false not valid
    */
    bool isNoisePowerValid();
    
    /** Check if the environmental noise has been detected.
    *
    * @returns
    *       true valid
    *       false not valid
    */
    bool isEnvironmentalNoise();
    
    /** Check if the the ADCs are clipping.
    *
    * @returns
    *       true valid
    *       false not valid
    */
    bool isClipping();
    
    /** Check if the system is currently running. If not set, the system is about to go to Sleep.
    *
    * @returns
    *       true valid
    *       false not valid
    */
    bool isDSPRunning();

    /** 
    *200 Hz counter value wraps around after 256 ticks. This indicates when an
    *event has taken place and allows measuring the elapsed time between two
    *events, as long as it is below approximately 1.25 seconds.
    *
    * @returns 8-Bit Counter of 200 Hz (Sample Interval)
    *
    */
    int getTimeStamp();
    
    /** Get detailed gesture information.
    *
    * @returns @GestureInfo NULL means data not avaliable
    *
    */
    GestureInfo * getGestureInfo();

    /** Get detailed touch information.
    *
    * @returns @TouchInfo NULL means data not avaliable
    *
    */
    TouchInfo * getTouchInfo();

    /**
    *First: Value represents the current angular position with a resolution of 32 counts for a full revolution.
    *Second: [0 - 7] Counts of full rotations.
    *Each time the angular position crosses ‘0’, a full revolution is counted.
    *If the users hand is moving in clockwise direction the counter is
    *increased. For counterclockwise movements, the counter is decreased.
    *
    * @returns
    *   int array [angular,Counts]  NULL means data not avaliable
    */
    int * getAirWheelInfo();

    /** Get x, y and z position data.
    *
    * @returns
    *   int array [x,y,z]  NULL means data not avaliable
    *
    */
    int * getxyzPosition();

    /** Get noise power of the GestIC system.
    *
    * @return float value
    *
    */
    float getNoisePower();

    /**
    *Uncalibrated Sensor Data (CIC Data)
    *Structure: Vector of five, 32-bit Words interpreted as float values in format. An
    *offset of 32000 needs to be added to each channel.
    *xxxx.xxxx.xxxx.xxxx.xxxx (South.West.North.East.Center)
    *
    * @returns int array [South.West.North.East.Center]  NULL means data not avaliable
    *
    */
    float * getUncalibratedData();

    /** Get signal deviation
    *Structure: Vector of five, 32-bit Words interpreted as float values in xxxx.xxxx.xxxx.xxxx.xxxx (South.West.North.East.Center) format
    *
    * @returns int array [South.West.North.East.Center]  NULL means data not avaliable
    *
    */
    float * getSignalDeviation();
};

#endif