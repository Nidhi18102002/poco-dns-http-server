cmake_minimum_required(VERSION 3.5)
project(poco_server)

find_package(Poco REQUIRED Net Util Foundation)

add_executable(poco_server src/main.cpp)
target_link_libraries(poco_server PRIVATE Poco::Net Poco::Util Poco::Foundation)

