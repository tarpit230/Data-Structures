// Given an array arr[], the task is to find the subarray that has the maximum sum and return its sum.

#include<bits/stdc++.h>

using namespace std;

class Solution {
    public: 
    int BruteForceApproach(vector<int> arr, int size) {
        int res = arr[0];
        for(int i=0; i<size; i++) {
            int currSum = 0;
            for(int j=i; j<size; j++) {
                currSum = currSum + arr[j];
                res = max(res, currSum);
            }
        }
        return res;
    }
};

int main() {
    // vector<int> arr = {2, 3, -8, 7, -1, 2, 3};
    // vector<int> arr = {-2, -4};
    vector<int> arr = {5, 4, 1, 7, 8};
    int size = arr.size();
    
    Solution obj;
    cout<< obj.BruteForceApproach(arr, size);

    return 0;
}