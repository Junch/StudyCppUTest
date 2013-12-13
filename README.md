StudyCppUTest
=============

Study CppUTest, gtest and gmock in Mac.

Use the make to build the gmock in Mac.

###Build the gtest libray with XCode
  
It is said in README of the gtest source tree as below

```
As an example, the make/ directory contains a Makefile that you can use to build Google Test on systems where GNU make is available (e.g. Linux, Mac OS X, and Cygwin). It doesn't try to build Google Test's own tests. Instead, it just builds the Google Test library and a sample test. You can use it as a starting point for your own build script.

If the default settings are correct for your environment, the following commands should succeed:

cd ${GTEST_DIR}/make make ./sample1_unittest

If you see errors, try to tweak the contents of make/Makefile to make them go away. There are instructions in make/Makefile on how to do it.
```

I refer to the more detailed instructions from [google test with Xcode in mac os x](http://dennycd.me/google-test-xcode-mac-osx).

- Go to the make/ directory under gtest’s source tree and make two static lib

```
make gtest.a gtest_main.a
```

- In order to support the libc++ library in Xcode (with C++11 support), you need to go to gtest’s make/ directory and modify the Makefile by adding the following to CXXFLAGS

```
CXXFLAGS += -g -Wall -Wextra -stdlib=libc++ -std=c++11
```
- You can also build the samples to verify your build.

```
make sample1_unittest
./sample1_unittest
```
