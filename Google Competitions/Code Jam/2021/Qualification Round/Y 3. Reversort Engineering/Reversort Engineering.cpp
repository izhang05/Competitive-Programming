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

template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

void solve() {
    int n, c;
    cin >> n >> c;
    if (c < n - 1 || c >= (n * (n + 1)) / 2) {
        cout << "IMPOSSIBLE" << "\n";
        return;
    }
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        sol[i] = i + 1;
    }
    int l = 0, r = n - 1;
    for (int i = 1; i < n + 1; ++i) {
        int rev = min(r - l + 1, c - (n - i - 1));
        if (sol[l] == i) {
            reverse(sol.begin() + l, sol.begin() + l + rev);
            --r;
        } else {
            reverse(sol.begin() + r - rev + 1, sol.begin() + r + 1);
            ++l;
        }
        c -= rev;
        if (rev == n - i - 1) {
            break;
        }
    }
    print(sol);
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
