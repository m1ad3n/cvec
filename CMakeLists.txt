cmake_minimum_required(VERSION 3.25)
project(cvec)

add_library(cvec SHARED cvec.c)

install(TARGETS cvec DESTINATION lib)
install(FILES cvec.h DESTINATION include)