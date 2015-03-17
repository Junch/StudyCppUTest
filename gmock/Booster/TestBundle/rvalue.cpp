//
//  rvalue.cpp
//  Booster
//
//  Created by Jun on 15/3/15.
//  Copyright (c) 2015年 Jun. All rights reserved.
//

// http://www.th7.cn/Program/cp/201304/131554.shtml

#include <gmock/gmock.h>
#include <string>
using namespace std;

class rvalue: public testing::Test{
protected:
    
    class AClass {
    public:
        
        void reference_overload(string& str){
            m_str = "type &";
        }
        
        void reference_overload(string&& str){
            m_str = "type &&";
        }
        
        void reference_overload(string const & str){
            m_str = "type const &";
        }
        
        void reference_overload(string const && str){
            m_str = "type const &&";
        }
        
        string m_str;
    };
    
    
    class BClass {
    public:
        
        void reference_overload(string&& str){
            m_str = "type &&";
        }
        
        void reference_overload(string const & str){
            m_str = "type const &";
        }
        
        string m_str;
    };
    
    
    string const GetConstString() {
        return string("const_rvalue");
    }
    
    AClass m_foo;
    BClass m_goo;
};

TEST_F(rvalue, left_refer)
{
    string lvalue("lvalue");
    m_foo.reference_overload(lvalue);
    ASSERT_THAT(m_foo.m_str, testing::Eq("type &"));
    
    m_goo.reference_overload(lvalue);
    ASSERT_THAT(m_goo.m_str, testing::Eq("type const &"));
}

TEST_F(rvalue, const_left_refer)
{
    string const const_lvalue("lvalue");
    m_foo.reference_overload(const_lvalue);
    ASSERT_THAT(m_foo.m_str, testing::Eq("type const &"));
    
    m_goo.reference_overload(const_lvalue);
    ASSERT_THAT(m_goo.m_str, testing::Eq("type const &"));
}

TEST_F(rvalue, right_refer)
{
    m_foo.reference_overload(string("rvalue"));
    ASSERT_THAT(m_foo.m_str, testing::Eq("type &&"));
    
    m_goo.reference_overload(string("rvalue"));
    ASSERT_THAT(m_goo.m_str, testing::Eq("type &&"));
}


TEST_F(rvalue, const_right_refer)
{
    m_foo.reference_overload(GetConstString());
    ASSERT_THAT(m_foo.m_str, testing::Eq("type const &&"));
    
    m_goo.reference_overload(GetConstString());
    ASSERT_THAT(m_goo.m_str, testing::Eq("type const &"));
}
