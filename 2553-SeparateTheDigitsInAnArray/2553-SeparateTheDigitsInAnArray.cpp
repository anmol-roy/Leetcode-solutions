// Last updated: 03/10/2026, 23:50:46
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> result;

        for (int num : nums) {
            // Temporary vector to hold digits of the current number
            vector<int> temp;
            while (num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }
            // Add them to result in reverse order to fix the sequence
            for (int j = temp.size() - 1; j >= 0; j--) {
                result.push_back(temp[j]);
            }
        }
        return result;
    }
};
