/* Author: izhang05
 * Time: 11-01-2021 14:48:03
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
    vector<int> a(n);
    map<int, int> count;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++count[a[i]];
    }
    int b;
    for (auto &i : count) {
        if (i.second == 1) {
            b = i.first;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (a[i] == b) {
            cout << i + 1 << "\n";
            return;
        }
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
