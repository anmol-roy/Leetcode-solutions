// Last updated: 02/08/2026, 08:59:17
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector <int> sorted = arr;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> rank;
        int curRank = 1;

        for(auto x : sorted) {
           if (!rank.count(x)){
            rank[x] = curRank++;
           }
        }

        vector<int> res;
        res.reserve(arr.size());

        for(int i : arr) {
            res.push_back(rank[i]);
        }
        return res;


    }
};