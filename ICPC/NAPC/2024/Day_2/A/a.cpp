#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> sol;
    multiset<pair<int, pair<int, int>>> nodes; // val, tree_index, num_left
    int next = 0;
    for (int i = 0; i < n; ++i) {
        auto it = nodes.lower_bound({a[i] + 1, {-1, -1}});
        if (it == nodes.begin()) {
            sol.push_back(vector<int>{i + 1});
            nodes.insert({a[i], {next++, 2}});
        } else {
            it = prev(it);
            pair<int, pair<int, int>> cur = *it;
            nodes.erase(it);
            sol[cur.second.first].push_back(i + 1);
            nodes.insert({a[i], {cur.second.first, 2}});
            if (cur.second.second == 2) {
                nodes.insert({cur.first, {cur.second.first, 1}});
            }
        }
    }

    cout << sol.size() << "\n";
    for (auto &i: sol) {
        cout << i.size();
        for (auto &j: i) {
            cout << " " << j;
        }
        cout << "\n";
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}