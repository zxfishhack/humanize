cmake_minimum_required(VERSION 3.20)
project(humanize)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

OPTION(humanize_BUILD_TESTS "build test" OFF)

if(humanize_BUILD_TESTS)
  include(FetchContent)
  FetchContent_Declare(
    gtest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  )
  FetchContent_MakeAvailable(gtest)
  include_directories(${gtest_SOURCE_DIR}/googlemock/include)
  include_directories(${gtest_SOURCE_DIR}/googletest/include)

  file(GLOB_RECURSE all_tests_files FOLLOW_SYMLINKS tests/*.cpp)

  add_executable(tests ${all_tests_files} ${common_test_files} ${all_proto_files})
  target_link_libraries(tests gtest_main)

  add_custom_target(check
    COMMAND tests --gtest_brief=1
    DEPENDS tests
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
endif()
