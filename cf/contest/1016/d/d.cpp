/* Author: izhang05
 * Time: 10-30-2021 22:03:55
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 105;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int sol[maxn][maxn];

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int a_sum = 0, b_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a_sum ^= a[i];
    }
    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        b_sum ^= b[i];
    }
    if (a_sum != b_sum) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int cur = a[0];
    for (int i = 1; i < m; ++i) {
        cur ^= b[i];
    }
    cout << cur;
    for (int i = 1; i < m; ++i) {
        cout << " " << b[i];
    }
    cout << "\n";
    for (int i = 1; i < n; ++i) {
        cout << a[i];
        for (int j = 1; j < m; ++j) {
            cout << " 0";
        }
        cout << "\n";
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
