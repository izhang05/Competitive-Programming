/* Author: izhang
 * Time: 04-17-2022 10:35:03
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

void test_case() {
    int n, k;
    cin >> n >> k;
    int orig_k = k;
    string s;
    cin >> s;
    vector<int> sol(n);
    string new_s;
    if (k % 2 == 0) {
        for (int i = 0; i < n && k; ++i) {
            if (s[i] == '0') {
                sol[i] = 1;
                --k;
            }
        }
    } else {
        for (int i = 0; i < n && k; ++i) {
            if (s[i] == '1') {
                sol[i] = 1;
                --k;
            }
        }
    }
    sol.back() += k;
    for (int i = 0; i < n; ++i) {
        if (orig_k % 2 == sol[i] % 2) {
            cout << s[i];
        } else {
            cout << '1' - s[i];
        }
    }
    cout << "\n";
    for (auto &i : sol) {
        cout << i << " ";
    }
    cout << "\n";
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
