/* Author: izhang05
 * Time: 12-28-2021 13:28:28
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, maxk = 22;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
int n, k, down[maxn][2 * maxk], a[maxn], sol[maxn], up[maxn][2 * maxk];

void dfs1(int c, int p) {
    down[c][0] = a[c];
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs1(i, c);
            for (int j = 0; j < 2 * k; ++j) {
                down[c][(j + 1) % (2 * k)] ^= down[i][j];
            }
        }
    }
}
void dfs2(int c, int p) {
    if (p != -1) {
        for (int i = 0; i < 2 * k; ++i) {
            up[c][(i + 1) % (2 * k)] ^= up[p][i] ^ down[p][i];
        }
        for (int i = 0; i < 2 * k; ++i) {
            up[c][(i + 2) % (2 * k)] ^= down[c][i];
        }
    }
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
        }
    }
    int cur = 0;
    for (int i = k; i < 2 * k; ++i) {
        cur ^= down[c][i] ^ up[c][i];
    }
    sol[c] = bool(cur);
}

void test_case() {
    cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    dfs1(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " \n"[i == n - 1];
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
