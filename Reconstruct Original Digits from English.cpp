/*
Reconstruct Original Digits from English

Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.

Note:
Input contains only lowercase English letters.
Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
Input length is less than 50,000.

Example 1:
Input: "owoztneoer"

Output: "012"

Example 2:
Input: "fviefuro"

Output: "45"
*/

class Solution {
public:
    string originalDigits(string s) {
        int n = s.length();
        vector<int> chr(26, 0);
        vector<int> nums(10, 0);
        for(int i = 0; i < n; i++)
            chr[s[i] - 'a']++;
        while(chr['z' - 'a'] != 0){
            nums[0]++;
            chr['z' - 'a']--;
            chr['e' - 'a']--;
            chr['r' - 'a']--;
            chr['o' - 'a']--;
        }
        while(chr['w' - 'a'] != 0){
            nums[2]++;
            chr['t' - 'a']--;
            chr['w' - 'a']--;
            chr['o' - 'a']--;
        }
        while(chr['u' - 'a'] != 0){
            nums[4]++;
            chr['f' - 'a']--;
            chr['o' - 'a']--;
            chr['u' - 'a']--;
            chr['r' - 'a']--;
        }
        while(chr['x' - 'a'] != 0){
            nums[6]++;
            chr['s' - 'a']--;
            chr['i' - 'a']--;
            chr['x' - 'a']--;
        }
        while(chr['g' - 'a'] != 0){
            nums[8]++;
            chr['e' - 'a']--;
            chr['i' - 'a']--;
            chr['g' - 'a']--;
            chr['h' - 'a']--;
            chr['t' - 'a']--;
        }
        while(chr['o' - 'a'] != 0){
            nums[1]++;
            chr['o' - 'a']--;
            chr['n' - 'a']--;
            chr['e' - 'a']--;
        }
        while(chr['t' - 'a'] != 0){
            nums[3]++;
            chr['t' - 'a']--;
            chr['h' - 'a']--;
            chr['r' - 'a']--;
            chr['e' - 'a'] -= 2;
        }
        while(chr['f' - 'a'] != 0){
            nums[5]++;
            chr['f' - 'a']--;
            chr['i' - 'a']--;
            chr['v' - 'a']--;
            chr['e' - 'a']--;
        }
        while(chr['v' - 'a'] != 0){
            nums[7]++;
            chr['f' - 'a']--;
            chr['i' - 'a']--;
            chr['v' - 'a']--;
            chr['e' - 'a'] -= 2;
        }
        while(chr['e' - 'a'] != 0){
            nums[9]++;
            chr['n' - 'a'] -= 2;
            chr['i' - 'a']--;
            chr['e' - 'a']--;
        }
        string res;
        for(int i = 0; i < 10; i++){
            while(nums[i] != 0){
                 res += ('0' + i);
                 nums[i]--;
            }
        }
        return res;
    }
};
