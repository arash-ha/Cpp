/*
Reverse String
Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

 

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

// Solution I
class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> vec{};
        for(int i = s.size() - 1; i >= 0; i--){
            vec.push_back(s[i]);
        }
        s = vec;
    }
};

// Solution II
class Solution {
public:
    void reverseString(vector<char>& s) {
        int low = 0, high = s.size() - 1;
        while(low <= high){
            swap(s[low], s[high]);
            low++;
            high--;
        }
    }
};
