/*
Maximum Length of a Concatenated String with Unique Characters

Given an array of strings arr. String s is a concatenation of a sub-sequence of arr which have unique characters.
Return the maximum possible length of s.

Example 1:

Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.

Example 2:

Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible solutions are "chaers" and "acters".

Example 3:

Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
 
Constraints:

1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lower case English letters.
*/

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> vec;
        int res = 0;
        for(auto a : arr){
            bitset<26> bits;
            for(char c : a)
                bits.set(c - 'a');
            int n = bits.count();
            if(n != a.size())
                continue;
            for(int i = vec.size() - 1; i >= 0; i--){
                auto& b = vec[i];
                if((b & bits).any())
                    continue;
                res = max<int>(res, b.count() + n);
                vec.emplace_back(b | bits);
            }
            vec.emplace_back(bits);
            res = max<int>(res, n);
        }
        return res;
    }
};
