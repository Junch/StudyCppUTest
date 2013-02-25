//
//  FooInterface.h
//  test2
//
//  Created by wolf76 on 2/25/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#ifndef FooInterface_h
#define FooInterface_h

#include <string>

namespace seamless{
    
class FooInterface{
public:
    virtual ~FooInterface(){}
public:
    virtual std::string getAribitraryString() = 0;
};
    
} //namespace seamless

#endif
