/*
Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.

 

Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]
 

Constraints:

1 <= n <= 20
1 <= k <= n
*/


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> partial;
        vector<vector<int>> result;
        combination(result, partial, n, 1, k);
        return result;
    }
    
    void combination(vector<vector<int>>& result, vector<int>& partial, int n, int start, int k){
        if(partial.size() == k){
            result.emplace_back(partial);
            return;
        }
        for(int i = start; i <= n; i++){
            partial.emplace_back(i);
            combination(result, partial, n, i + 1, k);
            partial.pop_back();
        }
    }
    
};
