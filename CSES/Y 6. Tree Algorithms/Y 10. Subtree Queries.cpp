#include <bits/stdc++.h>

using namespace std;
//#define DEBUG
void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef LOCAL
    freopen("10.in", "r", stdin);
    freopen("10.out", "w", stdout);
#endif
}
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
int n, st[maxn], en[maxn], t = 1;
long long bit[maxn];
vector<int> adj[maxn];

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

void dfs(int c, int p = -1) {
    st[c] = t++;
    for (int i : adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
    en[c] = t - 1;
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
    int b, c;
    for (int i = 0; i < n - 1; ++i) {
        cin >> b >> c;
        adj[b].push_back(c);
        adj[c].push_back(b);
    }
    dfs(1);
#ifdef DEBUG
    for (int j = 1; j < n + 1; ++j) {
        cout << st[j] << " ";
    }
    cout << "\n";
    for (int j = 1; j < n + 1; ++j) {
        cout << en[j] << " ";
    }
    cout << endl;
#endif
    for (int i = 1; i < n + 1; ++i) {
        update(st[i], a[i]);
    }
    int d;
    for (int i = 0; i < q; ++i) {
        cin >> b;
        if (b == 1) {
            cin >> c >> d;
            update(st[c], -a[c] + d);
            a[c] = d;
        } else {
            cin >> c;
#ifdef DEBUG
            cout << "\n";
            cout << c << " " << en[c] << " " << st[c] - 1 << "\n";
            cout << query(en[c]) << " " << query(st[c] - 1) << "\n";
            cout << endl;
#endif
            cout << query(en[c]) - query(st[c] - 1) << endl;
        }
    }
#ifdef LOCAL
    auto end_time = std::chrono::high_resolution_clock::now();
    cout << setprecision(6) << fixed;
    cout << "Execution time: " << std::chrono::duration_cast<std::chrono::duration<double>>(end_time - start_time).count() << " seconds" << endl;
#endif
    return 0;
}
