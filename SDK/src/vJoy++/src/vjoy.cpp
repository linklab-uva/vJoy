#include "vJoy++/vjoy.h"
#include <stdexcept>
#include <sstream>
namespace vjoy_plusplus
{
	vJoy::vJoy(const unsigned int& rID)
	{
		rID_ = rID;
		if (!AcquireVJD(rID_))
		{
			std::stringstream ss;
			ss << "Could not acquire device id: " << rID_ << std::endl;
			throw std::runtime_error(ss.str());
		}
	}
	vJoy::~vJoy()
	{
		RelinquishVJD(rID_);
	}
	void vJoy::reset()
	{
		ResetVJD(rID_);
	}

	unsigned int vJoy::minAxisvalue()
	{
		return 0;
	}

	unsigned int vJoy::maxAxisvalue()
	{
		return 32775;
	}

	void vJoy::update(const vjoy_plusplus::JoystickPosition& joystick)
	{
		PVOID pPositionMessage = (PVOID)(&joystick);
		if (!UpdateVJD(rID_, pPositionMessage))
		{
			std::stringstream ss;
			ss << "Feeding vJoy device number " << rID_ << " failed." << std::endl;
			throw std::runtime_error(ss.str());
		}
	}

	bool vJoy::enabled()
	{
		return vJoyEnabled();
	}

	VjoyDeviceStatus vJoy::getStatus(unsigned int device_id)
	{
		return GetVJDStatus(device_id);
	}
}