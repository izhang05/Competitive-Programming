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

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int maxn = 2e5;
long long t[2 * maxn];
int s[maxn], n, cur, st[maxn], en[maxn];
vector<int> adj[maxn];

void build() {
    for (int i = n - 1; i > 0; --i) {
        t[i] = t[2 * i] + t[2 * i + 1];
    }
}

void upd(int p, int val) {
    for (t[p += n] = val; p > 1; p /= 2) {
        t[p / 2] = t[p] + t[p ^ 1];
    }
}

long long que(int l, int r) {
    long long res = 0;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res += t[l++];
        }
        if (r & 1) {
            res += t[--r];
        }
    }
    return res;
}


void dfs(int node, int parent) {
    st[node] = cur++;
    for (int i : adj[node]) {
        if (i != parent) {
            dfs(i, node);
        }
    }
    en[node] = cur - 1;
}

int main() {
    setIO();
    int q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int b, c;
    for (int i = 0; i < n - 1; ++i) {
        cin >> b >> c;
        --b, --c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        t[st[i] +n] = a[i];
    }
    build();
    int d;
    for (int i = 0; i < q; ++i) {
        cin >> b;
        if (b == 2) {
            cin >> c;
            --c;
            cout << que(st[c], en[c]) << "\n";
        } else {
            cin >> c >> d;
            upd(st[c - 1], d);
        }
    }
    return 0;
}
