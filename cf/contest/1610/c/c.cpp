/* Author: izhang05
 * Time: 12-22-2021 16:30:02
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

void test_case() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    int lo = 0, hi = n, mid, sol = 0;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            if (cur + 1 + a[i].first >= mid && a[i].second >= cur) {
                ++cur;
            }
        }
        if (cur >= mid) {
            sol = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << sol << "\n";
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
