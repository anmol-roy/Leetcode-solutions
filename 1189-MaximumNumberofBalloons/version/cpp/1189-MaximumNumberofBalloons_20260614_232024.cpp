// Last updated: 14/06/2026, 23:20:24
1class Solution {
2public:
3    int maxNumberOfBalloons(string text) {
4        unordered_map<char, int> have;
5        unordered_map<char, int> need;
6        
7        // Define what we need for the word "balloon"
8        need['b'] = 1;
9        need['a'] = 1;
10        need['l'] = 2;
11        need['o'] = 2;
12        need['n'] = 1;
13        
14        for (char c : text) {
15            have[c]++;
16        }
17        
18        int res = INT_MAX; 
19        
20        for (auto i : need) {
21            char c = i.first;
22            int fneed = i.second;
23            int fhave = have[c]; 
24            
25            int times = fhave / fneed;
26            res = min(res, times);
27        }
28        
29        return res;
30    }
31};
32