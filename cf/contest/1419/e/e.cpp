/* Author: izhang05
 * Time: 09-09-2021 10:03:34
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
map<int, int> factor(int x) {
    map<int, int> res;
    while (x % 2 == 0) {
        ++res[2];
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        while (x % i == 0) {
            ++res[i];
            x /= i;
        }
    }
    if (x > 1) {
        ++res[x];
    }
    return res;
}
int m;
vector<pair<int, int>> f;

void gen(int mask, int i, long long val) {
    if (i == m) {
        cout << val << " ";
        return;
    }
    if (!(mask & (1 << i))) {
        gen(mask, i + 1, val);
        return;
    }
    for (int j = 1; j <= f[i].second; ++j) {
        val *= f[i].first;
        gen(mask, i + 1, val);
    }
}

void solve() {
    int n;
    cin >> n;
    map<int, int> tmp = factor(n);
    f = vector<pair<int, int>>(tmp.begin(), tmp.end());
    m = int(f.size());
    vector<string> sol{"0", "1"};
    sol.resize(1 << m);
    for (int i = 2; i <= m; ++i) {
        for (int j = 1 << (i - 1); j < (1 << i); ++j) {
            sol[j] = sol[(1 << i) - j - 1];
            sol[j].push_back('1');
            sol[(1 << i) - j - 1].push_back('0');
        }
    }
    sol.erase(sol.begin());
    if (m == 1) {
        gen(1, 0, 1);
        cout << "\n";
        cout << 0 << "\n";
    } else if (m == 2) {
        if (f[0].second == 1 && f[1].second == 1) {
            cout << f[0].first << " " << f[0].first * f[1].first << " " << f[1].first << "\n";
            cout << 1 << "\n";
        } else {
            if (f[0].second == 1) {
                swap(f[0], f[1]);
            }
            long long cur = 1;
            for (int i = 1; i <= f[0].second; ++i) {
                cur *= f[0].first;
                cout << " " << cur;
            }
            cout << " " << f[0].first * f[1].first;
            cur = 1;
            for (int i = 1; i <= f[1].second; ++i) {
                cur *= f[1].first;
                cout << " " << cur;
            }
            cur = 1;
            for (int i = 1; i <= f[0].second; ++i) {
                cur *= f[0].first;
                long long orig = cur;
                for (int j = 1; j <= f[1].second; ++j) {
                    cur *= f[1].first;
                    if (i != 1 || j != 1) {
                        cout << " " << cur;
                    }
                }
                cur = orig;
            }
            cout << "\n";
            cout << 0 << "\n";
        }
    } else {
        swap(sol[int(sol.size()) - 2], sol[int(sol.size()) - 1]);
        for (auto &i : sol) {
            int cur = 0;
            for (int j = 0; j < m; ++j) {
                if (i[j] == '1') {
                    cur |= 1 << j;
                }
            }
            gen(cur, 0, 1);
        }
        cout << "\n";
        cout << 0 << "\n";
    }
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
