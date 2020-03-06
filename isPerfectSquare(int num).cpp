class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return -1;
        else if (num == 0) return 0;
        long mid, low = 0, high = num;
        while(low <= high){
        mid = (low + high)/2;
        if (mid*mid == num) return true;
        else{
            if((mid * mid < num && (mid + 1)*(mid + 1) > num)) return false;
            else if (mid * mid < num)  low = mid + 1;   
            else high = mid - 1;
        }
        }
        return mid;
    }
};
