/* Author: izhang05
 * Time: 06-28-2021 16:15:31
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
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
vector<pair<int, int>> adj[maxn];
int dist[maxn], par[maxn];

int main() {
    setIO("1");

    int n, k, d;
    cin >> n >> k >> d;
    memset(dist, 0x3f, sizeof(dist));
    queue<int> q;
    for (int i = 0; i < k; ++i) {
        int a;
        cin >> a;
        --a;
        if (dist[a]) {
            q.push(a);
        }
        dist[a] = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].emplace_back(b, i + 1);
        adj[b].emplace_back(a, i + 1);
    }
    set<int> sol;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i : adj[cur]) {
            if (dist[i.first] > dist[cur] + 1) {
                dist[i.first] = dist[cur] + 1;
                q.push(i.first);
                par[i.first] = cur;
            } else {
                if (i.first != par[cur]) {
                    sol.insert(i.second);
                }
            }
        }
    }
    cout << sol.size() << "\n";
    print(sol);
    return 0;
}
