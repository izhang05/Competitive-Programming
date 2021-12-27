/* Author: izhang05
 * Time: 12-27-2021 09:35:02
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
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum <= k) {
        cout << 0 << "\n";
        return;
    }
    if (n == 1) {
        cout << a[0] - k << "\n";
        return;
    }
    sort(a.begin(), a.end());
    vector<long long> suf(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        suf[i] = suf[i + 1] + a[i];
    }
    long long sol = INFL;
    for (int i = 1; i <= n; ++i) {
        long long goal = k - (suf[1] - suf[i]), new_a = goal / (n - i + 1);
        while (new_a * (n - i + 1) > goal) {
            --new_a;
        }
        sol = min(sol, max(0ll, a[0] - new_a) + (n - i));
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
