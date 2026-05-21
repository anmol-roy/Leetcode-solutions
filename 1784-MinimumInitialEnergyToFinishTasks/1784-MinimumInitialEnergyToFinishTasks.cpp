// Last updated: 21/05/2026, 18:33:23

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        // Sort tasks by the difference (minimum - actual) in descending order
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        
        int current_energy = 0;
        int initial_energy = 0;
        
        for (const auto& task : tasks) {
            int actual = task[0];
            int minimum = task[1];
            
            // If current energy is less than the required minimum
            if (current_energy < minimum) {
                // Add the deficit to both total initial energy and current pool
                initial_energy += (minimum - current_energy);
                current_energy = minimum;
            }
            
            // Spend the actual energy required for the task
            current_energy -= actual;
        }
        
        return initial_energy;
    }
};
