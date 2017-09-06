find_package(OpenSSL)
find_path(CPPREST_INCLUDE cpprest/http_client.h)
find_library(CPPREST_LIB NAMES cpprest_2_9d cpprest_2_9 cpprestd cpprest)

if (OPENSSL_FOUND AND CPPREST_LIB)

   include_directories(${CPPREST_INCLUDE})
   include_directories(${OPENSSL_INCLUDE_DIR})

   set (PACKAGE_NAME "Rigetti XACC Accelerator")
   set (PACKAGE_DESCIPTION "Rigetti XACC Accelerator Framework")
   set (LIBRARY_NAME xacc-rigetti-accelerator)

   file (GLOB_RECURSE HEADERS *.hpp)
   file (GLOB SRC *.cpp)

   # Set up dependencies to resources to track changes
   usFunctionGetResourceSource(TARGET ${LIBRARY_NAME} OUT SRC)
   # Generate bundle initialization code
   usFunctionGenerateBundleInit(TARGET ${LIBRARY_NAME} OUT SRC)

   add_library(${LIBRARY_NAME} SHARED ${SRC})

   set(_bundle_name xacc_rigetti_accelerator) 

   set_target_properties(${LIBRARY_NAME} PROPERTIES
     # This is required for every bundle
     COMPILE_DEFINITIONS US_BUNDLE_NAME=${_bundle_name}
     # This is for convenience, used by other CMake functions
     US_BUNDLE_NAME ${_bundle_name}
     )

   if(BUILD_SHARED_LIBS)
     set_target_properties(${LIBRARY_NAME} PROPERTIES
       CXX_VISIBILITY_PRESET hidden
       VISIBILITY_INLINES_HIDDEN 1
       )
   endif()

   # Embed meta-data from a manifest.json file
   usFunctionEmbedResources(TARGET ${LIBRARY_NAME}
     WORKING_DIRECTORY
       ${CMAKE_CURRENT_SOURCE_DIR}
     FILES
       manifest.json
     )

   target_link_libraries(${LIBRARY_NAME} ${Boost_LIBRARIES} ${OPENSSL_LIBRARIES} ${CPPREST_LIB} ${XACC_LIBRARIES})

   install(TARGETS ${LIBRARY_NAME} DESTINATION ${XACC_ROOT}/lib/plugins/accelerators)
   
   file (GLOB test_files ../tests/RigettiAcceleratorTester.cpp)
   add_tests("${test_files}" "${CMAKE_CURRENT_SOURCE_DIR}" "${Boost_LIBRARIES};xacc-rigetti-accelerator")
   
else()
	message(STATUS "OpenSSL or CppRestSDK not found, cannot include Rigetti Accelerator plugin.")
endif()
