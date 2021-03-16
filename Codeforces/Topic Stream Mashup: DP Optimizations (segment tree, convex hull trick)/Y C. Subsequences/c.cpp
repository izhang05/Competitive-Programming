#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxk = 15;

long long t[2 * maxn][maxk], dp[maxn][maxk];
int n;

long long calc(long long a, long long b) {
    return a + b;
}


void update(int p, long long val, int k) {
    for (t[p += n][k] = val; p > 1; p /= 2) {
        t[p / 2][k] = calc(t[p][k], t[p ^ 1][k]); // p ^ 1 is the other child for node p / 2
    }
}

long long query(int l, int r, int k) {
    long long res = 0;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++][k]);
        }
        if (r & 1) {
            res = calc(res, t[--r][k]);
        }
    }
    return res;
}

int main() {
    setIO();

    int k;
    cin >> n >> k;
    ++k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    dp[0][1] = 1;
    update(a[0], 1, 1);
    for (int i = 1; i < n; ++i) {
        for (int j = k; j >= 2; --j) {
            dp[i][j] = query(0, a[i], j - 1);
            update(a[i], dp[i][j], j);
        }
        dp[a[i]][1] = 1;
        update(a[i], 1, 1);
    }
#ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < k + 1; ++j) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
#endif
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += dp[i][k];
    }
    cout << sol << "\n";
    return 0;
}
