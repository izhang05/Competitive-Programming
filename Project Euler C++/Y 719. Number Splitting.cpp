#include <bits/stdc++.h>

using namespace std;

bool natural(long long x) {
    long long sq = x * x;
    int n = 1 + (int) log10(sq);
    long long rev = 0;
    while (sq) {
        rev *= 10;
        rev += sq % 10;
        sq /= 10;
    }
    sq = rev;
    for (int i = 0; i < 1 << (n - 1); ++i) {
        long long num = sq, sum = 0, cur = 0;
        for (int j = 0; j < n - 1; ++j) {
            cur *= 10;
            cur += num % 10;
            num /= 10;
            if (i & (1 << j)) {
                sum += cur;
                cur = 0;
            }
        }
        cur *= 10;
        assert(num < 10);
        cur += num;
        sum += cur;
        if (sum == x) {
            return true;
        }
    }
    return false;
}

int main() {
    long long n = 1e12, sol = 0;
    for (long long i = 2; i * i <= n; ++i) {
        if (natural(i)) {
            cout << i << " " << i * i << endl;
            sol += i * i;
        }
    }
    cout << sol << "\n";
}
