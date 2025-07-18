// Given an array of integers nums which is sorted in ascending order, and an integer target, 
// write a function to search target in nums. 
// If target exists, then return its index. Otherwise, return -1.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    int BinaySearch(vector<int> nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        while(low <= high) {
            int mid = (low + high)/2;
            if(target == nums[mid]) return mid;
            if(target > nums[mid]) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    int result = solution.BinaySearch(nums, target);
    cout << "Result: " << result;
}