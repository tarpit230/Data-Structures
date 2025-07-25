#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while(low < high) {
            int mid = (low + high) / 2;
            if(nums[mid] > nums[mid + 1]) {
                high = mid; // Move to the left half
            } else {
                low = mid + 1; // Move to the right half
            }
        }
        return low; // The peak element index
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 1};
    int peakIndex = solution.findPeakElement(nums);
    cout << "Peak Element Index: " << peakIndex << endl; // Output: Peak Element Index: 2
    return 0;
}