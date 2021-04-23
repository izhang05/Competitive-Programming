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

long long a[2][2], b[2][2], tmp[2][2];

void eval(bool sol = false) {
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (sol) {
                    tmp[i][k] += b[i][j] * a[j][k];
                } else {
                    tmp[i][k] += a[i][j] * a[j][k];
                }
                tmp[i][k] %= mod;
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (sol) {
                b[i][j] = tmp[i][j];
            } else {
                a[i][j] = tmp[i][j];
            }
            tmp[i][j] = 0;
        }
    }
}


int main() {
    setIO("1");
    long long n;
    cin >> n;
    a[0][0] = 19;
    a[0][1] = 7;
    a[1][0] = 6;
    a[1][1] = 20;

    b[0][0] = 1;
    while (n) {
        if (n % 2) {
            eval(true);
        }
        eval();
        n >>= 1;
    }
#ifdef DEBUG
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cout << b[i][j] << " ";
        }
        cout << "\n";
    }
#endif
    cout << b[0][0] << "\n";
    return 0;
}
