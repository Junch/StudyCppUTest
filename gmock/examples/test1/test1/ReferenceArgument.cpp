//
//  ReferenceArgument.cpp
//  test1
//
//  Created by wolf76 on 12/20/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include <gmock/gmock.h>

using namespace std;
using namespace testing;

namespace ReferenceArgument {
    class Request{
    };
    
    class Response {
    public:
        int age;
        bool operator == (const Response& r) const {
            if (this == &r )
                return true;
            
            return age == r.age;
        }
    };
    
    class Foo {
    public:
        virtual ~Foo(){}
        virtual void QueryXXX(const Request&, Response&) = 0;
    };
    
    class MockFoo: public Foo {
    public:
        MOCK_METHOD2(QueryXXX, void(const Request&, Response&));
    };
    
    TEST(ReferenceArgument, Foo){
        MockFoo foo;
        
        Response r;
        r.age = 20;
        EXPECT_CALL(foo, QueryXXX(_, _)).WillOnce(SetArgReferee<1>(r));
        
        Request a;
        Response b;
        foo.QueryXXX(a, b);
        EXPECT_THAT(b, Eq(r));
    }
}
