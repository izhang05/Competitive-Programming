/* Author: izhang
 * Time: 02-25-2022 23:31:49
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
    string s;
    cin >> s;
    int n = int(s.size());
    if (n % 2 == 1) {
        cout << "NO"
             << "\n";
        return;
    }
    string a, b;
    for (int i = 0; i < n / 2; ++i) {
        a.push_back(s[i]);
    }
    for (int i = n / 2; i < n; ++i) {
        b.push_back(s[i]);
    }
    cout << (a == b ? "YES" : "NO") << "\n";
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
