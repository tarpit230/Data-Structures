#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
    string longestCommonPrefix(vector<string>& strs){
        int count = 0, min = 1000;
        string str;
        for(int i=0; i<strs.size(); i++){
            int len = strs[i].size();
            if(len < min){
                min = len;
                str = strs[i];
            }
        }

        for(int i=0; i<min; i++){
            for(int j=0; j<strs.size(); j++){
                if(strs[j][i] != str[i]){
                    return str.substr(0, count);
                }
            }
            count++;
        }
        return str.substr(0, count);

    }
};

int main(){
    vector<string> strs = {"flower", "flow", "flight"};
    Solution obj;
    cout<<obj.longestCommonPrefix(strs);

    return 0;
}