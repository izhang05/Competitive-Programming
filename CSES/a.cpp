#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

long long md(long long a, long long p) {
    return (a % p + p) % p;
}

int main() {
    setIO("1");

    long long n, p, k;
    cin >> n >> p >> k;
    map<long long, long long> cnt;
    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;
        ++cnt[md(((a * a) % p) * ((a * a) % p) - a * k, p)];
    }
    long long sol = 0;
    for (auto &i : cnt) {
        sol += ((i.second) * (i.second - 1)) / 2;
    }
    cout << sol << "\n";
    return 0;
}
