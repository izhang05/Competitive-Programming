/* Author: izhang05
 * Time: 12-23-2021 01:31:03
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct robot {
    int x, r, q;
};
struct event {
    int x, ind, t;
    bool operator<(const event &rhs) const {
        return x == rhs.x ? t < rhs.t : x < rhs.x;
    }
};

void test_case() {
    int n, k;
    cin >> n >> k;
    vector<robot> a(n);
    vector<event> e;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].r >> a[i].q;
        e.push_back({a[i].x, i, 0});
        e.push_back({a[i].x + a[i].r, i, 1});
    }
    sort(e.begin(), e.end());
    long long sol = 0;
    map<int, indexed_set<pair<int, int>>> seen;
    for (auto &i : e) {
        if (i.t == 0) {
            for (int j = a[i.ind].q - k; j <= a[i.ind].q + k; ++j) {
                if (seen.find(j) != seen.end()) {
                    sol += int(seen[j].size()) - seen[j].order_of_key({i.x - a[i.ind].r, -inf});
                }
            }
            seen[a[i.ind].q].insert({i.x, i.ind});
        } else {
            seen[a[i.ind].q].erase({i.x - a[i.ind].r, i.ind});
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
