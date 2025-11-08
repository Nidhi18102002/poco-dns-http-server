cmake_minimum_required(VERSION 3.10)
project(poco_http)

find_package(Poco REQUIRED Net Util Foundation)

add_executable(poco_http src/main.cpp)
target_link_libraries(poco_http Poco::Net Poco::Util Poco::Foundation)
