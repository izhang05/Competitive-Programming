/* Author: izhang05
 * Time: 12-29-2021 10:35:02
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
    if (n >= 2 && s[0] == s[1]) {
        string sol;
        sol.push_back(s[0]);
        sol.push_back(s[1]);
        cout << sol << "\n";
        return;
    }
    string sol;
    sol.push_back(s[0]);
    s.push_back(char('z' + 1));
    int last = 1;
    for (int i = 1; i <= n; ++i) {
        if (s[i] < s[i - 1]) {
            for (int j = last; j < i; ++j) {
                sol.push_back(s[i - 1]);
            }
            sol.push_back(s[i]);
            last = i + 1;
        } else if (s[i] > s[i - 1]) {
            for (int j = last; j < i; ++j) {
                sol.push_back(s[i - 1]);
            }
            break;
        }
    }
    string rev(sol.begin(), sol.end());
    reverse(rev.begin(), rev.end());
    for (auto &i : rev) {
        sol.push_back(i);
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
