//
//  OverloadedFunctions.cpp
//  test1
//
//  Created by wolf76 on 12/20/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//  The examples are from
//  https://code.google.com/p/googlemock/wiki/V1_7_CookBook#Creating_Mock_Classes

#include <gmock/gmock.h>
using namespace testing;

namespace OverloadedFunctions {

// To disambiguate functions overloaded on the const-ness
// of this object, use the Const() argument wrapper.
    
// If a mock function's return type is a reference, you need to
// use ReturnRef() instead of Return() to return a result:
    
class Bar {

};
    
class Foo {
    virtual Bar& GetBar() = 0;
    virtual const Bar& GetBar() const = 0;
};

class MockFoo: public Foo{
public:
    MOCK_METHOD0(GetBar, Bar&());
    MOCK_CONST_METHOD0(GetBar, Bar&());
    
    Bar& test() const{
        return GetBar();
    }
};
    
TEST(OverloadedFunctions, GetBar)
{
    MockFoo foo;
    Bar bar1, bar2;
    
    EXPECT_CALL(foo, GetBar()).WillOnce(ReturnRef(bar1));
    EXPECT_CALL(Const(foo), GetBar()).Times(2).WillRepeatedly(ReturnRef(bar2));
    
    ASSERT_THAT(&foo.GetBar(), Eq(&bar1));
    ASSERT_THAT(&foo.test(), Eq(&bar2));
    ASSERT_THAT(&(Const(foo).test()), Eq(&bar2));
}

// To disambiguate overloaded functions with the same number of arguments but
// different argument types, you may need to specify the exact type of a matcher,
// either by wrapping your matcher in Matcher<type>(), or using a matcher whose type
// is fixed (TypedEq<type>, An<type>(), etc):

class Printer {
public:
    virtual void Print(int n) = 0;
    virtual void Print(char c)=0;
};

class MockPrinter: public Printer {
public:
    MOCK_METHOD1(Print, void(int n));
    MOCK_METHOD1(Print, void(char c));
};

TEST(OverloadedFunctions, Print)
{
    MockPrinter printer;
    
    
    EXPECT_CALL(printer, Print(An<int>()));
    EXPECT_CALL(printer, Print(Matcher<int>(Lt(5))));
    EXPECT_CALL(printer, Print(TypedEq<char>('a')));
    
    printer.Print('a');
    printer.Print(4);
    printer.Print(10);
}
    
}

