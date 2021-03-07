#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
vector<pair<int, int>> adj[maxn];

int parent[maxn], depth[maxn], s[maxn];
multiset<int> comps;
long long cur_sol;

int get(int x) {
    return parent[x] == x ? x : parent[x] = get(parent[x]);
}

bool merge(int x, int y) {
    int xroot = get(x), yroot = get(y);
    if (depth[xroot] > depth[yroot]) {
        swap(xroot, yroot);
    }
    if (xroot != yroot) {
        if (s[yroot] != 1) {
            comps.erase(comps.find(s[yroot]));
            cur_sol -= ((long long) (s[yroot]) * (long long) (s[yroot] - 1)) / 2;
        }
        if (s[xroot] != 1) {
            comps.erase(comps.find(s[xroot]));
            cur_sol -= ((long long) (s[xroot]) * (long long) (s[xroot] - 1)) / 2;
        }
        parent[xroot] = yroot;
        depth[yroot] = max(depth[yroot], depth[xroot] + 1);
        s[yroot] += s[xroot];
        comps.insert(s[yroot]);
        cur_sol += ((long long) (s[yroot]) * (long long) (s[yroot] - 1)) / 2;
        return true;
    }
    return false;
}

bool same(int x, int y) {
    return get(x) == get(y);
}

int main() {
    setIO();
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
        q.push({c, {a, b}});
        s[i] = 1;
        parent[i] = i;
    }
    s[n - 1] = 1;
    parent[n - 1] = n - 1;
    vector<pair<int, int>> que(m);
    for (int i = 0; i < m; ++i) {
        cin >> que[i].first;
        que[i].second = i;
    }
    vector<long long> sol(m);
    sort(que.begin(), que.end());
    for (int i = 0; i < m; ++i) {
#ifdef DEBUG
        cout << que[i].first << " " << que[i].second << "\n";
#endif
        while (!q.empty() && q.top().first <= que[i].first) {
            pair<int, int> cur = q.top().second;
            merge(cur.first, cur.second);
            q.pop();
        }
        sol[que[i].second] = cur_sol;
    }
    print(sol);
    return 0;
}
