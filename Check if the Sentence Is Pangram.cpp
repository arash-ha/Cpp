/*
Check if the Sentence Is Pangram

A pangram is a sentence where every letter of the English alphabet appears at least once.
Given a string sentence containing only lowercase English letters, return true if sentence is a pangram, or false otherwise.

Example 1:

Input: sentence = "thequickbrownfoxjumpsoverthelazydog"
Output: true
Explanation: sentence contains at least one of every letter of the English alphabet.

Example 2:

Input: sentence = "leetcode"
Output: false
 
Constraints:

1 <= sentence.length <= 1000
sentence consists of lowercase English letters.
*/

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> vec(26, 0);
        for(auto s : sentence)
            vec[s - 'a']++;
        for(auto v : vec)
            if(v == 0)
                return false;
        return true;
    }
};
