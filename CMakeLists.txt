cmake_minimum_required(VERSION 3.17)
project(mikegairlines)

set(CMAKE_CXX_STANDARD 14)

include_directories( ./airport ./frontend ./passenger ./voyage cmake-build-debug/credentials)

add_executable(mikegairlines main.cpp date.h voyage/voyage.h voyage/plane.h frontend/mainmenu.h  airport/airport.h
        passenger/passenger.h frontend/mainmenu.cpp date.cpp frontend/admin.cpp frontend/admin.h frontend/workers.cpp
        frontend/workers.h frontend/clients.cpp frontend/clients.h airport/staff.h airport/service.h airport/transport.h
        airport/service.cpp airport/airport.cpp airport/transport.cpp airport/staff.cpp)