#include <bits/stdc++.h>

using namespace std;

bool increasing(long long num) {
    long long cur = num % 10;
    num /= 10;
    while (num) {
        if (num % 10 > cur) {
            return false;
        }
        cur = num % 10;
        num /= 10;
    }
    return true;
}
bool decreasing(long long num) {
    long long cur = num % 10;
    num /= 10;
    while (num) {
        if (num % 10 < cur) {
            return false;
        }
        cur = num % 10;
        num /= 10;
    }
    return true;
}

bool bouncy(long long num) {
    return !increasing(num) && !decreasing(num);
}

int main() {
    int p = 99;
    long long cnt = 0;
    for (long long i = 1;; ++i) {
        cnt += bouncy(i);
        if (i * p == cnt * 100) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
