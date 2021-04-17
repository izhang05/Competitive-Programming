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


int main() {
    setIO("1");

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0, j = 0, used = 0;
    pair<int, int> inter;
    for (int i = 0; i < n; ++i, j = max(j, i)) {
        if (used < 0) {
            used = 0;
        }
        while (j < n) {
            if (used + !a[j] > k) {
                break;
            }
            if (a[j++] == 0) {
                ++used;
            }
        }
        if (j - i > sol) {
            sol = j - i;
            inter = {i, j};
        }
        if (a[i] == 0) {
            --used;
        }
    }
    cout << sol << "\n";
    for (int i = 0; i < inter.first; ++i) {
        cout << a[i] << " ";
    }
    for (int i = inter.first; i < inter.second; ++i) {
        cout << 1 << " ";
    }
    for (int i = inter.second; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
