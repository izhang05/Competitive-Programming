/* Author: izhang05
 * Time: 12-21-2021 16:46:02
**/
#include <bits/stdc++.h>

using namespace std;

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
int n, cur_ind;
vector<pair<int, long long>> adj[4 * maxn];
long long dist[4 * maxn];

struct segtree {
    int size{};
    vector<vector<int>> ind = vector<vector<int>>(2);

    int build(int x, int lx, int rx, int t) {
        if (rx - lx == 1) {
            ind[t][x] = lx;
            return lx;
        }
        int m = (lx + rx) / 2, cur = cur_ind++;
        ind[t][x] = cur;
        if (t == 0) {
            if (lx < n) {
                adj[cur].emplace_back(build(2 * x + 1, lx, m, t), 0);
            }
            if (m < n) {
                adj[cur].emplace_back(build(2 * x + 2, m, rx, t), 0);
            }
        } else {
            if (lx < n) {
                adj[build(2 * x + 1, lx, m, t)].emplace_back(cur, 0);
            }
            if (m < n) {
                adj[build(2 * x + 2, m, rx, t)].emplace_back(cur, 0);
            }
        }
        return cur;
    }

    void init() {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        ind[0].resize(2 * size);
        ind[1].resize(2 * size);
        build(0, 0, size, 0);
        build(0, 0, size, 1);
    }

    void upd(int l, int r, int p, int w, int x, int lx, int rx, int t) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            if (t == 0) {
                adj[p].emplace_back(ind[t][x], w);
            } else {
                adj[ind[t][x]].emplace_back(p, w);
            }
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, p, w, 2 * x + 1, lx, m, t), upd(l, r, p, w, 2 * x + 2, m, rx, t);
    }

    void upd(int l, int r, int p, int w, int t) {
        upd(l, r, p, w, 0, 0, size, t);
    }
};

void test_case() {
    int q, s;
    cin >> n >> q >> s;
    cur_ind = n;
    segtree seg;
    seg.init();
#ifdef DEBUG
    cout << cur_ind << "\n";
    for (int i = 0; i < cur_ind; ++i) {
        cout << i << ": ";
        for (auto &j : adj[i]) {
            cout << j.first << " ";
        }
        cout << "\n";
    }
    cout << "\n";
#endif
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int u, v, w;
            cin >> u >> v >> w;
            --u, --v;
            adj[u].emplace_back(v, w);
        } else if (t == 2) {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            --v, --l;
            seg.upd(l, r, v, w, 0);
        } else {
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            --v, --l;
            seg.upd(l, r, v, w, 1);
        }
#ifdef DEBUG
        cout << cur_ind << "\n";
        for (int i = 0; i < cur_ind; ++i) {
            cout << i << ": ";
            for (auto &j : adj[i]) {
                cout << j.first << " ";
            }
            cout << "\n";
        }
        cout << "\n";
#endif
    }
    memset(dist, 0x3f, sizeof(dist));
    --s;
    dist[s] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        pair<long long, int> cur = pq.top();
        pq.pop();
        for (auto &i : adj[cur.second]) {
            if (dist[i.first] > cur.first + i.second) {
                pq.push({dist[i.first] = cur.first + i.second, i.first});
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << (dist[i] == INFL ? -1 : dist[i]) << " \n"[i == n - 1];
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
