// Last updated: 03/10/2026, 23:52:26
// 19/04/26
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        int result = 0;
        while( i < m && j < n ){
            if(nums1[i] > nums2[j]){
                i++;
            }
            else {
                result = max(result, j- i);
            }
            j++;
        }
        return result;
    }
};