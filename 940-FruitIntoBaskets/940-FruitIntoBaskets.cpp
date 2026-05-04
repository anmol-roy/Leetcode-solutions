// Last updated: 04/05/2026, 15:42:50
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> basket; // Tracks frequency of fruit types in the window
        int left = 0;
        int maxFruits = 0;

        for (int right = 0; right < fruits.size(); ++right) {
            // Add the fruit at the current 'right' position to our basket
            basket[fruits[right]]++;

            // If we have more than 2 distinct fruit types, shrink from the left
            while (basket.size() > 2) {
                int leftFruit = fruits[left];
                basket[leftFruit]--;
                
                // If the fruit type count hits zero, remove it from the map
                if (basket[leftFruit] == 0) {
                    basket.erase(leftFruit);
                }
                left++; // Move the window's starting point to the right
            }

            // Update the maximum number of fruits found in a valid window [left, right]
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};