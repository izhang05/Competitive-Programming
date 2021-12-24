/* Author: izhang05
 * Time: 12-24-2021 09:35:01
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, long long>> adj[maxn];
vector<pair<int, int>> graph_adj[maxn];
int color[maxn];
bool pos = true;

void dfs1(int c, int p, int cur_c) {
    color[c] = cur_c;
    for (auto &i : graph_adj[c]) {
        if (i.first != p) {
            if (color[i.first] == -1) {
                dfs1(i.first, c, cur_c ^ i.second);
            } else if (color[i.first] != (cur_c ^ i.second)) {
                pos = false;
                return;
            }
        }
    }
}

void dfs2(int c, int p) {
    for (auto &i : adj[c]) {
        if (i.first != p) {
            if (i.second != -1) {
                cout << c + 1 << " " << i.first + 1 << " " << i.second << "\n";
            } else {
                cout << c + 1 << " " << i.first + 1 << " " << (color[i.first] ^ color[c]) << "\n";
            }
            dfs2(i.first, c);
        }
    }
}

void test_case() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        graph_adj[i].clear();
        color[i] = -1;
        pos = true;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        if (c != -1) {
            graph_adj[a].emplace_back(b, __builtin_popcount(c) % 2);
            graph_adj[b].emplace_back(a, __builtin_popcount(c) % 2);
        }
    }
    while (m--) {
        int a, b, p;
        cin >> a >> b >> p;
        --a, --b;
        graph_adj[a].emplace_back(b, p);
        graph_adj[b].emplace_back(a, p);
    }
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            dfs1(i, -1, 0);
        }
        if (!pos) {
            break;
        }
    }
    if (!pos) {
        cout << "NO"
             << "\n";
        return;
    }
    cout << "YES"
         << "\n";

    dfs2(0, -1);
}
int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
