#ifndef VJOY_PLUSPLUS_H
#define VJOY_PLUSPLUS_H
//#include "vJoy/public.h"
#include "vJoy/vjoyinterface.h"
#ifndef VJOY_PLUSPLUS_VISIBILITY
  #define VJOY_PLUSPLUS_VISIBILITY __declspec(dllimport)
#endif
namespace vjoy_plusplus
{
	typedef JOYSTICK_POSITION_V2 JoystickPosition;
	typedef VjdStat VjoyDeviceStatus;
	class VJOY_PLUSPLUS_VISIBILITY vJoy 
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

		static unsigned int minAxisvalue();

		static unsigned int maxAxisvalue();

		static bool enabled();

		static VjoyDeviceStatus getStatus(unsigned int device_id);
	private:
		unsigned int rID_;
	};
}
#endif