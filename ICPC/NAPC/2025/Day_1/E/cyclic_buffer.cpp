#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MAXN = 1000005;
int a[2 * MAXN], inv[MAXN];
int nxt[2][MAXN];
long long dp[2][MAXN];
int n, k;

struct Tree {
    typedef int T;
    T f(T x, T y) { return min(x, y); } // (any associative fn)
    vector<T> s;
    Tree() : s(2 * n, n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e)
        T ra = n, rb = n;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

inline int dist(int x, int y) {
    if (x < 0) x += n; 
    if (y < 0) y += n;
    int d = x - y;
    if (d < 0) d += n;
    return min(d, n - d);
}

void solve() {
    cin >> n >> k;
    int first_out = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        a[i]--; a[n + i] = a[i];
        if (i >= k && (first_out == -1 || a[i] < a[first_out])) {
            first_out = i;
        }
        inv[a[i]] = i;
        dp[0][i] = dp[1][i] = INF;
    }
    if (k >= n) {
        cout << "0\n";
        return;
    }

    Tree t;
    for (int i = n - 1; i >= 0; i--) {
        int l = inv[i];
        int r = inv[i] + k - 1; if (r >= n) r -= n;
        if (l <= r) {
            nxt[0][i] = min(t.query(r + 1, n), t.query(0, l));
        } else {
            nxt[0][i] = t.query(r + 1, l);
        }
        l = inv[i] - k + 1; if (l < 0) l += n;
        r = inv[i];
        if (l <= r) {
            nxt[1][i] = min(t.query(r + 1, n), t.query(0, l));
        } else {
            nxt[1][i] = t.query(r + 1, l);
        }
        t.update(inv[i], i);
    }
    
    // dp[i][0/1] = min cost to visit 0...i and have i as the L/R bound of window
    dp[0][a[first_out]] = dist(0, first_out);
    dp[1][a[first_out]] = dist(0, first_out - k + 1);
    long long res = INF;
    for (int i = 0; i < n; i++) {
        if (nxt[0][i] >= n) {
            res = min(res, dp[0][i]);
        } else {
            dp[0][nxt[0][i]] = min(dp[0][nxt[0][i]], dp[0][i] + dist(inv[i], inv[nxt[0][i]]));
            dp[1][nxt[0][i]] = min(dp[1][nxt[0][i]], dp[0][i] + dist(inv[i], inv[nxt[0][i]] - k + 1));
        }
        if (nxt[1][i] >= n) {
            res = min(res, dp[1][i]);
        } else {
            dp[0][nxt[1][i]] = min(dp[0][nxt[1][i]], dp[1][i] + dist(inv[i] - k + 1, inv[nxt[1][i]]));
            dp[1][nxt[1][i]] = min(dp[1][nxt[1][i]], dp[1][i] + dist(inv[i] - k + 1, inv[nxt[1][i]] - k + 1));
        }
    }
    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}