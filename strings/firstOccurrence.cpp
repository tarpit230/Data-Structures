#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int strStr(string& haystack, string& needle){
        int n1 = haystack.size();
        int n2 = needle.size();

        if(n2 > n1) return -1;

        

        return 0;
    }
};

int main(){
    string haystack = "sadbutsad";
    string needle = "sad";

    Solution obj;
    cout<< obj.strStr(haystack, needle);

    return 0;
}