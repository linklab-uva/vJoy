include_directories(include)
add_library(vJoy++ STATIC
src/vJoy.cpp
)
target_link_libraries(vJoy++ ${VJOY_LIB})
install(TARGETS vJoy++
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
		)
