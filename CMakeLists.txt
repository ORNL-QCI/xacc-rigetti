cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(xacc-rigetti LANGUAGES CXX)

set(CMAKE_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
message(STATUS "C++ version ${CXX_STANDARD} configured.")

find_package(XACC REQUIRED)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${XACC_ROOT}" CACHE PATH "default install path" FORCE )
endif()

set(CppMicroServicesConfig_DIR "${XACC_ROOT}/share/cppmicroservices3/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${XACC_ROOT}/share/xacc")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CppMicroServicesConfig_DIR}")
set(BOOST_ROOT ${XACC_ROOT})
include(tests)
include(CppMicroServicesConfig)

#find_package(Boost COMPONENTS system program_options filesystem chrono thread REQUIRED)

include_directories(${XACC_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/utils)

link_directories(${XACC_LIBRARY_DIR})

add_subdirectory(compiler)
add_subdirectory(accelerator)
if(PYTHON_INCLUDE_DIR)
add_subdirectory(python)
endif()
#add_subdirectory(examples)

include_directories(${CMAKE_SOURCE_DIR}/compiler)
# Gather tests
file (GLOB test_files tests/Quil*.cpp)
#add_tests("${test_files}" "${CMAKE_CURRENT_SOURCE_DIR}" "${XACC_LIBRARIES};xacc-rigetti-quilcompiler")
   
