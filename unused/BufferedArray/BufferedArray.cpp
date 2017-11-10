#include "BufferedArray.h"

BufferedArray::BufferedArray(unsigned int initialLength, unsigned int expandSize)
{
    this->expandSize = expandSize;
    max = initialLength;
    data = new unsigned char[initialLength];
    index = 0;
}

BufferedArray::BufferedArray(BufferedArray * bufferedArray)
{
    if (bufferedArray != NULL) {
        this->data = bufferedArray->data;
        this->index = bufferedArray->index;
        this->max = bufferedArray->max;
        this->expandSize = bufferedArray->expandSize;
    }
}

BufferedArray::~BufferedArray()
{
    if (data == NULL)
        return;

    delete[] data;
}

unsigned char * BufferedArray::gets()
{
    return data;
}

unsigned char * BufferedArray::gets(unsigned long position)
{
    return data + position;
}

unsigned char BufferedArray::get(unsigned long position)
{
    return *(data + position);
}

int BufferedArray::getPosition()
{
    return index;
}

void BufferedArray::setPosition(unsigned long position)
{
    if (this->index > max)
        this->index = max;
    else this->index = position;
}

void BufferedArray::allocate(unsigned long length)
{
    if (length <= 0)
        return;

    if (length > max) {
        if (data != NULL)
            delete[] data;
        data = new unsigned char[length];
    }

    rewind();
}

void BufferedArray::rewind()
{
    index = 0;
}

void BufferedArray::expandSpace(unsigned long length)
{
    max += expandSize * (1 + length / expandSize);
    unsigned char * temp = new unsigned char[max];
    memcpy(temp, data, index);
    delete[] data;
    data = temp;
}

void BufferedArray::set(unsigned long position, unsigned char value)
{
    if (position >= max)
        expandSpace(position - max + 1);

    data[position] = value;
}

void BufferedArray::set(unsigned char value)
{
    set(index, value);
    index++;
}

void BufferedArray::sets(const unsigned char * value, unsigned long offset, unsigned long length)
{
    if (length <= 0)
        return;

    sets(index, value, offset, length);
    index += length;
}

void BufferedArray::sets(unsigned long position, const unsigned char * value, unsigned long offset, unsigned long length)
{
    if (length <= 0)
        return;

    if (position + length > max)
        expandSpace(position + length - max);

    memcpy(data + position, value, length);
}