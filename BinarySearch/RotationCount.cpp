#include<iostream>

using namespace std;

class Solution {
    public:
    int RotationCount(int arr[], int n) {
        int low = 0, high = n - 1;
        while(low < high) {
            int mid = (low + high) / 2;
            if(arr[mid] > arr[high]) {
                low = mid + 1; // Rotation point is in the right half
            } else {
                high = mid; // Rotation point is in the left half or at mid
            }
        }
        return low; // The index of the smallest element, which is the rotation count
    }
};

int main() {
    Solution solution;
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = solution.RotationCount(arr, n);
    cout << "Rotation Count: " << result << endl; // Output: Rotation Count: 4
    return 0;
}