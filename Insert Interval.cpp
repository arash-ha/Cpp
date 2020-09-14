/*
Insert Interval
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
Example 2:

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int i = 0, n = intervals.size();
        while(i < n && intervals[i][1] < newInterval[0]) res.emplace_back(intervals[i++]);
        
        vector<int> nI = newInterval;
        while(i < n && intervals[i][0] <= newInterval[1]){
            nI[0] = min(nI[0], intervals[i][0]);
            nI[1] = max(nI[1], intervals[i++][1]);
        }
        res.emplace_back(nI);
        while(i < n) res.emplace_back(intervals[i++]);
        
        return res;
    }
};
