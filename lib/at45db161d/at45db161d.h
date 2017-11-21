#ifndef AT45DB161D_H
#define AT45DB161D_H

#include "mbed.h"

extern "C" {
#include <inttypes.h>
};

#include "at45db161d_commands.h"

/**
 * @defgroup AT45DB161D AT45DB161D module
 * @{
 **/

/**
 * @defgroup SPI SPI pinout and transfert function
 * @{
 **/
#ifndef SPI
/**
 * @defgroup SPI_Pinout SPI pinout
 * @{
 **/
/** Serial input (SI) **/
#define DATAOUT     11
/** Serial output (SO) **/
#define DATAIN      12
/** Serial clock (SCK) **/
#define SPICLOCK    13
/** Chip select (CS) **/
#define SLAVESELECT 10
/** Reset (Reset) **/
#define RESET        8
/** Write protect (WP) **/
#define WP           7
/**
 * @} 
 **/

/**
 * @fn inline uint8_t spi_transfer(uint8_t data)
 * @brief Transfer a byte via spi
 * @param data Data to transfer via SPI
 * @return The content of the SPI data register (SPDR)
 **/
/*
inline uint8_t spi_transfer(uint8_t data)
{
    SPDR = data;
    while(!(SPSR & (1 << SPIF))) ;
    return SPDR;
}
*/
//#define spi_transfer(data) MemorySpi.write(data)

/** De-assert CS **/
#define DF_CS_inactive MemoryCs = 1
/** Assert CS **/
#define DF_CS_active MemoryCs = 0

#endif /* SPI */
/**
 * Ready/busy status is indicated using bit 7 of the status register.
 * If bit 7 is a 1, then the device is not busy and is ready to accept
 * the next command. If bit 7 is a 0, then the device is in a busy 
 * state.
 **/
#define READY_BUSY 0x80
/**
 * Result of the most recent Memory Page to Buffer Compare operation.
 * If this bit is equal to 0, then the data in the main memory page
 * matches the data in the buffer. If it's 1 then at least 1 byte in 
 * the main memory page does not match the data in the buffer.
 **/
#define COMPARE 0x40
/**
 * Bit 1 in the Status Register is used to provide information to the
 * user whether or not the sector protection has been enabled or
 * disabled, either by software-controlled method or 
 * hardware-controlled method. 1 means that the sector protection has
 * been enabled and 0 that it has been disabled.
 **/
#define PROTECT 0x02
/**
 * Bit 0 indicates wether the page size of the main memory array is
 * configured for "power of 2" binary page size (512 bytes) (bit=1) or 
 * standard DataFlash page size (528 bytes) (bit=0).
 **/
#define PAGE_SIZE 0x01
/**
 * Bits 5, 4, 3 and 2 indicates the device density. The decimal value
 * of these four binary bits does not equate to the device density; the
 * four bits represent a combinational code relating to differing
 * densities of DataFlash devices. The device density is not the same
 * as the density code indicated in the JEDEC device ID information.
 * The device density is provided only for backward compatibility.
 **/
#define DEVICE_DENSITY 0x2C 

/**
 * @brief at45db161d module
 * @todo
 *     - TESTS!
 *     - Protection and Security Commands
 *     - Auto Page Rewrite through Buffer 1
 *     - Auto Page Rewrite through Buffer 2
 **/
struct ID
{
    uint8_t manufacturer;       /**< Manufacturer id                           **/
    uint8_t device[2];          /**< Device id                                 **/
    uint8_t extendedInfoLength; /**< Extended device information string length **/
};

void Memory_Spi_Frequency(int frequency);
int Memory_Spi_Write(int value);
void Memory_Init();
int spi_transfer(int value);
uint8_t Memory_ReadStatusRegister();
void Memory_ReadManufacturerAndDeviceID(struct ID *id);
void Memory_ReadMainMemoryPage(uint16_t page, uint16_t offset);
void Memory_ContinuousArrayRead(uint16_t page, uint16_t offset, uint8_t low);
void Memory_BufferRead(uint8_t bufferNum, uint16_t offset, uint8_t low);
void Memory_BufferWrite(uint8_t bufferNum, uint16_t offset);
void Memory_BufferToPage(uint8_t bufferNum, uint16_t page, uint8_t erase);
void Memory_PageToBuffer(uint16_t page, uint8_t bufferNum);
void Memory_PageErase(uint16_t page);
void Memory_BlockErase(uint16_t block);
void Memory_SectoreErase(uint8_t sector);
void Memory_ChipErase();
void Memory_BeginPageWriteThroughBuffer(uint16_t page, uint16_t offset, uint8_t bufferNum);
void Memory_EndAndWait();
int8_t Memory_ComparePageToBuffer(uint16_t page, uint8_t bufferNum);
void Memory_DeepPowerDown();
void Memory_ResumeFromDeepPowerDown();

#endif /* AT45DB161D_H */
