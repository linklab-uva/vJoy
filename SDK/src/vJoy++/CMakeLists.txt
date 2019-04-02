set(Boost_USE_STATIC_LIBS ON)
find_package( Boost REQUIRED COMPONENTS date_time filesystem program_options regex )
message(STATUS "Found the following boost libraries: ${Boost_LIBRARIES}")
set(vJoy++_SOURCES src/vjoy.cpp)
add_library(vJoy++ STATIC ${vJoy++_SOURCES})
target_link_libraries(vJoy++ ${VJOY_LIB})

set(vjoy++_testapp_SOURCES src/vjoy++_testapp.cpp)
add_executable(vjoy++_testapp ${vjoy++_testapp_SOURCES})
target_link_libraries(vjoy++_testapp vJoy++)


set(f1_calibration_SOURCES src/f1_calibration.cpp)
add_executable(f1_calibration ${f1_calibration_SOURCES})
target_link_libraries(f1_calibration vJoy++ ${Boost_LIBRARIES})
target_include_directories(f1_calibration PRIVATE ${Boost_INCLUDE_DIRS})


install(DIRECTORY include/vJoy++
		DESTINATION include
        FILES_MATCHING PATTERN "*.h"
		)
install(TARGETS vJoy++
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
	)

