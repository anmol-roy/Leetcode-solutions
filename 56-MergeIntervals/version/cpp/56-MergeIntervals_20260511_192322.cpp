// Last updated: 11/05/2026, 19:23:22
1// 11/02/26
2class Solution {
3public:
4    vector<vector<int>> merge(vector<vector<int>>& intervals) {
5
6        sort(intervals.begin(), intervals.end());
7
8        vector<vector<int>> res;
9
10        int start1 = intervals[0][0];
11        int end1 = intervals[0][1];
12
13        for(int i = 1; i < intervals.size(); i++) {
14
15            int start2 = intervals[i][0];
16            int end2 = intervals[i][1];
17
18            if(start2 <= end1) {
19                end1 = max(end1, end2);
20            }
21            else {
22                res.push_back({start1, end1});
23                start1 = start2;
24                end1 = end2;
25            }
26        }
27
28        res.push_back({start1, end1});
29
30        return res;
31    }
32};