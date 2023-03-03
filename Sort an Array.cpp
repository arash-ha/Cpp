/*
Sort an Array

Given an array of integers nums, sort the array in ascending order and return it.
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.
 
Constraints:

1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4
*/

// Solution I
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        quickSort(nums, 0, n-1);
        return nums;
    }
    void quickSort(vector<int>& nums, int low, int high){
        if (low < high){ 
            int pivot = partition(nums, low, high);
            quickSort(nums, low, pivot - 1);
            quickSort(nums, pivot + 1, high);
        }
    }
    int partition (vector<int>& nums, int low, int high){
        int i = (low - 1);
        int pivot = nums[high];
        for (int j = low; j <= high- 1; j++) {
            if (nums[j] <= pivot){
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[high]);
        return (i + 1);
    }
};

// Solution II
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
       int n = nums.size();
        mergeSort(nums, n);
        return nums;
    }

    void mergeSort(vector<int> &A, int n){
        if(n < 2)
            return;
        int mid = n / 2;
        vector<int> L, R;
        for(int i = 0; i < n; i++){
            if(i < mid)
                L.push_back(A[i]);
            else
                R.push_back(A[i]);
        }
        mergeSort(L, L.size());
        mergeSort(R, R.size());
        mergeArrays(A, L, R);
    }

    void mergeArrays(vector<int> &A, vector<int> &L, vector<int> &R){
        int sizeL = L.size(), sizeR = R.size(), i = 0, j = 0, k = 0;
        while(i < sizeL && j < sizeR){
            if (L[i] <= R[j]){
                A[k] = L[i];
                i++;
            }
            else{
                A[k] = R[j];
                j++;
            }
            k++;
        }
        while(i < sizeL){
            A[k] = L[i];
            i++;
            k++;
        }
        while(j < sizeR){
            A[k] = R[j];
            j++;
            k++;
        }
    }
};
