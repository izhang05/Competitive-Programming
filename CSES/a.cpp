#include <bits/stdc++.h>

using namespace std;

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

    int n, q;
    cin >> n >> q;
    int odd = 0, even = 1;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int a;
            cin >> a;
            odd += a;
            even += a;
        } else {
            if (even % 2 == 1) {
                ++odd;
                --even;
            } else {
                --odd;
                ++even;
            }
        }
        odd %= n, even %= n;
        odd = (odd + n) % n;
        even = (even + n) % n;
    }
    vector<int> sol(n);
    for (int i = 1; i < n; i += 2) {
        sol[odd] = i;
        odd = (odd + 2) % n;
    }
    for (int i = 2; i <= n; i += 2) {
        sol[even] = i;
        even = (even + 2) % n;
    }
    print(sol);
    return 0;
}
