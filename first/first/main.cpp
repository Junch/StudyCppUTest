#include <CppUTest/CommandLineTestRunner.h>

int Foo( int a , int b)
{
    if ( a == 0 || b == 0)
        throw "don't do that" ;
    
    int c = a % b;
    if ( c == 0)
        return b ;
    
    return Foo (b, c);
}

TEST_GROUP(FirstTestGroup)
{
};

TEST(FirstTestGroup, FirstTest)
{
    CHECK_EQUAL(2, Foo(4, 10));
    LONGS_EQUAL(6, Foo(30, 18));
}

//        In GTEST
//
//TEST (FooTest, HandleNoneZeroInput)
//{
//    EXPECT_EQ(2 , Foo (4, 10));
//    EXPECT_EQ(6 , Foo (30, 18));
//}

TEST(FirstTestGroup, FailTest)
{
    FAIL("Fail me!");
}

int main(int argc, const char * argv[])
{
    return CommandLineTestRunner::RunAllTests(argc, argv);
}
