//Author:twoentartian
//Date:11/10/2017 (MDY)

#ifndef LCD2004_H
#define LCD2004_H
#pragma once

#include "mbed.h"
#include "TextLCD.h"

#define LCD_ROW         4
#define LCD_COLUMN     20

void LCD_ChangeBuffer(int column,int row, int c);
void LCD_ChangeBuffer(int column, char args[]);
void LCD_Refresh();

#endif