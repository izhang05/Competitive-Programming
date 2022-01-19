/* Author: izhang
 * Time: 01-18-2022 22:27:49
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int co[maxn];
vector<int> adj[maxn], new_adj[maxn];
int cnt[maxn];
bool visited[maxn];
int dfs1(int c, int p) {
    for (auto &i : adj[c]) {
        if (i != p) {
            cnt[c] += dfs1(i, c);
        }
    }
    return cnt[c];
}
void dfs2(int c, int p) {
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs2(i, c);
            if (co[i] || cnt[i] >= 2) {
                new_adj[i].push_back(c);
            }
            if (co[c] || cnt[0] - cnt[i] >= 2) {
                new_adj[c].push_back(i);
            }
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> co[i];
        cnt[i] = co[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (co[i]) {
            q.push(i);
            visited[i] = true;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : new_adj[cur]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << visited[i] << " \n"[i == n - 1];
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
