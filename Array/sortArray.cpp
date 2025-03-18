#include<bits/stdc++.h>

using namespace std;

class Solution {
    public:
     void BruteForceApproach(vector<int> arr) {
        sort(arr.begin(), arr.end());
        for(int num : arr) {
            cout<< num << " ";
        }
     }

     void BetterApproach(vector<int> arr) {
        int c0=0, c1=0, c2=0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == 0) c0++;
            if(arr[i] == 1) c1++;
            if(arr[i] == 2) c2++;
        }
        int index=0;
        for(int i=0; i<c0; i++) arr[index++] = 0;
        for(int i=0; i<c1; i++) arr[index++] = 1;
        for(int i=0; i<c2; i++) arr[index++] = 2;

        for(int num : arr) {
            cout<< num << " ";
        }
     }
};

int main() {
    vector<int> arr = {0,1,2,0,1,2};

    Solution obj;
    obj.BetterApproach(arr);

    return 0;
}