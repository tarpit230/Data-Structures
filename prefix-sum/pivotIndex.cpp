#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int> nums){
        int n = nums.size();
        
        vector<int> prefix(n + 1, 0);
        
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }

        int total = prefix[n];

        for(int i = 1; i <= n; i++){
            int leftSum = prefix[i - 1];
            int rightSum = total - prefix[i];

            if(leftSum == rightSum) return i - 1;
        }

        return -1;
    }
};

int main(){
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    Solution obj;
    cout << obj.pivotIndex(nums);
    return 0;
}