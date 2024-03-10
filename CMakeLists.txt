cmake_minimum_required(VERSION 3.25)
project(cvec)

add_library(cvec SHARED cvec.c)
add_executable(cvec_test cvec.c)

if(CMAKE_SYSTEM_NAME MATCHES "Linux")
	set(CMAKE_INSTALL_PREFIX /usr)
else()

endif()

install(TARGETS cvec DESTINATION lib)
install(FILES cvec.h DESTINATION include)