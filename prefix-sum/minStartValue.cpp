#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int currentSum = 0;
        int minPrefix = 0;

        for(int num : nums){
            currentSum += num;
            minPrefix = min(minPrefix, currentSum);
        }

        return 1 - minPrefix;
    }
};

int main(){
    vector<int> vec = {-3, 2, -3, 4, 2};
    Solution obj;
    cout << obj.minStartValue(vec);
    return 0;
}