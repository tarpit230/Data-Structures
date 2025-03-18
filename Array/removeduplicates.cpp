#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:

    int BruteForceApproach(vector<int> arr, int size) {
        int j=1;
        for(int i=0; i<size-1; i++) {
            if(arr[i] != arr[i+1]){
                arr[j] = arr[i+1];
                j++;
            }
        }
        return j;
    }
};

int main() {

    vector<int> arr = {1, 1, 2};
    int size = arr.size();

    Solution duplicates;
    cout<< duplicates.BruteForceApproach(arr, size);

    return 0;
}