//
//  regex.cpp
//  Booster
//
//  Created by Jun on 15/3/14.
//  Copyright (c) 2015年 Jun. All rights reserved.
//

#include <gmock/gmock.h>
#include <regex>
#include <string>
#include <vector>
using namespace std;
using namespace testing;

TEST(regex, regex_search)
{
    regex pattern("(\\w+day)");
    string weekend = "Saturday and Sunday, but some Fridays also.";
    
    smatch result;
    bool match = regex_search(weekend, result, pattern);

    ASSERT_TRUE(match);
    ASSERT_EQ(2, result.size());
    ASSERT_THAT(result.str(0), Eq("Saturday"));
    ASSERT_THAT(result.str(1), Eq("Saturday"));
}

TEST(regex, sregex_token_iterator)
{
    regex pattern("(\\w+day)");
    string weekend = "Saturday and Sunday, but some Fridays also.";
    
    vector<string> tokens;
    for (std::sregex_token_iterator i(weekend.begin(),weekend.end(), pattern), end; i != end ; ++i) {
        tokens.push_back(*i);
    }
    
    ASSERT_THAT(tokens[0], Eq("Saturday"));
    ASSERT_THAT(tokens[1], Eq("Sunday"));
    ASSERT_THAT(tokens[2], Eq("Friday"));
}

//std::cregex_iterator when your subject is an array of char
//std::sregex_iterator when your subject is an std::string object
//std::wcregex_iterator when your subject is an array of wchar_t
//std::wsregex_iterator when your subject is an std::wstring object

TEST(regex, sregex_iterator)
{
    std::string subject("This is a test");
    
    std::regex re("\\w+");
    std::sregex_iterator next(subject.begin(), subject.end(), re);
    std::sregex_iterator end;
    
    vector<string> tokens;
    while (next != end) {
        std::smatch match = *next;
        tokens.push_back(match.str());
        next++;
    }
    
    ASSERT_THAT(tokens[0], Eq("This"));
    ASSERT_THAT(tokens[1], Eq("is"));
    ASSERT_THAT(tokens[2], Eq("a"));
    ASSERT_THAT(tokens[3], Eq("test"));
}

TEST(regex, wsregex_iterator)
{
    std::wstring subject(L"This is a test");
    
    std::wregex re(L"\\w+");
    std::wsregex_iterator next(subject.begin(), subject.end(), re);
    std::wsregex_iterator end;
    
    vector<wstring> tokens;
    while (next != end) {
        std::wsmatch match = *next;
        tokens.push_back(match.str());
        next++;
    }
    
    ASSERT_THAT(tokens[0], Eq(L"This"));
    ASSERT_THAT(tokens[1], Eq(L"is"));
    ASSERT_THAT(tokens[2], Eq(L"a"));
    ASSERT_THAT(tokens[3], Eq(L"test"));
}

TEST(regex, cregex_iterator)
{
    const char* subject = "This is a test";
    
    std::regex re("\\w+");
    std::cregex_iterator next(subject, subject + std::strlen(subject), re);
    std::cregex_iterator end;
    
    vector<string> tokens;
    while (next != end) {
        std::cmatch match = *next;
        tokens.push_back(match.str());
        next++;
    }
    
    ASSERT_THAT(tokens[0], Eq("This"));
    ASSERT_THAT(tokens[1], Eq("is"));
    ASSERT_THAT(tokens[2], Eq("a"));
    ASSERT_THAT(tokens[3], Eq("test"));
}
