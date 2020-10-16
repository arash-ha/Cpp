/*
Spiral Matrix II
Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        if(n <= 0) return result;
        int up = 0, down = n - 1;
        int left = 0, right = n - 1;
        int num = 1;
        while(num <= n * n){
            for(int i = left; i <= right && num <= n * n; i++){
                result[up][i] = num++;
            }
            for(int i = up + 1; i <= down - 1 && num <= n * n; i++){
                result[i][right] = num++;
            }
            for(int i = right; i >= left && num <= n * n; i--){
                result[down][i] = num++;
            }
            for(int i = down - 1; i >= up + 1 && num <= n * n; i--){
                result[i][left] = num++;
            }
            left++; right--; up++; down--;
        }

        return result;
    }
};
