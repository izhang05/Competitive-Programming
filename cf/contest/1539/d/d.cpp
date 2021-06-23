/* Author: izhang05
 * Time: 06-22-2021 21:25:02
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

int main() {
    setIO("1");

    int n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left.second == right.second ? left.first < right.first : left.second < right.second;
    });
    long long sol = 0, bought = 0;
    int l = 0, r = n - 1;
    while (l <= r) {
        if (bought >= a[l].second) {
            sol += a[l].first;
            bought += a[l].first;
            ++l;
        } else {
            long long take = min(a[r].first, a[l].second - bought);
            a[r].first -= take;
            sol += 2 * take;
            bought += take;
            if (!a[r].first) {
                --r;
            }
        }
    }
    cout << sol << "\n";
    return 0;
}
