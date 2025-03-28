#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void searchRange(vector<int>& nums, int target) {
        vector<int> result;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == target) result.push_back(i);
        }
        if(result.size() == 0) {
            result.push_back(-1);
            result.push_back(-1);
        } else if(result.size() == 1){
            result.push_back(result[0]);
        } else {
            int temp1 = result[0];
            int temp2 = result[result.size() - 1];
            result.clear();
            result.push_back(temp1);
            result.push_back(temp2);
        }
        for(int num: result){
            cout<< num << " ";
        }
    }
};

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution obj;
    obj.searchRange(nums, target);

    return 0;
}