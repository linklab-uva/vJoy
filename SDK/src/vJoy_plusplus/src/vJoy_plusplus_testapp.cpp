#include <iostream>
#include <string>
#include <vJoy_plusplus/vjoy.h>
#include <memory>
int main(int argc, char** argv)
{
  std::cout<<"Hello World!"<<std::endl; 
  if (argc < 4)
  {
	  std::cout << "Usage is:" << std::endl;
	  std::cout << "vjoy++_testapp <device_id> <+/-> for left/right steering direction, respectively <sleeptime>" << std::endl;
  }
  unsigned int DevID = std::stoi(argv[1]);
  std::string specified_direction(argv[2]);
  unsigned int sleeptime = std::stoi(argv[3]);  
  int direction;
  if (specified_direction.compare("+")==0)
  {
	  direction = 1;
  }
  else if (specified_direction.compare("-") == 0)
  {

	  direction = -1;
  }
  else
  {
	  std::cerr << "Invalid direction specifier " << argv[2] << std::endl;
	  exit(-1);
  }
  if (!vjoy_plusplus::vJoy::enabled())
  {
	  std::cerr << "VJoy driver is not installed/enabled." << std::endl;
	  exit(-1);
  }
  vjoy_plusplus::VjoyDeviceStatus status = vjoy_plusplus::vJoy::getStatus(DevID);
  switch (status)
  {
	  case vjoy_plusplus::VjoyDeviceStatus::VJD_STAT_OWN:
		  std::printf("vJoy device %d is already owned by this feeder\n", DevID);
		  break;
	  case vjoy_plusplus::VjoyDeviceStatus::VJD_STAT_FREE:
		  std::printf("vJoy device %d is free\n", DevID);
		  break;
	  case vjoy_plusplus::VjoyDeviceStatus::VJD_STAT_BUSY:
		  std::printf("vJoy device %d is already owned by another feeder\nCannot continue\n", DevID);
		  exit(-3);
	  case vjoy_plusplus::VjoyDeviceStatus::VJD_STAT_MISS:
		  std::printf("vJoy device %d is not installed or disabled\nCannot continue\n", DevID);
		  exit(-4);
	  default:
		  std::printf("vJoy device %d general error\nCannot continue\n", DevID);
		  exit(-1);
  }

  vjoy_plusplus::JoystickPosition iReport;
  std::unique_ptr<vjoy_plusplus::vJoy> vjoy(new vjoy_plusplus::vJoy(DevID));

  unsigned int angle = 0;

  iReport.lButtons = 0x00000000;
  unsigned int min = 0, max = 32750;
  unsigned int middle = (min + max)/2;
  while (1)
  {
	  // Set position data of 3 first axes
	  if (angle > middle)
	  {
		  angle = 0;
	  }
	  unsigned int setval;
	  if (direction > 0)
	  {
		  setval = angle;
	  }
	  else
	  {
		  setval = middle + angle;
	  }
	  printf("Setting wheel val: %ld \n", setval);
	  iReport.wAxisY = setval;
	  vjoy->update(iReport);
	  angle += 50;
	  Sleep(sleeptime);
  }

}