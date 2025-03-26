// Given an integer array, the task is to find the maximum product of any subarray.

#include<iostream>
#include <algorithm>

using namespace std;

class Solution {
    public:
    int BruteForce(int arr[], int size){
        int maxProduct = INT_MIN;
        for(int i=0; i<size; i++){
            int product = 1;
            for(int j=i; j<size; j++){
                product *= arr[j];
                maxProduct = max(maxProduct, product);
            }
        }
        return maxProduct;
    }

    int optimalApproach(int arr[], int size){
        int currMax = arr[0];
        int currMin = arr[0];
        int maxProd = arr[0];
        for(int i=1; i<size; i++){
            int temp = max({arr[i], currMax * arr[i], currMin * arr[i]});
            currMin = min({arr[i], currMax * arr[i], currMin * arr[i]});
            currMax = temp;
            maxProd = max(maxProd, currMax);
        }
        return maxProd;
    }
};

int main(){
    int arr[] = {-2, 6, -3, -10, 0, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    cout<< obj.optimalApproach(arr, size);
}