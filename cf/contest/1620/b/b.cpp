/* Author: izhang05
 * Time: 12-19-2021 00:37:45
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
    long long w, h;
    cin >> w >> h;
    long long sol = 0;
    for (long long i = 0; i < 2; ++i) {
        long long k;
        cin >> k;
        long long cur;
        cin >> cur;
        for (long long j = 1; j < k-1; ++j) {
            long long _;
            cin >> _;
        }
        long long a;
        cin >> a;
        sol = max(sol, (a - cur) * h);
    }
    for (long long i = 0; i < 2; ++i) {
        long long k;
        cin >> k;
        long long cur;
        cin >> cur;
        for (long long j = 1; j < k-1; ++j) {
            long long _;
            cin >> _;
        }
        long long a;
        cin >> a;
        sol = max(sol, (a - cur) * w);
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
