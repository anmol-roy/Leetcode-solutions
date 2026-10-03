// Last updated: 03/10/2026, 23:46:12
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res(words.size(), 0);
        int i = 0;

        for (auto& word : words) {
            int sum = 0;
            for (auto& c : word)
                sum += weights[(c & 31) - 1];
            int q = (sum * 2521) >> 16;

           
            int r = sum - q * 26;

            
            res[i++] = 'z' - r;
        }

        return res;
    }
};