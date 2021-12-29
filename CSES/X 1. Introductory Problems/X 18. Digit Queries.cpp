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

long long x;
long long solve() {
    int d = 1;
    long long cnt = 0;
    while (x >= cnt + d * 9 * (long long) pow(10, d - 1)) {
        cnt += d * 9 * (long long) pow(10, d - 1);
        ++d;
    }
    x -= cnt;
    long long num = (long long) pow(10, d - 1) + x / d;
    for (int i = 0; i < d - (x % d) - 1; ++i) {
        num /= 10;
    }
    return num % 10;
}

int main() {
    setIO("18");
    int t;
    cin >> t;
    while (t--) {
        cin >> x;
        --x;
        cout << solve() << "\n";
    }
    return 0;
}
