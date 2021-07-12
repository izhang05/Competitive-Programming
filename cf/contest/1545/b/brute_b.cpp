/* Author: izhang05
 * Time: 07-11-2021 10:48:18
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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    int one = 0, zero = 0, pre = 0;
    vector<int> single;
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
        if (a[i] == 0) {
            ++zero;
            pre = 0;
        } else {
            if (pre == 1) {
                ++one;
                pre = 0;
            } else {
                pre = 1;
                single.push_back(i);
            }
        }
    }
    long long sol = 0;
    for (int i = 0; i < (1 << (n - 1)); ++i) {
        int c_one = 0, c_zero = 0;
        pre = 0;
        for (int j = 0; j < n; ++j) {
            if (!(i & (1 << j))) {
                ++c_zero;
                pre = 0;
            } else {
                if (pre == 1) {
                    ++c_one;
                    pre = 0;
                } else {
                    pre = 1;
                }
            }
        }
        if (one == c_one && zero == c_zero) {
            ++sol;
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
