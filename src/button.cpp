//Author:twoentartian
//Date:11/7/2017 (MDY)

#include "button.h"

//Variables
volatile bool IsButtonEnabled[BUTTON_INPUT_NUMBER*BUTTON_SELECT_NUMBER];

DigitalIn Buttons[BUTTON_INPUT_NUMBER] = 
{
    PG_3,PE_2,PE_4,PE_5
};

DigitalOut ButtonsSelect[BUTTON_SELECT_NUMBER] = 
{
    PF_2,PF_8,PF_9,PG_1
};

char ButtonTable[BUTTON_INPUT_NUMBER*BUTTON_SELECT_NUMBER] = 
{
    'D','#','0','*','C','9','8','7','B','6','5','4','A','3','2','1'
};

bool IsInit = false;

//Functions
void Button_Init()
{
    for (int i = 0; i < BUTTON_INPUT_NUMBER; i++)
    {
        Buttons[i].mode(PullDown);
    }
    IsInit=true;
}

void Button_SelectButton(int select)
{
    for (int i = 0; i < BUTTON_SELECT_NUMBER; i++)
    {
        ButtonsSelect[i] = 0;
    }
    ButtonsSelect[select] = 1;
}

bool Button_CheckButton(int index)
{
    int i = CHECK_BUTTON_LOOPOUT;
    while (Buttons[index] == 1)
    {
        i--;
        if (i == 0)
        {
            return true;
        }
    }
    return false;
}

void Button_RefreshButtonState()
{
    if(!IsInit) Button_Init();
    for (char select = 0; select < BUTTON_SELECT_NUMBER; select++)
    {
        Button_SelectButton(select);
        for (char button = 0; button < BUTTON_INPUT_NUMBER; button++)
        {
            if(Button_CheckButton(button))
            {
                if(!IsButtonEnabled[select*BUTTON_INPUT_NUMBER + button])
                {
                    IsButtonEnabled[select*BUTTON_INPUT_NUMBER + button] = true;
                    Button_EnabledHook(button,select);
                }
            }
            else
            {
                IsButtonEnabled[select*BUTTON_INPUT_NUMBER + button] = false;
            }
        }
    }
}

char LookUpButtonTable(int x,int y)
{
    return ButtonTable[x+y*BUTTON_INPUT_NUMBER];
}