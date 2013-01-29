cmake_minimum_required(VERSION 2.8)

project(FRC)
set(CMAKE_MODULE_PATH /home/mcoffin/workspace/cmake-wpilib/cmake/Modules)

find_package(WPILib REQUIRED)
include_directories(${WPILib_INCLUDE_DIR})

include_directories(src)
file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(FRC_UserProgram ${SOURCES})
set_target_properties(FRC_UserProgram PROPERTIES
	SUFFIX .out
	RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

target_link_libraries(FRC_UserProgram ${WPILib_LIBRARY})
