// Last updated: 11/05/2026, 18:00:49

using namespace std;

class Solution {
    vector<bool> is_prime;
    void sieve(int max_val) {
        is_prime.assign(max_val + 1, true);
        is_prime[0] = is_prime[1] = false;
        for (int p = 2; p * p <= max_val; p++) {
            if (is_prime[p]) {
                for (int i = p * p; i <= max_val; i += p)
                    is_prime[i] = false;
            }
        }
    }

public:
    int minJumps(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int max_val = 0;
        for (int x : nums) max_val = max(max_val, x);
        sieve(max_val);

        // Map prime factor p -> indices j where nums[j] % p == 0
        unordered_map<int, vector<int>> prime_to_indices;
        // Optimization: Pre-calculate which indices belong to which prime multiples
        // To keep it efficient, we only map if nums[i] is prime
        for (int i = 0; i < n; i++) {
            int val = nums[i];
            for (int p = 2; p * p <= val; p++) {
                if (val % p == 0) {
                    prime_to_indices[p].push_back(i);
                    while (val % p == 0) val /= p;
                }
            }
            if (val > 1) prime_to_indices[val].push_back(i);
        }

        queue<int> q;
        vector<int> dist(n, -1);
        unordered_set<int> used_primes;

        q.push(0);
        dist[0] = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == n - 1) return dist[curr];

            // 1. Adjacent steps
            for (int next : {curr - 1, curr + 1}) {
                if (next >= 0 && next < n && dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }

            // 2. Prime Teleportation
            int p = nums[curr];
            if (is_prime[p] && used_primes.find(p) == used_primes.end()) {
                used_primes.insert(p);
                for (int target : prime_to_indices[p]) {
                    if (dist[target] == -1) {
                        dist[target] = dist[curr] + 1;
                        q.push(target);
                    }
                }
            }
        }
        return -1;
    }
};
