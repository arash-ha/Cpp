/*
First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++) map[s[i]]++;
        for(int j = 0; j < s.length(); j++)  {
            if(map[s[j]] == 1){
                return j;
                break;
            }
        }
        return -1;
    }
};
