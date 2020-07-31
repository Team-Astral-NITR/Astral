cmake_minimum_required(VERSION 2.8.3)
project(RRTSim)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_CXX_FLAGS "-march=native -O3 -Wall")

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Eigen3)

## System dependencies are found with CMake's conventions
find_package(Qt4 REQUIRED COMPONENTS QtCore QtGui)
include(${QT_USE_FILE})
include_directories(${CMAKE_CURRENT_BINARY_DIR})

################################################
## Find files
################################################
file(GLOB QT_FORMS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ui/*.ui)
set(QT_MOC include/mainwindow/mainwindow.h)
SET(QT_SOURCES src/mainwindow.cpp)

################################################
## Setup QT
################################################
QT4_WRAP_UI(QT_FORMS_HPP ${QT_FORMS})
QT4_WRAP_CPP(QT_MOC_HPP ${QT_MOC})

if(Eigen3_FOUND)
  set(CUSTOM_EIGEN ${EIGEN3_INCLUDE_DIR})
else()
  find_package(Eigen)
  set(CUSTOM_EIGEN ${EIGEN_INCLUDE_DIR})
endif()

include_directories(
  include
  ${CUSTOM_EIGEN}
  ${QT_INCLUDE_DIRS}
)

add_library(qt_lib ${QT_SOURCES} ${QT_FORMS_HPP} ${QT_MOC_HPP})
target_link_libraries(qt_lib ${QT_LIBRARIES})

add_library(obstacles_lib include/common/obstacles.h src/obstacles.cpp)
add_library(renderarea_lib include/common/renderarea.h src/renderarea.cpp)
add_library(rrt_lib include/rrt/rrt.h src/rrt.cpp)

add_executable(rrt-test src/main.cpp)
target_link_libraries(rrt-test qt_lib obstacles_lib renderarea_lib rrt_lib)
