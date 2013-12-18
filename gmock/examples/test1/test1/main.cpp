#include <gmock/gmock.h>
using namespace testing;

int Foo( int a , int b)
{
    if ( a == 0 || b == 0)
        throw "don't do that" ;
    
    int c = a % b;
    if ( c == 0)
        return b ;
    
    return Foo (b, c);
}

TEST (FooTest, HandleNoneZeroInput)
{
    EXPECT_EQ(2 , Foo (4, 10));
    EXPECT_EQ(6 , Foo (30, 18));
}

TEST (FooTest, testfail)
{
    EXPECT_EQ(2 , 4);
}

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

int main( int argc , const char * argv [])
{
    testing::InitGoogleTest (&argc, (char **)argv);
    return RUN_ALL_TESTS();
}
