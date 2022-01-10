/*
Surrounded Regions

Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Surrounded regions should not be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.

Example 2:

Input: board = [["X"]]
Output: [["X"]]
 
Constraints:

m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] is 'X' or 'O'.
*/

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        unsigned m = board.size();
        unsigned n = board[0].size();
        if(m <= 2 || n <= 2)
          return;

    static const function<void(int,int)> markBorder = [&](int i, int j){
        if(i >= 0 && i < m && j >= 0 && j < n && board[i][j] == 'O'){
            board[i][j] = 'B';
            markBorder(i + 1, j);
            markBorder(i - 1, j);
            markBorder(i, j + 1);
            markBorder(i, j - 1);
          }
        };

        for(unsigned i = 0; i < m; i++){
            markBorder(i, 0);
            markBorder(i, n - 1);
        }

        for(unsigned j = 0; j < n; j++){
            markBorder(0, j);
            markBorder(m - 1, j);
        }

        for(unsigned i = 0; i < m; i++){
          for(unsigned j = 0; j < n; j++){
              char c = board[i][j];
              if (c != 'X')
              board[i][j] = c == 'O' ? 'X' : 'O';
          }
        }
    }
};
