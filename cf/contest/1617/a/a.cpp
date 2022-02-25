/* Author: izhang
 * Time: 02-24-2022 08:51:57
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
    string s, t;
    cin >> s >> t;
    map<char, int> cnt;
    for (auto &i : s) {
        ++cnt[i];
    }
    if (t == "abc" && cnt['a'] && cnt['b'] && cnt['c']) {
        string sol;
        for (int i = 0; i < cnt['a']; ++i) {
            sol += 'a';
        }
        for (int i = 0; i < cnt['c']; ++i) {
            sol += 'c';
        }
        for (int i = 0; i < cnt['b']; ++i) {
            sol += 'b';
        }
        for (char i = 'd'; i <= 'z'; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                sol += i;
            }
        }
        cout << sol << "\n";
    } else {
        sort(s.begin(), s.end());
        cout << s << "\n";
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
