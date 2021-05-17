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

const int mod = 1e9 + 7, maxn = 1e5 + 5;
const long long inf = 1e18;

vector<pair<int, long long>> adj[maxn];
long long dist[maxn];

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].second;
        dist[i] = inf;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; ++i) {
        adj[i + 1].emplace_back(i, 0ll);
    }
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(a.begin(), a.end(), make_pair(a[i].first + a[i].second, inf));
        if (it != a.begin()) {
            --it;
        }
        if (it - a.begin() != i) {
            adj[i].emplace_back(it - a.begin(), 0);
        }
        if (next(it) != a.end()) {
            ++it;
            adj[i].emplace_back(it - a.begin(), it->first - a[i].first - a[i].second);
        }
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    q.push({0, 0});
    dist[0] = 0;
    while (!q.empty()) {
        pair<long long, int> cur = q.top();
        q.pop();
#ifdef DEBUG
        cout << cur.first << " " << cur.second << endl;
#endif
        if (dist[cur.second] != cur.first) {
            continue;
        }
        for (auto &i : adj[cur.second]) {
            if (dist[i.first] > cur.first + i.second) {
                q.push({dist[i.first] = cur.first + i.second, i.first});
            }
        }
    }
    cout << dist[n - 1] + sum << "\n";
}
