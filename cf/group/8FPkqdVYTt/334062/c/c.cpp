/* Author: izhang05
 * Time: 07-10-2021 14:30:03
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

template<class T, int SZ>
struct OffBIT2D {
    bool mode = 0;               // mode = 1 -> initialized
    vector<pair<int, int>> todo; // locations of updates to process
    int cnt[SZ], st[SZ];
    vector<int> val;
    vector<T> bit; // store all BITs in single vector
    void init() {
        assert(!mode);
        mode = 1;
        int lst[SZ];
        for (int i = 0; i < SZ; ++i) {
            lst[i] = cnt[i] = 0;
        }
        sort(todo.begin(), todo.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; });
        for (auto &t : todo) {
            for (int x = t.first; x < SZ; x += x & -x)
                if (lst[x] != t.second) lst[x] = t.second, cnt[x]++;
        }
        int sum = 0;
        for (int i = 0; i < SZ; ++i) {
            lst[i] = 0,
            st[i] = (sum += cnt[i]);
        }
        val.resize(sum);
        bit.resize(sum);
        reverse(todo.begin(), todo.end());
        for (auto &t : todo) {
            for (int x = t.first; x < SZ; x += x & -x)
                if (lst[x] != t.second) lst[x] = t.second, val[--st[x]] = t.second;
        }
    }
    int rank(int y, int l, int r) {
        return upper_bound(begin(val) + l, begin(val) + r, y) - begin(val) - l;
    }
    void UPD(int x, int y, T t) {
        for (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x]; y += y & -y)
            bit[st[x] + y - 1] += t;
    }
    void upd(int x, int y, T t) {
        if (!mode) todo.emplace_back(x, y);
        else
            for (; x < SZ; x += x & -x) UPD(x, y, t);
    }
    int QUERY(int x, int y) {
        T res = 0;
        for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y) res += bit[st[x] + y - 1];
        return res;
    }
    T query(int x, int y) {
        assert(mode);
        T res = 0;
        for (; x; x -= x & -x) res += QUERY(x, y);
        return res;
    }
    T query(int xl, int xr, int yl, int yr) {
        return query(xr, yr) - query(xl - 1, yr) - query(xr, yl - 1) + query(xl - 1, yl - 1);
    }
};
const int maxn = 1e5 + 5;
OffBIT2D<int, maxn> bit;

int main() {
    setIO("friendcross");
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> occ(n);
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        --a;
        occ[a].first = i + 1;
    }
    for (int i = 0; i < n; ++i) {
        int b;
        cin >> b;
        --b;
        occ[b].second = i + 1;
        bit.upd(occ[b].first, i + 1, 1);
    }
    bit.init();
    long long sol = 0;
    for (int i = k + 1; i < n; ++i) {
        bit.upd(occ[i - k - 1].first, occ[i - k - 1].second, 1);
#ifdef DEBUG
        cout << i << " " << bit.query(occ[i].first + 1, n, 1, occ[i].second - 1) + bit.query(1, occ[i].first - 1, occ[i].second + 1, n) << "\n";
#endif
        sol += bit.query(occ[i].first + 1, n, 1, occ[i].second - 1) + bit.query(1, occ[i].first - 1, occ[i].second + 1, n);
    }
    cout << sol << "\n";
    return 0;
}
