// Last updated: 02/08/2026, 09:00:14
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build the adjacency list (1-indexed nodes)
        // Each entry maps a source node to a pair: {target_node, travel_time}
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        
        // Step 2: Initialize min-heap and tracking array
        // Min-heap stores pairs of {accumulated_time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> dist(n + 1, INT_MAX);
        
        // Signal starts at node k at time 0
        dist[k] = 0;
        minHeap.push({0, k});
        
        // Step 3: Execute Dijkstra's Algorithm
        while (!minHeap.empty()) {
            auto [currentTime, currNode] = minHeap.top();
            minHeap.pop();
            
            // Skip stale pairs if a shorter path to this node was already processed
            if (currentTime > dist[currNode]) continue;
            
            // Explore all directed connections out of the current node
            for (const auto& neighbor : adj[currNode]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;
                
                // Relaxation step
                if (dist[currNode] + edgeWeight < dist[nextNode]) {
                    dist[nextNode] = dist[currNode] + edgeWeight;
                    minHeap.push({dist[nextNode], nextNode});
                }
            }
        }
        
        // Step 4: Aggregate results
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            // If any node remains untouched, it is unreachable
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        
        return maxTime;
    }
};
