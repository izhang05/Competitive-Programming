/* Author: izhang05
 * Time: 10-29-2021 20:55:47
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e5 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
vector<int> adj[maxn];
int n;

int min_reg(pair<int, int> x) {
    return min(x.second - x.first, x.first - x.second + n);
}

void solve() {
    int m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first, --a[i].second;
        if (a[i].first > a[i].second) {
            swap(a[i].first, a[i].second);
        }
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return min_reg(left) < min_reg(right);
    });
    // create tree with m + 1 nodes
    for (auto &i : a) {
        cout << i.first << " " << i.second << "\n";
    }

    int cur = m;
    for (auto &i : a) {
    }
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
