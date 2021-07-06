/*
ID: izhang01
TASK: boards
LANG: C++11
*/

#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    freopen("boards.in", "r", stdin);
    freopen("boards.out", "w", stdout);
    freopen("boards.out", "w", stderr);
}
//#define DEBUG
struct node {
    long long mn;
    int lx, rx, lc{0}, rc{0};
};

struct segtree {
    int size = 1, cnt = 1;
    long long neutral = 1e18;
    vector<node> t;
    void init(int n) {
        while (size < n) {
            size *= 2;
        }
        t.resize(64 * size);
        t[0].lx = 0, t[0].rx = 1e9;
    }
    void create(int x) {
        int m = (t[x].lx + t[x].rx) / 2;
        if (!t[x].lc) {
            t[x].lc = cnt++;
            t[t[x].lc].lx = t[x].lx;
            t[t[x].lc].rx = m;
            t[t[x].lc].mn = neutral;
        }
        if (!t[x].rc) {
            t[x].rc = cnt++;
            t[t[x].rc].lx = m;
            t[t[x].rc].rx = t[x].rx;
            t[t[x].rc].mn = neutral;
        }
    }
    void upd(int p, long long v, int x) {
        if (t[x].rx - t[x].lx == 1) {
            t[x].mn = min(t[x].mn, v);
            return;
        }
        int m = (t[x].lx + t[x].rx) / 2;
        create(x);
        if (p < m) {
            upd(p, v, t[x].lc);
        } else {
            upd(p, v, t[x].rc);
        }
        t[x].mn = min(t[t[x].lc].mn, t[t[x].rc].mn);
    }

    long long query(int l, int r, int x) {
        if (t[x].lx >= r || t[x].rx <= l) {
            return neutral;
        }
        if (t[x].lx >= l && t[x].rx <= r) {
            return t[x].mn;
        }
        create(x);
        return min(query(l, r, t[x].lc), query(l, r, t[x].rc));
    }
};

int main() {
    setIO();
    int n, p;
    cin >> n >> p;
    segtree seg;
    seg.init(p);
    seg.upd(0, 0, 0);
    vector<long long> sol(p);
    vector<array<int, 4>> a;
    for (int i = 0; i < p; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a.push_back({y1, x1, 0, i});
        a.push_back({y2, x2, 1, i});
    }
    sort(a.begin(), a.end());
    for (auto &i : a) {
        int t = i[2];
        if (t == 0) {
            sol[i[3]] = seg.query(0, i[1] + 1, 0) + i[0] + i[1];
        } else {
            seg.upd(i[1], sol[i[3]] - i[0] - i[1], 0);
        }
    }
#ifdef DEBUG
    for (int i = 0; i < p; ++i) {
        cout << i << " " << sol[i] << "\n";
    }
#endif
    cout << seg.query(0, n + 1, 0) + 2 * n << "\n";
    return 0;
}
