// Last updated: 19/07/2026, 00:22:41
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector <int> prefix;

        int mx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > mx) mx = nums[i];
            nums[i] = gcd(mx, nums[i]);
        }

        sort(nums.begin(),nums.end());
        int l = 0, h = nums.size() - 1;
        long long result = 0;
        while(l < h) {
            result += gcd(nums[l],nums[h]);
            l++;
            h--;
        }
        return result;
        
    }
};