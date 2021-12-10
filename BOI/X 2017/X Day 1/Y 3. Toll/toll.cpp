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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e4 + 5, maxs = 16, maxk = 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn];

int up[maxn][maxk][maxk][maxs], depth[maxn], n, k;


void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < n / k; ++j) {
            if (j + (1 << i) >= (n + k - 1) / k) {
                continue;
            }
            for (int a = 0; a < k; ++a) {
                for (int c = 0; c < k; ++c) {
                    for (int b = 0; b < k; ++b) {
                        up[j][a][c][i] = min(up[j][a][c][i], up[j][a][b][i - 1] + up[j + (1 << (i - 1))][b][c][i - 1]);
                    }
                }
            }
        }
    }
}


void solve() {
    int m, q;
    cin >> k >> n >> m >> q;
    memset(up, 0x3f, sizeof(up));
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        up[a / k][a % k][b % k][0] = c;
    }
    build();
    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b;
        int jumps = (b / k) - (a / k);
        if (jumps == 0) {
            cout << -1 << "\n";
            continue;
        }
        vector<vector<int>> cur(k, vector<int>(k, inf));
        for (int j = 0; j < k; ++j) {
            cur[j][j] = 0;
        }
        int cur_group = a / k;
        for (int j = 0; j < maxs; ++j) {
            if (jumps & (1 << j)) {
                vector<vector<int>> new_cur(k, vector<int>(k, inf));
                for (int c = 0; c < k; ++c) {
                    for (int e = 0; e < k; ++e) {
                        for (int d = 0; d < k; ++d) {
                            new_cur[c][e] = min(new_cur[c][e], cur[c][d] + up[cur_group][d][e][j]);
                        }
                    }
                }
                cur_group += 1 << j;
                swap(cur, new_cur);
            }
        }

        cout << (cur[a % k][b % k] == inf ? -1 : cur[a % k][b % k]) << "\n";
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
