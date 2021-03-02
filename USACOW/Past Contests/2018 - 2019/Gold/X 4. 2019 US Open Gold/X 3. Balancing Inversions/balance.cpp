/*
ID: izhang01
TASK: balance
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("balance.in", "r", stdin);
    freopen("balance.out", "w", stdout);
}
//#define DEBUG

// observations
// swap in same side:
// 01->10 - ++score
// 10->01 - --score
// switch between sides:
// 01->10 l.sc-=l.one, r.sc-=r.zero
// 10->01 --l.one, l.sc+=l.one, --r.zero, r.sc+=r.zero


struct state {
    long long sc{}, zero{}, one{};
    vector<int> loc{};
};

int main() {
    setIO();
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cin >> a[i];
    }
    state l, r;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0) {
            l.sc += l.one;
            ++l.zero;
        } else {
            ++l.one;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (a[n + i] == 0) {
            r.sc += r.one;
            ++r.zero;
        } else {
            ++r.one;
        }
    }

#ifdef DEBUG
    cout << l.sc << " " << l.zero << " " << l.one << "\n";
    cout << r.sc << " " << r.zero << " " << r.one << "\n";
#endif

    int sol = 1e9;
    for (int swaps = 0; swaps < n; ++swaps) {

    }
#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
