#!/bin/bash
#2345678901234567890123456789012345678901234567890123456789012345678901234567890
# xcionapp_gtest.bash

 2051  g++ -isystem ${GTEST_DIR}/include -pthread path/to/your_test.cc libgtest.a     -o your_test
 2052  ls
 2053  cat tests.cpp 
 2054  g++ -isystem ${GTEST_DIR}/include -pthread ./tests.cpp libgtest.a     -o your_test
 2055  env | grep GTEST
 2056  g++ -isystem ${GTEST_INCLUDE_DIRS} -pthread ./tests.cpp libgtest.a     -o your_test
 2057  find /lib -type f -name libgtest.a
 2058  find /usr -type f -name libgtest.a
 2059  g++ -isystem ${GTEST_INCLUDE_DIRS} -pthread ./tests.cpp /usr/lib/libgtest.a     -o your_test
 2060  ./your_test
 2061  mkdir gtestirchelp1
 2062  cd *1
 2063  git clone --recurse-submodules https://gitlab.ida.liu.se/osksu635/fizzbuzz.git
 2064  ls
 2065  cd fizzbuzz/
 2066  ls
 2067  cd googletest/
 2068  ls
 2069  cd ..
 2070  ls
 2071  vi README.md 
 2072  ls
 2073  vi Makefile
 2074  cp Makefile ~/garage/resinate/cpp/gtestirc.example.mk
 2075  cd ~/garage/resinate/cpp/gtestirc.example.mk
 2076  cd ~/garage/resinate/cpp
 2077  ls
 2078  vi Makefile gtestirc.example.mk 
 2079  ls *.mk
 2080  find  . -type f -name "*.mk"
 2081  vi Makefile old/example.mk 
 2082  ls
 2083  make resinGTests
 2084  ls
 2085  git clone https://github.com/google/googletest.git
 2090  cmake CMakeLists.txt 
 2091  make
