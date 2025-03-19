#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int BruteForce(int arr[],int size) {
        for(int i=0; i<size; i++){
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    return arr[i]; 
                }
            }}
        return -1;
    }
};

int main() {

    int arr[] = {10, 5, 3, 4, 3, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    Solution obj;
    cout<<obj.BruteForce(arr, size);

    return 0;
}