/* Author: izhang05
 * Time: 07-01-2021 13:51:29
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

struct node {
    int mx, ind, lx{}, rx{}, lc, rc;
    node() : mx(0), ind(0), lc(-1), rc(-1) {}
};

struct segtree {
    int size = 1, cnt = 1;
    vector<node> t;

    void init(int n) {
        while (size < n) {
            size *= 2;
        }
        t.resize(64 * size);
    }

    void create(int x) {
        int m = (t[x].lx + t[x].rx) / 2;
        if (t[x].lc == -1) {
            t[x].lc = cnt++;
            t[t[x].lc].lx = t[x].lx;
            t[t[x].lc].rx = m;
        }
        if (t[x].rc == -1) {
            t[x].rc = cnt++;
            t[t[x].rc].lx = m;
            t[t[x].rc].rx = t[x].rx;
        }
    }
    void upd(int x, int p, int v, int ind) {
        if (t[x].rx - t[x].lx == 1) {
            t[x].mx = v;
            t[x].ind = ind;
            return;
        }
        int m = (t[x].lx + t[x].rx) / 2;
        if (p < m) {
            if (t[x].lc == -1) {
                t[x].lc = cnt++;
                t[t[x].lc].lx = t[x].lx;
                t[t[x].lc].rx = m;
            }
            upd(t[x].lc, p, v, ind);
            if (t[t[x].lc].mx > t[x].mx) {
                t[x].ind = t[t[x].lc].ind;
            }
            t[x].mx = max(t[x].mx, t[t[x].lc].mx);
        } else {
            if (t[x].rc == -1) {
                t[x].rc = cnt++;
                t[t[x].rc].lx = m;
                t[t[x].rc].rx = t[x].rx;
            }
            upd(t[x].rc, p, v, ind);
            if (t[t[x].rc].mx > t[x].mx) {
                t[x].ind = t[t[x].rc].ind;
            }
            t[x].mx = max(t[x].mx, t[t[x].rc].mx);
        }
    }

    pair<int, int> query(int x, int l, int r) {
        if (t[x].lx >= r || t[x].rx <= l) {
            return {0, 0};
        }
        if (t[x].lx >= l && t[x].rx <= r) {
            return {t[x].mx, t[x].ind};
        }
        create(x);
        pair<int, int> a = query(t[x].lc, l, r), b = query(t[x].rc, l, r);
        pair<int, int> res;
        res.first = max(a.first, b.first);
        if (a.first > b.first) {
            res.second = a.second;
        } else {
            res.second = b.second;
        }
        return res;
    }
};
template<class T>
void print(T a, string sep = " ", string end = "\n") {
    for (auto i : a) {
        cout << i << sep;
    }
    cout << end;
}
const int maxn = 1e5 + 5;
int par[maxn];

int main() {
    setIO("1");

    int n, d;
    cin >> n >> d;
    segtree seg;
    seg.init(n);
    seg.t[0].lx = 0, seg.t[0].rx = 1e9 + 1;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        seg.upd(0, h[i], 1, i);
        par[i] = i;
    }
    pair<int, int> best{1, 0};
    for (int i = 1; i < n; ++i) {
        pair<int, int> cur = seg.query(0, max(0, h[i] - d), h[i] + d + 1);
        par[i] = cur.second;
        best = max(best, {cur.first + 1, i});
        seg.upd(0, h[i], cur.first + 1, i);
    }
    cout << best.first << "\n";
    int cur = best.second;
    cout << cur << "\n";
    for (int i = 0; i < n; ++i) {
        cout << par[i] << "\n";
    }
    //    vector<int> sol;
//    cout << cur << endl;
//    while (par[cur] != cur) {
//        sol.push_back(cur + 1);
//        cur = par[cur];
//        cout << cur << endl;
//    }
//    sol.push_back(cur + 1);
//    reverse(sol.begin(), sol.end());
//    cout << sol.size() << "\n";
//    print(sol);
//    return 0;
}
