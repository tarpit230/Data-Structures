// Given an array of positive integers arr[] of size n, the task is to find 
// second largest distinct element in the array.

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
    public:

    int BruteForceMethod(vector<int> arr, int size) {
        sort(arr.begin(), arr.end());
        for(int i=size-2; i>=0; i--){
            if(arr[i] != arr[size-1]) {
                return arr[i];
            }
        }
        return -1;
    }

    int BetterApproach(vector<int> arr, int size) {
        int largest = -1;
        for(int i=0; i<size; i++) {
            if(arr[i] > largest) {
                largest = arr[i];
            }
        }

        int secondLargest = -1;
        for(int j=0; j<size; j++) {
            if(arr[j] > secondLargest && arr[j] != largest) {
                secondLargest = arr[j];
            }
        }
        return secondLargest;
    }

    int OptimalApproach(vector<int> arr, int size) {
        int largest = -1, secondLargest = -1;
        for(int i=0; i<size; i++) {
            if(arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            } else if(arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }
        return secondLargest;
    }
};

int main() {
    // vector<int> arr = {12, 35, 1, 10, 34, 1};
    // vector<int> arr = {10, 10, 10};
    // vector<int> arr = {10, 5, 10};
    vector<int> arr;
    int num;
    cout<< "Enter the elements: "<< endl;
    for(int i=0; i<6; i++) {
        cin>> num;
        cout << "You entered: " << num << endl;
        arr.push_back(num);
    }
    int size = arr.size();

    Solution secondLargest;
    cout<< "Second Largest: " << secondLargest.OptimalApproach(arr, size);

    return 0;
}