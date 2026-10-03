// Last updated: 03/10/2026, 23:45:22
class Solution {
int gcd(int a, int b) {
    return std::gcd(a, b);
}
int getScore(vector<int>& arr) {
    int n = arr.size();
    if (n < 2) {
        return 0;
    }
    vector<int> pref(n);
    pref[0] = arr[0];
    for(int i = 1; i < n; i++) {
        pref[i] = gcd(pref[i - 1], arr[i]);
    }
    vector<int> suff(n);
    suff[n - 1] = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suff[i] = gcd(suff[i + 1], arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int leftGCD = pref[i];
        int rightGCD = suff[i + 1];
        if (leftGCD == rightGCD)
            ans++;
    }
    return ans;
}
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int ans = getScore(nums);
        for (int remove = 0; remove < n; remove++) {
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                if (i != remove)
                    arr.push_back(nums[i]);
            }
            ans = max(ans, getScore(arr));
        }
        return ans;
    }
};