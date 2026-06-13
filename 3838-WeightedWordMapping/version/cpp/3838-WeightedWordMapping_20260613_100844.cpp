// Last updated: 13/06/2026, 10:08:44
1class Solution {
2public:
3    string mapWordWeights(vector<string>& words, vector<int>& weights) {
4        string res(words.size(), 0);
5        int i = 0;
6
7        for (auto& word : words) {
8            int sum = 0;
9            for (auto& c : word)
10                sum += weights[(c & 31) - 1];
11            int q = (sum * 2521) >> 16;
12
13           
14            int r = sum - q * 26;
15
16            
17            res[i++] = 'z' - r;
18        }
19
20        return res;
21    }
22};