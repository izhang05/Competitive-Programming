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
    freopen("13.in", "r", stdin);
    freopen("13.out", "w", stdout);
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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
int a[maxn], sol[maxn];
vector<int> adj[maxn];

unordered_set<int, custom_hash> dfs(int c, int p) {
#ifdef DEBUG
    cout << c << endl;
#endif
    unordered_set<int, custom_hash> cur;
    cur.insert(a[c]);
    for (int i : adj[c]) {
        if (i != p) {
            unordered_set<int, custom_hash> next = dfs(i, c);
            if (next.size() > cur.size()) {
                swap(cur, next);
            }
            for (int j : next) {
                cur.insert(j);
            }
        }
    }
    sol[c] = cur.size();
    return cur;
}

int main() {
#ifdef LOCAL
    auto start_time = chrono::high_resolution_clock::now();
#endif
    setIO();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int b, c;
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        cout << sol[i] << " ";
    }
    cout << "\n";
#ifdef LOCAL
    auto end_time = chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << chrono::duration_cast<chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
