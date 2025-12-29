// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
    vector<string> generateParanthesis(int n) {
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;
    }
    
    void dfs(int openP, int closeP, string s, int n, vector<string>& res) {
        if(openP == closeP && openP+closeP == n*2) {
            res.push_back(s);
            return;
        }

        if(openP < n){
            dfs(openP+1, closeP, s+'(', n, res);
        }
        if(closeP<openP) {
            dfs(openP, closeP+1, s+')', n, res);
        }
    }
};

int main() {
    Solution obj;
    int n = 3;
    vector<string> result = obj.generateParanthesis(n);
    for(const string& s : result) {
        cout << s << endl;
    }

    return 0;
}