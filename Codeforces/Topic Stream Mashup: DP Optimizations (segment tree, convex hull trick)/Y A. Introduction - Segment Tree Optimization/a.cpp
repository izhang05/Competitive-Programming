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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
int pre[maxn], n, dp[maxn];
long long t[2 * maxn];

long long calc(long long a, long long b) {
    return min(a, b);
}

void build() {
    for (int i = n - 1; i > 0; --i) {
        t[i] = calc(t[2 * i], t[2 * i + 1]);
    }
}

void update(int p, long long val) {
    for (t[p += n] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]); // p ^ 1 is the other child for node p / 2
    }
}

long long query(int l, int r) {
    long long res = 1e18;
    for (l += n, r += n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++]);
        }
        if (r & 1) {
            res = calc(res, t[--r]);
        }
    }
    return res;
}

int main() {
    setIO();
    cin >> n;
    vector<int> a(n);
    memset(t, 0x3f, sizeof(t));
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < n + 1; ++i) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    vector<pair<int, int>> range(n);
    for (int i = 1; i < n; ++i) {
        cin >> range[i].first >> range[i].second;
        --range[i].first, --range[i].second;
    }
    update(0, 0);
    for (int i = 1; i < n; ++i) {
#ifdef DEBUG
        cout << i << " " << query(range[i].first, range[i].second + 1) << "\n";
#endif
        dp[i] = (int) query(range[i].first, range[i].second + 1) + pre[i + 1];
        update(i, dp[i] - pre[i]);
    }
#ifdef DEBUG
    for (int j = 0; j < 2 * n; ++j) {
        cout << t[j] << "\n";
    }
#endif
    for (int i = 0; i < n; ++i) {
        cout << dp[i] << " ";
    }
    cout << "\n";
    return 0;
}