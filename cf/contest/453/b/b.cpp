/* Author: izhang05
 * Time: 06-21-2021 17:26:24
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen(("in" + name + ".txt").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105, p = 16;

int dp[maxn][1 << p], val[maxn][1 << p], pre[maxn][1 << p], f[maxn];

vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
map<int, int> ind;

int factor(int x) {
    if (x == 1) {
        return 0;
    }
    int res = 0;
    if (x % 2 == 0) {
        res += 1 << ind[2];
        while (x % 2 == 0) {
            x /= 2;
        }
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            res += 1 << ind[i];
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        res += 1 << ind[x];
    }
    return res;
}

int main() {
    setIO("1");
    memset(dp, 0x3f, sizeof(dp));
    for (int i = 0; i < p; ++i) {
        ind[primes[i]] = i;
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i < 59; ++i) {
        f[i] = factor(i);
        if (abs(a[0] - i) < dp[0][f[i]]) {
            dp[0][f[i]] = abs(a[0] - i);
            val[0][f[i]] = i;
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int mask = 0; mask < (1 << p); ++mask) {
            int &cur = dp[i][mask];
            for (int j = 1; j < 59; ++j) {
                if ((mask & f[j]) == f[j]) {
                    int trans = mask ^ f[j];
                    if (dp[i - 1][trans] + abs(j - a[i]) < cur) {
                        cur = dp[i - 1][trans] + abs(j - a[i]);
                        val[i][mask] = j;
                        pre[i][mask] = trans;
                    }
                }
            }
        }
    }
    pair<int, int> best{inf, 0};
    for (int i = 0; i < (1 << p); ++i) {
        best = min(best, {dp[n - 1][i], i});
    }
    vector<int> sol(n);
    int cur = best.second;
    for (int i = n - 1; i >= 0; --i) {
        sol[i] = val[i][cur];
        cur = pre[i][cur];
    }
    print(sol);
    return 0;
}
