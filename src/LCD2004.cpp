//Author:twoentartian
//Date:11/10/2017 (MDY)

#include "LCD2004.h"
#include "rtos.h"

TextLCD lcd(PF_12,PD_15,PD_14,PA_7,PA_6,PB_9);

bool ChangeSign[LCD_ROW][LCD_COLUMN]=
{
    {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
    {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
    {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true},
    {true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true,true}
};
char LCDBuffer[LCD_ROW][LCD_COLUMN+1]=
{
    "01234567890123456789","01234567890123456789","01234567890123456789","01234567890123456789"
};

void LCD_ChangeBuffer(int row,int column, int c)
{
    ChangeSign[row][column]=true;
    LCDBuffer[row][column]=c;
}

void LCD_ChangeBuffer(int row, char *args)
{
    for(int column=0;column<LCD_COLUMN;column++)
    {
        ChangeSign[row][column]=true;
        LCDBuffer[row][column]=*args;
        args++;
    }
}

void LCD_Refresh()
{
    for(int row=0;row<LCD_ROW;row++)
    {
        for(int column=0;column<LCD_COLUMN;column++)
        {
            if(ChangeSign[row][column])
            {
                ChangeSign[row][column]=false;
                lcd.locate(column,row);
                lcd.putc(LCDBuffer[row][column]);
            }
        }
    }
}
