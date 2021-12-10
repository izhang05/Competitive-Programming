/* Author: izhang05
 * Time: 12-07-2021 17:16:02
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
const int inf = 0x3f3f3f3f, mod = 1e9 + 7, maxn = 5e3 + 5;
const long long INFL = 0x3f3f3f3f3f3f3f3f;
int n, a[maxn];

int solve(int l, int r) {
    if (r <= l) {
        return 0;
    }
    int mn = *min_element(a + l, a + r), ind;
    for (int i = l; i < r; ++i) {
        a[i] -= mn;
        if (!a[i]) {
            ind = i;
        }
    }
    return min(solve(l, ind) + solve(ind + 1, r) + mn, r - l);
}

void test_case() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << solve(0, n) << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
