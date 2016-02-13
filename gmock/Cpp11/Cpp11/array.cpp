//
//  array.cpp
//  Cpp11
//
//  Created by Jun Chen on 16/2/13.
//  Copyright © 2016年 Jun. All rights reserved.
//

#include <gtest/gtest.h>
#include <memory>
using namespace testing;
using namespace std;

namespace array {
    TEST(array, initialization) {
        int x[4] = {1};
        
        ASSERT_EQ(1, x[0]);
        ASSERT_EQ(0, x[1]);
        ASSERT_EQ(0, x[2]);
        ASSERT_EQ(0, x[3]);
        
        vector<int> y(4, 1);
        vector<int> z{1, 1, 1, 1};
        ASSERT_EQ(z, y);
    }
}
