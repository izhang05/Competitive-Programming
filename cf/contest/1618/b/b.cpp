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
    n -= 2;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    string sol;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i][1] != a[i + 1][0]) {
            cout << a[0];
            for (int j = 1; j <= i; ++j) {
                cout << a[j][1];
            }
            cout << a[i + 1];
            for (int j = i + 2; j < n; ++j) {
                cout << a[j][1];
            }
            cout << "\n";
            return;
        }
    }
    cout << "a";
    cout << a[0];
    for (int i = 1; i < n; ++i) {
        cout << a[i][1];
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
