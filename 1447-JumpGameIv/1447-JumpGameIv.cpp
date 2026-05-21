// Last updated: 21/05/2026, 18:33:25
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0; // Base case: already at the end

        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);
        queue<int> que;
        
        que.push(0);
        visited[0] = true;
        int steps = 0;

        while(!que.empty()) {
            int size = que.size();
            while(size--) {
                int curr = que.front();
                que.pop();

                if(curr == n - 1)
                    return steps;

                int left = curr - 1;
                int right = curr + 1;

                // Move Left
                if(left >= 0 && !visited[left]) {
                    que.push(left);
                    visited[left] = true; // Fixed: Mark left as visited
                }

                // Move Right
                if(right < n && !visited[right]) {
                    que.push(right);
                    visited[right] = true; // Added: Handle right movement safely
                }

                // Jump to same values
                if (mp.count(arr[curr])) {
                    for(int idx : mp[arr[curr]]) {
                        if(!visited[idx]) {
                            que.push(idx);
                            visited[idx] = true;
                        }
                    }
                    mp.erase(arr[curr]); // Prevent redundant map lookups
                }
            }
            steps++;
        }
        return -1;
    }
};
