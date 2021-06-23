#include <bits/stdc++.h>

using namespace std;

const int maxn = 15;
const long double eps = 1e-3, inf = 1e18;
long double dp[1 << maxn][maxn], p[maxn]; // p[i] = pow(m,i)

struct mouse {
    long double x, y, s;
};

long double dist(mouse a, mouse b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int n;
long double m;
vector<mouse> a;
mouse orig = {0, 0, 0};
bool check(long double v) {
    for (auto &i : dp) {
        for (long double &j : i) {
            j = inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        long double time = dist(orig, a[i]) / v;
        if (time <= a[i].s) {
            dp[1 << i][i] = time;
        }
    }
    for (int mask = 1; mask < (1 << n); ++mask) {
        int num_mice = __builtin_popcount(mask) - 1;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                int pre = mask ^ (1 << i);
                for (int j = 0; j < n; ++j) {
                    if (pre & (1 << j)) {
                        long double cur_v = v * p[num_mice], time = dp[pre][j] + dist(a[j], a[i]) / cur_v;
                        if (dp[pre][j] != inf && time <= a[i].s) {
                            dp[mask][i] = min(dp[mask][i], time);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dp[(1 << n) - 1][i] != inf) {
            return true;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y >> a[i].s;
    }
    cin >> m;
    p[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        p[i] = p[i - 1] * m;
    }
    long double l = 0, r = 1e9;
    while (r - l > eps) {
        long double mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << fixed << setprecision(16) << l << "\n";
    return 0;
}
