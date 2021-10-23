/* Author: izhang05
 * Time: 10-22-2021 19:28:30
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = 0;
    while (true) {
        bool sorted = true;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] > a[i]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            break;
        }
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (a[i] > x) {
                swap(a[i], x);
                ++sol;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << "\n";
            return;
        }
    }
    cout << sol << "\n";
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
