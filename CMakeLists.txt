cmake_minimum_required(VERSION 3.10)
project(imgProc)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_executable(imgProc main.cpp cropImage.cpp normalize.cpp grayScale.cpp histEqualization.cpp medianBlur.cpp)

target_link_libraries(imgProc ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
