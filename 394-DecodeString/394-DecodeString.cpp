// Last updated: 02/08/2026, 09:00:53

class Solution {
public:
    string decodeString(string s) {
        stack<int> numStack;
        stack<string> strStack;
        string currentString = "";
        int currentNum = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                currentNum = currentNum * 10 + (ch - '0');
            } 
            else if (ch == '[') {
                numStack.push(currentNum);
                strStack.push(currentString);
                
                currentNum = 0;
                currentString = "";
            } 
            else if (ch == ']') {
                int repeatTimes = numStack.top();
                numStack.pop();
                
                string previousString = strStack.top();
                strStack.pop();

                string duplicatedString = "";
                for (int i = 0; i < repeatTimes; i++) {
                    duplicatedString += currentString;
                }

                currentString = previousString + duplicatedString;
            } 
            else {
                currentString += ch;
            }
        }

        return currentString;
    }
};
