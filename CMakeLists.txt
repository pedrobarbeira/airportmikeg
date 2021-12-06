cmake_minimum_required(VERSION 3.17)
project(mikegairlines)

set(CMAKE_CXX_STANDARD 14)

include_directories( ./airport ./frontend ./passenger ./voyage data)

add_executable(mikegairlines main.cpp src/date.h voyage/voyage.h voyage/plane.h frontend/mainmenu.h  airport/airport.h
        passenger/passenger.h frontend/mainmenu.cpp src/date.cpp frontend/company.cpp frontend/company.h
        frontend/clients.cpp frontend/clients.h airport/staff.h airport/service.h airport/transport.h
        airport/service.cpp airport/airport.cpp airport/transport.cpp airport/staff.cpp data/company.txt voyage/voyage.cpp
        frontend/mikeg.h passenger/luggage.h passenger/luggage.cpp passenger/passenger.h passenger/passenger.cpp
        passenger/ticket.h passenger/ticket.cpp frontend/mikeg.cpp passenger/luggagetransport.cpp passenger/luggagetransport.h
        voyage/flight.cpp voyage/flight.h voyage/plane.cpp)
