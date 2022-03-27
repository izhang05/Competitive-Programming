/* Author: izhang
 * Time: 03-26-2022 18:21:28
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
vector<int> adj[maxn];
long long dist[maxn], max_dist[maxn];
pair<long long, int> cur_mx;
int pre[maxn], a[maxn];
bool diam[maxn];
void dfs0(int c, int p) {
    for (auto &i : adj[c]) {
        if (i != p) {
            pre[i] = c;
            dist[i] = dist[c] + i;
            dfs0(i, c);
        }
    }
}
void dfs1(int c, int p) {
    cur_mx = max(cur_mx, {dist[c], c});
    for (auto &i : adj[c]) {
        if (i != p && !diam[i]) {
            pre[i] = c;
            dist[i] = dist[c] + i;
            dfs1(i, c);
        }
    }
}

void test_case() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int node1, node2;
        cin >> node1 >> node2;
        --node1, --node2;
        adj[node1].push_back(node2);
        adj[node2].push_back(node1);
    }
    dist[0] = a[0];
    dfs0(0, -1);
    int l = int(max_element(begin(dist), end(dist)) - begin(dist));
    dist[l] = a[l], pre[l] = -1;
    dfs0(l, -1);
    int r = int(max_element(begin(dist), end(dist)) - begin(dist));
    dbg() << l << " " << r;
    vector<int> path;
    long long sol = 0;
    for (int i = r; i != -1; i = pre[i]) {
        path.push_back(i);
        sol += a[i];
        diam[i] = true;
    }
    long long mx = 0;
    int m = int(path.size());
    vector<long long> mx_left(m), mx_right(m);
    long long cur_dist = 0;
    int ind = 0;
    for (auto &i : path) {
        for (auto &j : adj[i]) {
            if (!diam[j]) {
                cur_mx = {0, 0};
                dist[j] = a[j];
                dfs1(j, i);
                max_dist[i] = max(max_dist[i], cur_mx.first);
                int cur_l = cur_mx.second;
                dist[cur_l] = a[cur_l], pre[cur_l] = -1;
                cur_mx = {0, 0};
                dfs1(cur_l, -1);
                mx = max(mx, cur_mx.first);
            }
        }
        cur_dist += a[i];
        mx_right[ind] = mx_right[max(ind - 1, 0)];
        mx_right[ind] = max(mx_right[ind], cur_dist + max_dist[i]);
        ++ind;
    }
    cur_dist = 0;
    for (int i = m - 1; i >= 0; --i) {
        cur_dist += a[path[i]];
        mx_left[i] = mx_left[min(m - 1, i + 1)];
        mx_left[i] = max(mx_left[i], cur_dist + max_dist[path[i]]);
    }

    dbg() << mx_right;
    dbg() << mx_left;
    dbg() << sol;
    sol += mx;
    dbg() << sol;
    for (int i = 0; i < m - 1; ++i) {
        sol = max(sol, mx_right[i] + mx_left[i + 1]);
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