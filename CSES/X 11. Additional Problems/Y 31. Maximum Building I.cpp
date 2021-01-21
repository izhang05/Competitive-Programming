#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    //freopen("solution.out", "w", stdout);
    freopen("Y 31.in", "r", stdin);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
set<int> trees[maxn]; // trees in column[i]

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    char c;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> c;
            if (c == '*') {
                trees[j].insert(i);
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        trees[i].insert(n);
    }
    int sol = 0;
    for (int row = 0; row < n; ++row) {
        stack<pair<int, int>> st;
        for (int col = 0; col < m; ++col) {
            int start = col, dist = *trees[col].lower_bound(row) - row;
            while (!st.empty() && st.top().second >= dist) {
                pair<int, int> cur = st.top();
                st.pop();
                start = cur.first;
                sol = max(sol, (col - cur.first) * cur.second);
            }
            st.push({start, dist});
        }
        while (!st.empty()) {
            pair<int, int> cur = st.top();
            st.pop();
            sol = max(sol, (m - cur.first) * cur.second);
        }
    }
    cout << sol << "\n";
    return 0;
}
