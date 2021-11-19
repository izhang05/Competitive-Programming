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

[[maybe_unused]] const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 1e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        edges[i] = {i + 1, i + 2};
    }
    m -= n - 1;
    if (m != 0) {
        for (int r = 3; r <= n && m; ++r) {
            for (int i = 1; i < r - 1 && m; ++i) {
                edges.emplace_back(i, r);
                --m;
            }
        }
    }
    for (auto &i : edges) {
        cout << i.first << " " << i.second << "\n";
    }

}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
