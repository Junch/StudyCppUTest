//
//  PredicatesAsMatcher.cpp
//  test1
//
//  Created by wolf76 on 12/20/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include <gmock/gmock.h>
using namespace testing;

namespace PredicatesAsMatcher {
    
    class Foo {
    public:
        virtual ~Foo(){};
        virtual void Bar(int a) = 0;
    };
    
    class MockFoo: public Foo {
    public:
        MOCK_METHOD1(Bar, void(int a));
    };
    
    bool isEven(int n) {
        return n%2==0;
    }
    
    TEST(PredicatesAsMatcher, Foo)
    {
        MockFoo foo;
        
        EXPECT_CALL(foo, Bar(Truly(isEven)));
        
        foo.Bar(4);
    }
}
