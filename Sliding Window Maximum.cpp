/*
Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]
 
Constraints:

1 <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
1 <= k <= nums.length
*/

// Solution I
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq;
        for(int i = 0; i < nums.size(); i++){
            while(!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
            if(i >= k-1){
                res.emplace_back(dq.front());
                if(nums[i - k + 1] == dq.front())
                    dq.pop_front();
            }
        }
        return res;
    }
};

// Solution II
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int left = 0, right = 0;
        deque<int> q;
        while (right < nums.size()) {
            while (!q.empty() && nums[right] > nums[q.back()])
                q.pop_back();
            q.push_back(right);
            if (left > q.front())
                q.pop_front();
            if (right + 1 >= k) {
                res.push_back(nums[q.front()]);
                left++;
            }
            right++;
        }
        return res;   
    }
};
