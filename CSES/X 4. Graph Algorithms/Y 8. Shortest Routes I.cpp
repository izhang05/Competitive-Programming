#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", "w", stdout);
    freopen("1.in", "r", stdin);
#endif
}


int main() {
    setIO();
    int n, m, a, b, c;
    cin >> n >> m;
    vector<pair<int, int> > adj[n];
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
    }
    priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<> > q; // first = dist, second = index
    q.push(make_pair(0, 0));
    vector<long long> sol(n);
    for (int i = 0; i < n; ++i) {
        sol[i] = 1e18;
    }
    sol[0] = 0;
    while (!q.empty()) {
        pair<long long, long long> cur = q.top();
        q.pop();
        if (cur.first != sol[cur.second]) {
            continue;
        }
        for (pair<int, int> i : adj[cur.second]) {
            if (cur.first + i.second < sol[i.first]) {
                q.push(make_pair(cur.first + i.second, i.first));
                sol[i.first] = cur.first + i.second;
            }
        }
    }
    for (long long i : sol) {
        cout << i << " ";
    }
    return 0;
}
