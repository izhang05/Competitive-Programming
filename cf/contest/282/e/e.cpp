/* Author: izhang05
 * Time: 07-26-2021 02:05:31
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
    freopen("out.txt", "w", stdout);
    freopen("out.txt", "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxs = 40;
int x[maxn * maxs][2], t = 1;

void build(long long s) {
    int v = 0;
    for (long long i = maxs - 1; i >= 0; --i) {
        bool cur = s & (1ll << i);
        if (x[v][cur] == -1) {
            v = x[v][cur] = t++;
        } else {
            v = x[v][cur];
        }
    }
}

int main() {
    setIO("5");

    int n;
    cin >> n;
    memset(x, -1, sizeof(x));
    vector<long long> a(n);
    long long pre = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pre ^= a[i];
    }
    long long sol = pre, suf = 0;
    build(0);
    for (int i = n - 1; i >= 0; --i) {
        pre ^= a[i];
        suf ^= a[i];
        build(suf);
        long long cur = pre;
        int v = 0;
        for (long long j = maxs - 1; j >= 0; --j) {
            bool goal = !(pre & (1ll << j));
#ifdef DEBUG
            cout << v << " " << goal << " " << x[v][goal] << " " << j << "\n";
#endif
            if (x[v][goal] != -1) {
                v = x[v][goal];
                if (goal) {
                    cur ^= (1ll << j);
                }
            } else {
                v = x[v][!goal];
                if (!goal) {
                    cur ^= (1ll << j);
                }
            }
        }
#ifdef DEBUG
        cout << i << " " << cur << " " << pre << "\n";
#endif
        sol = max(sol, cur);
    }
    cout << sol << "\n";
    return 0;
}
