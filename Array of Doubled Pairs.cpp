/*
Array of Doubled Pairs

Given an array of integers arr of even length, return true if and only if it is possible to reorder it such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2. 

Example 1:

Input: arr = [3,1,3,6]
Output: false

Example 2:

Input: arr = [2,1,2,6]
Output: false

Example 3:

Input: arr = [4,-2,2,-4]
Output: true
Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].

Example 4:

Input: arr = [1,2,4,16,8,4]
Output: false
 
Constraints:

0 <= arr.length <= 3 * 10^4
arr.length is even.
-10^5 <= arr[i] <= 10^5
*/

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> ump;
        sort(arr.begin(), arr.end());
        for(int a : arr)
            ump[a]++;
        for(int a : arr){
            if(ump[a] && ump[2 * a]){
                ump[a]--;
                ump[2 * a]--;
            }
        }
        for(auto [a, b] : ump)
            if(b)
                return false;
        return true;
    }
};
