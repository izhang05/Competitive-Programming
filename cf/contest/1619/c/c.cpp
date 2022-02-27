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
    long long a, s;
    cin >> a >> s;
    vector<int> b;
    while (s) {
        if (a % 10 <= s % 10) {
            b.push_back(s % 10 - a % 10);
            s /= 10;
        } else {
            if (s % 100 - a % 10 < 10 && (s % 100 - a % 10 >= 0)) {
                b.push_back(s % 100 - a % 10);
            } else {
                cout << -1 << "\n";
                return;
            }
            s /= 100;
        }
        a /= 10;
    }
    if (a) {
        cout << -1 << "\n";
        return;
    }
    while (!b.empty() && b.back() == 0) {
        b.pop_back();
    }
    reverse(b.begin(), b.end());
    for (auto &i : b) {
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
