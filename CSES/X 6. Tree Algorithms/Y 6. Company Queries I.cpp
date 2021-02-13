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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int maxn = 2e5, maxl = 18;
int p[maxn][maxl];


int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < maxl; ++j) {
            p[i][j] = -1;
        }
    }
    for (int i = 1; i < n; ++i) {
        cin >> p[i][0];
        --p[i][0];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < maxl - 1; ++j) {
            if (p[i][j] == -1) {
                continue;
            }
            p[i][j + 1] = p[p[i][j]][j];
        }
    }
    int a, b;
    for (int i = 0; i < q; ++i) {
        cin >> a >> b;
        --a;
        for (int j = 0; j < maxl; ++j) {
            if (b & (1 << j)) {
                a = p[a][j];
            }
            if (a == -1) {
                break;
            }
        }
        cout << (a == -1 ? a : a + 1) << "\n";
    }
    return 0;
}
