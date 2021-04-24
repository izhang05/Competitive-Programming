#include <bits/stdc++.h>

using namespace std;

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 505;
int sol[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        int comp = a[i];
        pair<int, int> cur = {i, i};
        sol[i][i] = comp;
        --a[i];
        while (a[i]) {
            if (cur.second > 0) {
                if (!sol[cur.first][cur.second - 1]) {
                    --cur.second;
                    sol[cur.first][cur.second] = comp;
                    --a[i];
                    continue;
                }
            }
            if (cur.first + 1 < n) {
                if (!sol[cur.first + 1][cur.second]) {
                    ++cur.first;
                    sol[cur.first][cur.second] = comp;
                    --a[i];
                    continue;
                }
            }
            cout << -1 << "\n";
            return 0;

        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
