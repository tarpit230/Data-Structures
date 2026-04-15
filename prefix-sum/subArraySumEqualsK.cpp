#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int subArraySum(vector<int> nums, int k){
        unordered_map<int, int> subNum;
        subNum[0] = 1;
        int total = 0, count = 0;

        for (int n : nums) {
            total += n;

            if (subNum.find(total - k) != subNum.end()) {
                count += subNum[total - k];
            }

            subNum[total]++;
        }

        return count;
    }
};

int main(){
    vector<int> nums = {1, 2, 3};
    int k = 3;
    Solution obj;
    cout << obj.subArraySum(nums, k);
    return 0;
}