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

[[maybe_unused]] const int inf = 0x3f3f3f3f, mod = 1e9 + 7;
const long long INFL = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string tmp;
    cin >> tmp;
    int n = (int) tmp.size(), sol = inf;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        s[i] = tmp[i] - '0';
    }
    for (int x = 0; x < 2; ++x) {
        int cur_sol = 0, pre = s[0], len = 1;
        vector<int> l(n);
        for (int i = 1; i < n; ++i) {
            if (s[i] != pre) {
                l[i - len] = len;
                pre = s[i], len = 1;
            } else {
                ++len;
            }
        }
        l[n - len] = len;
        pre = s[0], len = 1;
        for (int i = 1; i < n; ++i) {
            if (s[i] != pre) {
                if (pre != x) {
                    if (i < n - 1 && l[i] == 1 && (len > 1 || l[i + 1] > 1)) {
                        ++len;
                        ++cur_sol;
                        continue;
                    }
                    if (len == 1) {
                        cur_sol += 1;
                    } else {
                        cur_sol += 2;
                    }
                }
                pre = s[i], len = 1;
            } else {
                ++len;
            }
        }
        if (pre != x) {
            if (len == 1) {
                cur_sol += 1;
            } else {
                cur_sol += 2;
            }
        }
        sol = min(sol, cur_sol);
    }
    cout << sol << "\n";
}

int main() {
    setIO("2");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        solve();
    }
    return 0;
}
