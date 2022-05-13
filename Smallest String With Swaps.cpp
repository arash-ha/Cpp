/*
Smallest String With Swaps

You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] indicates 2 indices(0-indexed) of the string.
You can swap the characters at any pair of indices in the given pairs any number of times.
Return the lexicographically smallest string that s can be changed to after using the swaps.

Example 1:

Input: s = "dcab", pairs = [[0,3],[1,2]]
Output: "bacd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[1] and s[2], s = "bacd"

Example 2:

Input: s = "dcab", pairs = [[0,3],[1,2],[0,2]]
Output: "abcd"
Explaination: 
Swap s[0] and s[3], s = "bcad"
Swap s[0] and s[2], s = "acbd"
Swap s[1] and s[2], s = "abcd"

Example 3:

Input: s = "cba", pairs = [[0,1],[1,2]]
Output: "abc"
Explaination: 
Swap s[0] and s[1], s = "bca"
Swap s[1] and s[2], s = "bac"
Swap s[0] and s[1], s = "abc"
 
Constraints:

1 <= s.length <= 10^5
0 <= pairs.length <= 10^5
0 <= pairs[i][0], pairs[i][1] < s.length
s only contains lower case English letters.
*/

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        vector<int> ds(s.size(), -1);
        vector<vector<int>> m(s.size());
        for(auto& p : pairs){
            auto i = find(ds, p[0]), j = find(ds, p[1]);
            if(i != j)
                ds[j] = i;
        }
        for(auto i = 0; i < s.size(); i++)
            m[find(ds, i)].emplace_back(i);
        for(auto &ids : m){
            string ss = "";
            for(auto i : ids)
                ss += s[i];
            sort(begin(ss), end(ss));
            for(auto i = 0; i < ids.size(); i++)
                s[ids[i]] = ss[i];
        }
        return s;
    }
    int find(vector<int>& ds, int i){
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
};
