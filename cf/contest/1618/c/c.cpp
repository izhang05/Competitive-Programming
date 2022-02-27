/* Author: izhang
 * Time: 02-27-2022 11:20:27
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
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    long long g1 = a[0], g2 = a[1];
    for (int i = 0; i < n; i += 2) {
        g1 = gcd(g1, a[i]);
    }
    for (int i = 1; i < n; i += 2) {
        g2 = gcd(g2, a[i]);
    }
    bool good = true;
    for (int i = 0; i < n; i += 2) {
        if (a[i] % g2 == 0) {
            good = false;
        }
    }
    if (good) {
        cout << g2 << "\n";
        return;
    }
    good = true;
    for (int i = 1; i < n; i += 2) {
        if (a[i] % g1 == 0) {
            good = false;
        }
    }
    if (good) {
        cout << g1 << "\n";
        return;
    }
    cout << 0 << "\n";
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
