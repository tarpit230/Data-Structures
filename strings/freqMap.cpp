// Print all the duplicates in the input string

#include <bits/stdc++.h>
using namespace std;

int main(){
    string str = "Helllo";
    unordered_map<char, int> M;

    for(int i=0; i<str.size();i++){
        if(M.find(str[i]) == M.end()){
            M.insert(make_pair(str[i],1));
        }else{
            M[str[i]]++;
        }
    }

    for (auto& it : M) {
        cout << it.first << ' ' << it.second << '\n';
    }
    
    for(auto& it : M){
        if(it.second>1)
            cout<<it.first<<' '<<it.second;
    }

    return 0;
}