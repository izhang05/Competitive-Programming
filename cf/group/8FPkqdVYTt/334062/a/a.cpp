/* Author: izhang05
 * Time: 07-10-2021 14:30:03
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    setIO("mincross");
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        --b[i];
    }
    unsigned long long sol = 4e18;
    for (int _ = 0; _ < 2; ++_) {
        vector<int> occ(n);
        for (int i = 0; i < n; ++i) {
            occ[a[i]] = i;
        }
        indexed_set<int> cows;
        unsigned long long cur = 0;
        for (int i = 0; i < n; ++i) {
            cur += cows.size() - cows.order_of_key(occ[b[i]]);
            cows.insert(occ[b[i]]);
        }
        sol = min(cur, sol);
        for (int i = n - 1; i >= 0; --i) {
            cur -= n - occ[b[i]] - 1;
            cur += occ[b[i]];
            sol = min(sol, cur);
        }
        swap(a, b);
    }
    cout << sol << "\n";
    return 0;
}
