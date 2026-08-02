// Last updated: 02/08/2026, 09:00:09
class Solution {
private:
    bool dfs(int node, int color, vector<int>& colors, const vector<vector<int>>& graph) {
        colors[node] = color;
        for (int neighbor : graph[node]) {
            if (colors[neighbor] == -1) {
                if (!dfs(neighbor, 1 - color, colors, graph)) return false;
            } else if (colors[neighbor] == color) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1); 

        for (int i = 0; i < n; ++i) {
            if (colors[i] == -1) {
                if (!dfs(i, 0, colors, graph)) return false;
            }
        }
        return true;
    }
};
