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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 55;
char grid[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int red = -1, white = -1;
        bool pos = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> grid[i][j];
            }
        }
        for (int i = 0; i < n && pos; ++i) {
            for (int j = 0; j < m && pos; ++j) {
                if (grid[i][j] == 'R') {
                    if (red == -1) {
                        red = (i + j) % 2;
                    } else {
                        if ((i + j) % 2 != red) {
                            pos = false;
                        }
                    }
                } else if (grid[i][j] == 'W') {
                    if (white == -1) {
                        white = (i + j) % 2;
                    } else {
                        if ((i + j) % 2 != white) {
                            pos = false;
                        }
                    }
                }
            }
        }
        if (red != -1 && white != -1 && red == white) {
            pos = false;
        }
        if (red == -1 && white == -1) {
            red = 0;
        } else if (white == 1) {
            red = 0;
        } else if (white == 0) {
            red = 1;
        }
        if (!pos) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if ((i + j) % 2 == 0) {
                        if (red == 0) {
                            cout << 'R';
                        } else {
                            cout << 'W';
                        }
                    } else {
                        if (red == 1) {
                            cout << 'R';
                        } else {
                            cout << 'W';
                        }
                    }
                }
                cout << "\n";
            }
        }
    }
    return 0;
}
