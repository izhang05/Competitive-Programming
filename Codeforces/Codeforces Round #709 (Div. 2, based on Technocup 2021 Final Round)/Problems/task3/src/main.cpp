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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> day(m, vector<int>());
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        day[i].resize(k);
        for (int j = 0; j < k; ++j) {
            cin >> day[i][j];
            --day[i][j];
        }
    }
    unordered_set<int> erase;
    while (true) {
        vector<int> occ(n);
        int cur = 0;
        for (int i = 0; i < m; ++i) {
            if (erase.find(i) == erase.end()) {
                for (auto j : day[i]) {
                    ++occ[j];
                }
            }
        }
        unordered_set<int> small;
        for (int i = 0; i < n; ++i) {
            if (occ[i] < (m + 1) / 2) {
                small.insert(i);
            }
        }
        vector<int> sol(n);
        for (int i = 0; i < m; ++i) {
            bool found = false;
            if (erase.find(i) != erase.end()) {
                continue;
            }
            for (auto j : day[i]) {
                if (found) {
                    --occ[j];
                } else if (small.find(j) != small.end()) {
                    ++cur;
                    erase.insert(j);
                    sol[i] = j + 1;
                    found = true;

                }
            }
        }
        int rem = m - (int) erase.size();
        if (rem < (m + 1) / 2) {
            cout << "YES" << "\n";
            for (int i = 0; i < m; ++i) {
                if (erase.find(i) == erase.end()) {
                    sol[i] = day[i][0] + 1;
                }
            }
            print(sol);
            return;
        } else {
            if (cur == 0) {
                break;
            }
        }
    }
    int rem = m - (int) erase.size();

    cout << "NO" << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
