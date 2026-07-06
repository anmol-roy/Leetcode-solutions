// Last updated: 06/07/2026, 09:52:09
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        // total will keep the count of all the peaks and valleys in the given range
        int total = 0;
        // explore the complete range : [num1 , num2];
        for(int num = num1 ; num <= num2 ; num ++){
            // convert to string for easier traversal
            string s = to_string(num);
            for(int i = 1 ; i < s.length() - 1 ; i ++){
                // peak
                if(s[i] > s[i - 1] && s[i] > s[i + 1]) total ++;
                // valley
                else if(s[i] < s[i - 1] && s[i] < s[i + 1]) total ++;
            }
        }
        return total;
    }
};