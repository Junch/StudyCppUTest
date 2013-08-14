//
//  hdoj1016.cpp
//  interview1
//  http://acm.hdu.edu.cn/showproblem.php?pid=1016
//  Created by wolf76 on 13-8-13.
//  Copyright (c) 2013年 com.wolf76. All rights reserved.
//

#include <CppUTest/TestHarness.h>
#include <cassert>
#include <iostream>
#include <vector>
#include <sstream> //strstream is deprecated
#include <string>
using namespace std;

namespace HDOJ1016 {

bool prime(int n)
{
    if (n < 2)
        return false;
    
    for (int i=2; i*i<n+1; i+=1)
        if (n%i == 0)
            return false;
        
    return true;
}
    
void (*ringcallback)(vector<int>& v) = NULL;
    
void print(vector<int>& a){
    cout << a[0];
    for (vector<int>::iterator iter=a.begin()+1; iter!=a.end(); ++iter)
        cout << " " << *iter;
    cout << endl;
}

string buffer;
void print2(vector<int>& a){
    stringstream ss;
    ss << a[0];
    for (vector<int>::iterator iter=a.begin()+1; iter!=a.end(); ++iter)
        ss << " " << *iter;
    ss << endl;
    buffer += ss.str();
}

void ring(vector<int>& r, vector<int>& s)
{
    if (s.empty()) {
        if (ringcallback)
            ringcallback(r);
        return;
    }
    else if(s.size() == 1) {
        if (!prime(s[0] + 1))
            return;
    }
    
    int val = *r.rbegin();

    vector<int>::iterator iter = s.begin();
    while(iter != s.end()) {
        int i = *iter;
        if (prime(i+val)) {
            r.push_back(i);
            s.erase(iter);
            ring(r,s);
            r.pop_back();
            s.insert(iter, i);
        }
        iter++;
    }
}

int main()
{
    int n = 0;
    int cases = 0;
    ringcallback = print;
    while(cin >> n)
    {
        vector<int> r;
        r.push_back(1);
               
        vector<int> s;
        for (int i=2; i<=n; i++)
            s.push_back(i);
        
        cout << "Case " << ++cases << ":\n";
        ring(r,s);
        cout << endl;
    }
    
    return 0;
}

////////////////////
//  TEST
////////////////////
TEST_GROUP(HDOJ1016)
{
    void setup() {
        MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    }
    
    void teardown(){
        MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
    }
};
    
IGNORE_TEST(HDOJ1016, HDOJ1016)
{
    main();
}
    
TEST(HDOJ1016, ring)
{
    vector<int> r;
    r.push_back(1);
    
    int n = 6;
    
    vector<int> s;
    for (int i=2; i<=n; i++)
        s.push_back(i);

    ringcallback = print2;
    ring(r,s);
    char expected[] = "1 4 3 2 5 6\n1 6 5 2 3 4\n";
    STRCMP_EQUAL(expected, buffer.c_str());
}
    
TEST(HDOJ1016, test1)
{
    CHECK_FALSE(prime(1));
    CHECK_TRUE(prime(2));
    CHECK_TRUE(prime(7));
    CHECK_FALSE(prime(9));
    CHECK_FALSE(prime(15));
    CHECK_TRUE(prime(23));
}
    
}//namespace HDOJ1016
