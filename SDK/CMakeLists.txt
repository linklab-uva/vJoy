project(vJoy)

include_directories(include)
link_directories(lib/amd64)

add_executable(vJoyClient
src/vJoyClient.cpp
)
target_link_libraries(vJoyClient C:\Users\ttw2xk\Documents\git_repos\vJoy\SDK\lib\amd64\vJoyInterface.lib)
