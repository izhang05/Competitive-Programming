/* Author: izhang
 * Time: 01-22-2022 10:39:01
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
bool palindrome(const string &s) {
    for (int i = 0; i < int(s.size()) / 2; ++i) {
        if (s[i] != s[int(s.size()) - i - 1]) {
            return false;
        }
    }
    return true;
}

void test_case() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (palindrome(a[i])) {
            cout << "YES"
                 << "\n";
            return;
        }
        for (int j = i + 1; j < n; ++j) {
            string cur = a[i];
            cur += a[j];
            if (palindrome(cur)) {
                cout << "YES"
                     << "\n";
                return;
            }
        }
    }
    cout << "NO"
         << "\n";
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
