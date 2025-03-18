// Given an array nums containing n distinct numbers in the range [0, n], 
// return the only number in the range that is missing from the array.
#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
    public:

    int BruteForceApproach(int arr[], int size) {
        sort(arr, arr + size);
        for(int i=0; i < size + 1; i++){
            if(arr[i] != i) return i;
        }
        return -1;
    }
};

int main () {
    // int arr[] = {9,6,4,2,3,5,7,0,1};
    int arr[] = {3,0,1};
    int size = (sizeof(arr) / sizeof(arr[0]));

    Solution obj;
    cout << obj.BruteForceApproach(arr, size);

    return 0;
}