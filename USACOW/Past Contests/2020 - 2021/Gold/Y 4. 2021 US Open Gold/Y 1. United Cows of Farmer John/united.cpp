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

const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5;
int bit[maxn], n;
map<int, int> last;

void update(int p, int v) {
    for (; p <= n; p += p & (-p)) {
        bit[p] += v;
    }
}
long long query(int p) {
    long long res = 0;
    for (; p > 0; p -= p & (-p)) {
        res += bit[p];
    }
    return res;
}


int main() {
    setIO();
    cin >> n;
    vector<int> a(n + 1);
    map<int, int> l;
    vector<pair<int, int>> queries;
    for (int i = 1; i < n + 1; ++i) {
        cin >> a[i];
        if (l.find(a[i]) != l.end()) {
            queries.emplace_back(l[a[i]] + 1, i - 1);
        }
        l[a[i]] = i;
    }
    long long sol = 0;
    for (auto i : l) {
        if (i.second != n) {
            queries.emplace_back(i.second + 1, n);
        }
    }
    sort(queries.begin(), queries.end(), [](pair<int, int> left, pair<int, int> right) {
        return left.second == right.second ? left.first < right.first : left.second < right.second;
    });
#ifdef DEBUG
    for (auto i : queries) {
        cout << i.first << " " << i.second << "\n";
    }
#endif
    int ind = 1;
    vector<int> vals(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        pair<int, int> cur = queries[i];
        for (; ind <= cur.second; ++ind) {
            if (last.find(a[ind]) != last.end()) {
                update(last[a[ind]], -1);
                vals[last[a[ind]]] = 0;
            }
            last[a[ind]] = ind;
            vals[ind] = 1;
            update(ind, 1);
        }
#ifdef DEBUG
        cout << cur.first << " " << cur.second << " " << query(cur.second) - query(cur.first - 1) << "\n";
#endif
        sol += query(cur.second) - query(cur.first - 1);
    }
    cout << sol << "\n";
    return 0;
}
