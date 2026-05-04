// Last updated: 04/05/2026, 15:42:44
// 18/04/2006
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        int noDel = arr[0];
        int oneDel = 0; // At index 0, you can't have "one deleted" from a 1-element array
        int ans = arr[0];
        for (int i = 1; i < n; i++) {
            // Must update oneDel first so it uses the 'noDel' from index i-1
            oneDel = max(oneDel + arr[i], noDel); 
            noDel = max(noDel + arr[i], arr[i]);
            
            ans = max({ans, oneDel, noDel});
        }
        return ans;
    }
};
