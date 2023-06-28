/*
Can Make Arithmetic Progression From Sequence

A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

Example 1:

Input: arr = [3,5,1]
Output: true
Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

Example 2:

Input: arr = [1,2,4]
Output: false
Explanation: There is no way to reorder the elements to obtain an arithmetic progression.
 
Constraints:

2 <= arr.length <= 1000
-10^6 <= arr[i] <= 10^6
*/
class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int length = arr.size();
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        for (int num : arr) {
            min_val = std::min(min_val, num);
            max_val = std::max(max_val, num);
        }
        double diff = static_cast<double>(max_val - min_val) / (length - 1);
        for (int i = 0; i < length; i++) {
            double expected = min_val + i * diff;
            bool found = false;
            for (int num : arr) {
                if (std::abs(num - expected) < 1e-9) {
                    found = true;
                    break;
                }
            }
            if (!found)
                return false;
        }

        return true;
    }
};
