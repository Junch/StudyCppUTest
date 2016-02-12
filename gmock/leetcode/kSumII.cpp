//
//  kSumII.cpp
//  leetcode
//
//  Created by Jun Chen on 16/2/12.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace testing;

namespace KSUMII {
    
    class Solution {
    public:
        /**
         * @param A: an integer array.
         * @param k: a positive integer (k <= length(A))
         * @param target: a integer
         * @return a list of lists of integer
         */
        vector<vector<int>> m_vv;
        
        
        void dfs(vector<int>& A, int i, int k, int target, vector<int>& v){
            if (k == 0 && target == 0){
                m_vv.push_back(v);
                return;
            }
            
            if (k == 0 || target < 0){
                return;
            }
            
            for (int j=i+1; j<A.size(); ++j){
                v.push_back(A[j]);
                dfs(A, j, k-1, target-A[j], v);
                v.pop_back();
            }
        }
        
        
        
        vector<vector<int> > kSumII(vector<int> A, int k, int target) {
            std::sort(A.begin(), A.end());
            
            m_vv.clear();
            vector<int> v;
            
            for (int i=0, len=(int)A.size(); i<len; ++i){
                v.push_back(A[i]);
                dfs(A, i, k-1, target-A[i], v);
                v.pop_back();
            }
            
            return m_vv;
        }
    };
    
    
    TEST(KSUMII, sum){
        Solution* s = new Solution();
        vector<int> a{1, 2, 3, 4};
        auto vv = s->kSumII(a, 1, 3);
        vector<int> v{3};
        ASSERT_EQ(v, vv[0]);
    }
    
    TEST(KSUMII, sum2){
        Solution* s = new Solution();
        vector<int> a{1, 2, 3, 4};
        auto vv = s->kSumII(a, 2, 5);
        vector<int> v{1, 4};
        ASSERT_EQ(v, vv[0]);
    }
}