#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
int down[maxn][2], up[maxn][2];
map<int, int, greater<>> occ;

//#define DEBUG
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    if (n == 2) {
        cout << 0 << "\n";
        return 0;
    }
    int cur = 0;
    bool state = true; // true = down, false = up
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i - 1]) {
            if (state) {
                ++cur;
            } else {
                cur = 1;
                state = true;
            }
            down[i][0] = cur;
        } else {
            if (state) {
                ++occ[down[i - 1][0]];
            }
            state = false;
            cur = 1;
        }
    }
    ++occ[down[n - 1][0]];
    cur = 0, state = true;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] > a[i + 1]) {
            if (state) {
                ++cur;
            } else {
                cur = 1;
                state = true;
            }
            down[i][1] = cur;
        } else {
            if (state) {
                ++occ[down[i + 1][1]];
            }
            state = false;
            cur = 1;
        }
    }
    ++occ[down[0][1]];
//    for (int i = 0; i < n; ++i) {
//        cout << down[i][0] << " " << down[i][1] << " " << up[i][0] << " " << up[i][1] << "\n";
//    }
//    cout << occ.begin()->first << " " << occ.begin()->second << "\n";
    int val = occ.begin()->first;
    if (occ.begin()->second != 2 || val % 2 == 1) {
        cout << 0 << "\n";
        return 0;
    }
    bool sol = false;
    for (int i = 1; i < n - 1; ++i) {
        if (down[i][0] == down[i][1] && down[i][0] == val) {
            sol = true;
            break;
        }
    }
    cout << sol << "\n";
    return 0;
}
