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
const long long inf = 4e18;

int n;


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
                    if (a[i][j] != inf && other.a[j][k] != inf) {
                        product.a[i][k] = min(product.a[i][k], a[i][j] + other.a[j][k]);
                    }
                }
            }
        }
        return product;
    }
};

int main() {
    setIO("1");
    int m, k;
    cin >> n >> m >> k;
    matrix a{}, sol{};
    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            a.a[i][j] = inf;
            sol.a[i][j] = inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        sol.a[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int b, c;
        long long d;
        cin >> b >> c >> d;
        --b, --c;
        a.a[b][c] = d;
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
    long long s = inf;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s = min(s, sol.a[i][j]);
        }
    }
    if (s != inf) {
        cout << s << "\n";
    } else {
        cout << "IMPOSSIBLE" << "\n";
    }
    return 0;
}
