#ifndef UK_AC_HERTS_SMARTLAB_XBEE_BufferedArray
#define UK_AC_HERTS_SMARTLAB_XBEE_BufferedArray

#include "mbed.h"

/**
* Represent a generic, dynamic-length raw binary data buffer.
*/
class BufferedArray
{
protected :
    /// initial size and automatically increase length.
    unsigned int expandSize;

    /// Raw data
    unsigned char * data;

    /// Current index of the data, could also used as data lendth.
    unsigned long index;

    /// Max data size that the raw data can hold.
    unsigned long max;
    
    void expandSpace(unsigned long length);

public:
    BufferedArray(unsigned int initialLength, unsigned int expandSize);

    BufferedArray(BufferedArray * bufferedArray);
    
    ~BufferedArray();

    /** Get the raw data.
    * @returns unsigned char array.
    */
    unsigned char * gets();
        
    /** Get the raw data from a specific location.
    *
    * @param position where to retrieve
    *
    * @returns unsigned char array.
    */
    unsigned char * gets(unsigned long position);
           
    /** Get 1 byte data from a specific location.
    *
    * @param position where to retrieve
    *
    * @returns unsigned char.
    */
    unsigned char get(unsigned long position);

    /** Get the current index.
    * @returns unsigned char array.
    */
    int getPosition();

    /** Set the index within the max length of raw data.
    * @param position where to begin read and write
    */
    void setPosition(unsigned long position);

    /** Reset the raw data.
    * @param length current max size for the raw data
    */
    void allocate(unsigned long length);

    /** Reset the position and does not affect the content of the data.
    * @param length current max size for the raw data
    */
    void rewind();
    
    /** Write 8-bit data into current posiston and increase by 1.
    * @param value sigle byte
    */
    void set(unsigned char value);

    /** Write array of data into current posiston, and increase by the lenght.
    * @param value array of byte
    * @param offset start point of the data
    * @param length length to write
    */
    void sets(const unsigned char * value, unsigned long offset, unsigned long length);

    /** Write 8-bit data into specific posiston and deos not affect the current position.
    * @param position where to write
    * @param value sigle byte
    */
    void set(unsigned long position, unsigned char value);

    /** Write array of data into specific posiston and deos not affect the current position.
    * @param position where to write
    * @param value array of byte
    * @param offset start point of the data
    * @param length length to write
    */
    void sets(unsigned long position, const unsigned char * value, unsigned long offset, unsigned long length);
}; 

#endif
