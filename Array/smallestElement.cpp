//  Find the Smallest and Second Smallest Elements in an Array.

#include<iostream>
#include<algorithm>
using namespace std;

class Solution {
    public:
    void BruteForce(int arr[], int size){
        sort(arr, arr + size);
        int smallest = arr[0];
        int secondSmallest;
        for(int i=1; i<size; i++){
            if(arr[i] != smallest) {
                secondSmallest = arr[i];
                break;
            }
        }
        cout<< "smallest: "<<smallest<<endl;
        cout<< "second Smallest: "<<secondSmallest;
    }

    void BetterApproach(int arr[], int size){
        int smallest = arr[0];
        int secondSmallest = smallest;
        for(int i=0; i<size; i++){
            if(arr[i] < smallest){
                secondSmallest = smallest;
                smallest = arr[i];
            } else if(arr[i]>smallest && arr[i] < secondSmallest){
                secondSmallest = arr[i];
            }
        }
        cout<< "Smallest: "<<smallest <<endl;
        cout<< "Second Smallest: "<< secondSmallest;
    }
};

int main(){
    int arr[] = {12, 13, 1, 10, 34, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    Solution obj;
    obj.BetterApproach(arr, size);

    return 0;
}