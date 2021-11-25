cmake_minimum_required(VERSION 3.17)
project(mikegairlines)

set(CMAKE_CXX_STANDARD 14)

add_executable(mikegairlines main.cpp date.h voyage/voyage.h voyage/plane.h frontend/mainmenu.h  airport/airport.h passenger/passenger.h frontend/mainmenu.cpp)