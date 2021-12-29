/* Author: izhang05
 * Time: 12-29-2021 10:35:02
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int sol = n - 1;
    for (int i = 0; i < n; ++i) {
        for (int l = i + 1; l < n; ++l) {
            int cnt = 1;
            int d = a[l] - a[i], k = (l - i);
            int g = __gcd(d, k);
            d /= g, k /= g;
            for (int j = i + 1; j < n; ++j) {
                if ((j - i) % k == 0) {
                    if (a[j] == a[i] + d * ((j - i) / k)) {
                        ++cnt;
                    }
                }
            }
            sol = min(sol, n - cnt);
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
