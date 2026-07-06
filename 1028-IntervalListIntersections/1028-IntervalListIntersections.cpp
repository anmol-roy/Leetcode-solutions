// Last updated: 06/07/2026, 09:53:40
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int n = firstList.size(), m = secondList.size();

        while (i < n && j < m) {
            // Find the overlapping area
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            // If start <= end, a valid intersection exists
            if (start <= end) {
                res.push_back({start, end});
            }

            // Move the pointer pointing to the interval that ends first
            if (firstList[i][1] < secondList[j][1]) {
                i++;
            } else {
                j++;
            }
        }
        return res;
    }
};
