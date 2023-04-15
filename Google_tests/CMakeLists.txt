# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run Index_of_Coincidence_Tests.cpp Index_of_Confidence_Tests.cpp ../lib/Index_of_Coincidence.cpp ../lib/Index_of_Coincidence.h ../lib/CipherLib.cpp ../lib/CipherLib.h)
target_link_libraries(Google_Tests_run gtest gtest_main)