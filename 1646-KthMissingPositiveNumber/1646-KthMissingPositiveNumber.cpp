// Last updated: 04/05/2026, 15:42:41
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    
    int current = 1; 
    int i = 0;       
    int missingCount = 0;

    while (missingCount < k) {
        if (i < n && arr[i] == current) {
           
            i++;
        } else {
           
            missingCount++;
            if (missingCount == k) {
                break;
            }
        }
        current++;
    }

    return current;
    }
};