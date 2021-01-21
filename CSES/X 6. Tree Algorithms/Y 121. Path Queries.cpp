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
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;

int st[maxn], en[maxn], cnt, t_n;
vector<int> adj[maxn];
long long t[2 * maxn];

long long calc(long long a, long long b) {
    return a + b;
}

void build() {
    for (int i = t_n - 1; i > 0; --i) {
        t[i] = calc(t[2 * i], t[2 * i + 1]);
    }
}

void update(int p, long long val) {
    for (t[p += t_n] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]); // p ^ 1 is the other child for node p / 2
    }
}

long long query(int l, int r) {
    long long res = 0;
    for (l += t_n, r += t_n; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++]);
        }
        if (r & 1) {
            res = calc(res, t[--r]);
        }
    }
    return res;
}

void dfs(int c, int p) {
    st[c] = cnt++;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
    en[c] = cnt - 1;
}

int main() {
    setIO();
    int n, q;
    cin >> n >> q;
    t_n = n + 1;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
    }
    int b, c;
    for (int i = 0; i < n - 1; ++i) {
        cin >> b >> c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs(1, 0);
    for (int i = 1; i < n + 1; ++i) {
        update(st[i], query(st[i], st[i] + 1) + a[i]);
        update(1 + en[i], query(1 + en[i], 2 + en[i]) - a[i]);
    }

    int d;
    for (int i = 0; i < q; ++i) {
        cin >> d;
        if (d == 1) {
            cin >> b >> c;
            update(st[b], query(st[b], st[b] + 1) + c - a[b]);
            update(1 + en[b], query(1 + en[b], 2 + en[b]) - (c - a[b]));
            a[b] = c;
        } else {
            cin >> b;
            cout << query(0, st[b] + 1) << "\n";
        }
    }
    return 0;
}
