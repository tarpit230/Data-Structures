// A digit string is good if the digits (0-indexed) at even indices are even and the digits at 
// odd indices are prime (2, 3, 5, or 7).

#include<bits/stdc++.h>
#define mod 1000000007

using namespace std;

class Solution {
    public:

    long long power(long long x, long long y) {
        if(y == 0) return 1;
        long long ans = power(x, y/2);
        ans = (ans*ans)%mod;
        if(y%2) ans*=x;
        ans%=mod;
        return ans;
    }
    int countGoodNumbers(int n){
        long long even = n/2 + n%2;
        long long odd = n/2;

        return (power(5,even)*power(4, odd))%mod;
    }
};

int main() {
    Solution obj;
    int n = 9;
    cout << obj.countGoodNumbers(n);


    return 0;
}