/* Author: izhang
 * Time: 05-26-2023 16:57:26
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
    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }
    vector<int> r(n);
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
        total += r[i] - l[i] + 1;
    }
    if (total < k) {
        cout << -1 << "\n";
        return;
    }
    long long sol = INFL;
    int single = 0;
    long long cost = 0;
    for (int i = 0; i < n; ++i) {
        if (l[i] == r[i]) {
            ++single;
        } else {
            cost += 2;
            k -= r[i] - l[i] + 1;
        }
        if (k <= 0) {
            sol = min(sol, cost + r[i] + k);
        } else {
            if (k <= single) {
                sol = min(sol, cost + r[i] + 2 * k);
            }
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
    }
    return 0;
}
