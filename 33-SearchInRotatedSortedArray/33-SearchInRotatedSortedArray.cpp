// Last updated: 04/05/2026, 15:44:41
class Solution {
public:
    int search(vector<int>& arr, int k) {
      int l = 0, h = arr.size()-1;
      while(l <= h){
        int m = (l+h)/2;
        if(arr[m]==k) return m;
        if(arr[l] <= arr[m]){
            if(arr[l] <= k && k <= arr[m]){
                h = m - 1;
            } else {
                l = m + 1;
            }
        } else {
            if(arr[m] <= k && k <= arr[h]){
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
      }  
        return -1;
    }
};