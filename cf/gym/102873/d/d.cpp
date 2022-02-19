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
    long long a, s;
    cin >> a >> s;
    long long b = s - a;
    if (b <= 0) {
        cout << "NO"
             << "\n";
        return;
    }
    multiset<int> a_n, b_n;
    while (a) {
        a_n.insert(a % 10);
        a /= 10;
    }
    while (b) {
        b_n.insert(b % 10);
        b /= 10;
    }
    cout << (a_n == b_n ? "YES" : "NO") << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
