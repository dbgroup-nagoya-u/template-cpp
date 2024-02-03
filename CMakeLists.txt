cmake_minimum_required(VERSION "3.8")

# decline in-source build
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

# project information
project(
  hello_world
  VERSION "0.1.0"
  DESCRIPTION "A template project for C++ language."
  LANGUAGES "CXX"
)

#------------------------------------------------------------------------------#
# Use gflags to manage CLI options
#------------------------------------------------------------------------------#

find_package(gflags REQUIRED)

#------------------------------------------------------------------------------#
# Build targets
#------------------------------------------------------------------------------#

add_executable(${PROJECT_NAME}
  "${CMAKE_CURRENT_SOURCE_DIR}/src/hello_world.cpp"
)
target_compile_features(${PROJECT_NAME} PRIVATE
  "cxx_std_17"
)
target_compile_options(${PROJECT_NAME} PRIVATE
  -Wall
  -Wextra
  $<$<STREQUAL:${CMAKE_BUILD_TYPE},"Release">:"-O2 -march=native">
  $<$<STREQUAL:${CMAKE_BUILD_TYPE},"RelWithDebInfo">:"-g3 -Og -pg">
  $<$<STREQUAL:${CMAKE_BUILD_TYPE},"Debug">:"-g3 -O0 -pg">
)
target_link_libraries(${PROJECT_NAME} PRIVATE
  gflags
)

#------------------------------------------------------------------------------#
# Build unit tests if required
#------------------------------------------------------------------------------#

option(BUILD_TESTS, "Build unit tests" OFF)
if(${BUILD_TESTS})
  # enable CTest
  enable_testing()
  # include unit tests
  add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test")
endif()
