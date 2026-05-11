// Last updated: 11/05/2026, 18:27:43
1class Solution {
2public:
3    vector<int> separateDigits(vector<int>& nums) {
4        vector<int> result;
5
6        for (int num : nums) {
7            // Temporary vector to hold digits of the current number
8            vector<int> temp;
9            while (num > 0) {
10                temp.push_back(num % 10);
11                num /= 10;
12            }
13            // Add them to result in reverse order to fix the sequence
14            for (int j = temp.size() - 1; j >= 0; j--) {
15                result.push_back(temp[j]);
16            }
17        }
18        return result;
19    }
20};
21