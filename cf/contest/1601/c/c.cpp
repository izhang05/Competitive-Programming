/* Author: izhang05
 * Time: 10-27-2021 13:56:36
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

struct query {
    int l, r, tl, tr;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    queue<query> q;
    q.push({0, m - 1, 0, n});
    vector<vector<int>> add(n + 1);
    while (!q.empty()) {
        query cur = q.front();
        q.pop();
        if (cur.r < cur.l) {
            continue;
        }
        int ind = (cur.l + cur.r) / 2;
        vector<int> inv(cur.tr - cur.tl + 1);
        int cnt = 0;
        for (int i = cur.tl; i <= cur.tr; ++i) {
            inv[i - cur.tl] += cnt;
            if (i != cur.tr && a[i] > b[ind]) {
                ++cnt;
            }
        }
        cnt = 0;
        for (int i = cur.tr; i >= cur.tl; --i) {
            inv[i - cur.tl] += cnt;
            if (i != cur.tl && a[i - 1] < b[ind]) {
                ++cnt;
            }
        }
        pair<long long, int> mn = {INFL, -1};
        for (int i = 0; i < cur.tr - cur.tl + 1; ++i) {
            mn = min(mn, {inv[i], i + cur.tl});
        }
        add[mn.second].push_back(b[ind]);
#ifdef DEBUG
        cout << ind << " " << cur.l << " " << cur.r << " " << cur.tl << " " << cur.tr << " " << mn.first << endl;
#endif
        q.push({cur.l, ind - 1, cur.tl, mn.second});
        q.push({ind + 1, cur.r, mn.second, cur.tr});
    }
    vector<int> c;
    for (int i = 0; i <= n; ++i) {
        sort(add[i].begin(), add[i].end());
        for (auto &j : add[i]) {
            c.push_back(j);
        }
        if (i != n) {
            c.push_back(a[i]);
        }
    }
    long long sol = 0;
    indexed_set<pair<int, int>> prev;
    for (int i = 0; i < int(c.size()); ++i) {
        sol += prev.size() - prev.order_of_key({c[i], inf});
        prev.insert({c[i], i});
    }
    cout << sol << "\n";
}

int main() {
    setIO("2");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
