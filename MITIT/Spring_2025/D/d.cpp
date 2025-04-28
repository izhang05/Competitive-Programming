#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else

struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};

#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, mxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;


vector<int> adj[mxn];
int dist[mxn];

void test_case() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> cities(k);
    for (auto &i: cities) {
        cin >> i;
        --i;
    }
    for (int i = 0; i < n; ++i) {
        adj[i].clear();
        dist[i] = inf;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    adj[0].push_back(cities[0]);
    adj[cities[0]].push_back(0);
    for (int i = 0; i < k - 1; ++i) {
        adj[cities[i]].push_back(cities[i + 1]);
        adj[cities[i + 1]].push_back(cities[i]);
    }
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto &i: adj[cur]) {
            if (dist[i] > dist[cur] + 1) {
                dist[i] = dist[cur] + 1;
                q.push(i);
            }
        }
    }
    for (int i = 0; i < k - 1; ++i) {
        if (dist[cities[i]] >= dist[cities[i + 1]]) {
            cout << "-1" << "\n";
            return;
        }
    }
    vector<pair<int, int>> sol;
    if (cities[0] != 0) {
        sol.emplace_back(1, cities[0] + 1);
    }
    for (int i = 0; i < k - 1; ++i) {
        sol.emplace_back(cities[i] + 1, cities[i + 1] + 1);
    }
    cout << sol.size() << "\n";
    for (auto &i: sol) {
        cout << i.first << " " << i.second << "\n";
    }
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
