#include <bits/stdc++.h>

using namespace std;

#define int unsigned long long
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

pair<int, int> mina(int a, int b) {
#ifdef DEBUG
    cout << "Starting: " << a << " " << b << "\n";
#endif
    int da = 0, db = 0, tmp = a;
    while (tmp) {
        ++da;
        tmp /= 10;
    }

    vector<int> vb;
    tmp = b;
    while (tmp) {
        vb.push_back(tmp % 10);
        ++db;
        tmp /= 10;
    }
    reverse(vb.begin(), vb.end());
    pair<int, int> sol;
    tmp = a;
    for (int i = da; i < db; ++i) {
        tmp *= 10;
    }
#ifdef DEBUG
    cout << tmp << "\n";
#endif
    if (tmp >= b) {
        return {db - da, tmp};
    }
    sol = {db - da + 1, tmp * 10};
    tmp = a;
    for (int i = da; i < db; ++i) {
        tmp *= 10;
        tmp += vb[i];
    }
#ifdef DEBUG
    cout << tmp << "\n";
#endif
    if (tmp >= b) {
        return {db - da, tmp};
    }
#ifdef DEBUG
    cout << sol.first << " " << sol.second << "\n";
#endif
    return sol;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] < a[i - 1] + 1) {
            pair<int, int> cur = mina(a[i], a[i - 1] + 1);
            sol += cur.first;
            a[i] = cur.second;
        }
    }
    cout << sol << "\n";
}

signed main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
