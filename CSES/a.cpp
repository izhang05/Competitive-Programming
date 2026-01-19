#include <bits/stdc++.h>

using namespace std;
#ifdef LOCAL
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, off = 100;

int cnt[6][6][200];

struct item {
    long long ;
};

struct segtree {
    int size{};
    vector<item> t;
    item neutral = ;

    void init(int n) {
        size = 1;
        while (size < n) {
            size *= 2;
        }
        t.resize(2 * size);
    }

    static item merge(item a, item b) {
        return ;
    }

    static item single(long long v) {
        return ;
    }

    void upd(int p, long long v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            t[x] = single(v);
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

long long solve(vector<string> &a) {
    memset(cnt, 0, sizeof(cnt));
    long long sol = 0;
    int n = (int) a.size();
    for (int i = 0; i < n; ++i) {
        string s = a[i];
        int m = (int) s.size();
        vector<int> cur(m);
        for (int j = 0; j < m; ++j) {
            cur[j] = s[j] - '0';
        }
        if (m == 1) {
            int v = cur[0];
            sol += cnt[1][1][v + off];
            sol += cnt[3][2][v + off];
            sol += cnt[5][3][v + off];
            ++cnt[1][1][v + off];
        } else if (m == 2) {
            sol += cnt[2][2][cur[0] + cur[1] + off];
            sol += cnt[4][3][cur[0] + cur[1] + off];
            ++cnt[2][2][cur[0] + cur[1] + off];
        } else if (m == 3) {
            sol += cnt[1][1][-cur[0] + cur[1] + cur[2] + off];
            sol += cnt[3][3][cur[0] + cur[1] + cur[2] + off];
            sol += cnt[5][4][cur[0] + cur[1] + cur[2] + off];

            ++cnt[3][3][cur[0] + cur[1] + cur[2] + off];
            ++cnt[3][2][cur[0] + cur[1] - cur[2] + off];
        } else if (m == 4) {
            sol += cnt[4][4][cur[0] + cur[1] + cur[2] + cur[3] + off];
            sol += cnt[2][2][-cur[0] + cur[1] + cur[2] + cur[3] + off];
            ++cnt[4][4][cur[0] + cur[1] + cur[2] + cur[3] + off];
            ++cnt[4][3][cur[0] + cur[1] + cur[2] - cur[3] + off];
        } else if (m == 5) {
            sol += cnt[5][5][cur[0] + cur[1] + cur[2] + cur[3] + cur[4] + off];
            sol += cnt[3][3][-cur[0] + cur[1] + cur[2] + cur[3] + cur[4] + off];
            sol += cnt[1][1][-cur[0] - cur[1] + cur[2] + cur[3] + cur[4] + off];

            ++cnt[5][5][cur[0] + cur[1] + cur[2] + cur[3] + cur[4] + off];
            ++cnt[5][4][cur[0] + cur[1] + cur[2] + cur[3] - cur[4] + off];
            ++cnt[5][3][cur[0] + cur[1] + cur[2] - cur[3] - cur[4] + off];
        }

        //        int cur = 0;
        //        for (int j = 1; j <= m; ++j) {
        //            cur += s[j - 1] - '0';
        //            ++cnt[m][j][cur];
        //        }
    }
    return sol;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = solve(a);
//    cout << sol << "\n";
    reverse(a.begin(), a.end());
    sol += solve(a) + n;
    cout << sol << "\n";
    return 0;
}
