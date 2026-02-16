#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLength = 0;
        int left = 0;
        int count = 0;
        for(int right=0; right < nums.size();right++){
            if(nums[right] == 1) count++;
            int replaceable = (right - left + 1) - count;
            while(replaceable > k){
                if(count > 0 && nums[left] == 1) { count--; }
                if(nums[left] == 0) replaceable--;
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,1,1,0,0,0,1,1,1,1,0};
    int k = 2;
    cout << obj.longestOnes(nums, k);


return 0;
}