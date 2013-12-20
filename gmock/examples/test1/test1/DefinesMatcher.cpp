//
//  DefinesMatcher.cpp
//  test1
//
//  Created by wolf76 on 12/20/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include <gmock/gmock.h>
using namespace testing;

MATCHER(IsDivisibleBy7, ""){
    return (arg % 7) == 0;
}

TEST(FooTest, testMatcher)
{
    EXPECT_THAT(14, IsDivisibleBy7());
    EXPECT_THAT(15, Not(IsDivisibleBy7()));
}

// Cannot use the name IsEmpty since there is
// already an IsEmpty defined internally
MATCHER(isEmpty, ""){
    return arg.empty();
}

TEST(FooTest, testIsEmpty)
{
    std::string a("");
    EXPECT_THAT(a, isEmpty());
}

MATCHER_P(HasAbsoluteValue, value, "")
{
    return abs(arg) == value;
}

TEST(FooTest, testMatcherP)
{
    EXPECT_THAT(-10, HasAbsoluteValue(10));
    EXPECT_THAT(8, Not(HasAbsoluteValue(10)));
}