/* Author: izhang
 * Time: 08-25-2023 14:49:56
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
    int n;
    cin >> n;
    vector<vector<int>> a(n);
    int mn = inf;
    for (auto &i : a) {
        int m;
        cin >> m;
        i.resize(m);
        for (auto &j : i) {
            cin >> j;
            mn = min(mn, j);
        }
        sort(i.begin(), i.end());
    }
    sort(a.begin(), a.end(), [](auto left, auto right) {
        return left[0] < right[0];
    });
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i][1];
    }
    long long sol = 0;
    for (int i = 0; i < n; ++i) {
        sol = max(sol, sum - a[i][1] + mn);
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
