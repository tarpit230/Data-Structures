#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    long long myAtoi(string s) {
        if(s.empty()) return 0;
        int i = 0;
        int n = s.length();
        // skip leading whitespaces
        while(i<n && s[i] == ' '){
            i++;
        }
        if(i == n) return 0;

        int sign = 1;
        if(s[i] == '+') i++;
        else if(s[i] == '-') {
            sign = -1;
            i++;
        }

        // convert to digit and create response
        long long res = 0;
        while(i < n && isdigit(s[i])){
            int digit = s[i] - '0';
            res = res * 10 + digit;

            if(sign * res <= INT_MIN) return INT_MIN;
            else if(sign * res >= INT_MAX) return INT_MAX;
            i++;
        }
        return sign*res;
    }
};

int main() {
    Solution obj;
    string s = " -042";
    const long long res = obj.myAtoi(s);
    cout<< res;

    return 0;
}