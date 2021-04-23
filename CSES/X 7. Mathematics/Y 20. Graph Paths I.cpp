#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;

struct matrix {
    long long a[maxn][maxn];

    matrix operator*(matrix other) {
        matrix product{{{0, 0}, {0, 0}}};
        for (int i = 0; i < maxn; ++i) {
            for (int j = 0; j < maxn; ++j) {
                for (int k = 0; k < maxn; ++k) {
                    product.a[i][k] += a[i][j] * other.a[j][k];
                    product.a[i][k] %= mod;
                }
            }
        }
        return product;
    }
};

int main() {
    setIO("20");

    int n, m, k;
    cin >> n >> m >> k;
    matrix a{}, sol{};
    for (int i = 0; i < n; ++i) {
        sol.a[i][i] = 1;
    }
    for (int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        ++a.a[b][c];
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a.a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    while (k) {
        if (k % 2) {
            sol = sol * a;
        }
        a = a * a;
        k >>= 1;
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << a.a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout <<sol.a[i][j] << " ";
        }
        cout << "\n";
    }
#endif
    cout << sol.a[0][n - 1] << "\n";
    return 0;
}
