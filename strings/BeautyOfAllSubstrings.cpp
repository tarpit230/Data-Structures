// The beauty of a string is the difference in frequencies between the most frequent and least frequent characters.
// For example, the beauty of "abaacc" is 3 - 1 = 2.
// Given a string s, return the sum of beauty of all of its substrings.

#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
    public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> freq;
            for (int j = i; j < n; j++) {
                freq[s[j]]++;

                int maxFreq = INT_MIN;
                int minFreq = INT_MAX;
                for (auto& pair : freq) {
                    maxFreq = max(maxFreq, pair.second);
                    minFreq = min(minFreq, pair.second);
                }
                sum += (maxFreq - minFreq);
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    string s = "aabcb";
    int result = solution.beautySum(s);
    cout<< "Sum of beauty: " << result;
}