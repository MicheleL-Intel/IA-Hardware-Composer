#!/bin/sh
# benchmark
echo -e "\e[34mBlue Running benchmark_GUnit_test"
./libs/benchmark_GUnit_test
echo Running "benchmark_gtest_test"
./libs/benchmark_gtest_test

# examples
echo Running "example_GMock"
./libs/example_GMock
echo Running "example_GTest"
./libs/example_GTest
#echo Running "example_GTest-Lite"
#./libs/example_GTest-Lite

# test
#./libs/test_Detail_FileUtils
#./libs/test_Detail_Preprocessor
#./libs/test_Detail_ProgUtils
#./libs/test_Detail_RegexUtils
#./libs/test_Detail_StringUtils
#./libs/test_Detail_TypeTraits
#./libs/test_Detail_Utility
#./libs/test_GMake
#./libs/test_GMock
#./libs/test_GTest
#./libs/test_GTest-Lite
