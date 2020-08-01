/*
Transpose Matrix
Given a matrix A, return the transpose of A.

The transpose of a matrix is the matrix flipped over it's main diagonal, switching the row and column indices of the matrix.

Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]
Output: [[1,4,7],[2,5,8],[3,6,9]]
Example 2:

Input: [[1,2,3],[4,5,6]]
Output: [[1,4],[2,5],[3,6]]
*/

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int C = A.size();
        int R = A[0].size();
        vector<vector<int>> result(R,vector<int>(C,0));
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                result[i][j] = A[j][i];
            }
        }
        return result;
    }
};
