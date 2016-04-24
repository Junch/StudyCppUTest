//
//  SortLettersbyCase.cpp
//  leetcode
//
//  Created by Jun Chen on 16/2/13.
//
//

#include <gmock/gmock.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace testing;

namespace SortLettersbyCase {

    class Solution {
    public:
        /**
         * @param chars: The letters array you should sort.
         */
        void sortLetters(string &letters) {
            int l=0;
            int r=(int)letters.length()-1;
            
            while(l<r){
                while (letters[l]>='a' && letters[l]<='z' && l<r) ++l;
                while (letters[r]>='A' && letters[r]<='Z' && l<r) --r;
                
                char tmp = letters[l];
                letters[l] = letters[r];
                letters[r] = tmp;
                
                ++l;
                --r;
            }
        }
    };

    
    TEST(SortLettersbyCase, demo) {
        Solution* s = new Solution();
        string sz = "abAcD";
        s->sortLetters(sz);
        ASSERT_EQ("abcAD", sz);
    }
}
