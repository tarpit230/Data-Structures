#include <bits/stdc++.h>

using namespace std;
double myPow(double x, int n)
{
    // Iterative Approach
    // double result = 1.0;
    // if (n < 0)
    // {
    //     int modifiedN = -n;
    //     result = 1 / myPow(x, modifiedN);
    // }

    // while (n > 0)
    // {
    //     result *= x;
    //     n--;
    // }
    // return result;

    // Better Approach
    if (n == 0)
        return 1.0;

    long power = n; // to handle Integer.MIN_VALUE
    if (power < 0)
    {
        x = 1 / x;
        power = -power;
    }

    double result = 1.0;

    while (power > 0)
    {
        if (power % 2 == 1)
        {
            result *= x;
        }
        x *= x;
        power /= 2;
    }

    return result;
}

int main()
{
    double param1 = 2.00000;
    // int param2 = 2147483647;
    int param2 = 10;
    cout << myPow(param1, param2);

    return 0;
}