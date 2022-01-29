/* Author: izhang
 * Time: 01-29-2022 16:01:58
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
    vector<int> a(4 * n - 1);
    map<int, int> cnt;
    for (int i = 0; i < 4 * n - 1; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    for (auto &i: cnt) {
        if (i.second == 3) {
            cout << i.first << "\n";
            return;
        }
    }

}

int main() {
    setIO("1");

    int test_case_number = 1;
    while (test_case_number--) {
        test_case();
    }
    return 0;
}
