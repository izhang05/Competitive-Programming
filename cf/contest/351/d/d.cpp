/* Author: izhang05
 * Time: 07-12-2021 21:00:24
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5, k = 300;

struct query {
    int l, r, ind;
    bool operator<(query other) const {
        if (l / k != other.l / k) {
            return l < other.l;
        }
        return (l / k & 1) ? (r < other.r) : (r > other.r);
    }
};
int cnt[maxn], cur = 0, a[maxn], good = 0;
deque<int> occ[maxn];
map<int, int> diff[maxn];
bool g[maxn];

void add(int x, bool r) {
    ++cnt[a[x]];
    if (cnt[a[x]] == 1) {
        ++good;
        g[a[x]] = true;
        ++cur;
    } else {
        int y;
        if (r) {
            y = occ[a[x]].back();
        } else {
            y = occ[a[x]].front();
        }
        ++diff[a[x]][abs(x - y)];
        if (diff[a[x]].size() >= 2) {
            if (g[a[x]]) {
                --good;
                g[a[x]] = false;
            }
        }
    }
    if (r) {
        occ[a[x]].push_back(x);
    } else {
        occ[a[x]].push_front(x);
    }
}

void remove(int x, bool r) {
    --cnt[a[x]];
    int y;
    if (r) {
        y = occ[a[x]].back();
        occ[a[x]].pop_back();
    } else {
        y = occ[a[x]].front();
        occ[a[x]].pop_front();
    }
    if (!cnt[a[x]]) {
        --good;
        --cur;
        g[a[x]] = false;
    } else {
        int z;
        if (r) {
            z = occ[a[x]].back();
        } else {
            z = occ[a[x]].front();
        }
        if (--diff[a[x]][abs(y - z)] == 0) {
            diff[a[x]].erase(abs(y - z));
            if (diff[a[x]].size() <= 1) {
                if (!g[a[x]]) {
                    ++good;
                    g[a[x]] = true;
                }
            }
        }
    }
}
int main() {
    setIO("2");

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
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
        if (!good) {
            ++sol[i.ind];
        }
    }
    for (auto &i : sol) {
        cout << i << "\n";
    }
    return 0;
}
