/* Author: izhang05
 * Time: 08-18-2021 10:39:53
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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
#define int long long
vector<int> num;
int k, n, sol;

void solve(vector<int> cur) {
    bool greater = false, pos = true;
    int cur_sol = 0;
    for (int i = 0; i < n; ++i) {
        cur_sol *= 10;
        if (greater) {
            cur_sol += cur[0];
        } else {
            bool found = false;
            for (int j = 0; j < k; ++j) {
                if (num[i] < cur[j]) {
                    cur_sol += cur[j];
                    greater = true;
                    found = true;
                    break;
                } else if (num[i] == cur[j]) {
                    cur_sol += cur[j];
                    found = true;
                    int c = cur_sol - cur[j];
                    auto it = upper_bound(cur.begin(), cur.end(), num[i]);
                    if (it == cur.end()) {
                        continue;
                    }
                    c += *it;
                    for (int l = i + 1; l < n; ++l) {
                        c *= 10;
                        c += cur[0];
                    }
                    sol = min(sol, c);
                    break;
                }
            }
            if (!found) {
                pos = false;
                break;
            }
        }
    }
    //    print(cur);
    //    cout << cur_sol << " " << pos << "\n";
    if (pos) {
        sol = min(sol, cur_sol);
    }
}

void gen(vector<int> cur) {
    if ((cur.size()) == k) {
        solve(cur);
        return;
    }
    for (int i = cur.back() + 1; i <= 10 - k + (cur.size()); ++i) {
        cur.push_back(i);
        gen(cur);
        cur.pop_back();
    }
}

void solve() {
    int tmp;
    cin >> tmp >> k;
    num.clear();
    while (tmp) {
        num.push_back(tmp % 10);
        tmp /= 10;
    }
    reverse(num.begin(), num.end());
    n = (num.size());
    sol = INFL;
    for (int i = 0; i <= 10 - k; ++i) {
        gen(vector<int>{i});
    }
    cout << sol << "\n";
}

signed main() {
    setIO("2");

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
