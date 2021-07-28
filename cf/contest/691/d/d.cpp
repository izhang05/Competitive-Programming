/* Author: izhang05
 * Time: 07-27-2021 22:42:00
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e6 + 5;
vector<int> adj[maxn], a;
int sol = 0;
bool vis[maxn];
vector<int> cur_pos, cur_val;

void dfs(int c) {
    vis[c]=true;
    cur_pos.push_back(c);
    cur_val.push_back(a[c]);
    for (auto &i : adj[c]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    setIO("1");

    int n, m;
    cin >> n >> m;
    a.resize(n);
    vector<int> sol(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            dfs(i);
            sort(cur_val.begin(), cur_val.end());
            reverse(cur_val.begin(), cur_val.end());
            sort(cur_pos.begin(), cur_pos.end());
            for (int j = 0; j < int(cur_pos.size()); ++j) {
                sol[cur_pos[j]] = cur_val[j];
            }
            cur_pos.clear();
            cur_val.clear();
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " ";
    }
    cout << "\n";
    return 0;
}
