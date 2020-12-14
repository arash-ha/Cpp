/*
Burst Balloons

SolutionGiven n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 = n = 500, 0 = nums[i] = 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167           
*/

//Solution 1

class Solution {
    unordered_map<string, int> umap;
    int getCoin(const vector<int> nums, int l, int r){
        string key = to_string(l) + "|" + to_string(r);
        if(!umap.count(key)){
            int maxCoin = 0;
            for(int i = l + 1; i < r; i++){
                int score = nums[l] * nums[i] * nums[r];
                maxCoin = max(maxCoin, score + getCoin(nums, l, i) + getCoin(nums, i, r));
            }
            umap[key] = maxCoin;
        }
        return umap[key];
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        return getCoin(nums, 0, nums.size()-1);
    }
};

//Solution 2

class Solution {

    int getCoin(const vector<int> nums, vector<vector<int>>& memo, int l, int r){
        if(l + 1 == r)
            return 0;
        if(memo[l][r] == -1){
            int maxCoin = 0;
            for(int i = l + 1; i < r; i++){
                int score = nums[l] * nums[i] * nums[r];
                maxCoin = max(maxCoin, score + getCoin(nums, memo, l, i) + getCoin(nums, memo, i, r));
            }
            memo[l][r] = maxCoin;
        }
        return memo[l][r];
    }
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> memo(nums.size(), vector<int> (nums.size(), -1));
        return getCoin(nums, memo, 0, nums.size()-1);
    }
};


//Solution 3

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        
        vector<int> b(n+2);
        b[0] = b[n+1] = 1;
        for(int i = 1; i <= n; i++)
            b[i] = nums[i-1];
        
        int dp[b.size()][b.size()];
        memset(dp, 0, sizeof(dp));
        
        for(int gap = 2; gap < b.size(); gap++){
            for(int l = 0; l <= b.size() - gap - 1; l++){
                int r = l + gap;
                for(int i = l + 1; i < r; i++){
                    dp[l][r] = max(dp[l][r], dp[l][i] + dp[i][r] + (b[l] * b[i] * b[r]));
                }
            }
        }
        return dp[0][b.size()-1];
    }
};
