#include "vJoy.h"
#include <stdexcept>
#include <sstream>
namespace vJoy_plusplus
{
	vJoy::vJoy(const UINT& rID)
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

	void vJoy::update(const JOYSTICK_POSITION_V2& joystick)
	{
		PVOID pPositionMessage = (PVOID)(&joystick);
		if (!UpdateVJD(rID_, pPositionMessage))
		{
			std::stringstream ss;
			ss << "Feeding vJoy device number " << rID_ << " failed." << std::endl;
			throw std::runtime_error(ss.str());
		}
	}
}