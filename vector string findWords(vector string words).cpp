/*
Keyboard Row
Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
Example:

Input: ["Hello", "Alaska", "Dad", "Peace"]
Output: ["Alaska", "Dad"]
 

Note:

You may use one character in the keyboard more than once.
You may assume the input string will only contain letters of alphabet.
*/


class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for(auto str : words){
            bool r1 = str.find_first_of("QWERTYUIOPqwertyuiop") == string::npos ? false : true;
            bool r2 = str.find_first_of("ASDFGHJKLasdfghjkl") == string::npos ? false : true;
            bool r3 = str.find_first_of("ZXCVBNMzxcvbnm") == string::npos ? false : true;
            
            if (r1 + r2 + r3 == 1) result.emplace_back(str);
        }
        return result;
    }
};
