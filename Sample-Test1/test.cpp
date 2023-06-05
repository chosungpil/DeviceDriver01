#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include <string>
#include "../Project9/DeviceDriver.h"
#include "../Project9/DeviceDriver.cpp"
#include "../Project9/FlashMemoryDevice.h"
using namespace testing;
using namespace std;
class MockFlashMemoryDevice : public FlashMemoryDevice
{
public:
	MOCK_METHOD(unsigned char, read, (long address), ());
	MOCK_METHOD(void, write, (long address, unsigned char data), ());
};
TEST(TestCaseName, Read5TimesReadVerification) {
	MockFlashMemoryDevice mockFlashDevice;
	long readAddress = 0;
	EXPECT_CALL(mockFlashDevice, read(readAddress))
		.Times(DeviceDriver::READ_COUNT);

	DeviceDriver deviceDriver(&mockFlashDevice);
	deviceDriver.read(readAddress);
}
