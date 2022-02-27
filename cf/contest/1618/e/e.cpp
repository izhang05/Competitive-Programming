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
    vector<int> b(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
        sum += b[i];
    }
    long long tri = ((long long) n * (n + 1)) / 2;
    if (sum % tri != 0) {
        cout << "NO\n";
        return;
    }
    sum /= tri;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        int prev = (i - 1 + n) % n;
        long long cur = sum - b[i] + b[prev];
        if (cur % n != 0 || cur <= 0 || cur / n > (long long) 1e9) {
            cout << "NO\n";
            return;
        }
        a[i] = cur / n;
    }
    cout << "YES\n";
    for (auto &i : a) {
        cout << i << " ";
    }
    cout << "\n";
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
