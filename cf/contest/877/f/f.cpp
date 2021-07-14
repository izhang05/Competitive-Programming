/* Author: izhang05
 * Time: 07-12-2021 15:53:05
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, k = 320;
int n, a[maxn], diff;
long long pre[maxn], suf[maxn], cur;

map<long long, int> cnt, cnt_mn;

struct query {
    int l, r, ind;
    bool operator<(query other) const {
        if (l / k != other.l / k) {
            return l < other.l;
        }
        return (l / k & 1) ? (r < other.r) : (r > other.r);
    }
};

void add(int x, bool r) {
    if (r) {
        cur += cnt_mn[pre[x] - diff];
    } else {
        int sub = 0;
        if (x) {
            sub = x - 1;
        }
        cur += cnt[diff - sub];
    }
    ++cnt[pre[x]];
    long long p = 0;
    if (x) {
        p = pre[x - 1];
    }
    ++cnt_mn[p];
}

void remove(int x, bool r) {
    if (r) {
        cur -= cnt_mn[pre[x] - diff];
    } else {
        int sub = 0;
        if (x) {
            sub = x - 1;
        }
        cur -= cnt[diff - sub];
    }
    --cnt[pre[x]];
    long long p = 0;
    if (x) {
        p = pre[x - 1];
    }
    --cnt_mn[p];
}

int main() {
    setIO("1");
    cin >> n >> diff;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (t[i] == 2) {
            a[i] = -a[i];
        }
        pre[i] = pre[max(0, i - 1)] + a[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    int q;
    cin >> q;
    vector<query> queries(q);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        queries[i] = {l, r, i};
    }
    sort(queries.begin(), queries.end());
    vector<long long> sol(q);
    int l = 0, r = -1;
    for (auto &i : queries) {
        while (r < i.r) {
            ++r;
            add(r, true);
        }
        while (l > i.l) {
            --l;
            add(l, false);
        }
        while (r > i.r) {
            remove(r, true);
            --r;
        }
        while (l < i.l) {
            remove(l, false);
            ++l;
        }
        sol[i.ind] = cur;
    }
    for (auto &i : sol) {
        cout << i << "\n";
    }
    return 0;
}
