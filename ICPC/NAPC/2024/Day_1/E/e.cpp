#include <bits/extc++.h>

using namespace __gnu_pbds;
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const long long INFL = 0x3f3f3f3f3f3f3f3f;
const int mxn = 1e5 + 5;
vector<pair<int, int>> adj[mxn];
int d[mxn];
long long dist[mxn];
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;


Tree<pair<long long, int>> in[mxn];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        dist[i] = INFL;
        in[i].clear();
    }
    std::priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
    for (int i = 0; i < k; ++i) {
        int e;
        cin >> e;
        --e;
        dist[e] = 0;
        q.emplace(0, e);
    }

    for (int i = 0; i < n; ++i) {
        cin >> d[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    while (!q.empty()) {
        pair<long long, int> cur = q.top();
        q.pop();
        if (dist[cur.second] != cur.first) {
            continue;
        }
        for (auto u: adj[cur.second]) {
            if ((int) in[u.first].size() < d[u.first]) {
                in[u.first].insert({cur.first + u.second, cur.second});
            } else {
                in[u.first].insert({cur.first + u.second, cur.second});
//                if ((int) in[u.first].size() > d[u.first] + 1) {
//                    in[u.first].pop();
//                }
                if (in[u.first].find_by_order(d[u.first])->first < dist[u.first]) {
                    dist[u.first] = in[u.first].find_by_order(d[u.first])->first;
                    q.emplace(dist[u.first], u.first);
                }
            }
        }
    }
    cout << (dist[0] == INFL ? -1 : dist[0]) << "\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}