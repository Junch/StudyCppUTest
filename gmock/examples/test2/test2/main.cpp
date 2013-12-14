//
//  main.cpp
//  test2
//
//  Created by wolf76 on 2/25/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include <cstdlib>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <iostream>
#include <string>

#include "FooMock.h"

using namespace seamless;
using namespace std;
using ::testing::Return;

int main(int argc, const char * argv[])
{
    ::testing::InitGoogleMock(&argc, (char**)argv);
    
    string value = "Hello World";
    MockFoo mockFoo;

    EXPECT_CALL(mockFoo, getAribitraryString()).Times(1).WillOnce(Return(value));
    
    string returnValue = mockFoo.getAribitraryString();
    cout << "Returned Value: " << returnValue << endl;
    
    return EXIT_SUCCESS;
}

