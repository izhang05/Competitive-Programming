#include <bits/stdc++.h>

using namespace std;

//#define DEBUG
void setIO(const string &name) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin.exceptions(istream::failbit);
#ifdef LOCAL
    freopen((name + ".in").c_str(), "r", stdin);
//    freopen((name + ".out").c_str(), "w", stdout);
//    freopen((name + ".out").c_str(), "w", stderr);
#endif
}

const int inf = 0x3f3f3f3f, mod = 1e9 + 7;


int main() {
    setIO("1");

    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 != 0) {
        cout << 0 << "\n";
        return 0;
    }
    int l = 0, r = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++l;
        } else {
            ++r;
        }
    }
    if (abs(l - r) != 2) {
        cout << 0 << "\n";
        return 0;
    }
    if (l > r) {
        int cur = 0, sol = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                if (cur > 0) {
                    ++sol;
                }
                ++cur;
            } else {
                --cur;
                if (cur < 0) {
                    sol = 0;
                    break;
                }
                if (cur == 1) {
                    sol = 0;
                }
            }
        }
        cout << sol << "\n";
    } else {
        int cur = 0, sol = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '(') {
                ++cur;
                if (cur > 0) {
                    sol = 0;
                    break;
                }
                if (cur == -1) {
                    sol = 0;
                }
            } else {
                if (cur < 0) {
                    ++sol;
                }
                --cur;
            }
        }
        cout << sol << "\n";
    }
    return 0;
}
