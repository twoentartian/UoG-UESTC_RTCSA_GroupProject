//Author:twoentartian
//Date:11/7/2017 (MDY)

#ifndef USER_BUTTON_H
#define USER_BUTTON_H
#pragma once

#include "mbed.h"

//User define variables
#define BUTTON_INPUT_NUMBER     4
#define BUTTON_SELECT_NUMBER    4
#define BUTTON_HOOK_FUNCTION_ENABLED    true

//System pre define variables(DO NOT change in normal situations)
#define CHECK_BUTTON_LOOPOUT    20

void Button_RefreshButtonState();
char LookUpButtonTable(int x,int y);
#ifdef BUTTON_HOOK_FUNCTION_ENABLED
void Button_EnabledHook(int x,int y);
#endif

#endif