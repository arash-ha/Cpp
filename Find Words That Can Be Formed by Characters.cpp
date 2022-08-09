/*
Find Words That Can Be Formed by Characters

You are given an array of strings words and a string chars.
A string is good if it can be formed by characters from chars (each character can only be used once).
Return the sum of lengths of all good strings in words.

Example 1:

Input: words = ["cat","bt","hat","tree"], chars = "atach"
Output: 6
Explanation: The strings that can be formed are "cat" and "hat" so the answer is 3 + 3 = 6.

Example 2:

Input: words = ["hello","world","leetcode"], chars = "welldonehoneyr"
Output: 10
Explanation: The strings that can be formed are "hello" and "world" so the answer is 5 + 5 = 10.
 
Constraints:

1 <= words.length <= 1000
1 <= words[i].length, chars.length <= 100
words[i] and chars consist of lowercase English letters.
*/

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {}, res = 0;
        for(auto c : chars)
            cnt[c - 'a']++;
        for(auto &w : words){
            int cnt1[26] = {}, match = true;
            for(auto c : w)
                if(++cnt1[c - 'a'] > cnt[c - 'a']){
                    match = false;
                    break;
                }
            if(match)
                res += w.size();
        }
        return res;
    }
};
