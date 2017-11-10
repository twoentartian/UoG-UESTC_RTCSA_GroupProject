#include "MGC3130.h"

MGC3130::MGC3130(PinName sda, PinName scl, PinName EI0, bool IS2)
    :TS_Line(EI0), _i2c_bus(sda,scl), msg(), sensor()
{
    TS_Line.output();
    TS_Line.write(1);
    _i2c_bus.frequency(FREQUENCY_FULL);

    if (IS2)
        _addr = 0x86;
    else
        _addr = 0x84;
}

GestICMsg * MGC3130::readMsg()
{
    TS_Line.input();
    if (TS_Line.read() == 0)
        return NULL;

    msg.rewind();

    TS_Line.output();
    TS_Line.write(0);

    _i2c_bus.start();
    _i2c_bus.write(_addr | 0x01);

    int size = _i2c_bus.read(1);
    msg.set(size);

    for (int i = 1; i < size - 1; i++)
        msg.set(_i2c_bus.read(1));

    msg.set(_i2c_bus.read(0));

    _i2c_bus.stop();
    TS_Line.write(1);
    wait_us(200);
    return &msg;
}

SensorData * MGC3130::readSensorData()
{
    if (readMsg() != NULL && sensor.convert(&msg))
        return &sensor;
    else return NULL;
}

int MGC3130::setRuntimeParameter(Parameter * para)
{
    _i2c_bus.start();
    _i2c_bus.write(_addr);
    _i2c_bus.write(0x10);
    _i2c_bus.write(0x00);
    _i2c_bus.write(0x00);
    _i2c_bus.write(0xA2);

    for (int i =0; i < Parameter::Length; i++)
        _i2c_bus.write(para->gets()[i]);

    _i2c_bus.stop();

    while (!(readMsg() != NULL || msg.getID() == GestICMsg::System_Status))
        setRuntimeParameter(para);

    return msg.get(6) | (msg.get(7) << 8);
}