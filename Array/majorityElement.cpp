// Given an array arr. Find the majority element in the array. If no majority exists, 
// return -1. A majority element in an array is an element that appears strictly more than
// arr.size() / 2 times in the array.

#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
    public:

    int BruteForce(int arr[], int size){
        for(int i=0; i<size; i++){
            int count = 0;
            for(int j=0; j<size; j++){
                if(arr[j] == arr[i]){
                    count++;
                    if(count > size/2) return arr[i];
                }
            }
        }
        return -1;
    }

    int BetterApproach(int arr[], int size){
        unordered_map<int, int> freqMap;
        for(int i=0; i<size; i++){
            freqMap[arr[i]]++;
            if(freqMap[arr[i]] > size/2) return arr[i];
        }
        return -1;
    }
};

int main() {
    int arr[] = {1, 1, 2, 1, 3, 5, 1};
    // int arr[] = {3, 3, 4, 2, 4, 4, 2, 4};
    // int arr[] = {3};
    int size = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    cout<< obj.BetterApproach(arr, size);
}