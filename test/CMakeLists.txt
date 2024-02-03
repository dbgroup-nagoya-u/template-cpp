#------------------------------------------------------------------------------#
# Configure external libraries
#------------------------------------------------------------------------------#

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY "https://github.com/google/googletest.git"
  GIT_TAG "58d77fa8070e8cec2dc1ed015d66b454c8d78850" # v1.12.1
)
FetchContent_MakeAvailable(googletest)

FetchContent_Declare(
  cpp-utility
  GIT_REPOSITORY "https://github.com/dbgroup-nagoya-u/cpp-utility.git"
  GIT_TAG "c37418e13d8e258b9b76470a4958a974da37c093"
)
FetchContent_MakeAvailable(cpp-utility)

#------------------------------------------------------------------------------#
# Build Unit Tests
#------------------------------------------------------------------------------#

# define function to add unit tests in the same format
function(ADD_HELLO_WORLD_TEST HELLO_WORLD_TEST_TARGET)
  add_executable(${HELLO_WORLD_TEST_TARGET}
    "${CMAKE_CURRENT_SOURCE_DIR}/${HELLO_WORLD_TEST_TARGET}.cpp"
  )
  target_compile_features(${HELLO_WORLD_TEST_TARGET} PRIVATE
    "cxx_std_17"
  )
  target_compile_options(${HELLO_WORLD_TEST_TARGET} PRIVATE
    -Wall
    -Wextra
    $<$<STREQUAL:${CMAKE_BUILD_TYPE},"Release">:"-O2 -march=native">
    $<$<STREQUAL:${CMAKE_BUILD_TYPE},"RelWithDebInfo">:"-g3 -Og -pg">
    $<$<STREQUAL:${CMAKE_BUILD_TYPE},"Debug">:"-g3 -O0 -pg">
  )
  target_link_libraries(${HELLO_WORLD_TEST_TARGET} PRIVATE
    gflags
    GTest::gtest_main
  )
  add_test(NAME ${HELLO_WORLD_TEST_TARGET} COMMAND $<TARGET_FILE:${HELLO_WORLD_TEST_TARGET}>)
endfunction()

# add unit tests to build targets
ADD_HELLO_WORLD_TEST("hello_world_test")
