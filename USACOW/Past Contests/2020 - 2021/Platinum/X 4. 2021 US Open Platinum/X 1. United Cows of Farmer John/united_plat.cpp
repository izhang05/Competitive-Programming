#include <bits/stdc++.h>

using namespace std;

void setIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
    freopen("1.out", "w", stderr);
#endif
}
//#define DEBUG
const int maxn = 2e5 + 5;
set<int> occ[maxn];

struct item {
    long long sum, lz_add;
};

struct segtree {
    int size{};
    vector<item> t;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    void apply_push(int x, long long v, int len) {
        t[x].lz_add += v;
        t[x].sum += len * v;
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        apply_push(2 * x + 1, t[x].lz_add, rx - lx);
        apply_push(2 * x + 2, t[x].lz_add, rx - lx);
        t[x].lz_add = 0;
    }

    void upd(int l, int r, long long v, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            apply_push(x, v, rx - lx);
            return;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
        t[x].sum = t[2 * x + 1].sum + t[2 * x + 2].sum;
    }

    void upd(int l, int r, long long v) {
        upd(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return t[x].sum;
        }
        propagate(x, lx, rx);
        int m = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, m) + query(l, r, 2 * x + 2, m, rx);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    long long query(int p) {
        return query(p, p + 1);
    }
};


int main() {
    setIO();
    int n;
    cin >> n;
    vector<int> a(n), nxt(n), pre(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
        occ[a[i]].insert(i);
    }
    vector<vector<int>> process(n);
    for (int i = 0; i < n; ++i) {
        auto it = occ[a[i]].upper_bound(i);
        if (it != occ[a[i]].end()) {
            nxt[i] = *it;
        } else {
            nxt[i] = n;
        }
        it = occ[a[i]].lower_bound(i);
        if (it != occ[a[i]].begin()) {
            pre[i] = *(prev(it));
        } else {
            pre[i] = -1;
        }
        process[pre[i] + 1].push_back(i);
    }
    segtree seg;
    seg.init(n);
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        cout << "process: ";
        for (auto &j : process[i]) {
            if (j > i) {
                cout << j << " ";
                seg.upd(j, n, 1);
            }
        }
        cout << "\n";
        for (int j = 0; j < n; ++j) {
            cout << seg.query(j) << " ";
        }
        cout << "\n";
        for (int j = i + 1; j < nxt[i]; ++j) {
            if (pre[j] > i) {
                continue;
            }
            sol += seg.query(min(nxt[i], nxt[j]) - 1) - seg.query(j);
            cout << min(nxt[i], nxt[j]) - 1 << " " << j << " " << seg.query(min(nxt[i], nxt[j]) - 1) << " " << seg.query(j) << "\n";
        }
        cout << sol << "\n";
    }
    cout << sol << "\n";
    return 0;
}


//#include <bits/stdc++.h>
//
//using namespace std;
//
//void setIO() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cin.exceptions(istream::failbit);
//#ifdef LOCAL
//    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
//    freopen("1.out", "w", stderr);
//#endif
//}
//#define DEBUG
//const int maxn = 2e5 + 5;
//set<int> occ[maxn];
//
//int main() {
//    setIO();
//    int n;
//    cin >> n;
//    vector<int> a(n), nxt(n), pre(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//        --a[i];
//        occ[a[i]].insert(i);
//    }
//    vector<vector<int>> process(n);
//    for (int i = 0; i < n; ++i) {
//        auto it = occ[a[i]].upper_bound(i);
//        if (it != occ[a[i]].end()) {
//            nxt[i] = *it;
//        } else {
//            nxt[i] = n;
//        }
//        it = occ[a[i]].lower_bound(i);
//        if (it != occ[a[i]].begin()) {
//            pre[i] = *(prev(it));
//        } else {
//            pre[i] = -1;
//        }
//        process[pre[i] + 1].push_back(i);
//    }
//    long long sol = 0;
//    for (int i = 0; i < n; ++i) {
//        vector<int> prefix(n);
//        for (int j = i + 1; j < n; ++j) {
//            prefix[j] = pre[j] <= i;
//            prefix[j] += prefix[j - 1];
//        }
//        for (int j = i + 1; j < nxt[i]; ++j) {
//            if (pre[j] > i) {
//                continue;
//            }
//            sol += prefix[min(nxt[i], nxt[j]) - 1] - prefix[j];
//        }
//    }
//    cout << sol << "\n";
//    return 0;
//}
