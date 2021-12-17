/*
Maximal Square

Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 4

Example 2:

Input: matrix = [["0","1"],["1","0"]]
Output: 1

Example 3:

Input: matrix = [["0"]]
Output: 0
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 300
matrix[i][j] is '0' or '1'.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = size(matrix), n = size(matrix[0]), res = 0;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(i == m - 1 || j == n - 1)
                    res = max(res, int(matrix[i][j] -= '0'));
                else{
                    matrix[i][j] = (matrix[i][j] == '1' ? 1 + min({matrix[i + 1][j], matrix[i][j + 1], matrix[i + 1][j + 1]}) : 0);
                    res = max(res, int(matrix[i][j]));
                }
            }
        }
        return res * res;
    }
};
