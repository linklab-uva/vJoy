add_library(vJoy++ STATIC
src/vjoy.cpp
)
target_link_libraries(vJoy++ ${VJOY_LIB})
install(DIRECTORY include/
		DESTINATION include/vJoy++
        FILES_MATCHING PATTERN "*.h"
		)
install(TARGETS vJoy++
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
	)

