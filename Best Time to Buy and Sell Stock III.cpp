/*
Best Time to Buy and Sell Stock III
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
             Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n < 2) return 0;
        
        int p1 = prices[0], p2 = prices[n - 1];
        vector<int> profit1(n, 0);
        vector<int> profit2(n, 0);
        
        for(int i = 1; i < n; i++){
            profit1[i] = max(profit1[i - 1], prices[i] - p1);
            p1 = min(p1, prices[i]);
            
            int j = n - i -1;
            profit2[j] = max(profit2[j + 1], p2 - prices[j]);
            p2 = max(p2, prices [j]);
        }
        int profit = 0;
        for(int i = 0; i < n; i++){
            profit = max(profit, profit1[i] + profit2[i]);
        }
        return profit;
    }
};
