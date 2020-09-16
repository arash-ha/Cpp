/*
Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0) return result;
        int n = matrix.size();
        int m = matrix[0].size();
        int up = 0, down = n - 1;
        int left = 0, right = m - 1;
        while(result.size() < n * m){
            for(int i = left; i <= right && result.size() < n * m; i++){
                result.emplace_back(matrix[up][i]);
            }
            for(int i = up + 1; i <= down - 1 && result.size() < n * m; i++){
                result.emplace_back(matrix[i][right]);
            }
            for(int i = right; i >= left && result.size() < n * m; i--){
                result.emplace_back(matrix[down][i]);
            }
            for(int i = down - 1; i >= up + 1 && result.size() < n * m; i--){
                result.emplace_back(matrix[i][left]);
            }
            left++; right--; up++; down--;
        }

        return result;
    }
};
