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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    if (n % 2 == 1) {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> a(n);
    set<int> eva, oda;
    for (int i = 1; i <= m; i += 2) {
        oda.insert(i);
    }
    for (int i = 2; i <= m; i += 2) {
        eva.insert(i);
    }

    int even = 0, odd = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            ++even;
            eva.erase(a[i]);
        } else {
            ++odd;
            oda.erase(a[i]);
        }
        ++cnt[a[i]];
    }
    for (int i = 0; i < n; ++i) {

    }
    return 0;
}
