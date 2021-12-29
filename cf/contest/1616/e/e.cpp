/* Author: izhang05
 * Time: 12-29-2021 10:35:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
struct item {
    char mn;
    int ind;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = {'z' + 1, maxn};

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        if (a.mn <= b.mn) {
            return {a.mn, a.ind};
        }
        return {b.mn, b.ind};
    }

    static item single(char v, int pos) {
        return {v, pos};
    }

    void upd(int p, char v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v, p);
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

    void upd(int p, char v) {
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

void test_case() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (s < t) {
        cout << 0 << "\n";
        return;
    }
    if (*min_element(s.begin(), s.end()) >= *max_element(t.begin(), t.end())) {
        cout << -1 << "\n";
        return;
    }
    segtree seg;
    seg.init(n);
    for (int i = 0; i < n; ++i) {
        seg.upd(i, s[i]);
    }
    int j = 0, sol = 0, offset = 0;
    vector<int> take(n, 0);
    while (true) {
        while (j < n && s[j - offset] == t[j]) {
            ++j;
            if (take[j - offset]) {
                --offset;
            }
            if (j == n || t[j] != t[j - 1]) {
                break;
            }
        }
        item cur = seg.query(j - offset, n);
        int pre = -1;
        if (cur.mn == t[j]) {
            pre = cur.ind - (j - offset);
        }
        if (cur.mn >= t[j]) {
            item new_cur = seg.query(j - offset, n);
            if (new_cur.mn < t[j - 1]) {
                sol += new_cur.ind - (j - 1 - offset);
                break;
            } else if (pre != -1) {
                sol += pre;
                ++j;
            } else {
                seg.upd(new_cur.ind, 'z' + 1);
                take[new_cur.ind] = true;
                sol += new_cur.ind - (j - 1 - offset);
            }
        } else {
            sol += cur.ind - (j - offset);
            if (cur.mn < t[j]) {
                break;
            }
            seg.upd(cur.ind, 'z' + 1);
            take[cur.ind] = true;
            ++j;
        }
        ++offset;
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
