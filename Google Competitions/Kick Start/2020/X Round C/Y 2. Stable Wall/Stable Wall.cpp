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
    freopen("1.in", "r", stdin);
#endif
}


void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    unordered_map<char, unordered_set<char>> adj;
    unordered_map<char, int> in;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            in[grid[i][j]] = 0;
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] != grid[i + 1][j]) {
                if (adj[grid[i + 1][j]].find(grid[i][j]) == adj[grid[i + 1][j]].end()) {
                    adj[grid[i + 1][j]].insert(grid[i][j]);
                    ++in[grid[i][j]];
                }
            }
        }

        queue<char> q;
        for (pair<char, int> i : in) {
            if (i.second == 0) {
                q.push(i.first);
            }
        }
        vector<char> sol;
        while (!q.empty()) {
            char cur = q.front();
            sol.push_back(cur);
            q.pop();
            for (char i : adj[cur]) {
                if (--in[i] < 0) {
                    cout << -1 << "\n";
                    return;
                }
                if (in[i] == 0) {
                    q.push(i);
                }
            }
        }
        if (sol.size() == in.size()) {
            for (char c : sol) {
                cout << c;
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    setIO();
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
}
