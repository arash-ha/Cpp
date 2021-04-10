/*
Longest Increasing Path in a Matrix

Given an m x n integers matrix, return the length of the longest increasing path in matrix.
From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed). 

Example 1:

Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].

Example 2:

Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

Example 3:

Input: matrix = [[1]]
Output: 1

Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 2^31 - 1
*/


class Solution {
public:
    int rows;
    int cols;
    vector<vector<int>> f;

    int DFS(vector<vector<int>>& M, int r, int c) {
        if (f[r][c] > 0)
            return f[r][c]; 
        int res = 1;
        if (r+1 < rows && M[r+1][c] > M[r][c]) res = max(res, 1 + DFS(M, r+1, c));
        if (r-1 >= 0   && M[r-1][c] > M[r][c]) res = max(res, 1 + DFS(M, r-1, c));
        if (c+1 < cols && M[r][c+1] > M[r][c]) res = max(res, 1 + DFS(M, r, c+1));
        if (c-1 >= 0   && M[r][c-1] > M[r][c]) res = max(res, 1 + DFS(M, r, c-1));
        f[r][c] = res;
        return f[r][c];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty())
            return 0;
        rows = matrix.size();
        cols = matrix[0].size();
        f = vector<vector<int>>(rows, vector<int>(cols, 0));

        int res = 0;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                res = max(res, DFS(matrix, r, c));
            }
        }
        return res;
    }
};
