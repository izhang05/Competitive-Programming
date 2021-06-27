/* Author: izhang05
 * Time: 06-26-2021 22:22:16
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
//#ifndef TEST
//    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
//#endif
}
const int inf = 1e9;

int main() {
    setIO("");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    for (int i = 30; i >= -30; --i) {
        for (auto &j : a) {
            if (j > i) {
                j = -inf;
            }
        }
        int cur = 0, cur_sol = -inf;
        for (int j = 0; j < n; ++j) {
            cur += a[j];
            cur_sol = max(cur_sol, cur);
            if (cur < 0) {
                cur = 0;
            }
        }
        sol = max(sol, cur_sol - i);
    }
    cout << sol << "\n";
    return 0;
}
