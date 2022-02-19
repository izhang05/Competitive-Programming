/* Author: izhang
 * Time: 02-19-2022 14:20:02
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
    string s;
    cin >> s;
    string t;
    cin >> t;
    long long sol = 0;
    set<int> pos;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] == t[0] && s[i + 1] == t[1]) {
            pos.insert(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        auto it = pos.lower_bound(i);
        if (it != pos.end()) {
            sol += n - *it - 1;
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
