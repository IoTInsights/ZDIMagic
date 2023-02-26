cmake_minimum_required(VERSION 3.24)
project(ZDIMagician)

set(CMAKE_CXX_STANDARD 17)

add_executable(ZDIMagician main.cpp Parameter.cpp Parameter.h MagicException.cpp MagicException.h Magician.cpp Magician.h 3rdparty/cJSON/cJSON.c Command.cpp Command.h Commander.cpp Commander.h USBSerial.cpp USBSerial.h)

target_include_directories(ZDIMagician PUBLIC 3rdparty/cJSON)
