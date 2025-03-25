// Check if two arrays are equal or not

#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    void BruteForce(int arr1[], int arr2[2], int size){
        sort(arr1, arr1 + size);
        sort(arr2, arr2 + size);
        for(int i=0; i<size; i++){
            if(arr1[i] != arr2[i]){
                cout<< "Both arrays are not Equal!"<< endl;
                return;
            }
        }
        cout<< "Both arrays are equal!";
    }

    bool BetterApproach(int arr1[], int arr2[], int size){
        unordered_map<int, int> mp;
        for(int i=0; i<size; i++){
            mp[arr1[i]]++;
        }
        for(int i=0; i<size; i++){
            if(mp.find(arr2[i]) == mp.end()){
                return false;
            }
            if(mp[arr2[i]] == 0) return false;
            mp[arr2[i]]--;
        }
        return true;
    }
};

int main(){
    int arr1[] = {1, 2, 5, 4, 0};
    int arr2[] = {2, 4, 5, 0, 1};
    int size = sizeof(arr1)/sizeof(arr1[0]);

    Solution obj;
    if(obj.BetterApproach(arr1, arr2, size)){
        cout<< "Both arrays are same.";
    } else cout<< "Both array are unequal.";

    return 0;
}