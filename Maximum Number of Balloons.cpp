/*
Maximum Number of Balloons

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
You can use each character in text at most once. Return the maximum number of instances that can be formed.

Example 1:

Input: text = "nlaebolko"
Output: 1

Example 2:

Input: text = "loonbalxballpoon"
Output: 2

Example 3:

Input: text = "leetcode"
Output: 0
 
Constraints:

1 <= text.length <= 10^4
text consists of lower case English letters only.
*/


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};
        for(auto& t : text)
            freq[t - 'a']++;
        return min({freq[0], freq[1], freq[11] / 2, freq[13], freq[14] / 2});
    }
};
