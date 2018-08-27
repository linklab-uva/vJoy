#include <vJoy.h>
#include <pybind11/pybind11.h>

namespace py_vjoy {
	class vJoy {
	public:
		vJoy()
		{

		}
		virtual ~vJoy() {
			delete impl_;
		}
		void capture(unsigned int id)
		{
			impl_ = new vJoy_plusplus::vJoy((UINT)id);
		}
	protected:
		vJoy_plusplus::vJoy* impl_;
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
		def("capture", &py_vjoy::vJoy::capture, "Captures the specified vJoy device");

#ifdef VERSION_INFO
	m.attr("__version__") = VERSION_INFO;
#else
	m.attr("__version__") = "dev";
#endif
}