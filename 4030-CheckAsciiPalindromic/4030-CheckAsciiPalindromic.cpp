// Last updated: 03/10/2026, 23:45:21
class Solution {
bool isPalindrome(string result) {
    int left = 0;
    int right = result.length() - 1;
    while (left < right) {
        if(result[left] != result[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}
public:
    bool isPalindromic(string s) {
      string result = "";
        for(char c : s) {
            int ascii = (int)c;
            for(int i = 7; i >= 0; i--) {
                result += ((ascii >> i) & 1) + '0';
            }
        }
        return isPalindrome(result);
        
    }
};