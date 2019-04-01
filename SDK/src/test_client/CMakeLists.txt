add_executable(vJoyClient
vJoyClient.cpp
)
target_link_libraries(vJoyClient ${VJOY_LIB})
install(TARGETS vJoyClient
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
		)
