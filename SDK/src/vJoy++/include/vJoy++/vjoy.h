#include "vJoy/vjoyinterface.h"
namespace vjoy_plusplus
{
	typedef JOYSTICK_POSITION_V2 JoystickPosition;
	typedef VjdStat VjoyDeviceStatus;
	class vJoy 
	{
	public:
		vJoy(const unsigned int& rID);
		virtual ~vJoy();

		void reset();

		void update(const JoystickPosition& joystick);

		const unsigned int getID() const
		{
			return rID_;
		}

		static bool enabled();

		static VjoyDeviceStatus getStatus(unsigned int device_id);
	private:
		unsigned int rID_;
	};
}