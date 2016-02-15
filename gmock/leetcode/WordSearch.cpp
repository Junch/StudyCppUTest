//
//  WordSearch.cpp
//  leetcode
//
//  Created by Jun on 16/2/15.
//
//

#include <gmock/gmock.h>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;
using namespace testing;

namespace WordSearch {
    class Solution {
    public:
        /**
         * @param board: A list of lists of character
         * @param word: A string
         * @return: A boolean
         */
        bool findPath(vector<vector<char> > &board, int x, int y, string word) {
            int dirs[4][2] = {
                {1, 0},
                {0, -1},
                {-1, 0},
                {0, 1}
            };
            
            int h = (int)board.size();
            int w = (int)board[0].size();
            
            struct Node {
                int  x;
                int  y;
                int  dir;
                char v;
                Node (int _x, int _y, char _v)
                :x(_x), y(_y), v(_v), dir(-1)
                {
                }
            };
            
            stack<Node> st;
            st.push(Node(x, y, board[y][x]));
            board[y][x] = '\0';
            while (!st.empty()){
                int k = (int)st.size();
                if (k == word.length()){
                    return true;
                }
                
                auto& node = st.top();
                ++node.dir;
                if (node.dir == 4){
                    board[node.y][node.x] = node.v;
                    st.pop();
                }
                
                int x = node.x + dirs[node.dir][0];
                int y = node.y + dirs[node.dir][1];
                
                if (x<0 || y<0 || x>=w || y>=h ||
                    board[y][x] == '\0' ||
                    board[y][x] != word[k]) {

                }else{
                    st.push(Node(x, y, board[y][x]));
                    board[y][x] = '\0';
                }
            }
            
            return false;
        }
        
        bool exist(vector<vector<char> > &board, string word) {
            int h = (int)board.size();
            int w = (int)board[0].size();
            
            for(int i=0; i<h; ++i){
                for(int j=0; j<w; ++j){
                    if (board[i][j] == word[0]){
                        if(findPath(board, j, i, word))
                            return true;
                    }
                }
            }
            
            return false;
        }
    };
    
    TEST(WordSearch, demo1) {
        vector<vector<char>> board = {
            vector<char>{'A','B','C', 'E'},
            vector<char>{'S','F','C', 'S'},
            vector<char>{'A','D','E', 'E'}
        };
        
        Solution* s = new Solution();
        EXPECT_TRUE(s->exist(board, string("SEE")));
    }
    
    TEST(WordSearch, demo2) {
        vector<vector<char>> board = {
            vector<char>{'A','B','C', 'E'},
            vector<char>{'S','F','C', 'S'},
            vector<char>{'A','D','E', 'E'}
        };
        
        Solution* s = new Solution();
        EXPECT_TRUE(s->exist(board, string("ABCCED")));
    }
    
    TEST(WordSearch, demo3) {
        vector<vector<char>> board = {
            vector<char>{'A','B','C', 'E'},
            vector<char>{'S','F','C', 'S'},
            vector<char>{'A','D','E', 'E'}
        };
        
        Solution* s = new Solution();
        EXPECT_FALSE(s->exist(board, string("ABCB")));
    }
    
}


