// Last updated: 04/05/2026, 15:44:40
class Solution {
public:
    
    int lowerBound(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        int ans = nums.size();

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(nums[mid] >= target){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }

    int upperBound(vector<int>& nums, int target){
        int l = 0;
        int r = nums.size() - 1;
        int ans = nums.size();

        while(l <= r){
            int mid = l + (r - l) / 2;

            if(nums[mid] > target){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lb = lowerBound(nums, target);

        if(lb == nums.size() || nums[lb] != target)
            return {-1, -1};

        int ub = upperBound(nums, target) - 1;

        return {lb, ub};
    }
};