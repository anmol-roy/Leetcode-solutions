// Last updated: 06/07/2026, 09:53:52
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string,int> freq;

        for(string word : words){
            freq[word]++;
        }

        auto comp = [](pair<int,string>& a, pair<int,string>& b){

            if(a.first == b.first){
                return a.second < b.second;
            }

            return a.first > b.first;
        };

        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            decltype(comp)
        > pq(comp);

        for(auto &it : freq){

            pq.push({it.second, it.first});

            if(pq.size() > k){
                pq.pop();
            }
        }

        vector<string> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};