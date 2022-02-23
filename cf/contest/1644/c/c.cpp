/* Author: izhang
 * Time: 02-22-2022 15:57:31
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
    long long x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<long long> best(n + 1, -INFL);
    for (int i = 1; i <= n; ++i) {
        long long sum = 0;
        for (int j = 0; j < i; ++j) {
            sum += a[j];
        }
        best[i] = max(best[i], sum);
        for (int j = 0; j + i < n; ++j) {
            sum -= a[j];
            sum += a[j + i];
            best[i] = max(best[i], sum);
        }
    }
    for (int i = 0; i <= n; ++i) {
        long long sol = 0;
        for (int j = 0; j <= n; ++j) {
            sol = max(sol, best[j] + x * min(j, i));
        }
        cout << sol << " \n"[i == n];
    }
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
