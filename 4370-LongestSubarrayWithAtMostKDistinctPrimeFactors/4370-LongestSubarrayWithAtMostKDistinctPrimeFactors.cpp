// Last updated: 24/08/2026, 19:56:54
class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int left = 0;

        unordered_map<int, int> freq;
        int distinct = 0;
        for(int right = 0; right < n; right++) {
            int x = nums[right];
            for (int p = 2; p * p <= x; p++) {
                if (x % p == 0) {      
                    if (freq[p] == 0)
                        distinct++;
                    freq[p]++;
                    while (x % p == 0) 
                        x /= p;
                }
            }
            if (x > 1) {
                if (freq[x] == 0)
                    distinct++;
                freq[x]++;
            }
            while (distinct > k) {
                int y = nums[left++];
                for (int p = 2; p * p <= y; p++) {
                    if (y % p == 0) {
                        freq[p]--;
                        if (freq[p] == 0)
                            distinct--;
                        while(y % p == 0)
                            y /= p;
                    }
                }
                if (y > 1) {
                    freq[y]--;
                    if (freq[y] == 0)
                        distinct--;
                }
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};