cmake_minimum_required(VERSION 3.9)

project(PROTOFSM_Test_Lib)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../build)

if(UNIX)
    set(THREADS_PREFER_PTHREAD_FLAG ON)
    find_package(Threads REQUIRED)
endif()

set(SOURCE_DIR ${PROTOFSM_SOURCE_DIR}/src)

# Add re2 library
find_library(re2_location NAMES libre2.a)
message(STATUS "re2 location is: ${re2_location}")

add_library(re2 SHARED IMPORTED)
set_target_properties(re2 PROPERTIES IMPORTED_LOCATION ${re2_location})
target_link_libraries(re2 INTERFACE Threads::Threads)

file(GLOB files ./*.cpp)
foreach(file ${files})
    get_filename_component(name ${file} NAME_WE)
    message(STATUS "add execute file ${file}")
    add_executable(${name} ${file})
    # Add re2 for used files.
    if(${name} MATCHES "(re2)")
        # target_link_libraries(${name} re2)
        message(STATUS "find re2 include.")
    endif()
    target_include_directories(${name} PRIVATE ${SOURCE_DIR})
    target_link_libraries(${name} ProtoFsm)
    target_compile_features(${name} PUBLIC cxx_std_11)
endforeach()