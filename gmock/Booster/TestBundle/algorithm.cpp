//
//  algorithm.cpp
//  Booster
//
//  Created by Jun on 15/3/15.
//  Copyright (c) 2015年 Jun. All rights reserved.
//

#include <gmock/gmock.h>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <boost/algorithm/string/join.hpp>
using namespace std;

TEST(algorithm, copy)
{
    int myints[]={10,20,30};
    ostringstream ss;
    std::copy(myints, myints+3, std::ostream_iterator<int>(ss, ", "));
    ASSERT_THAT(ss.str(), testing::Eq("10, 20, 30, "));
}

TEST(algorithm, copy_if)
{
    int myints[]={10,-20,30};
    vector<int> bar (3);

    auto it = std::copy_if(myints,
                 myints + 3,
                 bar.begin(),
                 [](int i){
                     return i > 0;
                 }
    );
    
    bar.resize(std::distance(bar.begin(), it));
    ASSERT_THAT(bar, testing::ElementsAre(10, 30));
}

TEST(boost_algorithm, join)
{
    vector<string> list{"Hello", "World"};
    string joined = boost::algorithm::join(list, ", ");
    ASSERT_THAT(joined, testing::Eq("Hello, World"));
}
