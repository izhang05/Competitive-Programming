/* Author: izhang05
 * Time: 10-25-2021 09:28:15
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxa = 505;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> sol;
    vector<set<int>> vals(maxa), used(maxa);
    for (auto &i : vals) {
        i.insert(0);
    }
    sol.insert(0);
    for (int i = 0; i < n; ++i) {
        for (auto &j : vals[a[i]]) {
            for (int k = a[i] + 1; k < maxa; ++k) {
                if (used[k].find(a[i] ^ j) == used[k].end()) {
                    vals[k].insert(a[i] ^ j);
                    sol.insert(a[i] ^ j);
                }
            }
            used[a[i]].insert(j);
        }
        vals[a[i]].clear();
    }

    cout << sol.size() << "\n";
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
