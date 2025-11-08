cmake_minimum_required(VERSION 3.10)
project(poco_dns)

find_package(Poco REQUIRED Net Foundation)

add_executable(poco_dns src/main.cpp)

target_link_libraries(poco_dns PRIVATE Poco::Net Poco::Foundation)

