/* Author: izhang
 * Time: 01-23-2022 22:51:17
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
vector<int> adj[maxn];

int n, m, a, b, c;
vector<int> bfs(int x) {
    vector<int> dist(n, inf);
    dist[x] = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : adj[cur]) {
            if (dist[i] > dist[cur] + 1) {
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
    return dist;
}

void test_case() {
    cin >> n >> m >> a >> b >> c;
    --a, --b, --c;
    vector<int> p(m);
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
    }
    for (int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    for (int i = 0; i < m; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    sort(p.begin(), p.end());
    vector<long long> pre(m + 1, 0);
    for (int i = 1; i <= m; ++i) {
        pre[i] = pre[i - 1] + p[i - 1];
    }
    vector<int> da = bfs(a), db = bfs(b), dc = bfs(c);
    long long sol = INFL;
    for (int i = 0; i < n; ++i) {
        if (da[i] + db[i] + dc[i] > m) {
            continue;
        }
        sol = min(sol, 2 * pre[db[i]] + pre[da[i] + db[i] + dc[i]] - pre[db[i]]);
    }
    cout << sol << "\n";
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
