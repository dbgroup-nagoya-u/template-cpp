cmake_minimum_required(VERSION "3.8")

# decline in-source build
if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
  message(FATAL_ERROR "In-source builds are not allowed.")
endif()

# project information
project(cpp_template
  VERSION "0.1.0"
  DESCRIPTION "A template project for C++ language."
  LANGUAGES "CXX"
)

# define source directories
set(PROJECT_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

#--------------------------------------------------------------------------------------#
# Configure gflags
#--------------------------------------------------------------------------------------#

# prevent building unit tests
set(BUILD_TESTING OFF CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/external/gflags")

#--------------------------------------------------------------------------------------#
# Build project
#--------------------------------------------------------------------------------------#

add_executable(cpp_template
  "${PROJECT_SOURCE_DIR}/hello_world.cpp"
)
target_compile_features(cpp_template PRIVATE "cxx_std_17")
target_compile_options(cpp_template PRIVATE
  -Wall
  -Wextra
  $<$<STREQUAL:${CMAKE_BUILD_TYPE},"Release">:"-O2 -march=native">
  $<$<STREQUAL:${CMAKE_BUILD_TYPE},"RelWithDebInfo">:"-g3 -Og -pg">
  $<$<STREQUAL:${CMAKE_BUILD_TYPE},"Debug">:"-g3 -O0 -pg">
)
target_link_libraries(cpp_template PRIVATE
  gflags
)
add_dependencies(cpp_template
  gflags
)

# build unit tests if required
option(BUILD_TESTS, "Build unit tests" OFF)
if(${BUILD_TESTS})
  # enable CTest
  enable_testing()
  # include unit tests
  add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/test")
endif()
