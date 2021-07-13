/* Author: izhang05
 * Time: 07-12-2021 18:32:39
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 2e5 + 5, k = 450;

struct query {
    int l, r, ind;
    bool operator<(query other) const {
        if (l / k != other.l / k) {
            return l < other.l;
        }
        return (l / k & 1) ? (r < other.r) : (r > other.r);
    }
};
const int maxa = 1e6 + 5;
long long cnt[maxa], cur = 0, a[maxn];

void add(int x) {
    cur -= cnt[a[x]] * cnt[a[x]] * a[x];
    ++cnt[a[x]];
    cur += cnt[a[x]] * cnt[a[x]] * a[x];
}

void remove(int x) {
    cur -= cnt[a[x]] * cnt[a[x]] * a[x];
    --cnt[a[x]];
    cur += cnt[a[x]] * cnt[a[x]] * a[x];
}
int main() {
    setIO("2");

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
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
            add(r);
        }
        while (l > i.l) {
            --l;
            add(l);
        }
        while (r > i.r) {
            remove(r);
            --r;
        }
        while (l < i.l) {
            remove(l);
            ++l;
        }
        sol[i.ind] = cur;
    }
    for (auto &i : sol) {
        cout << i << "\n";
    }
    return 0;
}
