# CMake generated Testfile for 
# Source directory: /home/michelel/Celadon/vendor/intel/external/project-celadon/hwcomposer/GUnit-tests
# Build directory: /home/michelel/Celadon/vendor/intel/external/project-celadon/hwcomposer/GUnit-tests/libs
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(example_GMock "./example_GMock")
add_test(example_GTest "./example_GTest")
add_test(test_GMake "./test_GMake")
add_test(test_GMock "./test_GMock")
add_test(test_GTest "./test_GTest")
add_test(test_GTest-Lite "./test_GTest-Lite")
add_test(benchmark_GUnit_test "./benchmark_GUnit_test")
add_test(benchmark_gtest_test "./benchmark_gtest_test")
subdirs("libs/googletest")
subdirs("googletest/googletest-build")
