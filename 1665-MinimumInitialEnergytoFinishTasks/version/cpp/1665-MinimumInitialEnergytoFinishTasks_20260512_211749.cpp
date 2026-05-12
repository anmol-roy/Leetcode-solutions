// Last updated: 12/05/2026, 21:17:49
1
2class Solution {
3public:
4    int minimumEffort(vector<vector<int>>& tasks) {
5        // Sort tasks by the difference (minimum - actual) in descending order
6        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
7            return (a[1] - a[0]) > (b[1] - b[0]);
8        });
9        
10        int current_energy = 0;
11        int initial_energy = 0;
12        
13        for (const auto& task : tasks) {
14            int actual = task[0];
15            int minimum = task[1];
16            
17            // If current energy is less than the required minimum
18            if (current_energy < minimum) {
19                // Add the deficit to both total initial energy and current pool
20                initial_energy += (minimum - current_energy);
21                current_energy = minimum;
22            }
23            
24            // Spend the actual energy required for the task
25            current_energy -= actual;
26        }
27        
28        return initial_energy;
29    }
30};
31