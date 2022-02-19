/* Author: izhang
 * Time: 02-19-2022 02:17:18
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
    vector<pair<long long, long long>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol += max(0ll, a[(i + 1) % n].first - a[i].second);
        a[(i + 1) % n].first = min(a[(i + 1) % n].first, a[i].second);
    }
    long long mn = INFL;
    for (int i = 0; i < n; ++i) {
        mn = min(mn, a[i].first);
    }
    cout << sol + mn << "\n";
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
