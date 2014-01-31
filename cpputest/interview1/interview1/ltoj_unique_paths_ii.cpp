//
//  ltoj_unique_paths_ii.cpp
//  interview1
//
//  Created by Jun on 14-1-29.
//  Copyright (c) 2014年 com.wolf76. All rights reserved.
//

#include <iostream>
#include <vector>
#include <CppUTest/TestHarness.h>
using namespace std;

namespace LTOJ_UNIQUE_PATHS_II {
    class Solution {
    public:
        int uniquePaths(int m, int n) {
            // m rows, n columns
            vector<int> v(m);
            
            for (int i=0; i<m; ++i)
                v[i] = 1;
            
            for (int j=1; j<n; ++j) {
                for (int i=1; i<m; ++i) {
                    v[i] += v[i-1];
                }
            }
            
            return v[m-1];
        }
        
        int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
            size_t m = obstacleGrid.size();
            size_t n = obstacleGrid[0].size();
            
            if (obstacleGrid[0][0] == 1)
                return 0;
 
            size_t j = 0;
            for ( ; j < n && obstacleGrid[0][j] == 0; ++j)
                obstacleGrid[0][j] = 1;
            
            for (size_t k=j; k<n; ++k)
                obstacleGrid[0][k] = 0;
            
            size_t i = 1;
            for ( ; i < m && obstacleGrid[i][0] == 0; ++i)
                obstacleGrid[i][0] = 1;
            
            for (size_t k=i; k<m; ++k)
                obstacleGrid[k][0] = 0;

            for (size_t i=1; i<m; ++i) {
                for (size_t j=1; j<obstacleGrid[i].size(); ++j) {
                    if (obstacleGrid[i][j])
                        obstacleGrid[i][j] = 0;
                    else
                        obstacleGrid[i][j] = obstacleGrid[i][j-1] + obstacleGrid[i-1][j];
                }
            }
            
            return obstacleGrid[m-1][n-1];
        }
        
    };
    
    TEST_GROUP(LTOJ_UNIQUE_PATHS_II){
        Solution sln;
    };
    
    TEST(LTOJ_UNIQUE_PATHS_II, 2x2NoObstancles){
        vector<int> v1{0, 0};
        vector<int> v2{0, 0};
        vector<vector<int>> vv;
        vv.push_back(v1);
        vv.push_back(v2);
        LONGS_EQUAL(2, sln.uniquePathsWithObstacles(vv));
    }
    
    TEST(LTOJ_UNIQUE_PATHS_II, 2x2Obstancles){
        vector<int> v1{0, 1};
        vector<int> v2{0, 0};
        vector<vector<int>> vv;
        vv.push_back(v1);
        vv.push_back(v2);
        LONGS_EQUAL(1, sln.uniquePathsWithObstacles(vv));
    }
    
    TEST(LTOJ_UNIQUE_PATHS_II, NoPath){
        vector<int> v1{1, 0};
        vector<int> v2{0, 0};
        vector<vector<int>> vv;
        vv.push_back(v1);
        vv.push_back(v2);
        LONGS_EQUAL(0, sln.uniquePathsWithObstacles(vv));
    }
}
