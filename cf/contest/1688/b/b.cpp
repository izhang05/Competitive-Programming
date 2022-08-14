/* Author: izhang
 * Time: 08-01-2022 15:36:02
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
int cost(int x) {
    int res = 0;
    while (x % 2 == 0) {
        x /= 2;
        ++res;
    }
    return res;
//    return 2 * res - 1;
}

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    int odd = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] % 2 == 1) {
            ++odd;
        }
    }
    if (odd >= 1) {
        cout << n - odd << "\n";
    } else {
        int sol = inf;
        for (auto &i : a) {
            sol = min(sol, cost(i));
        }
        cout << sol + n - 1 << "\n";
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
