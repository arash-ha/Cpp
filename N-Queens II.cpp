/*
N-Queens II

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:

Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:

Input: n = 1
Output: 1
 
Constraints:

1 <= n <= 9
*/

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        dfs(n, 0, 0, 0, 0, res);
        return res;
    }
    void dfs(int n, int dep, int r, int d1, int d2, int& res){
		if(dep == n){
			res++;
			return;
		}
		for(int i = 0; i < n; i++){
			int cur = 1 << i;
			if((cur & r) || (cur & d1) || (cur & d2))
                continue;
			dfs(n, dep + 1, (cur | r), (cur | d1) << 1, (cur | d2) >> 1, res);
        }
	}
};
