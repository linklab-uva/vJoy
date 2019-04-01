add_library(vJoy++ STATIC
src/vjoy.cpp
)
target_link_libraries(vJoy++ ${VJOY_LIB})
add_executable(vjoy++_testapp src/vjoy++_testapp.cpp)
target_link_libraries(vjoy++_testapp vJoy++)
install(DIRECTORY include/vJoy++
		DESTINATION include
        FILES_MATCHING PATTERN "*.h"
		)
install(TARGETS vJoy++
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
	)

