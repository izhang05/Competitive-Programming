/* Author: izhang05
 * Time: 09-14-2021 16:11:20
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

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    map<long long, int> right, left;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++right[a[i]];
    }
    __int128 sol = 0;
    for (int i = 0; i < n; ++i) {
        sol -= a[i] * (n - i - 1 - right[a[i] + 1] - right[a[i] - 1]);
        sol += a[i] * (i - left[a[i] + 1] - left[a[i] - 1]);
        --right[a[i]], ++left[a[i]];
    }
    if (sol == 0) {
        cout << 0 << "\n";
        return;
    }
    if (sol < 0) {
        cout << "-";
        sol = -sol;
    }
    vector<int> res;
    while (sol) {
        res.push_back(sol % 10);
        sol /= 10;
    }
    reverse(res.begin(), res.end());
    for (auto &i : res) {
        cout << i;
    }
    cout << "\n";
}

int main() {
    setIO("1");

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
