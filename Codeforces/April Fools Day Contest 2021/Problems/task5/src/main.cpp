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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 10;
char grid[maxn][maxn];
int h, w;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            cin >> grid[i][j];
        }
    }
    pair<int, int> pos{0, 0};
    int sol = grid[0][0] == '*';

    while (pos != make_pair(h - 1, w - 1)) {
        pair<int, pair<int, int>> best;
        best.first = inf;
        for (int i = pos.first; i < h; ++i) {
            for (int j = pos.second; j < w; ++j) {
                if (make_pair(i, j) != pos && grid[i][j] == '*') {
                    best = min(best, {i - pos.first + j - pos.second, {i, j}});
                }
            }
        }
        if (best.first == inf) {
            break;
        }
        ++sol;
        pos = best.second;
    }
    cout << sol << "\n";
    return 0;
}
