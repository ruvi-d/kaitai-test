cmake_minimum_required(VERSION 3.2)
project(bir_parser VERSION 0.0.1 LANGUAGES CXX)

# App
file(GLOB SOURCES
    ${PROJECT_SOURCE_DIR}/src/*.cpp
)
add_executable(kaitai_test ${SOURCES})
target_link_libraries(kaitai_test PRIVATE kaitai_struct_cpp_stl_runtime)

# Testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR})
add_executable(tests ${PROJECT_SOURCE_DIR}/test/basic_tests.cpp)
target_link_libraries(tests PRIVATE  ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY} pthread)
add_test(NAME tests COMMAND tests)