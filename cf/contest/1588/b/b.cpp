/* Author: izhang05
 * Time: 11-15-2021 09:48:31
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
long long ask(int l, int r) {
    cout << "? " << l + 1 << " " << r + 1 << endl;
    long long res;
    cin >> res;
    if (res == -1) {
        exit(0);
    }
    return res;
}
void ans(int i, int j, int k) {
    cout << "! " << i + 1 << " " << j + 1 << " " << k << endl;
}

void solve() {
    int n;
    cin >> n;
    long long total = ask(0, n - 1);
    long long lo = 0, hi = n - 1, mid, l = -1;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (ask(mid, n - 1) == total) {
            l = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    long long a = total - ask(l + 1, n - 1) + 1;
    long long x = total - (a * (a - 1)) / 2;
    long long b = (1 + (long long) round(sqrt(1 + 8 * x))) / 2;
    ans(l, l + a, l + a + b);
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
