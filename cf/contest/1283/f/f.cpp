/* Author: izhang05
 * Time: 06-28-2021 20:15:26
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
    vector<int> a(n - 1);
    set<int> avail;
    for (int i = 1; i <= n; ++i) {
        avail.insert(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        cin >> a[i];
    }

    vector<pair<int, int>> sol(n - 1);
    for (int i = 0; i < n - 2; ++i) {
        avail.erase(a[i]);
        sol[i] = {a[i], *prev(avail.end())};
        avail.erase(prev(avail.end()));
    }
    sol[n - 2] = {a[n - 2], *avail.begin()};
    cout << a[0] << "\n";
    for (auto &i : sol) {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
