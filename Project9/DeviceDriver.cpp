#include "DeviceDriver.h"
#include <Windows.h>
#include <exception>
DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    int firstReadValue = (int)m_hardware->read(address);
    for (int readCount = 1; readCount < READ_COUNT ; readCount++)
    {
        int nextReadValue = m_hardware->read(address);
        if (firstReadValue == nextReadValue)
        {
            Sleep(READ_DELAY);
        }else
        {
            throw std::exception("Exception!!");
        }
    }
    return firstReadValue;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}