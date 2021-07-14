/* Author: izhang05
 * Time: 07-13-2021 23:21:32
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

int solve(const vector<int> &a) {
    pair<int, int> cnt{inf, 0};
    for (auto &i : a) {
        if (i == cnt.first) {
            ++cnt.second;
        } else if (i < cnt.first) {
            cnt.first = i;
            cnt.second = 1;
        }
    }
    int sub = cnt.first, sol = sub;
    vector<int> b;
    for (auto &i : a) {
        int cur = i - sub;
        if (cur) {
            b.push_back(cur);
        } else if (!b.empty()) {
            sol += solve(b);
            b.clear();
        }
    }
    if (!b.empty()) {
        sol += solve(b);
    }
    return min(sol, int(a.size()));
}

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(a) << "\n";
    return 0;
}
