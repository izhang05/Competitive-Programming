/* Author: izhang05
 * Time: 12-24-2021 09:35:01
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

vector<int> cnt(int x) {
    vector<int> cnt(18);
    for (int i = 0; i < 18; ++i) {
        int cur_size = 1 << i;
        if (x - (cur_size - 1) <= 0) {
            break;
        }
        cnt[i] = cur_size * ((x - (cur_size - 1)) / (2 * cur_size));
        cnt[i] += min(cur_size, (x - (cur_size - 1)) % (2 * cur_size));
    }
    return cnt;
}

void test_case() {
    int l, r;
    cin >> l >> r;
    int sol = 0;
    vector<int> a = cnt(r), b = cnt(l - 1);
    for (int i = 0; i < 18; ++i) {
        sol = max(sol, a[i] - b[i]);
    }
    cout << r - l + 1 - sol << "\n";
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
