/*
Word Pattern
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Example 1:

Input: pattern = "abba", str = "dog cat cat dog"
Output: true
Example 2:

Input:pattern = "abba", str = "dog cat cat fish"
Output: false
Example 3:

Input: pattern = "aaaa", str = "dog cat cat dog"
Output: false
Example 4:

Input: pattern = "abba", str = "dog dog dog dog"
Output: false
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters that may be separated by a single space.
*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> char_map;
        unordered_map<string, char> word_map;
        stringstream s(str);
        string word;
        int n = pattern.size(), i = 0;
        while(s >> word){
            if(i > n - 1) return false;
            char c = pattern[i];
            if(char_map.count(c) != word_map.count(word)) return false;
            if(char_map.count(c)){
                if((word_map[word] != c) || (char_map[c] != word)) return false;
            }else{
                char_map.insert({c, word});
                word_map.insert({word, c});
            }
            i++;
        }
        return i == n;
    }
};
