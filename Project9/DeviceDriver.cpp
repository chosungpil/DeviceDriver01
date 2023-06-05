#include "DeviceDriver.h"
#include <Windows.h>
DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware) : m_hardware(hardware)
{}

int DeviceDriver::read(long address)
{
    // TODO: implement this method properly
    for (int readCount = 0; readCount < READ_COUNT; readCount++)
    {
        m_hardware->read(address);
        Sleep(READ_DELAY);
    }
    return 0;
}

void DeviceDriver::write(long address, int data)
{
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}