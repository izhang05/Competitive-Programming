/* Author: izhang05
 * Time: 08-26-2021 10:35:03
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

bool is_prime(long long x) {
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (long long i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> occ;
    for (int i = 0; i < n; ++i) {
        ++occ[s[i]];
        if (s[i] == '4' || s[i] == '6' || s[i] == '8' || s[i] == '1' || s[i] == '9') {
            cout << 1 << "\n";
            cout << s[i] << "\n";
            return;
        }
    }
    for (auto &i : occ) {
        if (i.second > 1) {
            cout << 2 << "\n";
            cout << i.first << i.first << "\n";
            return;
        }
    }
    pair<int, long long> sol{inf, 0};
    for (long long i = 0; i < (1 << n); ++i) {
        long long cur = 0, len = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                cur *= 10;
                cur += s[j] - '0';
                ++len;
            }
        }
        if (len && !is_prime(cur)) {
            sol = min(sol, {len, cur});
        }
    }
    cout << sol.first << "\n";
    cout << sol.second << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
