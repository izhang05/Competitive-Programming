/* Author: izhang
 * Time: 03-26-2022 13:45:16
**/
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<pair<int, int>> adj[maxn];
int dist[maxn];
long long max_dist[maxn];
pair<int, int> pre[maxn];
bool diam[maxn];
void dfs0(int c, int p) {
    for (auto &i : adj[c]) {
        if (i.first != p) {
            pre[i.first] = {c, i.second};
            dist[i.first] = dist[c] + i.second;
            dfs0(i.first, c);
        }
    }
}
long long dfs1(int c, int p) {
    for (auto &i : adj[c]) {
        if (i.first != p && !diam[i.first]) {
            max_dist[c] = max(max_dist[c], dfs1(i.first, c) + i.second);
        }
    }
    return max_dist[c];
}

multiset<long long, greater<>> cur;
void rem(long long a) {
    if (cur.find(a) != cur.end()) {
        cur.erase(cur.find(a));
    }
}

void test_case() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 0 << "\n";
        return;
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    dfs0(0, -1);
    int l = int(max_element(begin(dist), end(dist)) - begin(dist));
    dist[l] = 0, pre[l] = {-1, -1};
    dfs0(l, -1);
    int r = int(max_element(begin(dist), end(dist)) - begin(dist));
    dbg() << l << " " << r;
    vector<pair<int, int>> path;
    for (int i = r; i != -1; i = pre[i].first) {
        path.emplace_back(i, pre[i].second);
        diam[i] = true;
    }
    for (auto &i : path) {
        dfs1(i.first, -1);
        dbg() << i << " " << max_dist[i.first];
    }
    int m = int(path.size());
    vector<long long> mx_right(m), mx_left(m);
    mx_right[m - 1] = max_dist[path[m - 1].first];
    for (int i = m - 2; i >= 0; --i) {
        mx_right[i] = max(max_dist[path[i].first], mx_right[i + 1] + path[i].second);
    }
    mx_left[0] = max_dist[path[0].first];
    for (int i = 1; i < m; ++i) {
        mx_left[i] = max(max_dist[path[i].first], mx_left[i - 1] + path[i - 1].second);
    }
    for (int i = 0; i < min(k, m); ++i) {
        cur.insert(max_dist[path[i].first]);
    }
    dbg() << imie(cur);
    dbg() << mx_right;
    dbg() << mx_left;
    long long sol = max(*cur.begin(), mx_right[min(k, m) - 1]);
    for (int a = 1, b = min(k, m); b < m; ++a, ++b) {
        rem(max_dist[path[a - 1].first]);
        dbg() << cur;

        cur.insert(max_dist[path[b].first]);
        dbg() << cur;

        sol = min(sol, max({*cur.begin(), mx_left[a], mx_right[b]}));
        dbg() << a << " " << b << " " << cur;
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
