//
//  UseON_CALL.cpp
//  test1
//
//  Created by wolf76 on 12/20/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//  Refer to
//  http://stackoverflow.com/questions/13933475/gmock-setting-default-actions-on-call-vs-expect-call

#include <gmock/gmock.h>
#include <string>

using namespace testing;

namespace UseON_CALL{
    class Foo{
    public:
        virtual ~Foo(){};
        virtual int Sign(int a, std::string *s) = 0;
    };
    
    class MockFoo: public Foo {
    public:
        MOCK_METHOD2(Sign, int(int a, std::string* s));
    };
    
    TEST(UseON_CALL, ProvidesDefaultBehaviorForACallSpecifiedByEXPECT_CALL)
    {
        MockFoo foo;
        ON_CALL(foo, Sign(Eq(0), _)).WillByDefault(DoAll(SetArgPointee<1>("argument is zero"), Return(0)));
        ON_CALL(foo, Sign(Gt(0), _)).WillByDefault(DoAll(SetArgPointee<1>("argument is positive"), Return(1)));
        ON_CALL(foo, Sign(Lt(0), _)).WillByDefault(DoAll(SetArgPointee<1>("argument is negtive"), Return(-1)));
        
        EXPECT_CALL(foo, Sign(10, _));
        std::string s;
        int ret = foo.Sign(10, &s);
        ASSERT_THAT(s, Eq("argument is positive"));
        ASSERT_THAT(ret, Eq(1));
    }
    
    TEST(UseON_CALL, UseEXPECT_CALLToSetReturnedValue)
    {
        MockFoo foo;
        
        EXPECT_CALL(foo, Sign(Gt(0), _)).WillRepeatedly(Return(1));
        EXPECT_CALL(foo, Sign(10, _));
  
        std::string s;
        int ret = foo.Sign(10, &s);
        ASSERT_THAT(ret, Eq(0));
    }
    
    TEST(UseON_CALL, UseON_CALLToSetReturnedValue)
    {
        MockFoo foo;
        
        ON_CALL(foo, Sign(Gt(0), _)).WillByDefault(Return(1));
        EXPECT_CALL(foo, Sign(10, _));
        
        std::string s;
        int ret = foo.Sign(10, &s);
        ASSERT_THAT(ret, Eq(1));
    }
}