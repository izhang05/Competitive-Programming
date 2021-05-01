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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 50;

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
    setIO("R");

    long long n, k;
    cin >> n >> k;
    matrix a{}, sol{};
    for (int i = 0; i < n; ++i) {
        sol.a[i][i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a.a[i][j];
        }
    }
    while (k) {
        if (k % 2) {
            sol = sol * a;
        }
        a = a * a;
        k >>= 1;
    }
    long long s = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            s += sol.a[i][j];
            s %= mod;
        }
    }
    cout << s << "\n";
    return 0;
}
