/* Author: izhang
 * Time: 06-24-2024 16:25:01
**/
#include <bits/stdc++.h>

using namespace std;

#if defined LOCAL || defined DEBUG
#include <debug.h>
#else
struct dbg {
    template<class c>
    dbg &operator<<(const c &) { return *this; }
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#endif

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

int solve(string &s, string &t) {
    int n = int(s.size());

    for (int i = 0; i + 2 < n; ++i) {
        if (s[i] == '0' && s[i + 2] == '0') {
            t[i + 1] = '1';
        }
    }
    for (int i = 0; i + 2 < n; ++i) {
        if (t[i] == '1' && t[i + 2] == '1') {
            s[i + 1] = '1';
        }
    }
    int sol = 0;
    for (auto &i : s) {
        sol += (i == '1');
    }
    return sol;
}

void test_case() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string new_s(s.begin(), s.end()), new_t(t.begin(), t.end());
    for (int i = 0; i + 2 < n; ++i) {
        if (s[i] == '0' && s[i + 2] == '0') {
            new_t[i + 1] = '1';
        }
    }
    for (int i = 0; i + 2 < n; ++i) {
        if (new_t[i] == '1' && new_t[i + 2] == '1') {
            new_s[i + 1] = '1';
        }
    }
    vector<int> pre(n + 1);
    for (int i = 0; i < n; ++i) {
        pre[i + 1] = pre[i] + (new_s[i] == '1');
    }

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        if (r - l <= 5) {
            string cur_s, cur_t;
            for (int i = l; i <= r; ++i) {
                cur_s += s[i];
                cur_t += t[i];
            }
            cout << solve(cur_s, cur_t) << "\n";
            continue;
        }
        int sol = pre[r + 1] - pre[l];
        if (s[l] == '0' && new_s[l] == '1') {
            --sol;
        }
        if (s[r] == '0' && new_s[r] == '1') {
            --sol;
        }
        if (s[l + 1] == '0' && new_s[l + 1] == '1' && t[l] == '0') {
            --sol;
        }
        if (s[r - 1] == '0' && new_s[r - 1] == '1' && t[r] == '0') {
            --sol;
        }
        cout << sol << "\n";
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
