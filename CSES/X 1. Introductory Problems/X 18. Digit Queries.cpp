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
int solve(int d, long long l, long long sol) {
    for (int i = 2; i < 10; ++i) {

    }
}

int main() {
    setIO("18");
    int t;
    cin >> t;
    while (t--) {
        cin >> x;
        int d = 1;
        long long cnt = 0;
        if (x > cnt + d * 9 * (long long) pow(10, d)) {
            cnt += d * 9 * (long long) pow(10, d);
            ++d;
        }
        cout << solve(d, cnt, 0) << "\n";
    }
    return 0;
}
