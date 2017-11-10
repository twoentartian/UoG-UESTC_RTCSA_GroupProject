#include "GestICMsg.h"

GestICMsg::GestICMsg(): BufferedArray(20,20)
{}

int GestICMsg::getMsgSize()
{
    return data[0];
}

int GestICMsg::getFlags()
{
    return data[1];
}

int GestICMsg::getSeq()
{
    return data[2];
}

int GestICMsg::getID()
{
    return data[3];
}
