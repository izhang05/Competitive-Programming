#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e8;
bool prime[maxn];

long long reverse(long long num) {
    long long res = 0;
    while (num > 0) {
        res *= 10;
        res += num % 10;
        num /= 10;
    }
    return res;
}

int main() {
    set<long long> ps;
    memset(prime, true, sizeof(prime));
    prime[0] = prime[1] = false;
    for (int i = 2; i < maxn; ++i) {
        if (prime[i]) {
            for (int j = i + i; j < maxn; j += i) {
                prime[j] = false;
            }
            long long cur = (long long) i * i;
            if (reverse(cur) != cur) {
                ps.insert(cur);
            }
        }
    }
    int cnt = 0;
    long long sol = 0;
    for (auto &i: ps) {
        if (ps.find(reverse(i)) != ps.end()) {
            sol += i;
            if (++cnt == 50) {
                break;
            }
        }
    }
    cout << cnt << "\n";
    cout << sol << "\n";
    return 0;
}
