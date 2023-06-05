#pragma once
#include "FlashMemoryDevice.h"

class DeviceDriver
{
public:
    DeviceDriver(FlashMemoryDevice* hardware);
    int read(long address);
    void write(long address, int data);
    constexpr static int READ_COUNT = 5;

protected:
    FlashMemoryDevice* m_hardware;

private:
    constexpr static int READ_DELAY = 200;
};