// Given an array arr[] of size n, the task is to find all the Leaders in the array. 
// An element is a Leader if it is greater than or equal to all the elements to its right side.

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    void BruteForce(int arr[], int size){
        vector<int> result;
        for(int i=0; i<size-1; i++) {
            
            int count = 1; 
            for(int j=i+1; j<size; j++) {
                if(arr[j] > arr[i]){
                    count = 0;
                    break;
                }
            }
            if(count == 1) result.push_back(arr[i]);
        }
        result.push_back(arr[size-1]);
        for(int num: result) {
            cout<< num << " ";
        }
    }
};

int main() {

    // int arr[] = {16, 17, 4, 3, 5, 2};
    int arr[] = {1, 2, 3, 4, 5, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    obj.BruteForce(arr, size);

    return 0;
}