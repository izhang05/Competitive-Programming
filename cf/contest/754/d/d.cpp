/* Author: izhang05
 * Time: 09-09-2021 21:45:43
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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n, k;
vector<pair<pair<int, int>, int>> a;

void gen(int x) {
    indexed_set<pair<int, int>> seen;
    for (int i = 0; i < n; ++i) {
        seen.insert({a[i].first.second, a[i].second});
        while (i + 1 < n && a[i + 1].first.first == a[i].first.first) {
            ++i;
            seen.insert({a[i].first.second, a[i].second});
        }
        while (!seen.empty() && seen.begin()->first < a[i].first.first) {
            seen.erase(seen.begin());
        }
        if (x == i) {
            vector<int> res(k);
            for (int j = 0; j < k; ++j) {
                res[j] = seen.find_by_order(seen.size() - 1 - j)->second + 1;
            }
            sort(res.begin(), res.end());
            for (auto &j : res) {
                cout << j << " ";
            }
            cout << "\n";
            return;
        }
    }
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    indexed_set<pair<int, int>> seen;
    pair<int, int> sol{0, inf};
    for (int i = 0; i < n; ++i) {
        seen.insert({a[i].first.second, a[i].second});
        while (i + 1 < n && a[i + 1].first.first == a[i].first.first) {
            ++i;
            seen.insert({a[i].first.second, a[i].second});
        }
        while (!seen.empty() && seen.begin()->first < a[i].first.first) {
            seen.erase(seen.begin());
        }
        if (int(seen.size()) >= k) {
            sol = max(sol, {seen.find_by_order(seen.size() - k)->first - a[i].first.first + 1, i});
        }
    }
    cout << sol.first << "\n";
    if (sol.second != inf) {
        gen(sol.second);
    } else {
        for (int i = 0; i < k; ++i) {
            cout << i + 1 << " ";
        }
        cout << "\n";
    }
}

int main() {
    setIO("4");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
