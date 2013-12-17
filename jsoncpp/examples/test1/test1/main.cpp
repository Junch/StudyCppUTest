//
//  main.cpp
//  test1
//
//  Created by wolf76 on 12/17/13.
//  Copyright (c) 2013 wolf76. All rights reserved.
//

#include <json/json.h>
#include <string>
#include <iostream>
using namespace std;
int main()
{
    string test ="{\"id\":1,\"name\":\"kurama\"}";
    Json::Reader reader;
    Json::Value value;
    if(reader.parse(test,value))
    {
        if(!value["id"].isNull())
        {
            cout<<value["id"].asInt()<<endl;
            cout<<value["name"].asString()<<endl;
        }
    }
    return 0;
}
