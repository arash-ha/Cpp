/*
Count Vowel Substrings of a String

A substring is a contiguous (non-empty) sequence of characters within a string.
A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
Given a string word, return the number of vowel substrings in word.

Example 1:

Input: word = "aeiouu"
Output: 2
Explanation: The vowel substrings of word are as follows (underlined):
- "aeiouu"
- "aeiouu"

Example 2:

Input: word = "unicornarihan"
Output: 0
Explanation: Not all 5 vowels are present, so there are no vowel substrings.

Example 3:

Input: word = "cuaieuouac"
Output: 7
Explanation: The vowel substrings of word are as follows (underlined):
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
- "cuaieuouac"
 
Constraints:

1 <= word.length <= 100
word consists of lowercase English letters only.

*/

class Solution {
public:
    int countVowelSubstrings(string word) {
        int j = 0, k = 0, vow = 0, cnt = 0;
        unordered_map<char, int> m {{'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0}};
        for (int i = 0; i < word.size(); ++i) {
            if (m.count(word[i])) {
                vow += ++m[word[i]] == 1;
                for (; vow == 5; k++)
                    vow -= --m[word[k]] == 0;
                cnt += k - j;
            }
            else {
                m['a'] = m['e'] = m['i'] = m['o'] = m['u'] = vow = 0;
                j = k = i + 1;
            }
        }
        return cnt;
    }
};
