/*
Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,50]], target = 13
Output: false
Example 3:

Input: matrix = [], target = 0
Output: false
 

Constraints:

m == matrix.length
n == matrix[i].length
0 <= m, n <= 100
-104 <= matrix[i][j], target <= 104
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        int m = matrix.size(), n = matrix[0].size();
        if(target < matrix[0][0] || target > matrix[m-1][n-1]) return false;
        
        int up = 0, bottom = m-1;
        while(up <= bottom){
            int mid = (up + bottom + 1)/2;
            if(matrix[mid][0] > target) bottom = mid - 1;
            else if(matrix[mid][0] < target) up = mid + 1;
            else return true;
        }
        
        int row = bottom;
        int left = 0, right = n-1;
        while(left <= right){
            int mid = (left + right)/2;
            if(matrix[row][mid] > target) right = mid - 1;
            else if(matrix[row][mid] < target) left = mid + 1;
            else return true;
        }
        return false;
    }
};
