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
#ifdef LOCAL
    freopen("Y 14.in", "r", stdin);
    freopen("Y 14.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
int bit[maxn], n;
map<int, int> last;

void update(int p, int v) {
    for (; p <= n; p += p & (-p)) {
        bit[p] += v;
    }
}
long long query(int p) {
    long long res = 0;
    for (; p > 0; p -= p & (-p)) {
        res += bit[p];
    }
    return res;
}

int main() {
#ifdef LOCAL
    auto start_time = std::chrono::high_resolution_clock::now();
#endif
    setIO();
    int q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i + 1];
    }
    vector<int> sol(q);
    vector<pair<pair<int, int>, int>> queries;
    int b, c;
    for (int i = 0; i < q; ++i) {
        cin >> b >> c;
        queries.emplace_back(make_pair(b, c), i + 1);
    }
    sort(queries.begin(), queries.end(), [](pair<pair<int, int>, int> left, pair<pair<int, int>, int> right) {
        return left.first.second == right.first.second ? left.first.first < right.first.first : left.first.second < right.first.second;
    });
    int ind = 1;
    vector<int> vals(n + 1);
    for (int i = 0; i < q; ++i) {
        pair<int, int> cur = queries[i].first;
        int pos = queries[i].second;
        for (; ind <= cur.second; ++ind) {
            if (last.find(a[ind]) != last.end()) {
#ifdef DEBUG
                cout << last[a[ind]] << "\n";
                cout << vals[last[a[ind]]] << " " << query(last[a[ind]]) << "\n";
#endif
                update(last[a[ind]], -1);
                vals[last[a[ind]]] = 0;
#ifdef DEBUG
                cout << vals[last[a[ind]]] << " " << query(last[a[ind]]) << "\n";
                cout << "\n";
#endif
            }
            last[a[ind]] = ind;
            vals[ind] = 1;
            update(ind, 1);
        }
#ifdef DEBUG
        print(vals);
        for (int j = 0; j < n + 1; ++j) {
            cout << j << " " << query(j) << "\n";
        }
        cout << "\n";
        cout << cur.second << " " << cur.first - 1 << "\n";
        cout << query(cur.second) << " " << query(cur.first - 1) << "\n";
        cout << "\n";
#endif
        sol[pos - 1] = query(cur.second) - query(cur.first - 1);
    }
    print(sol, "\n");
#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
