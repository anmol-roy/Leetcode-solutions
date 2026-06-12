// Last updated: 12/06/2026, 14:55:51
1class Solution {
2public:
3    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) {
4
5        vector<vector<int>> res;
6        int i = 0;
7        int n = intervals.size();
8
9        while (i < n && intervals[i][1] < newInterval[0]) {
10            res.push_back(intervals[i]);
11            i++;
12        }
13
14        while (i < n && intervals[i][0] <= newInterval[1]) {
15            newInterval[0] = min(newInterval[0], intervals[i][0]);
16            newInterval[1] = max(newInterval[1], intervals[i][1]);
17            i++;
18        }
19
20        res.push_back(newInterval);
21
22        while (i < n) {
23            res.push_back(intervals[i]);
24            i++;
25        }
26
27        return res;
28    }
29};