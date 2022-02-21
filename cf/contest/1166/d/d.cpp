/* Author: izhang
 * Time: 02-21-2022 00:11:02
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
const long long INFL = 0x3f3f3f3f3f3f3f3f, mx = 1e14;

void test_case() {
    long long t1, t2, t3;
    cin >> t1 >> t2 >> t3;
    __int128 a = t1, b = t2, m = t3;
    if (a == b) {
        cout << 1 << " " << (long long) a << "\n";
        return;
    }
    for (int i = 2; i <= 50; ++i) {
        __int128 coef = 1ll << (i - 2);
        if (coef * a > b) {
            break;
        }
        __int128 cur = b - coef * a;
        vector<long long> sol;
        for (int j = i - 3; j >= 0; --j) {
            coef = 1ll << j;
            __int128 lo = 1, hi = m, mid, res = 1;
            while (lo <= hi) {
                mid = (lo + hi) / 2;
                if (cur - coef * mid >= coef) {
                    res = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            cur -= coef * res;
            sol.push_back(res);
        }
        if (cur >= 1 && cur <= m) {
            sol.push_back(cur);
            cur = 0;
        }
        if (cur == 0) {
            cout << sol.size() + 1 << " ";
            __int128 sum = a;
            cout << (long long) sum;
            for (auto &j : sol) {
                cout << " " << (long long) (sum + j);
                sum *= 2;
                sum += j;
            }
            cout << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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
