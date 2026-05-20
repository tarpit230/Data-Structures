// Sort Character By Frequency

// Given a string s, sort it in decreasing order based on the frequency of the characters.
// The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:

// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string sortCharacters(string s) {
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto p: mp){
            pq.push({p.second, p.first});
        }
        string ans = "";
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            for(int i=0; i<freq; i++){
                ans += ch;
            }
            
        }

        return ans;
    }
};

int main() {
    string s = "tree";

    Solution obj;
    cout << obj.sortCharacters(s);

    return 0;
}