#pragma once
#include "FlashMemoryDevice.h"

class DeviceDriver
{
public:
    DeviceDriver(FlashMemoryDevice* hardware);
    int read(long address);
    void write(long address, int data);

protected:
    constexpr static int READ_COUNT = 5;
    constexpr static int READ_DELAY = 5;
    FlashMemoryDevice* m_hardware;
};