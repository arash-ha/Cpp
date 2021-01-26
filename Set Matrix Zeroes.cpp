/*
Set Matrix Zeroes

Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]

Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
*/


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
