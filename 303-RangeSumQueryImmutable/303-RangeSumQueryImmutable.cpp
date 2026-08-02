// Last updated: 02/08/2026, 09:01:16
class NumArray {
private: 
    vector<int> pref;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();

        pref.resize(n);
        int curr_sum = 0;
        for(int i = 0; i < n; i++) {
            curr_sum += nums[i];
            pref[i] = curr_sum;
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) {
            return pref[right];
        }
        return pref[right] - pref[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */