#include <vJoy.h>
#include <pybind11/pybind11.h>
#include <memory>
namespace py_vjoy {
	class Joystick
	{
		friend class vJoy;
		/*
			BYTE	bDevice;	// Index of device. 1-based.
	LONG	wThrottle;
	LONG	wRudder;
	LONG	wAileron;
	LONG	wAxisX;
	LONG	wAxisY;
	LONG	wAxisZ;
	LONG	wAxisXRot;
	LONG	wAxisYRot;
	LONG	wAxisZRot;
	LONG	wSlider;
	LONG	wDial;
	LONG	wWheel;
	LONG	wAxisVX;
	LONG	wAxisVY;
	LONG	wAxisVZ;
	LONG	wAxisVBRX;
	LONG	wAxisVBRY;
	LONG	wAxisVBRZ;
	LONG	lButtons;	// 32 buttons: 0x00000001 means button1 is pressed, 0x80000000 -> button32 is pressed
	DWORD	bHats;		// Lower 4 bits: HAT switch or 16-bit of continuous HAT switch
	DWORD	bHatsEx1;	// Lower 4 bits: HAT switch or 16-bit of continuous HAT switch
	DWORD	bHatsEx2;	// Lower 4 bits: HAT switch or 16-bit of continuous HAT switch
	DWORD	bHatsEx3;	// Lower 4 bits: HAT switch or 16-bit of continuous HAT switch LONG lButtonsEx1; // Buttons 33-64
	
	/// JOYSTICK_POSITION_V2 Extenssion
	LONG lButtonsEx1; // Buttons 33-64
	LONG lButtonsEx2; // Buttons 65-96
	LONG lButtonsEx3; // Buttons 97-128
	*/

	public:
		Joystick()
		{

		}
		void setThrottle(long wThrottle)
		{
			joystick_.wThrottle = (LONG)wThrottle;
		}
		void setRudder(long wRudder)
		{
			joystick_.wRudder = (LONG)wRudder;
		}
		void setAileron(long wAileron)
		{
			joystick_.wAileron = (LONG)wAileron;
		}
		void setAxisX(long wAxisX)
		{
			joystick_.wAxisX = (LONG)wAxisX;
		}
		void setAxisY(long wAxisY)
		{
			joystick_.wAxisY = (LONG)wAxisY;
		}
		void setAxisZ(long wAxisZ)
		{
			joystick_.wAxisZ = (LONG)wAxisZ;
		}

	protected:
		JOYSTICK_POSITION_V2 joystick_;
	};

	class vJoy {
	public:
		vJoy()
		{
		}
		virtual ~vJoy()
		{
		}
		void capture(int id)
		{
			impl_.reset(new vJoy_plusplus::vJoy((UINT)id));
		}
		void update(Joystick joystick)
		{
			impl_->update(joystick.joystick_);
		}
	protected:
		std::shared_ptr<vJoy_plusplus::vJoy> impl_;
	};
}
PYBIND11_MODULE(py_vjoy, m) {
	m.doc() = R"pbdoc(

        Pybind11 plugin for vJoy

        -----------------------

    )pbdoc";
	pybind11::class_<py_vjoy::vJoy> vJoy(m, "vJoy");
	vJoy.
		def(pybind11::init<>()).
		def("capture", &py_vjoy::vJoy::capture, "Captures the specified vJoy device").
		def("update", &py_vjoy::vJoy::update, "updates the device with joystick values");


	pybind11::class_<py_vjoy::Joystick> Joystick(m, "Joystick");
	Joystick.
		def(pybind11::init<>()).
		def("setThrottle", &py_vjoy::Joystick::setThrottle, "Sets the throttle").
		def("setRudder", &py_vjoy::Joystick::setRudder, "Sets the rudder").
		def("setAileron", &py_vjoy::Joystick::setAileron, "Sets the aileron").
		def("setAxisX", &py_vjoy::Joystick::setAxisX, "Sets the axis x").
		def("setAxisY", &py_vjoy::Joystick::setAxisY, "Sets the axis y").
		def("setAxisZ", &py_vjoy::Joystick::setAxisZ, "Sets the axis z");


	/*
			void setThrottle(long wThrottle)
		{
			joystick_.wThrottle = (LONG)wThrottle;
		}
		void setRudder(long wRudder)
		{
			joystick_.wRudder = (LONG)wRudder;
		}
		void setAileron(long wAileron)
		{
			joystick_.wAileron = (LONG)wAileron;
		}
		void setAxisX(long wAxisX)
		{
			joystick_.wAxisX = (LONG)wAxisX;
		}
		void setAxisY(long wAxisY)
		{
			joystick_.wAxisY = (LONG)wAxisY;
		}
		void setAxisZ(long wAxisZ)
		{
			joystick_.wAxisZ = (LONG)wAxisZ;
		}*/

#ifdef VERSION_INFO
	m.attr("__version__") = VERSION_INFO;
#else
	m.attr("__version__") = "dev";
#endif
}