#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e5 + 5;
bool dp[maxn], t[2 * maxn];
int n;

bool calc(bool a, bool b) {
    return a | b;
}

void build() {
    for (int i = n - 1; i > 0; --i) {
        t[i] = calc(t[2 * i], t[2 * i + 1]);
    }
}

void update(int p, bool val) {
    for (t[p += n] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]); // p ^ 1 is the other child for node p / 2
    }
}

bool query(int l, int r) { // [l, r)
    if (l < 0) {
        return false;
    }
    bool res = false;
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
    setIO("1");
    int k, d;
    cin >> n >> k >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int i = k - 1;
    for (; i < n && a[0] + d >= a[i]; ++i) {
        dp[i] = true;
        update(i, dp[i]);
    }
    for (; i < n; ++i) {
#ifdef DEBUG
        cout << i << " " << max(0, int(lower_bound(a.begin(), a.end(), a[i] - d) - a.begin()) - 1) << " " << i - k + 1 << "\n";
#endif
        dp[i] = query(max(0, int(lower_bound(a.begin(), a.end(), a[i] - d) - a.begin()) - 1), i - k + 1);
        update(i, dp[i]);
    }
#ifdef DEBUG
    for (int j = 0; j < n; ++j) {
        cout << dp[j] << " ";
    }
    cout << "\n";
#endif
    cout << (dp[n - 1] ? "YES" : "NO") << "\n";
    return 0;
}
