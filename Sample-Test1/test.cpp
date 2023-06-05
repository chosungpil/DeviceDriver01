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
TEST(TestCaseName, ReadException) {
	MockFlashMemoryDevice mockFlashDevice;
	long readAddress = 0;
	EXPECT_CALL(mockFlashDevice, read(readAddress))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x7))
		.WillOnce(Return(0x3));

	DeviceDriver deviceDriver(&mockFlashDevice);
	EXPECT_THROW(deviceDriver.read(readAddress), std::exception);
}
TEST(TestCaseName, WriteException) {
	MockFlashMemoryDevice mockFlashDevice;
	long writeAddress = 0;
	unsigned char writeValue = 0x21;
	DeviceDriver deviceDriver(&mockFlashDevice);
	EXPECT_THROW(deviceDriver.write(writeAddress, writeValue), std::exception);
}
TEST(TestCaseName, WriteReadCountCheck) {
	MockFlashMemoryDevice mockFlashDevice;
	
	constexpr static int TEST_COUNT = 5;
	EXPECT_CALL(mockFlashDevice, read(_))
		.Times(TEST_COUNT)
		.WillRepeatedly(Return(DeviceDriver::ERASE_STATE_VALUE));

	long writeAddress = 0;
	unsigned char writeValue = 0x21;
	DeviceDriver deviceDriver(&mockFlashDevice);
	for (int writeCount = 0; writeCount < TEST_COUNT; writeCount++)
	{
		deviceDriver.write(writeAddress, writeValue);
	}
}