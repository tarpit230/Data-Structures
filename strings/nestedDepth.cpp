// Given a valid parentheses string s, return the nesting depth of s. The nesting depth is 
// the maximum number of nested parentheses.

// Example 1:
// Input: s = "(1+(2*3)+((8)/4))+1"
// Output: 3
// Explanation: Digit 8 is inside of 3 nested parentheses in the string.

// Solution
// we used stack.

#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
    int nestedDepth(string s){
        stack<char> st;
        int maxi = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(s[i]);
                maxi = max(maxi, (int)st.size());
            } else if(s[i] == ')'){
                st.pop();
            }
        }
        return maxi;
    }
};

int main() {
    Solution obj;
    string str = "(1+(2*3)+((8)/4))+1";
    cout << obj.nestedDepth(str);

    return 0;
}