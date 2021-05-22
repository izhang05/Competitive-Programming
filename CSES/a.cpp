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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 20;

pair<int, int> sol[maxn][maxs];

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    pair<int, int> res{a.first + b.first, (a.second + b.second) % 10};
    if (a.second + b.second >= 10) {
        ++res.first;
    }
    return res;
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sol[i][0] = {0, a[i]};
    }
    for (int j = 1; j < maxs; ++j) {
        for (int i = 0; i < n; ++i) {
            if (i + (1 << j) <= n) {
                sol[i][j] = merge(sol[i][j - 1], sol[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << sol[l][__builtin_ctz(r - l + 1)].first << "\n";
    }
    return 0;
}
