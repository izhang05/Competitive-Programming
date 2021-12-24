/* Author: izhang05
 * Time: 12-23-2021 20:40:02
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

void test_case() {
    string s;
    cin >> s;
    bool zero = false, even = false;
    int sum = 0;
    for (auto &i : s) {
        if (!zero && i == '0') {
            zero = true;
        } else if (i == '0' || i == '2' || i == '4' || i == '6' || i == '8') {
            even = true;
        }
        sum += i - '0';
    }
    cout << (zero && even && sum % 3 == 0 ? "red" : "cyan") << "\n";
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
