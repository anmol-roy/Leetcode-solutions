// Last updated: 20/06/2026, 09:24:02
1class Solution {
2public:
3    bool containsDuplicate(vector<int>& nums) {
4        unordered_map<int, int > freq;
5        for (auto it : nums){
6            freq[it]++;
7        }
8        for ( auto it : freq) {
9            if(it.second > 1){
10                return true;
11            }
12        }
13        return false;
14    }
15};