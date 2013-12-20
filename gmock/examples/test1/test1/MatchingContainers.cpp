//
//  MatchingContainers.cpp
//  test1
//
//  Created by wolf76 on 12/20/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//  The examples are from
//  https://code.google.com/p/googlemock/wiki/V1_7_CookBook#Creating_Mock_Classes

#include <gmock/gmock.h>
#include <vector>
using namespace std;
using namespace testing;

namespace MatchingContainers {


class Foo {
public:
    virtual ~Foo(){};
    virtual void Bar(const vector<int>& numbers) = 0;
};

class MockFoo: public Foo {
public:
    MOCK_METHOD1(Bar, void(const vector<int>& numbers));
};

TEST(MatchingContainers, Foo)
{
    MockFoo foo;
    EXPECT_CALL(foo, Bar(ElementsAre(1, Gt(0), _, 5)));
    EXPECT_CALL(foo, Bar(UnorderedElementsAre(2, 3)));
    
    const vector<int> a{1, 2, 3, 5};
    foo.Bar(a);
    
    const vector<int> b{3, 2};
    foo.Bar(b);
}
    
}
