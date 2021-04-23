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

const int maxn = 105;
const long long inf = 3e18;

struct matrix {
    long long a[maxn][maxn];

    matrix operator*(matrix other) {
        matrix product{};
        for (auto &i : product.a) {
            for (long long &j : i) {
                j = inf;
            }
        }
        for (int i = 0; i < maxn; ++i) {
            for (int j = 0; j < maxn; ++j) {
                for (int k = 0; k < maxn; ++k) {
                    if (a[i][j] > 0 && other.a[j][k] > 0) {
                        product.a[i][k] = min(product.a[i][k], a[i][j] + other.a[j][k]);
                    }
                }
            }
        }
        for (auto &i : product.a) {
            for (long long &j : i) {
                if (j == inf) {
                    j = 0;
                }
            }
        }
        return product;
    }
};

int main() {
    setIO("21");

    int n, m, k;
    cin >> n >> m >> k;
    matrix a{}, sol{};
    sol.a[0][0] = 1;
//    for (int i = 0; i < n; ++i) {
//        sol.a[i][i] = 1;
//    }
    for (int i = 0; i < m; ++i) {
        int b, c;
        long long d;
        cin >> b >> c >> d;
        --b, --c;
        if (a.a[b][c] == 0) {
            a.a[b][c] = d;
        } else {
            a.a[b][c] = min(a.a[b][c], d);
        }
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
    cout << sol.a[0][n - 1] - 1 << "\n";
    return 0;
}
