cmake_minimum_required(VERSION 3.9)

project(PROTOFSM_Test_Lib)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../build)

file(GLOB files ./*.cpp)
foreach(file ${files})
    get_filename_component(name ${file} NAME_WE)
    message(STATUS "add execute file ${file}")
    add_executable(${name} ${file})
    # Add re2 for used files.
    if(${name} MATCHES "(re2)")
        target_link_libraries(${name} re2)
        message(STATUS "find re2 include.")
    endif()
endforeach()