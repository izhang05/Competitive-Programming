#include <bits/stdc++.h>

using namespace std;

mt19937 rng((uint32_t) chrono::steady_clock::now().time_since_epoch().count());

//#define DEBUG
void setIO(string name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 3e5 + 5;
vector<int> adj[maxn];
int st[maxn], en[maxn], timer = 1, n;
long double bit[maxn];

void update(int p, long double v) {
    for (; p <= n; p += p & (-p)) {
        bit[p] += v;
    }
}

long double query(int p) {
    long double res = 0;
    for (; p > 0; p -= p & (-p)) {
        res += bit[p];
    }
    return res;
}

void dfs(int c, int p) {
    st[c] = timer++;
    for (auto i : adj[c]) {
        if (i != p) {
            dfs(i, c);
        }
    }
    en[c] = timer - 1;
}

int main() {
    setIO("1");
    cout << fixed << setprecision(15);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    vector<long double> a(n + 1);
    for (int i = 1; i < n + 1; ++i) {
        a[i] = 0;
    }
    int q;
    cin >> q;
    while (q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if (t == 1) {
            update(st[x], (log(y) - a[x]));
            a[x] = log(y);
#ifdef DEBUG
            for (int i = 0; i < n + 1; ++i) {
                cout << bit[i] << " ";
            }
            cout << "\n";
#endif
        } else {
            long double xval = query(en[x]) - query(st[x] - 1), yval = query(en[y]) - query(st[y] - 1), solog =
                    xval - yval;
#ifdef DEBUG
            cout << xval << " " << yval << "\n";
#endif
            solog = min((long double) log(1e9), solog);
            cout << exp(solog) << "\n";
        }
    }
    return 0;
}
