#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        double findMaxAverage(vector<int>& nums, int k) {
            double maxAvg = 0, windowAvg = 0, sum = 0;
            for(int i=0; i<k; i++) {
                sum += nums[i];
            }
            windowAvg = sum / k;
            maxAvg = windowAvg;
            for(int i=k; i<nums.size(); i++){
                sum += nums[i] - nums[i - k];
                windowAvg = sum/k;
                maxAvg = max(maxAvg, windowAvg);
            }
            return maxAvg;
        }
    };

int main() {
    vector<int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    Solution obj;
    cout<< obj.findMaxAverage(nums, k);

    return 0;
}    