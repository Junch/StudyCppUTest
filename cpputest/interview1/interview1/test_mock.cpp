//
//  test_mock.cpp
//  interview1
//
//  Created by Jun on 14-3-13.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"

TEST_GROUP(MockDocumentation)
{
    void teardown()
    {
        mock().clear();
    }
};

void productionCode()
{
    mock().actualCall("productionCode");
}

TEST(MockDocumentation, SimpleScenario)
{
    mock().expectOneCall("productionCode");
    productionCode();
    mock().checkExpectations();
}
