// Given an array of integers arr[], the task is to move all the zeros 
// to the end of the array while maintaining the relative order of all non-zero elements.

#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:

    void BruteForceApproach(vector<int> arr, int size) {
        vector<int> temp(size);
        int j=0;
        for(int i=0; i<size; i++){
            if(arr[i] != 0){
                temp[j++] = arr[i];
            }
        }
        while(j<size){
            temp[j++] = 0;
        }
        for(int i=0; i<size; i++) {
            arr[i] = temp[i];
        }
        for(int num : arr){
            cout<< num << " ";
        }
    }
};

int main() {
    vector<int> arr = {1, 2, 0, 4, 3, 0, 5, 0};
    int size = arr.size();
    
    Solution obj;
    obj.BruteForceApproach(arr, size);

    return 0;
}