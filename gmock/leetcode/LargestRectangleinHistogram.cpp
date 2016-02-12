//
//  LargestRectangleinHistogram.cpp
//  https://leetcode.com/problems/largest-rectangle-in-histogram/
//
//  Created by Jun on 15/3/13.
//
//

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

namespace LargestRectangleinHistogram {
    class Solution {
    public:
//        int largestRectangleArea(vector<int> &height) {
//            if (height.empty()) {
//                return 0;
//            }
//            
//            vector<int> a(height.size());
//            for (int i=0; i<height.size(); ++i) {
//                // Get the value for the current i
//                a[i] = height[i];
//                
//                int j=i-1;
//                while (j >= 0 && height[j] >= height[i]) {
//                    a[i] += height[i];
//                    --j;
//                }
//                
//                // Update the value for the other short than height[i]
//                int min = height[i];
//                for (int j=i-1; j>=0; --j) {
//                    if (height[j] <= min) {
//                        a[j] += height[j];
//                        min = height[j];
//                    }
//                }
//            }
//            
//            int ret = *std::max_element(a.begin(), a.end());
//            return ret;
//        }
        
        
        // http://blog.csdn.net/kenden23/article/details/17487665
        int largestRectangleArea(vector<int> &h)
        {
            stack<int> stk;
            h.push_back(INT_MIN);
            int max_area = 0;
            for (int i = 0; i < h.size(); )
            {
                if (stk.empty() || h[i] >=h[stk.top()]) stk.push(i++);
                else
                {
                    int height = stk.top();
                    stk.pop();
                    int width = stk.empty()? i : i - stk.top() - 1;
                    max_area = max(max_area, width * h[height]);
                }
            }
            return max_area;
        }
        
    };
    
    TEST(LargestRectangleinHistogram, case1){
        vector<int> height = {2, 3};
        Solution* sln = new Solution();
        int val = sln->largestRectangleArea(height);
        ASSERT_EQ(4, val);
    }
    
    TEST(LargestRectangleinHistogram, case2){
        vector<int> height = {2, 1, 5, 6, 2, 3};
        Solution* sln = new Solution();
        int val = sln->largestRectangleArea(height);
        ASSERT_EQ(10, val);
    }
    
    TEST(LargestRectangleinHistogram, case3){
        vector<int> height = {2};
        Solution* sln = new Solution();
        int val = sln->largestRectangleArea(height);
        ASSERT_EQ(2, val);
    }
    
    TEST(LargestRectangleinHistogram, case4){
        vector<int> height;
        Solution* sln = new Solution();
        int val = sln->largestRectangleArea(height);
        ASSERT_EQ(0, val);
    }
    
//    TEST(LargestRectangleinHistogram, TLE) {
//        ADD_FAILURE() << "Time Limit Exceeded";
//    }
}


