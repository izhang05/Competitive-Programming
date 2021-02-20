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
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("6.in", "r", stdin);
    freopen("6.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

const int maxn = 2e5 + 5; // maximum n
const int MS = 18;        // 18 is calculated by $\log_2 2e5$

int up[MS][maxn];

int jmp(int x, int d) {
    for (int i = 0; i < MS; i++) {
        if ((d >> i) & 1) {
            x = up[i][x];
        }
    }
    return x ?: -1; // modification to return -1 if not found
}

int main() {
    setIO();

    int n, q;
    cin >> n >> q;
    for (int i = 2; i < n + 1; ++i) {
        int a;
        cin >> a;
        up[0][i] = a;
    }

    for (int i = 1; i < MS; ++i) {
        for (int j = 1; j < n + 1; ++j) {
            up[i][j] = up[i - 1][up[i - 1][j]];
        }
    } // construct our parent array

    // uncomment below if you want to see the parent array

    // F0R(i, MS) {
    //	 FOR(j, 1, n+1) {
    //		 cerr << setfill(' ') << setw(2) << up[i][j] << " ";
    //	 }
    //	 cerr << "\n";
    // }

    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << jmp(a, b) << "\n";
    }
}