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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    map<char, int> occ;
    for (auto &i : s) {
        ++occ[i];
    }
    int cnt = 0, odd = 0;
    for (auto &i : occ) {
        cnt += i.second / 2;
        odd += i.second % 2;
    }
    int sol = 2 * (cnt / k);
    if (odd + 2 * (cnt % k) >= k) {
        ++sol;
    }
    cout << sol << "\n";
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
