/* Author: izhang05
 * Time: 07-25-2021 10:36:09
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
bool inter(pair<int, int> a, pair<int, int> b) {
    assert(a.first < a.second && b.first < b.second);
    return (b.first < a.first && b.second > a.first && b.second < a.second) || (a.first < b.first && a.second > b.first && a.second < b.second);
}
const int maxn = 105;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(k);
    vector<int> used(2 * n);
    for (int i = 0; i < k; ++i) {
        cin >> a[i].first >> a[i].second;
        --a[i].first, --a[i].second;
        used[a[i].first] = true, used[a[i].second] = true;
        if (a[i].first > a[i].second) {
            swap(a[i].first, a[i].second);
        }
    }
    sort(a.begin(), a.end());

    vector<int> unused;
    for (int i = 0; i < 2 * n; ++i) {
        if (!used[i]) {
            unused.push_back(i);
        }
    }
    for (int i = 0; i < n - k; ++i) {
        a.emplace_back(unused[i], unused[i + n - k]);
    }
    int sol = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (inter(a[i], a[j])) {
                ++sol;
            }
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
