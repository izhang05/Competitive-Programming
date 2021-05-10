#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 20000;

int parent[2 * maxn], grid[2][maxn], ind[2 * maxn];

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (xroot != yroot) {
        parent[xroot] = yroot;
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < 2 * m; ++i) {
        parent[i] = i;
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
#ifdef DEBUG
        for (int j = 0; j < m; ++j) {
          cout << parent[j] << " ";
        }
        cout << "\n";
#endif
        for (int j = 0; j < m / 4; ++j) {
            char c;
            cin >> c;
            int a = (c >= 'A') ? (c - 'A' + 10) : (c - '0');
            for (int k = 0; k < 4; ++k) {
                bool cur = a & (1 << k);
                int col = 4 * j + 4 - k - 1;
                grid[i % 2][col] = cur;
            }
            for (int k = j * 4; k < j * 4 + 4; ++k) {
                bool cur = grid[i % 2][k];
                if (cur) {
                    ++sol;
                    if (grid[(i + 1) % 2][k]) {
                        if (merge(k, k + m)) {
                            --sol;
                        }
                    }
                    if (k > 0 && grid[i % 2][k - 1]) {
                        if (merge(k + m - 1, k + m)) {
                            --sol;
                        }
                    }
                }
#ifdef DEBUG
                cout << i << " " << k << " " << sol << "\n";
#endif
            }
        }
        for (int j = 0; j < 2 * m; ++j) {
            get(j);
            ind[j] = -1;
        }
#ifdef DEBUG
        for (int j = m; j < 2*m; ++j) {
          cout << parent[j] << " ";
        }
        cout << "\n";
#endif
        for (int j = m; j < 2 * m; ++j) {
            if (ind[parent[j]] == -1) {
                ind[parent[j]] = j - m;
            }
            parent[j - m] = ind[parent[j]];
            parent[j] = j;
        }
    }
    cout << sol << "\n";
    return 0;
}
