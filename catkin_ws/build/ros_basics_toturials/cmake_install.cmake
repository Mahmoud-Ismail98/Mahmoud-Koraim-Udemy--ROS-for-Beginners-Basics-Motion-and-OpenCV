# Install script for directory: /home/korayem/Udemy - ROS for Beginners Basics, Motion, and OpenCV./catkin_ws/src/ros_basics_toturials

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/korayem/Udemy - ROS for Beginners Basics, Motion, and OpenCV./catkin_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/korayem/Udemy - ROS for Beginners Basics, Motion, and OpenCV./catkin_ws/build/ros_basics_toturials/catkin_generated/installspace/ros_basics_toturials.pc")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros_basics_toturials/cmake" TYPE FILE FILES
    "/home/korayem/Udemy - ROS for Beginners Basics, Motion, and OpenCV./catkin_ws/build/ros_basics_toturials/catkin_generated/installspace/ros_basics_toturialsConfig.cmake"
    "/home/korayem/Udemy - ROS for Beginners Basics, Motion, and OpenCV./catkin_ws/build/ros_basics_toturials/catkin_generated/installspace/ros_basics_toturialsConfig-version.cmake"
    )
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/ros_basics_toturials" TYPE FILE FILES "/home/korayem/Udemy - ROS for Beginners Basics, Motion, and OpenCV./catkin_ws/src/ros_basics_toturials/package.xml")
endif()

