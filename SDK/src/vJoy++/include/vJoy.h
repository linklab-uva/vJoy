#include "vjoyinterface.h"

namespace vJoy_plusplus
{
	class vJoy 
	{
	public:
		vJoy(const UINT& rID);
		virtual ~vJoy();

		void reset();

		void update(const JOYSTICK_POSITION_V2& joystick);

		const UINT getID() const
		{
			return rID_;
		}
	private:
		UINT rID_;
	};
}