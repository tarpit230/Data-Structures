// Find all pairs with a given sum in two unsorted arrays

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:

    void BruteForce(int arr1[], int arr2[], int arr1Size, int arr2Size, int target){
        vector<int> result;
        for(int i=0; i<arr1Size; i++){
            for(int j=0; j<arr2Size; j++){
                if(arr1[i] + arr2[j] == target){
                    result.insert(result.end(), {arr1[i], arr2[j]});
                }
            }
        }
        for(int num: result){
            cout<< num << " ";
        }
    }

    int BinarySearch(int arr[], int l, int r, int x){
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (arr[m] == x)
                return m;
            if (arr[m] < x)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }

    void BetterApproach(int arr1[], int arr2[], int arr1Size, int arr2Size, int target){
        sort(arr1, arr1 + arr1Size);
        for(int i=0; i<arr2Size; i++){
            int complement = target - arr2[i];
            if(BinarySearch(arr1, 0, arr1Size-1, complement) != -1){
                cout<< complement << " " << arr2[i] << " ";
            }
        }
    }
};

int main() {
    int arr1[] = {-1, -2, 4, -6, 5, 7};
    int arr2[] = {6, 3, 4, 0};
    int x = 8;

    int arr1Size = sizeof(arr1)/sizeof(arr1[0]);
    int arr2Size = sizeof(arr2)/sizeof(arr2[0]);

    Solution obj;
    // obj.BruteForce(arr1, arr2, arr1Size, arr2Size, x);
    obj.BetterApproach(arr1, arr2, arr1Size, arr2Size, x);

    return 0;
}