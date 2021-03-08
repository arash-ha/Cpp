/*
Ugly Number II

Write a program to find the n-th ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 0, p3 = 0, p5 = 0;
        vector<int> dp{1};
        for(int i = 1; i < n; i++){
            int p2val = dp[p2] * 2;
            int p3val = dp[p3] * 3;
            int p5val = dp[p5] * 5;
            int cur = min(p2val, min(p3val, p5val));
            if(cur == p2val)
                p2++;
            if(cur == p3val)
                p3++;
            if(cur == p5val)
                p5++;
            dp.emplace_back(cur);
        }
        return dp[n - 1];
    }
};
