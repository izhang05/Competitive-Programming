#include<bits/stdc++.h>

using namespace std;

#define rep(i, a, b)

map<int, int> m{{1, 1},
                {0, 0},
                {2, 2},
                {5, 5},
                {8, 8},
                {6, 9},
                {9, 6}};

bool is_prime(long long x) {
    if (x == 1) {
        return false;
    }
    for (long long i = 2; i * i <= x; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    long long n;
    cin >> n;
    if (!is_prime(n)) {
        cout << "no" << "\n";
        return 0;
    }
    long long res = 0;
    while (n) {
        int cur = n % 10;
        n /= 10;
        if (m.find(cur) == m.end()) {
            cout << "no" << "\n";
            return 0;
        }
        res *= 10;
        res += m[cur];
    }
//    cout << res << "\n";
    if (!is_prime(res)) {
        cout << "no" << "\n";
        return 0;
    }
    cout << "yes" << "\n";
    return 0;
}