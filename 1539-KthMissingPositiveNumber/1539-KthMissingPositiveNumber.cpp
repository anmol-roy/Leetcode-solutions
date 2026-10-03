// Last updated: 03/10/2026, 23:53:27
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