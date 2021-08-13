/*
Set Matrix Zeroes

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's, and return the matrix.
You must do it in place.
 
Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2^31 <= matrix[i][j] <= 2^31 - 1

Follow up:

A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

// Solution 1
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowHasZero = false;
        bool colHasZero = false;
        
        for (int j = 0; j < matrix[0].size(); j++){
            if(matrix[0][j] == 0){
                rowHasZero = true;
                break;
            }
        }
        
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == 0){
                colHasZero = true;
                break;
            }
        }
        
        for(int i = 1; i < matrix.size(); i++){
            for (int j = 1 ; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (colHasZero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }

        if (rowHasZero) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }
    }
};

//Solution 2

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col0 = false;
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0)
                col0 = true;
            for(int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;
        }

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 1; j--)
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            if(col0) matrix[i][0] = 0;
        }
    }
};
