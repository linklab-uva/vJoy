include(CMakePackageConfigHelpers)
set(_version 1.0.0)
write_basic_package_version_file(${PROJECT_NAME}ConfigVersion.cmake
  VERSION ${_version}
  COMPATIBILITY AnyNewerVersion
)
set(INCLUDE_INSTALL_DIR include/)
get_filename_component(vjoyfile ${VJOY_LIB} NAME)
set(vjoy++install_lib "lib/vJoy++.lib")
set(vjoyinstall_lib "lib/${vjoyfile}")
#...
configure_package_config_file(${CMAKE_SOURCE_DIR}/modules/vJoy++Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/vJoy++Config.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
  PATH_VARS INCLUDE_INSTALL_DIR vjoy++install_lib vjoyinstall_lib)
write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/vJoy++ConfigVersion.cmake
  VERSION ${_version}
  COMPATIBILITY SameMajorVersion )
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/vJoy++Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/vJoy++ConfigVersion.cmake
        DESTINATION cmake )