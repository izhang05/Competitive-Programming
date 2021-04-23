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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

struct matrix {
    long long a[2][2];

    matrix operator*(matrix other) {
        matrix product{{{0, 0}, {0, 0}}};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    product.a[i][k] += a[i][j] * other.a[j][k];
                    product.a[i][k] %= mod;
                }
            }
        }
        return product;
    }
};

int main() {
    setIO("1");
    long long n;
    cin >> n;
    matrix sol{{{1, 0}, {0, 1}}}, a{{{0, 1}, {1, 1}}};
    while (n) {
        if (n % 2) {
            sol = sol * a;
        }
        a = a * a;
        n >>= 1;
    }
    cout << sol.a[0][1] << "\n";
    return 0;
}
