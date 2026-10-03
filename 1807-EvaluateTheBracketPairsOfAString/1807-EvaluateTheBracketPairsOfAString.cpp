// Last updated: 03/10/2026, 23:52:43
class Solution {
public:
    string evaluate(const string& s, vector<vector<string>>& knowledge) { 
    string res, t; // T/S: O(N)
    unordered_map<string, string> m; // knowledge <key, val>
    for(const auto& x : knowledge) m[x[0]] = x[1];
    for(const char& c : s)
        if(c=='(' || c==')'){ // if(!isalpha(c)){
            res += c=='(' ? t : m.count(t) ? m[t] : "?";
            t = "";
        }else t += c;
    return res+t;
    }
};