#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindowAtMost(nums, k) - slidingWindowAtMost(nums, k-1);
    }
    int slidingWindowAtMost(vector<int> &nums, int k){
        int start = 0, totalCount = 0;
        unordered_map<int, int> mp;

        for (int end = 0; end < nums.size(); end++) {
            mp[nums[end]]++;
            while(mp.size()>k){
                mp[nums[start]]--;
                if(mp[nums[start]] == 0){
                    mp.erase(nums[start]);
                }
                start++;
            }
            totalCount += end - start + 1;
        }
        return totalCount;
    }
};

int main(){
    Solution obj;
    vector<int> nums = {1,2,1,2,3};
    int k = 2;
    cout << obj.subarraysWithKDistinct(nums, k);

    return 0;
}