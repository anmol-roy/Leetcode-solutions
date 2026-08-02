// Last updated: 02/08/2026, 09:00:47
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int removed = 0;

        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {

            if (intervals[i][0] < end) {      // overlap
                removed++;
                end = min(end, intervals[i][1]); // keep interval with smaller end
            }
            else {
                end = intervals[i][1];
            }
        }

        return removed;
        
    }
};