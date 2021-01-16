/*
Kth Largest Element in an Array

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 = k = array's length.*/

// Solution 1
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};


// Solution 2
// MinHeap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums){
            pq.push(num);
            if(pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

// Solution 3
// MaxHeap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int, greater<int>> mset(nums.begin(), nums.end());
        for(int i = 0; i < k - 1; i++)
            mset.erase(mset.begin());
        return *mset.begin();
    }
};

