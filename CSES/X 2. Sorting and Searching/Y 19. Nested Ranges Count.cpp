#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct range {
    int l, r, ind;
    bool operator<(const range &rhs) const {
        return l == rhs.l ? r > rhs.r : l < rhs.l;
    }
};

int main() {
    setIO("19");
    int n;
    cin >> n;
    vector<range> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        a[i].ind = i;
    }
    sort(a.begin(), a.end());
    indexed_set<pair<int, int>> seen;
    vector<vector<int>> sol(2, vector<int>(n));
    reverse(a.begin(), a.end());
    for (auto &i : a) {
        sol[0][i.ind] = (int) seen.order_of_key({i.r, inf});
        seen.insert({i.r, i.ind});
    }
    seen.clear();
    reverse(a.begin(), a.end());
    for (auto &i : a) {
        sol[1][i.ind] = int(seen.size()) - seen.order_of_key({i.r, -inf});
        seen.insert({i.r, i.ind});
    }

    for (int i = 0; i < 2; ++i) {
        for (auto &j : sol[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}
