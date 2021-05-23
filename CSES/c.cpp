#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}

vector<int> adj[maxn];
int dist[maxn];

int main() {
    setIO("c");

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            adj[i].clear();
            dist[i] = inf;
        }
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<int> q;
        q.push(0);
        dist[0] = 0;
        vector<vector<int>> d(2);
        d[0].push_back(1);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            for (auto &i : adj[cur]) {
                if (dist[i] == inf) {
                    q.push(i);
                    dist[i] = dist[cur] + 1;
                    d[dist[i] % 2].push_back(i + 1);
                }
            }
        }
        if (d[0].size() > d[1].size()) {
            swap(d[0], d[1]);
        }
        cout << d[0].size() << "\n";
        print(d[0]);
    }
    return 0;
}
