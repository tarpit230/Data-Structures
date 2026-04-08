#include <bits/stdc++.h>
using namespace std;

class NumArray {
    public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefix.resize(n);
        prefix[0] = nums[0];
        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    int sumRange(int left, int right){
        if(left == 0) return prefix[right];
        return prefix[right] - prefix[left-1];
    }
};

int main(){
    vector<int> nums = {1, 3, 5, 7, 9};
    NumArray obj(nums);
    int left = 1, right = 3;
    cout<< obj.sumRange(left, right);
    
    return 0;
}