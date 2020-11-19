/*
Merge Intervals


Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        for(int i = 0; i < intervals.size(); i++){
            int end = intervals[i][1], index = -1;
            for(int j = i + 1; j < intervals.size(); j++){
                if(end >= intervals[j][0]){
                    end = max(end, intervals[j][1]);
                    index = j;
                }
            }
            res.push_back({intervals[i][0], end});
            
            if(index != -1)
                i = index;
        }
        return res;
    }
};
