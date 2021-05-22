/*
N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:

Input: n = 1
Output: [["Q"]]

Constraints:

1 <= n <= 9
*/

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> vec;
        vector<string> board(n,string(n,'.'));
        helper(vec, board, 0, n);
        return vec;
    }
    void helper(vector<vector<string>> &vec, vector<string> & board, int row, int &n){        
        if(row == n){
            vec.emplace_back(board);
            return;
        }
        for(int col = 0; col < n; col++)
            if(isValid(board,row,col,n)){
                board[row][col] = 'Q';
                helper(vec, board, row + 1, n); 
                board[row][col] = '.';
            }
    }
    bool isValid(vector<string> &board,int row,int col,int n){    
        for(int i = 0; i < row; i++)
            if(board[i][col] == 'Q')
                return false;
        for(int i = 1; row - i >= 0 && col - i >= 0; i++)
            if(board[row - i][col - i] == 'Q')
                return false;
        for(int i = 1; row - i >= 0&& col + i < n; i++)
            if(board[row - i][col + i] == 'Q')
                return false;
        return true;
    }
};
