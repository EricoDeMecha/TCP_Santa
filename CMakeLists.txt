cmake_minimum_required(VERSION 3.20)
project(TCPSanta)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        ${CMAKE_SOURCE_DIR}/main.cpp)
# Boost Asio for networking
set(BOOST_DEBUG ON)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS system program_options REQUIRED)
if(Boost_FOUND)
    message("${Boost_VERSION_STRING} Boost found")
    include_directories(${Boost_INCLUDE_DIR})
endif()

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})