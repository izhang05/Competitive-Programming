#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("3.in", "r", stdin);
    freopen("3.out", "w", stdout);
    freopen("3.out", "w", stderr);
#endif
}

//#define DEBUG

struct point {
    long long x, y;
    long long operator*(const point &rhs) const {
        return (long long) x * rhs.y - (long long) y * rhs.x;
    }
};


int area(point a, point b, point c) { // 2 * area of triangle [a, b, c]
    return abs(a * b + b * c + c * a);
}

bool in(point a, point b, point c, point d) { // d in triangle [a, b, c]?
    int sum = area(a, b, d) + area(a, c, d) + area(b, c, d);
    return sum == area(a, b, c);
}


const int mod = 1e9 + 7, maxn = 45;

long long dp[maxn][maxn][maxn][maxn];


int main() {
    setIO();
    int n;
    cin >> n;
    vector<point> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                dp[3][i][j][k] = 6;
            }
        }
    }
    for (int i = 3; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    long long cur = dp[i][j][k][l];
                    if (!cur) {
                        continue;
                    }
                    int cnt = 0;
                    for (int m = 0; m < n; ++m) {
                        if (m == j || m == k || m == l) {
                            continue;
                        }
                        if (in(a[j], a[k], a[l], a[m])) {
                            ++cnt;
                        } else {
                            vector<int> order;
                            if (in(a[l], a[j], a[m], a[k])) {
                                order = vector<int>{l, j, m};
                            } else if (in(a[j], a[k], a[m], a[l])) {
                                order = vector<int>{j, k, m};
                            } else if (in(a[k], a[l], a[m], a[j])) {
                                order = vector<int>{k, l, m};
                            }
                            if (!order.empty()) {
                                sort(order.begin(), order.end());
                                dp[i + 1][order[0]][order[1]][order[2]] += cur;
                                dp[i + 1][order[0]][order[1]][order[2]] %= mod;
                            }
                        }
                    }
                    dp[i + 1][j][k][l] += (cnt - (i - 3)) * cur;
                    dp[i + 1][j][k][l] %= mod;
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (dp[n][i][j][k]) {
                    cout << dp[n][i][j][k] << "\n";
                    return 0;
                }
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}
