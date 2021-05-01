#--------------------------------------------------------------------------------------#
# Configure GoogleTest
#--------------------------------------------------------------------------------------#

# Prevent overriding the parent INDEX_BENCH's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/external/googletest")

#--------------------------------------------------------------------------------------#
# Build Unit Tests
#--------------------------------------------------------------------------------------#

# define function to add unit tests in the same format
function(ADD_PROJECT_TEST PROJECT_TEST_TARGET)
  add_executable(${PROJECT_TEST_TARGET}
    "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_TEST_TARGET}.cpp"
  )
  target_compile_features(${PROJECT_TEST_TARGET} PRIVATE "cxx_std_17")
  target_compile_options(${PROJECT_TEST_TARGET} PRIVATE
    -Wall
    -Wextra
    $<$<STREQUAL:${CMAKE_BUILD_TYPE},"Release">:"-O2 -march=native">
    $<$<STREQUAL:${CMAKE_BUILD_TYPE},"RelWithDebInfo">:"-g3 -Og -pg">
    $<$<STREQUAL:${CMAKE_BUILD_TYPE},"Debug">:"-g3 -O0 -pg">
  )
  target_link_libraries(${PROJECT_TEST_TARGET} PRIVATE
    gflags
    gtest_main
  )
  add_dependencies(${PROJECT_TEST_TARGET}
    gflags
    gtest_main
  )
  add_test(NAME ${PROJECT_TEST_TARGET} COMMAND $<TARGET_FILE:${PROJECT_TEST_TARGET}>)
endfunction()

# add unit tests to build targets
ADD_PROJECT_TEST("hello_world_test")
