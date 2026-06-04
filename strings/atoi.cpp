
#include <bits/stdc++.h>
using namespace std;

class Example {
public:
    long long atoi(const string &s) {
        if (s.empty()) return 0;
        int n = s.length();
        int i = 0;
        while (i < n && s[i] == ' ') {
            i++;
        }

        long long MAX_INT = INT_MAX;
        long long MIN_INT = INT_MIN;
        int sign = 1;
        if (i < n && s[i] == '+') {
            i++;
        } else if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }

        long long res = 0;
        while (i < n && isdigit(static_cast<unsigned char>(s[i]))) {
            int digit = s[i] - '0';
            res = (res * 10) + digit;

            if (res * sign > MAX_INT) return MAX_INT;
            if (res * sign < MIN_INT) return MIN_INT;
            i++;
        }
        return res * sign;
    }
};

int main() {
    Example obj;
    string str = " -042";
    cout << obj.atoi(str);
    return 0;
}
