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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 15;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn], radj[maxn];
int dp[1 << maxn];


void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        adj[i].clear(), radj[i].clear();
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j] || abs(a[i] - a[j]) > 1) {
                adj[i].push_back(j);
                radj[j].push_back(i);
            }
        }
    }
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i))) {
                bool good = true;
                for (auto &j : radj[i]) {
                    if (!(mask & (1 << j))) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    dp[mask ^ (1 << i)] += dp[mask];
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}
