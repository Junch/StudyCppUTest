//
//  topK.cpp
//  Find the k-th Smallest Element in an array
//  http://www.cnblogs.com/wuchanming/p/4462192.html
//
//  Created by Jun Chen on 16/2/11.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <queue>
#include <set>
using namespace std;
using namespace testing;

namespace TopK {
    
class Solution {
public:
    vector<int> topK(vector<int>& a, int k) {
        vector<int> arr;
        if (k > a.size()) {
            return arr;
        }
        
        priority_queue<int> q;
        
        for (int i: a) {
            if (q.size() < k) {
                q.push(i);
                continue;
            }
            
            if(i < q.top()){
                q.pop();
                q.push(i);
            }
        }
        
        while(!q.empty()){
            arr.push_back(q.top());
            q.pop();
        }
        
        std::reverse(arr.begin(), arr.end());
        return arr;
    }
    
    
    vector<int> topK2(vector<int>& a, int k) {
        vector<int> arr;
        if (k > a.size()) {
            return arr;
        }
        
        set<int, greater<int>> st; // default, the compare is std::less<int>
        for (int i: a) {
            if (st.size() < k) {
                st.insert(i);
                continue;
            }
            
            auto iter = st.begin();
            if (i < *iter) {
                st.erase(iter);
                st.insert(i);
            }
        }
        
        for (int e: st) {
            arr.push_back(e);
        }
        std::reverse(arr.begin(), arr.end());
        
        return arr;
    }
};
    
TEST(TopK, smallest) {
    vector<int> a{6, 5, 3, 7, 9, 11, 2};
    Solution* s = new Solution();
    vector<int> arr{2, 3, 5};
    ASSERT_EQ(arr, s->topK(a, 3));
    ASSERT_EQ(arr, s->topK2(a, 3));
}
    
}
