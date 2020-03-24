/*
Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool flag = false;
        for (auto i = digits.rbegin(); i != digits.rend() && !flag; i++){
            if(*i < 9){
                (*i)++;
                flag = true;
            }
            else{
                *i = 0;
            }
        }
        if (digits[0] == 0 && !flag){
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
