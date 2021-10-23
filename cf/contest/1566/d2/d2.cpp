/* Author: izhang05
 * Time: 09-14-2021 17:17:11
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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n * m);
    map<int, vector<int>> cnt;
    for (int i = 0; i < n * m; ++i) {
        cin >> a[i];
        cnt[a[i]].push_back(i);
    }
    vector<int> sol(n * m);
    int ind = 0;
    for (auto &i : cnt) {
        int num = i.second.size();
        vector<pair<int, int>> cur;
        while (num) {
            int nxt = min(ind + num - 1, m * ((ind / m) + 1) - 1);
            num -= nxt - ind + 1;
            cur.emplace_back(ind, nxt);
            ind = nxt + 1;
        }
        reverse(i.second.begin(), i.second.end());
        reverse(cur.begin(), cur.end());
        int l = 0;
        for (auto &j : cur) {
            for (int k = j.first; k <= j.second; ++k) {
                sol[k] = i.second[l];
                ++l;
            }
        }
    }
    long long res = 0;
    for (int i = 0; i < n; ++i) {
        indexed_set<int> nums;
        for (int j = 0; j < m; ++j) {
            res += nums.order_of_key(sol[i * m + j]);
            nums.insert(sol[i * m + j]);
        }
    }
    cout << res << "\n";
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
