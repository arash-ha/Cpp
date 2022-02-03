/*
Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:

Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:

Input: matrix = []
Output: 0

Example 3:

Input: matrix = [["0"]]
Output: 0

Example 4:

Input: matrix = [["1"]]
Output: 1

Example 5:

Input: matrix = [["0","0"]]
Output: 0
 
Constraints:

rows == matrix.length
cols == matrix[i].length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()|| matrix[0].empty())
            return 0;
        int rows = matrix.size(), cols = matrix[0].size(), maxArea = 0;
        vector<int> h(cols + 1);
        for(int i = 0; i < rows; i++){
            stack<int> lowi;
            for(int j = 0; j <= cols; j++){
                h[j] = ((j != cols && matrix[i][j] == '1') ? h[j] + 1 : 0);
                while(!lowi.empty() && (h[j] < h[lowi.top()])){
                    int height = h[lowi.top()];
                    lowi.pop();
                    int lefti = (lowi.empty() ? -1 : lowi.top());
                    maxArea = max((j - lefti - 1) * height, maxArea);
                }
                lowi.push(j);
            }
        }
        return maxArea;     
    }
};
