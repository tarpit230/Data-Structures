#include<bits/stdc++.h>

using namespace std;
double myPow(double x, int n) {
    // Iterative Approach
    double result = 1.0;
    if(n<0) {
        int modifiedN = -n;
        result = 1 / myPow(x, modifiedN);
    }
    
        while(n > 0) {
            result *= x;
            n--;
        }
        return result;
}

int main() {
    double param1 = 1.00000;
    int param2 = 2147483647;
    cout << myPow(param1, param2);

    return 0;
}