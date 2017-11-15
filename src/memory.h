//Author:twoentartian
//Date:11/13/2017 (MDY)

#ifndef MEMORY_H
#define MEMORY_H
#pragma once

#include "mbed.h"
#include "at45db161d.h"

#undef PAGE_SIZE
//#define PAGE_SIZE 264 // AT45DB081D (1MB)
#define PAGE_SIZE 528 // AT45DB321D (4MB)
//#define PAGE_NUM 4095 // AT45DB081D (1MB)
#define PAGE_NUM 8192 // AT45DB321D (4MB)

#define WRITE_BUFFER 1
#define READ_BUFFER 2

void Memory_Init();
void Memory_Write(int addr, char *buf, int len);
void Memory_Read(int addr, char *buf, int len);

#endif