#ifndef UK_AC_HERTS_SMARTLAB_MGC3130
#define UK_AC_HERTS_SMARTLAB_MGC3130

#include "mbed.h"
#include "GestICMsg.h"
#include "SensorData.h"
#include "Parameter.h"
#include "TouchDetection.h"
#include "AirWheelDetection.h"
#include "ApproachDetection.h"
#include "TouchInfo.h"
#include "OutputEnable.h"
#include "Trigger.h"
#include "MakePersistent.h"
#include "CalibrationMode.h"
#include "GestureProcessing.h"

/**
* Outlines the function of the Library’s I2C message interface, and contains the complete message reference to control and operate the MGC3X30 system.
 *
 * Example:
 * @code
*#include "mbed.h"
*#include "MGC3130.h"
*
*SensorData * msg = NULL;
*
*void init()
*{
*    AirWheelDetection air(true);
*    device.setRuntimeParameter(&air);
*
*    TouchDetection touch(true);
*    device.setRuntimeParameter(&touch);
*
*    OutputEnable setting;
*    setting.enableGestureData(true)->enableTouchInfo(true)->enableAirWheelInfo(true)->enableNoisePower(false)
*    ->enablexyzPosition(false)->enableDSPStatus(false)->enableUncalibratedSignal(false)->enableSignalDeviation(false);
*    device.setRuntimeParameter(&setting);
*}
*
*void touch()
*{
*    TouchInfo * info = msg->getTouchInfo();
*
*    if (info == NULL)
*        return;
*
*    if (info->isTapCenterElectrode() == false)
*        return;
*}
*
*void airWheel()
*{
*    int * wheel = msg->getAirWheelInfo();
*    if (wheel == NULL)
*        return;
*}
*
*void gesture()
*{
*    GestureInfo * info = msg->getGestureInfo();
*
*    if (info == NULL)
*        return;
*
*    switch (info->getRecognizedGesture()) {
*            //Garbage Model
*        case 1 :
*            break;
*            //Flick West To East
*        case 2 :
*            break;
*            //Flick East To West
*        case 3 :
*            break;
*            //Flick South To North
*        case 4 :
*            break;
*            //Flick North To South
*        case 5 :
*            break;
*    }
*}
*
*int main()
*{
*    init();
*
*    while(1) {
*        msg = device.readSensorData();
*
*        if (msg == NULL)
*            continue;
*
*        touch();
*
*        gesture();
*
*        airWheel();
*    }
*}
 * @endcode
 *
*/
class MGC3130
{
private:
    static const int FREQUENCY_STANDARD = 100000;
    static const int FREQUENCY_FULL = 400000;
    static const int FREQUENCY_FAST = 1000000;
    static const int FREQUENCY_HIGH = 3200000;

    /// EI0 Pin:  The TS line is used to check whether the I2C data is valid and can be sent from MGC3X30 to the host controller.
    DigitalInOut TS_Line;

    I2C _i2c_bus;
    int _speed;
    int _addr;
    GestICMsg msg;
    SensorData sensor;

protected:
    GestICMsg * readMsg();

public:
    /** Construct a message with existing @GestICMsg as its base.
    * IS2 is available for address selection and enables the user to connect up to two MGC3X30 devices on the same bus without address conflict.
    * The MGC3X30 I2C addresses are 0x42 and 0x43. They are given as device addresses without the R/W bit.
    * In addition, MGC3X30 requires a dedicated transfer status line (TS), which features a
    * data transfer status function. The TS is used by both I2C Master and Slave to control
    * the data flow. I2C SCL, I2C SDA and TS lines require an open-drain connection on
    * MGC3X30 and the connected host controller. To function properly, I2C SCL and I2C
    * SDA need to be pulled up to VCC with 1.8 kΩ resistors and the TS line needs to be
    * pulled up to VCC with a 10 kΩ resistor.
    *
    * @param sda I2C sda signal
    * @param scl I2C scl signal
    * @param EI0 transfer status line
    * @param IS2 High->true, Low->false
    *
    */
    MGC3130(PinName sda, PinName scl, PinName EI0, bool IS2);

    /** Get a sensor data payload from the device.
    *
    * @returns @SensorData NULL means data not avaliable
    *
    */
    SensorData * readSensorData();

    /** Set the system runtime parameters.
    *
    * @param para @Parameter and any RuntimeParameter classes
    *
    * @returns
    *0x0000 NoError OK
    *0x0001 UnknownCommand Message ID is unknown
    *0x0002 InvalidSessionId Session ID is invalid or does not match (0x0 is not allowed) (message Fw_Update_Start, Fw_Update_Completed)
    *0x0003 InvalidCrc CRC is invalid thrown by messages: Fw_Update_Block, Fw_Update_Start, Fw_Update_Completed
    *0x0004 InvalidLength Length is invalid (message Fw_Update_Block)
    *0x0005 InvalidAddress Address is invalid (message Fw_Update_Block)
    *0x0006 InvalidFunction Function-Id is invalid (message Fw_Update_Start, Fw_Update_Block, Fw_Update_Completed)
    *0x0008 ContentMismatch The VerifyOnly function found a mismatch between content and Flash memory (message: Fw_Update_Block)
    *0x000B WrongParameterAddr Parameter Start address, contained in the new Library FW to be loaded, does not match Library Loader assumption. The Library Update is therefore aborted. (message: Fw_Update_Start)
    *0x0014 WrongParameterValue The value of the Argument/Parameter of a RuntimeParameter command is out of the valid range (message: Request_Message and Set_Runtime_Parameter)
    *0x0015 UnknownParameterID The MessageID or RuntimeParameterID is unknown or out of the valid range (message: Request_Message and Set_Runtime_Parameter)
    *0x001A WakeupHappend A wake-up by Host was detected
    *0x0080 LoaderUpdateStarted The Library Loader update started
    *0x0081 LoaderUpdateFinished The Library Loader update finished
    */
    int setRuntimeParameter(Parameter * para);
};

#endif