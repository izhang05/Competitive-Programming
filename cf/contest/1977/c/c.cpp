/* Author: izhang
 * Time: 06-19-2024 14:11:03
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

int solve(int i, const vector<int> &a) {
    int cur = 0;
    long long l = 1;
    bool bad = false;
    for (auto &j : a) {
        if (j == i) {
            bad = true;
        }
        if (i % j == 0) {
            l = lcm(l, j);
            ++cur;
        }
    }
    dbg() << i << " " << l << " " << cur;
    if (!bad && l == i) {
        return cur;
    }
    return 0;
}

void test_case() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long l = a[0];
    for (int i = 1; i < n; ++i) {
        l = lcm(l, a[i]);
        if (l > a.back()) {
            cout << n << "\n";
            return;
        }
    }
    if (l != a.back()) {
        cout << n << "\n";
        return;
    }
    int sol = 0;
    for (int i = 1; (long long) i * i <= a.back(); ++i) {
        if (a.back() % i == 0) {
            sol = max(sol, solve(i, a));
            sol = max(sol, solve(a.back() / i, a));
        }
    }
    cout << sol << "\n";
}

int main() {
    setIO("1");

    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
        dbg();
    }
    return 0;
}
