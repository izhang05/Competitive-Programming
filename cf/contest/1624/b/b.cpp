/* Author: izhang
 * Time: 01-10-2022 10:58:13
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
    vector<long long> a(3);
    for (auto &i : a) {
        cin >> i;
    }
    bool good = false;
    long long diff = a[2] - a[1];
    if ((a[1] - diff) > 0 && (a[1] - diff) % a[0] == 0) {
        good = true;
    }
    diff = a[1] - a[0];
    if ((a[1] + diff) > 0 && (a[1] + diff) % a[2] == 0) {
        good = true;
    }
    if ((a[2] - a[0]) % 2 == 0 && ((a[2] + a[0]) / 2) % a[1] == 0) {
        good = true;
    }
    cout << (good ? "YES" : "NO") << "\n";
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
