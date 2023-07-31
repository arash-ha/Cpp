/*
Make Array Strictly Increasing

Given two integer arrays arr1 and arr2, return the minimum number of operations (possibly zero) needed to make arr1 strictly increasing.
In one operation, you can choose two indices 0 <= i < arr1.length and 0 <= j < arr2.length and do the assignment arr1[i] = arr2[j].
If there is no way to make arr1 strictly increasing, return -1. 

Example 1:

Input: arr1 = [1,5,3,6,7], arr2 = [1,3,2,4]
Output: 1
Explanation: Replace 5 with 2, then arr1 = [1, 2, 3, 6, 7].

Example 2:

Input: arr1 = [1,5,3,6,7], arr2 = [4,3,1]
Output: 2
Explanation: Replace 5 with 3 and then replace 3 with 4. arr1 = [1, 3, 4, 6, 7].

Example 3:

Input: arr1 = [1,5,3,6,7], arr2 = [1,6,3,3]
Output: -1
Explanation: You can't make arr1 strictly increasing.
 
Constraints:

1 <= arr1.length, arr2.length <= 2000
0 <= arr1[i], arr2[i] <= 10^9
*/
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<vector<int>> dp(arr1.size(), vector<int>(arr2.size() + 1, -1));
        int res = helper(0, -1, arr1, arr2, dp);
        return res == 1e9 ? -1 : res;
    }
    int helper(int i, int prev, vector<int> &arr1, vector<int> &arr2, vector<vector<int>> &dp){    
        if (i == arr1.size())
            return 0;
        int ind = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if (dp[i][ind] != -1)
            return dp[i][ind];
        if (ind == arr2.size() && arr1[i] <= prev)
            return dp[i][ind] = 1e9;
        int pick = 1e9, npick = 1e9;
        if (ind != arr2.size())
            pick = 1 + helper(i + 1, arr2[ind], arr1, arr2, dp);
        if (arr1[i] > prev)
            npick = helper(i + 1, arr1[i], arr1, arr2, dp);   
        return dp[i][ind] = min(pick, npick);
    }
};
