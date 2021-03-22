#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;

vector<vector<pair<int, int>>> adj;
vector<long long> pass, sub, weight;

void dfs(int c, int p) {
    if (p != -1 && adj[c].size() == 1) {
#ifdef DEBUG
        cout << "leaf: " << c << "\n";
#endif
        sub[c] = 1;
    }
    for (auto i : adj[c]) {
        if (i.first != p) {
            dfs(i.first, c);
            pass[i.second] = sub[i.first];
            sub[c] += sub[i.first];
#ifdef DEBUG
            cout << c << " " << i.node << " " << i.ind << " " << sub[i.node] << "\n";
#endif
        }
    }
}

int main() {
    setIO("1");
    int t;
    cin >> t;
    while (t--) {
#ifdef DEBUG
        cout << "\n"
             << t << ":"
             << "\n";
#endif
        int n;
        cin >> n;
        long long s;
        cin >> s;
        long long sol = 0;
        adj = vector<vector<pair<int, int>>>(n);
        pass = sub = weight = vector<long long>(n);
        for (int i = 0; i < n - 1; ++i) {
            int a, b;
            cin >> a >> b >> weight[i];
            --a, --b;
            adj[a].push_back({b, i});
            adj[b].push_back({a, i});
        }
        dfs(0, -1);
        long long total = 0;
        priority_queue<pair<long long, int>> q;
        for (int i = 0; i < n - 1; ++i) {
#ifdef DEBUG
            cout << pass[i] << " " << weight[i] << "\n";
#endif
            total += pass[i] * weight[i];
            q.push({pass[i] * (weight[i] - weight[i] / 2), i});
        }
#ifdef DEBUG
        cout << total << "\n";
#endif
        while (total > s) {
            ++sol;
            pair<long long, int> cur = q.top();
            q.pop();
            total -= cur.first;
            weight[cur.second] /= 2;
            q.push({pass[cur.second] * (weight[cur.second] - weight[cur.second] / 2), cur.second});
        }
        cout << sol << "\n";
    }

    return 0;
}
