/* Author: izhang05
 * Time: 06-26-2021 13:15:02
**/
#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifndef TEST
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}
const long long inf = 1e18;

struct item {
    long long mn;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {inf};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
        reset();
    }

    void reset() {
        for (int i = 0; i < 2 * size; ++i) {
            t[i] = neutral;
        }
    }

    static item merge(item a, item b) {
        return {min(a.mn, b.mn)};
    }

    static item single(long long v) {
        return {v};
    }

    void upd(int p, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(min(v, t[x].mn));
            return;
        }
        int m = (lx + rx) / 2;
        if (p < m) {
            upd(p, v, 2 * x + 1, lx, m);
        } else {
            upd(p, v, 2 * x + 2, m, rx);
        }
        t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
    }

    void upd(int p, long long v) {
        upd(p, v, 0, 0, size);
    }

    item query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return neutral;
        }
        if (lx >= l && rx <= r) {
            return t[x];
        }
        int m = (lx + rx) / 2;

        return merge(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }

    item query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

struct sling {
    int x, y, t, cx, cy;
};

struct query {
    int a, b, ind, ca, cb;
};

int main() {
    setIO("slingshot");
    int n, m;
    cin >> n >> m;
    vector<long long> sol(m);
    vector<vector<sling>> s(2);
    vector<vector<query>> q(2);
    set<int> points;
    for (int i = 0; i < 2; ++i) {
        s[i].reserve(n);
        q[i].reserve(n);
    }
    for (int i = 0; i < n; ++i) {
        sling cur{};
        cin >> cur.x >> cur.y >> cur.t;
        points.insert(cur.x);
        points.insert(cur.y);
        if (cur.x <= cur.y) {
            s[0].push_back(cur);
        } else {
            swap(cur.x, cur.y);
            s[1].push_back(cur);
        }
    }

    for (int i = 0; i < m; ++i) {
        query cur{};
        cin >> cur.a >> cur.b;
        points.insert(cur.a);
        points.insert(cur.b);
        cur.ind = i;
        if (cur.a <= cur.b) {
            q[0].push_back(cur);
        } else {
            swap(cur.a, cur.b);
            q[1].push_back(cur);
        }
        sol[i] = cur.b - cur.a;
    }
    unordered_map<int, int> ind;
    int cur_i = 0;
    for (auto &i : points) {
        ind[i] = cur_i++;
    }
    for (int i = 0; i < 2; ++i) {
        for (auto &j : s[i]) {
            j.cx = ind[j.x];
            j.cy = ind[j.y];
        }
        for (auto &j : q[i]) {
            j.ca = ind[j.a];
            j.cb = ind[j.b];
        }
    }
    for (int i = 0; i < 2; ++i) {
#ifdef DEBUG
        cout << "first"
             << "\n";
#endif
        sort(q[i].begin(), q[i].end(), [](auto left, auto right) {
            return left.b == right.b ? left.a < right.a : left.b < right.b;
        });
        sort(s[i].begin(), s[i].end(), [](auto left, auto right) {
            return left.y == right.y ? left.x < right.x : left.y < right.y;
        });
#ifdef DEBUG
        cout << "q"
             << "\n";
        for (auto &j : q[i]) {
            cout << j.a << " " << j.b << " " << j.ind << "\n";
        }
        cout << "s"
             << "\n";
        for (auto &j : s[i]) {
            cout << j.x << " " << j.y << " " << j.t << "\n";
        }
        cout << "\n";
#endif
        segtree less, greater;
        less.init((int) ind.size()), greater.init((int) ind.size());
        int k = 0;
        for (auto &j : q[i]) {
            while (k < int(s[i].size()) && s[i][k].y <= j.b) {
                less.upd(s[i][k].cx, -s[i][k].x - s[i][k].y + s[i][k].t);
                greater.upd(s[i][k].cx, s[i][k].x - s[i][k].y + s[i][k].t);
                ++k;
            }
#ifdef DEBUG
            cout << j.a << " " << j.b << " " << j.ind << " " << greater.query(j.ca, j.cb + 1).mn + j.b - j.a << " " << less.query(0, j.ca).mn + j.b + j.a << "\n";
#endif
            sol[j.ind] = min({sol[j.ind], greater.query(j.ca, j.cb + 1).mn + j.b - j.a, less.query(0, j.ca).mn + j.b + j.a});
        }
#ifdef DEBUG
        cout << "second"
             << "\n";
#endif
        sort(q[i].begin(), q[i].end(), [](auto left, auto right) {
            return left.a == right.a ? left.b < right.b : left.a < right.a;
        });
        sort(s[i].begin(), s[i].end(), [](auto left, auto right) {
            return left.x == right.x ? left.y < right.y : left.x < right.x;
        });
        reverse(q[i].begin(), q[i].end());
        reverse(s[i].begin(), s[i].end());

        greater.reset();
        k = 0;
        for (auto &j : q[i]) {
            while (k < int(s[i].size()) && s[i][k].x >= j.a) {
                greater.upd(s[i][k].cy, s[i][k].x + s[i][k].y + s[i][k].t);
                ++k;
            }
#ifdef DEBUG
            cout << j.a << " " << j.b << " " << j.ind << " " << greater.query(j.cb, int(ind.size())).mn - j.a - j.b << "\n";
#endif
            sol[j.ind] = min(sol[j.ind], greater.query(j.cb, int(ind.size())).mn - j.a - j.b);
        }
#ifdef DEBUG
        cout << "third"
             << "\n";
#endif
        sort(q[i].begin(), q[i].end(), [](auto left, auto right) {
            return left.a == right.a ? left.b < right.b : left.a < right.a;
        });
        sort(s[i].begin(), s[i].end(), [](auto left, auto right) {
            return left.x == right.x ? left.y < right.y : left.x < right.x;
        });

        greater.reset();
        k = 0;
        for (auto &j : q[i]) {
            while (k < int(s[i].size()) && s[i][k].x < j.a) {
                greater.upd(s[i][k].cy, -s[i][k].x + s[i][k].y + s[i][k].t);
                ++k;
            }
#ifdef DEBUG
            cout << j.a << " " << j.b << " " << j.ind << " " << greater.query(j.cb, int(ind.size())).mn + j.a - j.b << "\n";
#endif
            sol[j.ind] = min(sol[j.ind], greater.query(j.cb, int(ind.size())).mn + j.a - j.b);
        }
    }
    for (auto &i : sol) {
        cout << i << "\n";
    }
    return 0;
}
