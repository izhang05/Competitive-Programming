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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
vector<int> adj[maxn];
int v[maxn];
long long sum[maxn], min_sub[maxn], sol = 0;

void dfs(int c, int p) {
    sum[c] = v[c];
    priority_queue<pair<long long, long long>> q;
    long long mn = 1e18, cur_min_sub = 1;
    for (auto &i : adj[c]) {
        if (i != p) {
            dfs(i, c);
            cur_min_sub = lcm(cur_min_sub, min_sub[i]);
            q.push({sum[i], min_sub[i]});
            mn = min(mn, sum[i]);
        }
    }
    if (!q.empty()) {
        min_sub[c] = cur_min_sub * (long long) q.size();
        while (q.top().first != mn) {
            pair<long long, long long> cur = q.top();
            q.pop();
            long long sub = ((cur.first - mn + cur.second - 1) / cur.second) * cur.second;
            sol += sub;
            mn = min(mn, cur.first - sub);
            q.push({cur.first - sub, cur.second});
        }
        sum[c] = mn * (long long) q.size();
    } else {
        min_sub[c] = 1;
    }
#ifdef DEBUG
    cout << c + 1 << " " << min_sub[c] << " " << sum[c] << " " << sol << "\n";
#endif
}

int main() {
    setIO("b");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    cout << sol << "\n";
    return 0;
}
