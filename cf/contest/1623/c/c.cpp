/* Author: izhang
 * Time: 01-12-2022 13:16:51
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7; //998244353;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void test_case() {
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int lo = 0, hi = 1e9, mid, res;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        vector<int> a(h.begin(), h.end());
        bool good = true;
        for (int i = 2; i < n; ++i) {
            int d = min(a[i] / 3, max({0, mid - a[i - 1], (mid - a[i - 2] + 1) / 2}));
            a[i - 1] += d, a[i - 2] += 2 * d, a[i] -= 3 * d;
            if (a[i] < 0) {
                good = false;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] < mid) {
                good = false;
            }
        }
        if (good) {
            res = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << res << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
