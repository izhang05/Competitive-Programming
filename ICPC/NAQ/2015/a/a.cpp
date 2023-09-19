/* Author: izhang
 * Time: 09-18-2023 19:22:02
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
const long long INFL = 0x3f3f3f3f3f3f3f3f, mx = 1ll << 32;

long long base(string s, long long b) {
    if (b == 1) {
        for (auto &i: s) {
            if (i != '1') {
                return false;
            }
        }
        return s.size();
    }
    vector<int> cur(int(s.size()));
    for (int i = s.size() - 1; i >= 0; --i) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            cur[i] = s[i] - 'a' + 10;
        } else {
            cur[i] = s[i] - '0';
        }
    }
    reverse(cur.begin(), cur.end());
    while (!cur.empty() && cur.back() == 0) {
        cur.pop_back();
    }
    int n = (int) cur.size();
    long long res = 0, mult = 1;
    for (int i = 0; i < n; ++i) {
        if (mult >= mx) {
            return 0;
        }
        if (cur[i] >= b) {
            return 0;
        }
        res += mult * cur[i];
        mult *= b;
    }
    if (res >= mx) {
        return 0;
    }
    return res;
}


void test_case() {
    string a, b, res;
    char op, _;
    cin >> a >> op >> b >> _ >> res;
    set<int> sol;
    for (int i = 1; i <= 36; ++i) {
        unsigned long long a_cur = base(a, i), b_cur = base(b, i), res_cur = base(res, i);
        if (a_cur == 0 || b_cur == 0 || res_cur == 0) {
            continue;
        }
        if (op == '+') {
            if (a_cur + b_cur == res_cur) {
                sol.insert(i);
            }
        } else if (op == '-') {
            if (a_cur - b_cur == res_cur) {
                sol.insert(i);
            }
        } else if (op == '*') {
            if (a_cur * b_cur == res_cur) {
                sol.insert(i);
            }
        } else {
            if (res_cur * b_cur == a_cur) {
                sol.insert(i);
            }
        }
    }

    if (sol.empty()) {
        cout << "invalid" << "\n";
    } else {
        for (auto &i: sol) {
            if (i < 10) {
                cout << i;
            } else if (i == 36) {
                cout << 0;
            } else {
                cout << char(i + 'a' - 10);
            }
        }
        cout << "\n";
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
