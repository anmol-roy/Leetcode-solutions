// Last updated: 04/05/2026, 15:42:35
class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxOnes = -1;
        int rowIndex = -1;
        
        for (int i = 0; i < mat.size(); i++) {
            int currentOnes = 0;
            // Simply count every 1 in the row
            for (int val : mat[i]) {
                if (val == 1) currentOnes++;
            }
            
            // Only update if we find a STRICTLY greater count
            // This naturally keeps the smallest index for ties
            if (currentOnes > maxOnes) {
                maxOnes = currentOnes;
                rowIndex = i;
            }
        }
        
        return {rowIndex, maxOnes};
    }
};
