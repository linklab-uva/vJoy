#include <vJoy++/vJoy.h>
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
			setThrottle(0);
			setRudder(0);
			setAileron(0);
			setAxisX(0);
			setAxisY(0);
			setAxisZ(0);
			setAxisXRot(0);
			setAxisYRot(0);
			setAxisZRot(0);
			setSlider(0);
			setDial(0);
			setWheel(0);
			setAxisVX(0);
			setAxisVY(0);
			setAxisVZ(0);
			setAxisVBRX(0);
			setAxisVBRY(0);
			setAxisVBRZ(0);
			setlButtons(0);
			setbHats(0);
			setbHatsEx1(0);
		    setbHatsEx2(0);
			setbHatsEx3(0);
		}
		virtual ~Joystick()
		{
			
		}
		//setters
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
		void setAxisXRot(long wAxisXRot)
		{
			joystick_.wAxisXRot = (LONG)wAxisXRot;
		}
		void setAxisYRot(long wAxisYRot)
		{
			joystick_.wAxisYRot = (LONG)wAxisYRot;
		}
		void setAxisZRot(long wAxisZRot)
		{
			joystick_.wAxisZRot = (LONG)wAxisZRot;
		}
		void setSlider(long wSlider)
		{
			joystick_.wSlider = (LONG)wSlider;
		}
		void setDial(long wDial)
		{
			joystick_.wDial = (LONG)wDial;
		}
		void setWheel(long wWheel)
		{
			joystick_.wWheel = (LONG)wWheel;
		}
		void setAxisVX(long wAxisVX)
		{
			joystick_.wAxisVX = (LONG)wAxisVX;
		}
		void setAxisVY(long wAxisVY)
		{
			joystick_.wAxisVY = (LONG)wAxisVY;
		}
		void setAxisVZ(long wAxisVZ)
		{
			joystick_.wAxisVZ = (LONG)wAxisVZ;
		}
		void setAxisVBRX(long wAxisVBRX)
		{
			joystick_.wAxisVBRX = (LONG)wAxisVBRX;
		}
		void setAxisVBRY(long wAxisVBRY)
		{
			joystick_.wAxisVBRY = (LONG)wAxisVBRY;
		}
		void setAxisVBRZ(long wAxisVBRZ)
		{
			joystick_.wAxisVBRZ = (LONG)wAxisVBRZ;
		}
		void setlButtons(long lButtons)
		{
			joystick_.lButtons = (LONG)lButtons;
		}
		void setlButtonsEx1(long lButtonsEx1)
		{
			joystick_.lButtonsEx1 = (LONG)lButtonsEx1;
		}
		void setlButtonsEx2(long lButtonsEx2)
		{
			joystick_.lButtonsEx2 = (LONG)lButtonsEx2;
		}
		void setlButtonsEx3(long lButtonsEx3)
		{
			joystick_.lButtonsEx3 = (LONG)lButtonsEx3;
		}
		void setbHats(unsigned long bHats)
		{
			joystick_.bHats = (DWORD)bHats;
		}
		void setbHatsEx1(unsigned long bHatsEx1)
		{
			joystick_.bHatsEx1 = (DWORD)bHatsEx1;
		}
		void setbHatsEx2(unsigned long bHatsEx2)
		{
			joystick_.bHatsEx2 = (DWORD)bHatsEx2;
		}
		void setbHatsEx3(unsigned long bHatsEx3)
		{
			joystick_.bHatsEx3 = (DWORD)bHatsEx3;
		}
		
		//getters

		long Throttle()
		{
			return (long)joystick_.wThrottle;
		}
		long Rudder()
		{
			return (long)joystick_.wRudder;
		}
		long Aileron( )
		{
			return (long)joystick_.wAileron;
		}
		long AxisX( )
		{
			return (long)joystick_.wAxisX;
		}
		long AxisY( )
		{
			return (long)joystick_.wAxisY;
		}
		long AxisZ( )
		{
			return (long)joystick_.wAxisZ;
		}
		long AxisXRot( )
		{
			return (long)joystick_.wAxisXRot;
		}
		long AxisYRot( )
		{
			return (long)joystick_.wAxisYRot;
		}
		long AxisZRot( )
		{
			return (long)joystick_.wAxisZRot;
		}
		long Slider( )
		{
			return (long)joystick_.wSlider;
		}
		long Dial( )
		{
			return (long)joystick_.wDial;
		}
		long Wheel( )
		{
			return (long)joystick_.wWheel;
		}
		long AxisVX( )
		{
			return (long)joystick_.wAxisVX;
		}
		long AxisVY( )
		{
			return (long)joystick_.wAxisVY;
		}
		long AxisVZ( )
		{
			return (long)joystick_.wAxisVZ;
		}
		long AxisVBRX( )
		{
			return (long)joystick_.wAxisVBRX;
		}
		long AxisVBRY( )
		{
			return (long)joystick_.wAxisVBRY;
		}
		long AxisVBRZ( )
		{
			return (long)joystick_.wAxisVBRZ;
		}
		long lButtons( )
		{
			return (long)joystick_.lButtons;
		}
		long lButtonsEx1( )
		{
			return (long)joystick_.lButtonsEx1;
		}
		long lButtonsEx2( )
		{
			return (long)joystick_.lButtonsEx2;
		}
		long lButtonsEx3( )
		{
			return (long)joystick_.lButtonsEx3;
		}
		unsigned long bHats()
		{
			return (unsigned long)joystick_.bHats;
		}
		unsigned long bHatsEx1()
		{
			return (unsigned long)joystick_.bHatsEx1;
		}
		unsigned long bHatsEx2()
		{
			return (unsigned long)joystick_.bHatsEx2;
		}
		unsigned long bHatsEx3()
		{
			return (unsigned long)joystick_.bHatsEx3;
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
			impl_->reset();
		}
		void capture(unsigned int id)
		{
			impl_.reset(new vjoy_plusplus::vJoy((UINT)id));
		}
		void update(Joystick& joystick)
		{
			joystick.joystick_.bDevice  = (unsigned char) impl_->getID();
			impl_->update(joystick.joystick_);
		}
	protected:
		std::shared_ptr<vjoy_plusplus::vJoy> impl_;
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
		def("setAxisZ", &py_vjoy::Joystick::setAxisZ, "Sets the axis z").
		def("setAxisXRot", &py_vjoy::Joystick::setAxisXRot, "Sets the axis XROT").
		def("setAxisYRot", &py_vjoy::Joystick::setAxisYRot, "Sets the axis YROT").
		def("setAxisZRot", &py_vjoy::Joystick::setAxisZRot, "Sets the axis ZROT").
		def("setSlider", &py_vjoy::Joystick::setSlider, "Sets the axis slider").
		def("setDial", &py_vjoy::Joystick::setDial, "Sets the axis dial").
		def("setWheel", &py_vjoy::Joystick::setWheel, "Sets the axis wheel").
		def("setAxisVX", &py_vjoy::Joystick::setAxisVX, "Sets the axis VX").
		def("setAxisVY", &py_vjoy::Joystick::setAxisVY, "Sets the axis VY").
		def("setAxisVZ", &py_vjoy::Joystick::setAxisVZ, "Sets the axis VZ").
		def("setAxisVBRX", &py_vjoy::Joystick::setAxisVBRX, "Sets the axis VBRX").
		def("setAxisVBRY", &py_vjoy::Joystick::setAxisVBRY, "Sets the axis VBRY").
		def("setAxisVBRZ", &py_vjoy::Joystick::setAxisVBRZ, "Sets the axis VBRZ").
		def("setlButtons", &py_vjoy::Joystick::setlButtons, "").
		def("setlButtonsEx1", &py_vjoy::Joystick::setlButtonsEx1, "").
		def("setlButtonsEx2", &py_vjoy::Joystick::setlButtonsEx2, "").
		def("setlButtonsEx3", &py_vjoy::Joystick::setlButtonsEx3, "").
		def("setbHats", &py_vjoy::Joystick::setbHats, "").
		def("setbHatsEx1", &py_vjoy::Joystick::setbHatsEx1, "").
		def("setbHatsEx2", &py_vjoy::Joystick::setbHatsEx2, "").
		def("setbHatsEx3", &py_vjoy::Joystick::setbHatsEx3, "").
		def("Throttle", &py_vjoy::Joystick::Throttle, "Sets the throttle").
		def("Rudder", &py_vjoy::Joystick::Rudder, "Sets the rudder").
		def("Aileron", &py_vjoy::Joystick::Aileron, "Sets the aileron").
		def("AxisX", &py_vjoy::Joystick::AxisX, "Sets the axis x").
		def("AxisY", &py_vjoy::Joystick::AxisY, "Sets the axis y").
		def("AxisZ", &py_vjoy::Joystick::AxisZ, "Sets the axis z").
		def("AxisXRot", &py_vjoy::Joystick::AxisXRot, "Sets the axis XROT").
		def("AxisYRot", &py_vjoy::Joystick::AxisYRot, "Sets the axis YROT").
		def("AxisZRot", &py_vjoy::Joystick::AxisZRot, "Sets the axis ZROT").
		def("Slider", &py_vjoy::Joystick::Slider, "Sets the axis slider").
		def("Dial", &py_vjoy::Joystick::Dial, "Sets the axis dial").
		def("Wheel", &py_vjoy::Joystick::Wheel, "Sets the axis wheel").
		def("AxisVX", &py_vjoy::Joystick::AxisVX, "Sets the axis VX").
		def("AxisVY", &py_vjoy::Joystick::AxisVY, "Sets the axis VY").
		def("AxisVZ", &py_vjoy::Joystick::AxisVZ, "Sets the axis VZ").
		def("AxisVBRX", &py_vjoy::Joystick::AxisVBRX, "Sets the axis VBRX").
		def("AxisVBRY", &py_vjoy::Joystick::AxisVBRY, "Sets the axis VBRY").
		def("AxisVBRZ", &py_vjoy::Joystick::AxisVBRZ, "Sets the axis VBRZ").
		def("lButtons", &py_vjoy::Joystick::lButtons, "").
		def("lButtonsEx1", &py_vjoy::Joystick::lButtonsEx1, "").
		def("lButtonsEx2", &py_vjoy::Joystick::lButtonsEx2, "").
		def("lButtonsEx3", &py_vjoy::Joystick::lButtonsEx3, "").
		def("bHats", &py_vjoy::Joystick::bHats, "").
		def("bHatsEx1", &py_vjoy::Joystick::bHatsEx1, "").
		def("bHatsEx2", &py_vjoy::Joystick::bHatsEx2, "").
		def("bHatsEx3", &py_vjoy::Joystick::bHatsEx3, "");
#ifdef VERSION_INFO
	m.attr("__version__") = VERSION_INFO;
#else
	m.attr("__version__") = "dev";
#endif
}