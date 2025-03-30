#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int minLength = INT_MAX, sum = 0, left = 0;
            for(int right = 0; right < nums.size(); right++) {
                sum += nums[right];
    
                while(sum >= target){
                    minLength = min(minLength, right - left + 1);
                    sum -= nums[left++];
                }
            }
            return minLength == INT_MAX ? 0 : minLength;
        }
    };

int main() {
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    Solution obj;
    cout<< obj.minSubArrayLen(target, nums);

    return 0;
}    