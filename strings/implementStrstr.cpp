// Find the index of first occurence in string

#include<bits/stdc++.h>
#include<String.h>
using namespace std;

int main(){
    string haystack = "sadbutsad";
    string needle = "uts";

    int n1 = haystack.size();
    int n2 = needle.size();

    if(n2 > n1)
        cout<< -1;

    int i = 0, j = 0, start = 0;

    while(i < n1 && j < n2){
        if(haystack[i] == needle[j]){
            if(i-start+1 == n2){
                cout<< start;
            }
            i++;
            j++;
        }
        else{
            j=0;
            start++;
            i=start;
        }
    }

    return 0;
}