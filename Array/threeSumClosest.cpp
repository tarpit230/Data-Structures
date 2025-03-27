// Given an integer array nums of length n and an integer target, 
// find three integers in nums such that the sum is closest to target.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = INT_MAX/2;
        for(int i=0; i<nums.size() -2; i++){
            int left = i+1, right = nums.size()-1;
            while(left<right){
                int currSum = nums[i] + nums[left] + nums[right];
                if(abs(currSum - target) < abs(closestSum - target)){
                    closestSum = currSum;
                }
                if(currSum < target) ++left;
                else if(currSum > target) --right;
                else return currSum;
            }
        }
        return closestSum;
    } 
};

int main(){
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    Solution obj;
    cout<< obj.threeSumClosest(nums, target);

    return 0;
}