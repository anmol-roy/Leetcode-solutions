// Last updated: 02/08/2026, 08:56:48
class Solution {
public:
    static string smallestPalindrome(string& s) {
        const int n=s.size(), n0=n/2;
        int freq[26]={0};
        for(int i=0; i<n0; i++)
            freq[s[i]-'a']++;
        int l=0;
        for(int x=0; x<26; x++){
            const int f=freq[x];
            if (f==0) continue;
            const char c='a'+x;
            fill(s.begin()+l, s.begin()+l+f, c);
            fill(s.rbegin()+l, s.rbegin()+l+f, c);
            l+=f;
        }
        return s;
    }
};