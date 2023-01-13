#include <bits/stdc++.h>

using namespace std;

bool odd(int num) {
    while (num > 0) {
        if ((num % 10) % 2 == 0) {
            return false;
        }
        num /= 10;
    }
    return true;
}

int reverse(int num) {
    int res = 0;
    while (num > 0) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }
    return res;
}

int main() {
    int n = 1e9, sol = 0;
    for (int i = 0; i < n; ++i) {
        if (i % 10 == 0) {
            continue;
        }
        sol += odd(i + reverse(i));
    }
    cout << sol << "\n";
    return 0;
}
