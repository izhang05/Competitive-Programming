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

int added;
int guess(int c) {
    added += c;
    cout << "+ " << c << endl;
    int res;
    cin >> res;
    return res;
}
void sol(int x) {
    cout << "! " << x << endl;
}

void test_case() {
    int n;
    cin >> n;
    int lo = 1, hi = n, cur = 0;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (guess(n * (cur + 1) - mid - added) == cur) {
            hi = mid - 1;
        } else {
            ++cur;
            lo = mid;
        }
    }
    sol(lo + added);
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
