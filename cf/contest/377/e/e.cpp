/* Author: izhang05
 * Time: 07-09-2021 12:20:47
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
    long long s;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left.second == right.second ? left.first > right.first : left.second < right.second;
    });
    return 0;
}
