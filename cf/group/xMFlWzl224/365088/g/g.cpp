/* Author: izhang
 * Time: 01-19-2022 18:47:43
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
    cout << 1 << " " << 0 << endl;
    string c;
    cin >> c;
    int lo = 1, hi = 1e9;
    for (int i = 1; i < n; ++i) {
        int mid = (lo + hi) / 2;
        cout << 1 << " " << mid << endl;
        string cur;
        cin >> cur;
        if (cur == c) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    cout << 2 << " " << lo << " " << 0 << " " << lo - 1 << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
