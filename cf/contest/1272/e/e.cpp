/* Author: izhang05
 * Time: 09-08-2021 09:58:43
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
int sol[maxn], dist[maxn];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sol[i] = -1;
        dist[i] = inf;
        if (a[i] % 2 == 0) {
            if (i - a[i] >= 0) {
                adj[i - a[i]].push_back(i);
            }
            if (i + a[i] < n) {
                adj[i + a[i]].push_back(i);
            }
        } else {
            q.push(i);
            dist[i] = 0;
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : adj[cur]) {
            if (dist[i] > dist[cur] + 1) {
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dist[i] != inf && a[i] % 2 == 0) {
            sol[i] = dist[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        dist[i] = inf;
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            q.push(i);
            dist[i] = 0;
        } else {
            if (i - a[i] >= 0) {
                adj[i - a[i]].push_back(i);
            }
            if (i + a[i] < n) {
                adj[i + a[i]].push_back(i);
            }
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : adj[cur]) {
            if (dist[i] > dist[cur] + 1) {
                q.push(i);
                dist[i] = dist[cur] + 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dist[i] != inf && a[i] % 2 == 1) {
            sol[i] = dist[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " \n"[i == n - 1];
    }
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
