#ifndef UK_AC_HERTS_SMARTLAB_MGC3130_GestICMsg
#define UK_AC_HERTS_SMARTLAB_MGC3130_GestICMsg

#include "BufferedArray.h"

/**
*A message is the container to exchange data between GestIC Library and the
*application host. Each message has a minimum length of 4 bytes and a maximum of
*255 bytes, and fits into the data packets of the communication interface (e.g., I2C).
*Each frame transports a single message (see Figure 3-1).
*/
class GestICMsg : public BufferedArray
{
public:
    static const int  System_Status = 0x15;
    static const int  Request_Message = 0x06;
    static const int  Fw_Version_Info = 0x83;
    static const int  Set_Runtime_Parameter = 0xA2;
    
    static const int   Sensor_Data_Output = 0x91;
    
    static const int  Fw_Update_Start = 0x80;
    static const int  Fw_Update_Block = 0x81;
    static const int  Fw_Update_Completed = 0x82;
    
    /// Construct a empty message.
    GestICMsg();
    
    /** Complete size of the message in bytes including the header
    *
    * @returns payload length, include head.
    *
    */
    int getMsgSize();

    /** Reserved for future use.
    *
    * @returns always be 0x00
    *
    */
    int getFlags();

    /** Sequence number which is increased for each message sent out by
    * MGC3X30. Range is 0…255. The host controller can use that information
    * to verify if the messages got lost during I2C™ transmission.
    * MGC3X30 ignores the sequence number in the received messages.
    *
    * @returns the sqeuence number
    *
    */
    int getSeq();

    /** For each ID, the GestIC Library holds a
    * dedicated structure containing the message direction, its payload
    * elements and possible reply actions.
    *
    * @returns ID of the messag.
    *
    */
    int getID();
};

#endif