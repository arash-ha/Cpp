class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = 0;
        int i = 0;
        int j = 0;
        vector<int> vect(m + n, 0);
        
        while (k < (m+n)){
            if (i == m) {
                while (j < n){
                    vect[k] = nums2[j];
                    j++;
                    k++;
                }
                break;
            }
            if (j == n) {
                while (i < m){
                    vect[k] = nums1[i];
                    i++;
                    k++;
                }
                break;
            }
            if(nums1[i] <= nums2[j]){
                vect[k] = nums1[i];
                k++;
                i++;
            } else {
                vect[k] = nums2[j];
                k++;
                j++;
            }
        }
        nums1 = vect;
    }
};
