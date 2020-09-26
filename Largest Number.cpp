/*
Largest Number
Given a list of non negative integers, arrange them such that they form the largest number.

Example 1:

Input: [10,2]
Output: "210"
Example 2:

Input: [3,30,34,5,9]
Output: "9534330"
Note: The result may be very large, so you need to return a string instead of an integer.
*/

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                string A = to_string(nums[i]) + to_string(nums[j]);
                string B = to_string(nums[j]) + to_string(nums[i]);
                if(stoll(A) < stoll(B)) swap(nums[i], nums[j]);
            }
        }
        
        bool allZero = true;
        string res = "";
        for(int num : nums){
            if(num != 0){
                allZero = false;
            }
            res += to_string(num);
        }
        if(allZero) return "0";
        return res;
    }
};
