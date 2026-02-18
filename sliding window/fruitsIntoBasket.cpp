#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruits = 0;
        int left = 0;
        unordered_map<int, int> mp;
        for(int right=0; right<fruits.size(); right++){
            mp[fruits[right]]++;
            int n = mp.size();
            while(n>2){
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
                n = mp.size();
            }
            maxFruits = max(maxFruits, right-left+1);
        }
        return maxFruits;
    }
};

int main() {
    Solution obj;
    vector<int> fruits = {1, 2, 3, 2, 2};
    cout << obj.totalFruit(fruits);

return 0;
}