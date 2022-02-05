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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn], radj[maxn];
long long add(long long a, long long b) {
    return (a + b > mod ? a + b - mod : a + b);
}

//void solve1(int n) {
//    for (int i = 0; i < n; ++i) {
//        adj[i].clear(), radj[i].clear();
//    }
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            if (a[i] == a[j] || abs(a[i] - a[j]) > 1) {
//                adj[i].push_back(j);
//                radj[j].push_back(i);
//            }
//        }
//    }
//    vector<int> dp(1 << n, 0);
//    dp[0] = 1;
//    for (int mask = 0; mask < (1 << n); ++mask) {
//        for (int i = 0; i < n; ++i) {
//            if (!(mask & (1 << i))) {
//                bool good = true;
//                for (auto &j : radj[i]) {
//                    if (!(mask & (1 << j))) {
//                        good = false;
//                        break;
//                    }
//                }
//                if (good) {
//                    dp[mask ^ (1 << i)] += dp[mask];
//                }
//            }
//        }
//    }
//    cout << dp[(1 << n) - 1] << "\n";
//}

long long dp[maxn][maxn];

void solve2(int n) {
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
                cout << i << " " << j << "\n";
            }
        }
    }
    cout << "\n";
}

long long nCr[5005][5005];

void test_case() {
    int n;
    cin >> n;
    if (n <= 100) {
        solve2(n);
        return;
    }
    int cnt = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 0) {
            ++cnt;
        }
    }
    cout << nCr[n][cnt] << "\n";
}

int main() {
    setIO("1");
    for (int i = 0; i < 5005; ++i) {
        nCr[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            nCr[i][j] = add(nCr[i - 1][j], nCr[i - 1][j - 1]);
        }
    }
    int t = 1;
    cin >> t;
    while (t--) {
        test_case();
    }
    return 0;
}
