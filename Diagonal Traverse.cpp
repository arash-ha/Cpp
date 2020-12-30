/*
Diagonal Traverse

Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

Note:

The total number of elements of the given matrix will not exceed 10,000.
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix.empty())
            return {};
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, column = 0;
        int dir = 1, i = 0;
        vector<int> res(n*m);
        while(row < n && column < m){
            res[i++] = matrix[row][column];
            int new_row = row + (dir == 1 ? -1 : 1);
            int new_column = column + (dir == 1 ? 1 : -1);
            if(new_row < 0 || new_row == n || new_column < 0 || new_column == m){
                if(dir == 1){
                    row += (column == m - 1 ? 1 : 0);
                    column += (column < m - 1 ? 1 : 0);
                }
                else{
                    column += (row == n - 1 ? 1 : 0);
                    row += (row < n - 1 ? 1 : 0);
                }
                dir = 1 - dir;
            }
            else{
                row = new_row;
                column = new_column;
            }
        }
        return res;
    }
};
