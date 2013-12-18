project(design)
cmake_minimum_required(VERSION 2.6)
#set(ENV{GMOCK_HOME} "${CMAKE_CURRENT_SOURCE_DIR}/../../../gmock")
#set(ENV{JSONCPP_HOME} "${CMAKE_CURRENT_SOURCE_DIR}/../../../jsoncpp")

set(CMAKE_CXX_FLAGS "-std=c++11 -stdlib=libc++ -Wall -O2")

include_directories($ENV{GMOCK_HOME}/include $ENV{JSONCPP_HOME}/include)
link_directories($ENV{GMOCK_HOME}/lib $ENV{JSONCPP_HOME}/lib)

set(sources 
   main.cpp 
   CurlHttpTest.cpp CurlHttp.cpp
   AddressExtractorTest.cpp AddressExtractor.cpp
   PlaceDescriptionServiceTest.cpp PlaceDescriptionService.cpp)
add_executable(test ${sources})
target_link_libraries(test pthread)
target_link_libraries(test gmock)
target_link_libraries(test json)
target_link_libraries(test curl)
