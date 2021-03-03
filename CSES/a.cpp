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
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
long long sol[maxn], c[maxn];
unordered_map<long long, long long, custom_hash> col[maxn];
map<long long, unordered_set<long long, custom_hash>, greater<>> cnt[maxn];
map<long long, long long, greater<>> cnt_sum[maxn];
vector<long long> adj[maxn];

void dfs(int node, int p) {
    //    if (col[node].find(c[node]) != col[node].end()) {
    //        cnt[node][col[node][c[node]]].erase(c[node]);
    //    }
    ++col[node][c[node]];
    if (cnt[node][col[node][c[node]]].find(c[node]) == cnt[node][col[node][c[node]]].end()) {
        cnt[node][col[node][c[node]]].insert(c[node]);
        cnt_sum[node][col[node][c[node]]] += c[node];
    }
    for (int i : adj[node]) {
        if (i != p) {
            dfs(i, node);
            if (col[i].size() > col[node].size()) {
                swap(col[i], col[node]);
                swap(cnt[i], cnt[node]);
                swap(cnt_sum[i], cnt_sum[node]);
            }
            for (pair<int, int> j : col[i]) {
                //                if (col[node].find(j.first) != col[node].end()) {
                //                    cnt[node][col[node][j.first]].erase(j.first);
                //                }
                col[node][j.first] += j.second;
                if (cnt[node][col[node][j.first]].find(j.first) == cnt[node][col[node][j.first]].end()) {
                    cnt[node][col[node][j.first]].insert(j.first);
                    cnt_sum[node][col[node][j.first]] += j.first;
                }
            }
        }
    }
    sol[node] = cnt_sum[node].begin()->second;
}

int main() {
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    setIO();

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1);
    for (int i = 0; i < n - 1; ++i) {
        cout << sol[i] << " ";
    }
    cout << sol[n - 1] << "\n";
#ifdef DEBUG
    for (auto i : cnt[0]) {
        cout << i.first << ": ";
        for (int j : i.second) {
            cout << j << " ";
        }
        cout << "\n";
    }
    for (pair<int, int> i : cnt_sum[0]) {
        cout << i.first << " " << i.second << "\n";
    }
#endif

#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
