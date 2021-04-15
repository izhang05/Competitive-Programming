#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 998244353, maxn = 2e5 + 5;
long long p[maxn];


int main() {
    setIO("1");
    p[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p[i] = (p[i - 1] * 2) % mod;
    }
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> last, cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        last[a[i]] = i;
        ++cnt[a[i]];
    }
    int sol = 0, l = 0;
    for (int i = 0; i < n - 1; ++i) {
        l = max(l, last[a[i]]);
        if (l <= i) {
            ++sol;
        }
    }
    cout << p[sol] << "\n";
    return 0;
}
