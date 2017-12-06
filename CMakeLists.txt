cmake_minimum_required(VERSION 3.8)
project(mikolajki_sfml)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
set(EXECUTABLE_NAME mikolajki_sfml)
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()