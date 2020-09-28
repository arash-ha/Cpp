/*
Word Search
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.
 

Constraints:

board and word consists only of lowercase and uppercase English letters.
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3
*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int m = 0; m < board.size(); m++){
            for(int n = 0; n < board[0].size(); n++){
                if(checkValid(board, word, m, n)) return true;
            }
        }
        return false;
    }
    
    bool checkValid(vector<vector<char>>& board, string& word, int m, int n){
        if(word.size() == 0) return true;
        if(m < 0 || m >= board.size() || n < 0 || n >= board[0].size() || board[m][n] != word[0]) return false;
        char c = board[m][n];
        board[m][n] = '*';
        string s = word.substr(1);
        bool v = checkValid(board, s, m - 1, n) || checkValid(board, s, m + 1, n) || checkValid(board, s, m, n - 1) || checkValid(board, s, m, n + 1);
        board[m][n] = c;
        return v;
    }
};
