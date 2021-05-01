#include <bits/stdc++.h>

using namespace std;

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

const int mod = 1e9 + 7, maxn = 2e5 + 5, maxs = 19;
const long long inf = 1e18;

int up[maxn][maxs], depth[maxn], n, m;

int jmp(int x, int d) {
    for (int i = 0; i < maxs && x != -1; ++i) {
        if ((1 << i) & d) {
            x = up[x][i];
        }
    }
    return x;
}


void build() {
    for (int i = 1; i < maxs; ++i) {
        for (int j = 0; j < m; ++j) {
            if (up[j][i - 1] == -1) {
                up[j][i] = -1;
            } else {
                up[j][i] = up[up[j][i - 1]][i - 1];
            }
        }
    }
}

long long t[2 * maxn];

long long calc(long long a, long long b) {
    return max(a, b);
}


void update(int p, long long val) {
    for (t[p += m] = val; p > 1; p /= 2) {
        t[p / 2] = calc(t[p], t[p ^ 1]); // p ^ 1 is the other child for mode p / 2
    }
}

long long query(int l, int r) {
    long long res = -1;
    for (l += m, r += m; l < r; l /= 2, r /= 2) {
        if (l & 1) {
            res = calc(res, t[l++]);
        }
        if (r & 1) {
            res = calc(res, t[--r]);
        }
    }
    return res;
}

int main() {
    setIO("1");
    int q;
    cin >> n >> m >> q;
    vector<int> p(n), ind(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        ind[p[i]] = i;
    }
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        --a[i];
    }
    vector<int> last(n, -1);
    for (int i = 0; i < m; ++i) {
        up[i][0] = last[p[(ind[a[i]] - 1 + n) % n]];
#ifdef DEBUG
        cout << i << " " << up[i][0] << "\n";
#endif
        last[a[i]] = i;
    }
    build();
    memset(t, -1, sizeof(t));
    for (int i = 0; i < m; ++i) {
        update(i, jmp(i, n - 1));
#ifdef DEBUG
        cout << jmp(i, n - 1) << "\n";
#endif
    }
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << (query(l, r + 1) >= l);
    }
    cout << "\n";
    return 0;
}

