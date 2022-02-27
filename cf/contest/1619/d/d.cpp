/* Author: izhang
 * Time: 02-25-2022 23:31:49
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
    int m, n;
    cin >> m >> n;
    vector<vector<int>> p(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> p[i][j];
        }
    }
    int lo = 0, hi = 1e9, mid, res;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        bool two = false;
        set<int> bad;
        for (int i = 0; i < n; ++i) {
            bad.insert(i);
        }
        for (int i = 0; i < m; ++i) {
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (p[i][j] >= mid) {
                    bad.erase(j);
                    ++cnt;
                }
            }
            if (cnt >= 2) {
                two = true;
            }
        }
        if (bad.empty() && two) {
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
