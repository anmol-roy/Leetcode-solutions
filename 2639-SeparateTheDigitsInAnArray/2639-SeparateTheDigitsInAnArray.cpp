// Last updated: 21/05/2026, 18:33:12
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
