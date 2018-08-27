project(vJoy)

include_directories(include)
link_directories(lib/amd64)

add_executable(vJoyClient
src/vJoyClient.cpp
)
target_link_libraries(vJoyClient ${CMAKE_SOURCE_DIR}/lib/amd64/vJoyInterface.lib)
