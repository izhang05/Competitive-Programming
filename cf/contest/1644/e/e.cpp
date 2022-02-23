/* Author: izhang
 * Time: 02-22-2022 15:57:31
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
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (auto &i : s) {
        if (i == 'D') {
            ++x;
        } else {
            ++y;
        }
    }
    int add_x = n - 1 - x, add_y = n - 1 - y;
    long long bad = 0;
    x = 0, y = 0;
    for (auto &i : s) {
        if (i == 'D') {
            ++x;
            for (int j = 0; j < add_x; ++j) {
                ++x;
            }
            add_x = 0;
        } else {
            bad += n - x - 1;
            ++y;
        }
    }
    bad += n - x - 1;
    x = 0, y = 0;
    for (auto &i : s) {
        if (i == 'D') {
            ++x;
        } else {
            bad += x;
            ++y;
            for (int j = 0; j < add_y; ++j) {
                bad += x;
                ++y;
            }
            add_y = 0;
        }
    }
    bool same = true;
    for (auto &i : s) {
        if (i != s[0]) {
            same = false;
            break;
        }
    }
    if (same) {
        cout << n << "\n";
    } else {
        cout << (long long) n * n - bad << "\n";
    }
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
