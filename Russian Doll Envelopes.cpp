/*
Russian Doll Envelopes

You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.
One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
Return the maximum number of envelopes can you Russian doll (i.e., put one inside the other).
Note: You cannot rotate an envelope.

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).

Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1

Constraints:

1 <= envelopes.length <= 5000
envelopes[i].length == 2
1 <= wi, hi <= 10^4
*/

// Solution I
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.empty())
            return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> dp(envelopes.size(), 1);
        for(int i = 0; i < envelopes.size(); i++)
            for(int j = 0; j < i; j++)
                if(envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1])
                    dp[i] = max(dp[i], dp[j] + 1);
        return *max_element(dp.begin(), dp.end());
    }
};

// Solution II

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), cmp);
        vector<int> list;
        for(int i = 0; i < n; i++){
            int ele = envelopes[i][1];
            int idx = lower_bound(list.begin(), list.end(), ele) - list.begin();
            if(idx >= list.size()) list.push_back(ele);
            else list[idx] = ele;
        }
        return list.size();
    }
    static bool cmp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
};
