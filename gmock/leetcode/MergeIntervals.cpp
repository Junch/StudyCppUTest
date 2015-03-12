//
//  https://oj.leetcode.com/problems/merge-intervals/
//  leetcode
//
//  Created by Jun on 15/2/24.
//
//

#include <gmock/gmock.h>
#include <vector>
using namespace std;
using namespace testing;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

namespace MergeIntervals {

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> v;
        
        struct Node {
            int flag;
            int value;
            
            bool operator < (const Node& node) const{
                if (value < node.value) {
                    return true;
                }else if(value > node.value){
                    return false;
                }
                
                return flag > node.flag;
            }
        };
        
        vector<Node> nodes;
        for (auto& item: intervals) {
            nodes.push_back(Node{1, item.start});
            nodes.push_back(Node{-1, item.end});
        }
        std::sort(nodes.begin(), nodes.end());
        
        int start=0;
        int counts=1;
        int i=1;
        while (i < nodes.size()) {
            if (nodes[i].flag == 1) {
                ++counts;
                if (counts == 1) {
                    start = i;
                }
                
                ++i;
            }else{
                int sum = 0;
                int j = i;
                while(j < nodes.size() && nodes[i].value == nodes[j].value){
                    sum += nodes[j].flag;
                    ++j;
                }
               
                counts += sum;
                if (counts == 0) {
                    v.push_back(Interval{nodes[start].value, nodes[i].value});
                }
                
                i = j;
            }
        }
        
        return v;
    }
};
    
TEST(MergeIntervals,case1){
    vector<Interval> v = {
        Interval(1, 3),
        Interval(2, 6),
    };
    
    Solution* sln = new Solution();
    auto r = sln->merge(v);
    ASSERT_EQ(1, r.size());
    
    ASSERT_EQ(1, r[0].start);
    ASSERT_EQ(6, r[0].end);
}


TEST(MergeIntervals,case2){
    vector<Interval> v = {
        Interval(1, 3),
        Interval(3, 6),
    };
    
    Solution* sln = new Solution();
    auto r = sln->merge(v);
    ASSERT_EQ(1, r.size());
    
    ASSERT_EQ(1, r[0].start);
    ASSERT_EQ(6, r[0].end);
}
    
TEST(MergeIntervals,case3){
    vector<Interval> v = {
        Interval(1, 6),
        Interval(3, 6),
    };
    
    Solution* sln = new Solution();
    auto r = sln->merge(v);
    ASSERT_EQ(1, r.size());
    
    ASSERT_EQ(1, r[0].start);
    ASSERT_EQ(6, r[0].end);
}
    
}


