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
    EXPECT_EQ(2 , 4) << "A deliberate failure";
}

int main( int argc , const char * argv [])
{
    testing::InitGoogleTest (&argc, (char **)argv);
    return RUN_ALL_TESTS();
}
