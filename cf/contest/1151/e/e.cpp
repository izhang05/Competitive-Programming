/* Author: izhang
 * Time: 02-17-2022 22:40:56
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

int n;
long long contrib(long long x, long long y) {
    if (x <= y) {
        return (y - x) * (x);
    } else {
        return (x - y) * (n - x + 1);
    }
}

void test_case() {
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long sol = 0;
    a.insert(a.begin(), 0);
    a.push_back(0);
    for (int i = 1; i < n + 1; ++i) {
        sol += contrib(a[i], a[i - 1]) + contrib(a[i], a[i + 1]);
    }
    cout << sol / 2 << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
