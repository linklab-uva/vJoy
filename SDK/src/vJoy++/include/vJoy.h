#include "vjoyinterface.h"
namespace vJoy_plusplus
{
	typedef JOYSTICK_POSITION_V2 JoystickPosition;
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
	private:
		unsigned int rID_;
	};
}