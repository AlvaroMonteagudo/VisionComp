cmake_minimum_required(VERSION 2.8)
project( practica1 )
find_package( OpenCV REQUIRED )
add_executable( distortion distortion.cpp )
add_executable( alien alien.cpp )
add_executable( reduce_colors reduce_colors.cpp )
add_executable( contraste contraste.cpp )
add_executable( hist hist.cpp )
target_link_libraries( distortion ${OpenCV_LIBS} )
target_link_libraries( alien ${OpenCV_LIBS} )
target_link_libraries( reduce_colors ${OpenCV_LIBS} )
target_link_libraries( contraste ${OpenCV_LIBS} )
target_link_libraries( hist ${OpenCV_LIBS} )