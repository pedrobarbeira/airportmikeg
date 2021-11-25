cmake_minimum_required(VERSION 3.17)
project(aiportmikeg)

set(CMAKE_CXX_STANDARD 14)

add_executable(aiportmikeg main.cpp date.h voyage/voyage.h voyage/plane.h)