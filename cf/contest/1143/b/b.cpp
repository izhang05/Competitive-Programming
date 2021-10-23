/* Author: izhang05
 * Time: 10-22-2021 19:11:22
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

void solve() {
    long long n;
    cin >> n;
    vector<long long> num;
    long long sol = 1;
    while (n) {
        num.push_back(n % 10);
        sol *= n % 10;
        n /= 10;
    }
    reverse(num.begin(), num.end());
    long long cur = 1;
    for (int i = 0; i < int(num.size()); ++i) {
        long long cur_val = cur * max(1ll, num[i] - 1);
        for (int j = i + 1; j < int(num.size()); ++j) {
            cur_val *= 9;
        }
        sol = max(sol, cur_val);
        cur *= num[i];
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
