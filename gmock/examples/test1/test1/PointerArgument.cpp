//
//  PointerArgument.cpp
//  test1
//
//  Created by wolf76 on 12/20/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//  The examples are from
//  https://code.google.com/p/googlemock/wiki/V1_7_CookBook#Creating_Mock_Classes

#include <gmock/gmock.h>
#include <vector>
using namespace testing;

namespace PointerArgument {
    
// C++ functions often take pointers as arguments. You can use matchers
// like IsNull(), NotNull(), and other comparison matchers to match a pointer,
// but what if you want to make sure the value pointed to by the pointer, instead
// of the pointer itself, has a certain property? Well, you can use the Pointee(m) matcher.

class Foo {
public:
    virtual ~Foo(){};
    virtual bool Bar(int *a)=0;
};

class MockFoo: public Foo {
public:
    MOCK_METHOD1(Bar, bool(int *a));
};

TEST(PointerArgument, Foo)
{
    MockFoo foo;
    
    //EXPECT_CALL(foo, Bar(AllOf(NotNull(), Pointee(Ge(3)))));
    
    // The input can be checked and the output can be set.
    EXPECT_CALL(foo, Bar(AllOf(NotNull(), Pointee(Ge(3))))).WillOnce(DoAll(SetArgPointee<0>(10), Return(false)));
    int i=4;
    bool ret = foo.Bar(&i);
    ASSERT_EQ(10, i);
    ASSERT_THAT(ret, Eq(false));
}
    
// If the output argument is an array, use the SetArrayArgument<N>(first, last)
// action instead. It copies the elements in source range [first, last) to
// the array pointed to by the N-th (0-based) argument:

TEST(PointerArgument, FooArray)
{
    MockFoo foo;

    int values[]={5, 4, 3, 2, 1};
    EXPECT_CALL(foo, Bar(NotNull())).WillOnce(DoAll(SetArrayArgument<0>(values, values+5), Return(true)));
    int a[5];
    bool ret = foo.Bar(a);
    
    //int arr[]={5, 4, 3, 2, 1};
    //ASSERT_THAT(a, ElementsAreArray(arr, arr+5));
    std::vector<int> b{5, 4, 3, 2, 1};
    ASSERT_THAT(a, ElementsAreArray(b.begin(), b.end()));
    ASSERT_THAT(ret, Eq(true));
}

}
