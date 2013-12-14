//
//  FooMock.h
//  test2
//
//  Created by wolf76 on 2/25/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#ifndef FooMock_h
#define FooMock_h

#include <gmock/gmock.h>
#include <string>
#include "FooInterface.h"

namespace seamless{

class MockFoo: public FooInterface {
public:
    MOCK_METHOD0(getAribitraryString, std::string());
};

} // seamless

#endif
