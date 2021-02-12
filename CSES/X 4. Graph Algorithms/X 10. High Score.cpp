#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
using indexed_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T>
void print(T a) {
    for (auto i : a) {
        cout << i << " ";
    }
    cout << "\n";
}

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    //freopen("solution.out", w", stdout);
    freopen("X 10.in", "r", stdin);
#endif
}
const int mod = 1e9 + 7, maxn = 2505;
const long long inf = 1e18;
map<int, int> adj[maxn];
vector<int> out[maxn];
long long dist[maxn];
bool reachable[maxn];

void dfs(int node) {
    reachable[node] = true;
    for (int i : out[node]) {
        if (!reachable[i]) {
            dfs(i);
        }
    }
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    int a, b, c;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a, --b;
        if (adj[a].find(b) != adj[a].end()) {
            adj[a][b] = max(adj[a][b], c);
        } else {
            adj[a][b] = c;
        }
        out[b].push_back(a);
    }
    dfs(n - 1);
    for (int i = 0; i < n; ++i) {
        dist[i] = -inf;
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>> q;
    q.push(make_pair(dist[0] = 0, 0));
    while (!q.empty()) {
        long long cur_dist = q.top().first, ind = q.top().second;
        q.pop();
        if (dist[ind] == -inf) {
            dist[ind] = cur_dist;
        }
        if (dist[ind] != cur_dist) {
            continue;
        }
        //        cerr << cur_dist << " " << ind << endl;
        for (pair<int, int> i : adj[ind]) {
            if (i.first == n - 1) {
                if (cur_dist + i.second > dist[n - 1]) {
                    q.push(make_pair(cur_dist + i.second, i.first));
                }
                continue;
            }
            if (dist[i.first] == -inf) {
                q.push(make_pair(cur_dist + i.second, i.first));
            } else if (dist[i.first] < cur_dist + i.second && reachable[i.first]) {
                cerr << dist[n - 1] << "\n";
                cerr << i.first << "\n";
                cerr << dist[i.first] << " " << cur_dist + i.second << "\n";
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    //    for (int i = 0; i < n; ++i) {
    //        cerr << dist[i] << "\n";
    //    }
    cout << dist[n - 1] << "\n";
    return 0;
}