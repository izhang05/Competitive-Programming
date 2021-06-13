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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 4e5 + 5;
vector<char> grid[maxn];
set<int> sand[maxn];
set<int> no_sand[maxn];
int farthest[maxn], taken[maxn], n, m;

void drop(int x, int pos) {
    //    cout << x << " " << pos << "\n";
    if (taken[x]) {
        return;
    }
    if (farthest[x] <= pos) {
        taken[x] = true;
        pos = *prev(sand[x].end());
    } else {
        pos = *no_sand[x].lower_bound(pos) - 1;
    }
    if (x > 0) {
        if (!taken[x - 1]) {
            auto it = sand[x - 1].upper_bound(pos);
            if (it != sand[x - 1].begin()) {
                int val = *prev(it);
                drop(x - 1, val);
            }
        }
    }
    if (x < m - 1) {
        if (!taken[x + 1]) {
            auto it = sand[x + 1].upper_bound(pos);
            if (it != sand[x + 1].begin()) {
                int val = *prev(it);
                drop(x + 1, val);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        grid[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            int cur = n - i - 1;
            if (grid[i][j] == '#') {
                if (sand[j].empty()) {
                    farthest[j] = cur;
                } else {
                    if (farthest[j] == cur + 1) {
                        farthest[j] = cur;
                    }
                }
                sand[j].insert(cur);
            } else {
                no_sand[j].insert(cur);
            }
        }
    }
    vector<int> a(m);
    vector<pair<int, pair<int, int>>> highest;
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        if (a[i]) {
            highest.push_back({farthest[i], {*prev(sand[i].end()), i}});
        } else {
            taken[i] = true;
        }
    }
    sort(highest.begin(), highest.end());
    reverse(highest.begin(), highest.end());
    int sol = 0;
    for (auto &i : highest) {
        //        cout << i.second.second << " " << i.first << "\n";
        if (taken[i.second.second]) {
            continue;
        }
        //        cout << "drop: " << i.second.second << " " << i.first << "\n";
        drop(i.second.second, i.first);
        //        cout << "\n";
        taken[i.second.second] = true;
        ++sol;
    }
    cout << sol << "\n";

    return 0;
}

