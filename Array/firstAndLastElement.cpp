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

    void BetterApproach(vector<int>& nums, int target) {
        vector<int> result;
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) {
                result.push_back(mid);
                int left = mid - 1;
                while(left >= 0 && nums[left] == target){
                    result.push_back(left);
                    left--;
                }
                int right = mid+1;
                while(right < nums.size() && nums[right] == target){
                    result.push_back(right);
                    right++;
                }
                break;
            } 
            else if(nums[mid] > target) {
                 high = mid - 1;
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }  
        }
        sort(result.begin(), result.end());
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
    obj.BetterApproach(nums, target);

    return 0;
}