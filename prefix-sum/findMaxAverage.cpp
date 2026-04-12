#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    double findMaxAverage(vector<int> nums, int k){
        int n= nums.size();
        vector<int> prefix(n+1, 0);
        for(int i=0; i<n; i++){
            prefix[i+1] = prefix[i] + nums[i];
        }
        int maxSum = INT_MIN;
        int left = 1, right = k;
        while(right<=n){
            int sum = prefix[right]-prefix[left-1];
            maxSum = max(maxSum, sum);
            left++; right++;
        }
        return (double)maxSum/k;
    }
};

int main(){
    Solution obj;
    vector<int> vec = {1, 12, -5, -6, 50, 3};
    cout<< obj.findMaxAverage(vec, 4);
    return 0;
}