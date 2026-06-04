// Last updated: 04/06/2026, 06:46:14
1class Solution {
2public:
3    int totalWaviness(int num1, int num2) {
4        // total will keep the count of all the peaks and valleys in the given range
5        int total = 0;
6        // explore the complete range : [num1 , num2];
7        for(int num = num1 ; num <= num2 ; num ++){
8            // convert to string for easier traversal
9            string s = to_string(num);
10            for(int i = 1 ; i < s.length() - 1 ; i ++){
11                // peak
12                if(s[i] > s[i - 1] && s[i] > s[i + 1]) total ++;
13                // valley
14                else if(s[i] < s[i - 1] && s[i] < s[i + 1]) total ++;
15            }
16        }
17        return total;
18    }
19};