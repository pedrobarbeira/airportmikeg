cmake_minimum_required(VERSION 3.17)
project(mikegairlines)

set(CMAKE_CXX_STANDARD 14)

include_directories(./data ./src ./docs)

add_executable(mikegairlines main.cpp src/date.h src/voyage.h src/plane.h src/airport.h
        src/passenger.h src/date.cpp src/service.h src/service.cpp src/airport.cpp
        data/company.txt src/voyage.cpp src/mikeg.h src/luggage.h src/luggage.cpp
        src/passenger.h src/ticket.h src/ticket.cpp src/mikeg.cpp
        src/flight.cpp src/flight.h src/plane.cpp src/bst.h src/menu.cpp src/menu.h
        src/user.h src/data.cpp src/data.h src/pointer.h src/pointer.cpp src/sorter.h src/exception.h src/sorter.cpp )

# Doxygen Build
find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/docs/output")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()
    set(DOXYGEN_IN "${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)
    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)
