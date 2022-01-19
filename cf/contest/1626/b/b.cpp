/* Author: izhang
 * Time: 01-16-2022 09:35:02
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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = s[i] - '0';
    }
    bool found = false;
    for (int i = n - 2; i >= 0; --i) {
        if (a[i] + a[i + 1] >= 10) {
            int cur = a[i] + a[i + 1];
            a[i] = cur / 10;
            a[i + 1] = cur % 10;
            found = true;
            break;
        }
    }
    if (!found) {
        int cur = a[0] + a[1];
        a[1] = cur % 10;
        a.erase(a.begin());
    }
    for (auto &i : a) {
        cout << i;
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
